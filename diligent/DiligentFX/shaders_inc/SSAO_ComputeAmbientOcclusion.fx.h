"#include \"SSAO_Common.fxh\"\n"
"#include \"PostFX_Common.fxh\"\n"
"#include \"BasicStructures.fxh\"\n"
"#include \"ScreenSpaceAmbientOcclusionStructures.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"\n"
"cbuffer cbCameraAttribs\n"
"{\n"
"    CameraAttribs g_Camera;\n"
"}\n"
"\n"
"cbuffer cbScreenSpaceAmbientOcclusionAttribs\n"
"{\n"
"    ScreenSpaceAmbientOcclusionAttribs g_SSAOAttribs;\n"
"}\n"
"\n"
"Texture2D<float>  g_TexturePrefilteredDepth;\n"
"Texture2D<float3> g_TextureNormal;\n"
"Texture2D<float2> g_TextureBlueNoise;\n"
"\n"
"SamplerState g_TexturePrefilteredDepth_sampler;\n"
"SamplerState g_TextureNormal_sampler;\n"
"\n"
"float2 SampleRandomVector2D(int2 PixelCoord)\n"
"{\n"
"    return g_TextureBlueNoise.Load(int3(PixelCoord & 127, 0));\n"
"}\n"
"\n"
"float3 SampleNormalWS(float2 ScreenCoordUV)\n"
"{\n"
"    return g_TextureNormal.SampleLevel(g_TextureNormal_sampler, ScreenCoordUV, 0.0);\n"
"}\n"
"\n"
"float SamplePrefilteredDepth(float2 ScreenCoordUV, float MipLevel)\n"
"{\n"
"    return g_TexturePrefilteredDepth.SampleLevel(g_TexturePrefilteredDepth_sampler, ScreenCoordUV, MipLevel);\n"
"}\n"
"\n"
"float2 ComputeSliceDirection(float Xi, int Index)\n"
"{\n"
"    float Rotation = float(Index) / 3.0;\n"
"    float Phi = (Xi + Rotation) * M_PI;\n"
"    return float2(cos(Phi), sin(Phi));\n"
"}\n"
"\n"
"float FastACos(float Value)\n"
"{\n"
"    float Result = -0.156583 * Value + M_HALF_PI;\n"
"    Result *= sqrt(1.0 - abs(Value));\n"
"    return (Value >= 0.0) ? Result : M_PI - Result;\n"
"}\n"
"\n"
"float IntegrateArcUniform(float HorizonX, float HorizonY)\n"
"{\n"
"    return (1.0f - cos(HorizonX) + (1.0 - cos(HorizonY)));\n"
"}\n"
"\n"
"float IntegrateArcCosWeighted(float HorizonX, float HorizonY, float N, float CosN)\n"
"{\n"
"    float H1 = HorizonX * 2.0;\n"
"    float H2 = HorizonY * 2.0;\n"
"    float SinN = sin(N);\n"
"    return 0.25 * ((-cos(H1 - N) + CosN + H1 * SinN) + (-cos(H2 - N) + CosN + H2 * SinN));\n"
"}\n"
"\n"
"float2 GetInvViewportSize()\n"
"{\n"
"#if SSAO_OPTION_HALF_RESOLUTION\n"
"    return 2.0 * g_Camera.f4ViewportSize.zw;\n"
"#else\n"
"    return g_Camera.f4ViewportSize.zw;\n"
"#endif\n"
"}\n"
"\n"
"float ComputeAmbientOcclusionPS(in FullScreenTriangleVSOutput VSOut) : SV_Target0\n"
"{\n"
"    float2 Position = VSOut.f4PixelPos.xy;\n"
"\n"
"    float2 ScreenCoordUV = Position * GetInvViewportSize();\n"
"    float3 PositionSS = float3(ScreenCoordUV, SamplePrefilteredDepth(ScreenCoordUV, 0.0));\n"
"\n"
"    if (IsBackground(PositionSS.z))\n"
"        discard;\n"
"\n"
"    // Trying to fix self-occlusion. Maybe there\'s a better way\n"
"#if SSAO_OPTION_HALF_PRECISION_DEPTH\n"
"    PositionSS.z *= 0.99995;\n"
"#else\n"
"    PositionSS.z *= 0.999999;\n"
"#endif\n"
"\n"
"    float3 NormalVS = mul(float4(SampleNormalWS(ScreenCoordUV), 0.0), g_Camera.mView).xyz;\n"
"    float3 PositionVS = ScreenXYDepthToViewSpace(PositionSS, g_Camera.mProj);\n"
"    float3 ViewVS = -normalize(PositionVS);\n"
"    float2 Xi = SampleRandomVector2D(int2(Position));\n"
"\n"
"    float EffectRadius = g_SSAOAttribs.EffectRadius * g_SSAOAttribs.RadiusMultiplier;\n"
"    float FalloffRange = g_SSAOAttribs.EffectFalloffRange * EffectRadius;\n"
"    float FalloffFrom = EffectRadius - FalloffRange;\n"
"\n"
"    float FalloffMul = -1.0 / FalloffRange;\n"
"    float FalloffAdd = FalloffFrom / FalloffRange + 1.0;\n"
"    float SampleRadius = 0.5 * EffectRadius * MATRIX_ELEMENT(g_Camera.mProj, 0, 0) / PositionVS.z;\n"
"\n"
"    float Visibility = 0.0;\n"
"    for (int SliceIdx = 0; SliceIdx < SSAO_SLICE_COUNT; SliceIdx++)\n"
"    {\n"
"        float2 Omega = ComputeSliceDirection(Xi.x, SliceIdx);\n"
"\n"
"        float3 SliceDirection = float3(Omega, 0.0);\n"
"        float3 OrthoSliceDir = SliceDirection - dot(SliceDirection, ViewVS) * ViewVS;\n"
"        float3 Axis = cross(SliceDirection, ViewVS);\n"
"        float3 ProjNormal = NormalVS - Axis * dot(NormalVS, Axis);\n"
"\n"
"        float ProjNormalLen = length(ProjNormal);\n"
"        float CosNorm = saturate(dot(ProjNormal / ProjNormalLen, ViewVS));\n"
"        float N = sign(dot(OrthoSliceDir, ProjNormal)) * FastACos(CosNorm);\n"
"\n"
"        float2 MinCosHorizons;\n"
"        MinCosHorizons.x = cos(N + M_HALF_PI);\n"
"        MinCosHorizons.y = cos(N - M_HALF_PI);\n"
"\n"
"        float2 MaxCosHorizons;\n"
"        MaxCosHorizons.x = MinCosHorizons.x;\n"
"        MaxCosHorizons.y = MinCosHorizons.y;\n"
"\n"
"        float2 SampleDirection = float2(Omega.x, Omega.y) * F3NDC_XYZ_TO_UVD_SCALE.xy * SampleRadius;\n"
"        SampleDirection.x *= g_Camera.f4ViewportSize.y * g_Camera.f4ViewportSize.z; // Aspect ratio correction\n"
"\n"
"        for (int SampleIdx = 0; SampleIdx < SSAO_SAMPLES_PER_SLICE; SampleIdx++)\n"
"        {\n"
"            float Noise = frac(Xi.y + float(SliceIdx + SampleIdx * SSAO_SAMPLES_PER_SLICE) * 0.6180339887498948482);\n"
"            float Sample = (float(SampleIdx) + Noise) / float(SSAO_SAMPLES_PER_SLICE);\n"
"\n"
"            float2 SampleOffset = Sample * Sample * SampleDirection;\n"
"            float2 SamplePositionSS0 = PositionSS.xy + SampleOffset;\n"
"            float2 SamplePositionSS1 = PositionSS.xy - SampleOffset;\n"
"\n"
"            float MipLevel = clamp(log2(length(SampleOffset * g_Camera.f4ViewportSize.xy)) - g_SSAOAttribs.DepthMIPSamplingOffset, 0.0, float(SSAO_DEPTH_PREFILTERED_MAX_MIP));\n"
"            float3 SamplePositionVS0 = ScreenXYDepthToViewSpace(float3(SamplePositionSS0, SamplePrefilteredDepth(SamplePositionSS0, MipLevel)), g_Camera.mProj);\n"
"            float3 SamplePositionVS1 = ScreenXYDepthToViewSpace(float3(SamplePositionSS0, SamplePrefilteredDepth(SamplePositionSS1, MipLevel)), g_Camera.mProj);\n"
"\n"
"            float3 SampleDifference0 = SamplePositionVS0 - PositionVS;\n"
"            float3 SampleDifference1 = SamplePositionVS1 - PositionVS;\n"
"\n"
"            float SampleDistance0 = length(SampleDifference0);\n"
"            float SampleCosHorizon0 = dot(SampleDifference0 / SampleDistance0, ViewVS);\n"
"            float Weight0 = saturate(SampleDistance0 * FalloffMul + FalloffAdd);\n"
"\n"
"            float SampleDistance1 = length(SampleDifference1);\n"
"            float SampleCosHorizon1 = dot(SampleDifference1 / SampleDistance1, ViewVS);\n"
"            float Weight1 = saturate(SampleDistance1 * FalloffMul + FalloffAdd);\n"
"\n"
"            MaxCosHorizons.x = max(MaxCosHorizons.x, lerp(MinCosHorizons.x, SampleCosHorizon0, Weight0));\n"
"            MaxCosHorizons.y = max(MaxCosHorizons.y, lerp(MinCosHorizons.y, SampleCosHorizon1, Weight1));\n"
"        }\n"
"\n"
"        float2 HorizonAngles;\n"
"        HorizonAngles.x = +FastACos(MaxCosHorizons.x);\n"
"        HorizonAngles.y = -FastACos(MaxCosHorizons.y);\n"
"\n"
"#if SSAO_OPTION_UNIFORM_WEIGHTING\n"
"        Visibility += 0.5 * IntegrateArcUniform(HorizonAngles.x, HorizonAngles.y);\n"
"#else\n"
"        Visibility += ProjNormalLen * IntegrateArcCosWeighted(HorizonAngles.x, HorizonAngles.y, N, CosNorm);\n"
"#endif\n"
"    }\n"
"\n"
"    return Visibility / float(SSAO_SLICE_COUNT);\n"
"}\n"