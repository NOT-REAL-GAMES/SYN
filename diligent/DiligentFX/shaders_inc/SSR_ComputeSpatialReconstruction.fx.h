"#include \"ScreenSpaceReflectionStructures.fxh\"\n"
"#include \"BasicStructures.fxh\"\n"
"#include \"PBR_Common.fxh\"\n"
"#include \"SSR_Common.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"#include \"PostFX_Common.fxh\"\n"
"\n"
"cbuffer cbCameraAttribs\n"
"{\n"
"    CameraAttribs g_Camera;\n"
"}\n"
"\n"
"cbuffer cbScreenSpaceReflectionAttribs\n"
"{\n"
"    ScreenSpaceReflectionAttribs g_SSRAttribs;\n"
"}\n"
"\n"
"struct PSOutput\n"
"{\n"
"    float4 ResolvedRadiance : SV_Target0;\n"
"    float  ResolvedVariance : SV_Target1;\n"
"    float  ResolvedDepth    : SV_Target2;\n"
"};\n"
"\n"
"Texture2D<float>  g_TextureRoughness;\n"
"Texture2D<float3> g_TextureNormal;\n"
"Texture2D<float>  g_TextureDepth;\n"
"Texture2D<float4> g_TextureRayDirectionPDF;\n"
"Texture2D<float4> g_TextureIntersectSpecular;\n"
"\n"
"struct PixelAreaStatistic\n"
"{\n"
"    float Mean;\n"
"    float Variance;\n"
"    float WeightSum;\n"
"    float4 ColorSum;\n"
"};\n"
"\n"
"float SampleRoughness(int2 PixelCoord)\n"
"{\n"
"    return g_TextureRoughness.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float3 SampleNormalWS(int2 PixelCoord)\n"
"{\n"
"    return g_TextureNormal.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float SampleDepth(int2 PixelCoord)\n"
"{\n"
"    return g_TextureDepth.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float ComputeGaussianWeight(float Distance)\n"
"{\n"
"    return exp(-0.66 * Distance * Distance); // assuming Distance is normalized to 1\n"
"}\n"
"\n"
"float4 ComputeBlurKernelRotation(uint2 PixelCoord, uint FrameIndex)\n"
"{\n"
"    float Angle = Bayer4x4(PixelCoord, FrameIndex);\n"
"    return GetRotator(2.0 * M_PI * Angle);\n"
"}\n"
"\n"
"float2 ComputeWeightRayLength(int2 PixelCoord, float3 V, float3 N, float Roughness, float NdotV, float Weight)\n"
"{\n"
"    float4 RayDirectionPDF = g_TextureRayDirectionPDF.Load(int3(PixelCoord, 0));\n"
"    float InvRayLength = rsqrt(dot(RayDirectionPDF.xyz, RayDirectionPDF.xyz));\n"
"    if (isnan(InvRayLength))\n"
"        return float2(1.0e-6f, 1.0e-6f);\n"
"\n"
"    float3 RayDirection = RayDirectionPDF.xyz * InvRayLength;\n"
"    float PDF = RayDirectionPDF.w;\n"
"    float AlphaRoughness = Roughness * Roughness;\n"
"\n"
"    float3 L = RayDirection;\n"
"    float3 H = normalize(L + V);\n"
"\n"
"    float NdotH = saturate(dot(N, H));\n"
"    float NdotL = saturate(dot(N, L));\n"
"\n"
"    float Vis = SmithGGXVisibilityCorrelated(NdotL, NdotV, AlphaRoughness);\n"
"    float D = NormalDistribution_GGX(NdotH, AlphaRoughness);\n"
"    float LocalBRDF = Vis * D * NdotL;\n"
"    LocalBRDF *= ComputeGaussianWeight(Weight);\n"
"    return float2(max(LocalBRDF / max(PDF, 1.0e-5f), 1e-6), rcp(InvRayLength));\n"
"}\n"
"\n"
"// Weighted incremental variance\n"
"// https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance\n"
"void ComputeWeightedVariance(inout PixelAreaStatistic Stat, float4 SampleColor, float Weight)\n"
"{\n"
"    Stat.ColorSum += Weight * SampleColor;\n"
"    Stat.WeightSum += Weight;\n"
"\n"
"    float Value = Luminance(SampleColor.rgb);\n"
"    float PrevMean = Stat.Mean;\n"
"\n"
"    Stat.Mean += Weight * rcp(Stat.WeightSum) * (Value - PrevMean);\n"
"    Stat.Variance += Weight * (Value - PrevMean) * (Value - Stat.Mean);\n"
"}\n"
"\n"
"float ComputeResolvedDepth(float3 PositionWS, float SurfaceHitDistance)\n"
"{\n"
"    float CameraSurfaceDistance = distance(g_Camera.f4Position.xyz, PositionWS);\n"
"    return CameraZToDepth(CameraSurfaceDistance + SurfaceHitDistance, g_Camera.mProj);\n"
"}\n"
"\n"
"float3 ScreenSpaceToWorldSpace(float3 ScreenCoordUV)\n"
"{\n"
"    return InvProjectPosition(ScreenCoordUV, g_Camera.mViewProjInv);\n"
"}\n"
"\n"
"SSR_ATTRIBUTE_EARLY_DEPTH_STENCIL\n"
"PSOutput ComputeSpatialReconstructionPS(in FullScreenTriangleVSOutput VSOut)\n"
"{\n"
"    // samples = 8, min distance = 0.5, average samples on radius = 2\n"
"    float3 Poisson[SSR_SPATIAL_RECONSTRUCTION_SAMPLES];\n"
"    Poisson[0] = float3(-0.4706069, -0.4427112, +0.6461146);\n"
"    Poisson[1] = float3(-0.9057375, +0.3003471, +0.9542373);\n"
"    Poisson[2] = float3(-0.3487388, +0.4037880, +0.5335386);\n"
"    Poisson[3] = float3(+0.1023042, +0.6439373, +0.6520134);\n"
"    Poisson[4] = float3(+0.5699277, +0.3513750, +0.6695386);\n"
"    Poisson[5] = float3(+0.2939128, -0.1131226, +0.3149309);\n"
"    Poisson[6] = float3(+0.7836658, -0.4208784, +0.8895339);\n"
"    Poisson[7] = float3(+0.1564120, -0.8198990, +0.8346850);\n"
"\n"
"    float4 Position = VSOut.f4PixelPos;\n"
"    float2 ScreenCoordUV = Position.xy * g_Camera.f4ViewportSize.zw;\n"
"    float3 PositionWS = ScreenSpaceToWorldSpace(float3(ScreenCoordUV, SampleDepth(int2(Position.xy))));\n"
"    float3 NormalWS = SampleNormalWS(int2(Position.xy));\n"
"    float3 ViewWS = normalize(g_Camera.f4Position.xyz - PositionWS);\n"
"    float NdotV = saturate(dot(NormalWS, ViewWS));\n"
"\n"
"    float Roughness = SampleRoughness(int2(Position.xy));\n"
"    float RoughnessFactor = saturate(float(SSR_SPATIAL_RECONSTRUCTION_ROUGHNESS_FACTOR) * Roughness);\n"
"    float Radius = lerp(0.0, g_SSRAttribs.SpatialReconstructionRadius, RoughnessFactor);\n"
"    float4 Rotator = ComputeBlurKernelRotation(uint2(Position.xy), g_Camera.uiFrameIndex);\n"
"\n"
"    PixelAreaStatistic PixelAreaStat;\n"
"    PixelAreaStat.ColorSum = float4(0.0, 0.0, 0.0, 0.0);\n"
"    PixelAreaStat.WeightSum = 0.0;\n"
"    PixelAreaStat.Variance = 0.0;\n"
"    PixelAreaStat.Mean = 0.0;\n"
"\n"
"    float NearestSurfaceHitDistance = 0.0;\n"
"\n"
"    // TODO: Try to implement sampling from https://youtu.be/MyTOGHqyquU?t=1043\n"
"    for (int SampleIdx = 0; SampleIdx < SSR_SPATIAL_RECONSTRUCTION_SAMPLES; SampleIdx++)\n"
"    {\n"
"        float2 Xi = RotateVector(Rotator, Poisson[SampleIdx].xy);\n"
"#if SSR_OPTION_HALF_RESOLUTION\n"
"        int2 SampleCoord = ClampScreenCoord(int2(0.5 * (floor(Position.xy) + Radius * Xi) + float2(0.5, 0.5)), int2(0.5 * g_Camera.f4ViewportSize.xy));\n"
"#else\n"
"        int2 SampleCoord = ClampScreenCoord(int2(Position.xy + Radius * Xi), int2(g_Camera.f4ViewportSize.xy));\n"
"#endif\n"
"        float WeightS = ComputeSpatialWeight(Poisson[SampleIdx].z * Poisson[SampleIdx].z, SSR_SPATIAL_RECONSTRUCTION_SIGMA);\n"
"        float2 WeightLength = ComputeWeightRayLength(SampleCoord, ViewWS, NormalWS, Roughness, NdotV, WeightS);\n"
"        float4 SampleColor = g_TextureIntersectSpecular.Load(int3(SampleCoord, 0));\n"
"        ComputeWeightedVariance(PixelAreaStat, SampleColor, WeightLength.x);\n"
"\n"
"        if (WeightLength.x > 1.0e-6)\n"
"            NearestSurfaceHitDistance = max(WeightLength.y, NearestSurfaceHitDistance);\n"
"    }\n"
"\n"
"    PSOutput Output;\n"
"    Output.ResolvedRadiance = PixelAreaStat.ColorSum / max(PixelAreaStat.WeightSum, 1e-6f);\n"
"    Output.ResolvedVariance = PixelAreaStat.Variance / max(PixelAreaStat.WeightSum, 1e-6f);\n"
"    Output.ResolvedDepth = ComputeResolvedDepth(PositionWS, NearestSurfaceHitDistance);\n"
"    return Output;\n"
"}\n"
