"#include \"ScreenSpaceAmbientOcclusionStructures.fxh\"\n"
"#include \"BasicStructures.fxh\"\n"
"#include \"PBR_Common.fxh\"\n"
"#include \"PostFX_Common.fxh\"\n"
"#include \"SSAO_Common.fxh\"\n"
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
"Texture2D<float>  g_TextureOcclusion;\n"
"Texture2D<float>  g_TextureHistory;\n"
"Texture2D<float>  g_TextureDepth;\n"
"Texture2D<float3> g_TextureNormal;\n"
"\n"
"float SampleOcclusion(int2 PixelCoord)\n"
"{\n"
"    return g_TextureOcclusion.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float SampleDepth(int2 PixelCoord)\n"
"{\n"
"    return g_TextureDepth.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float SampleHistory(int2 PixelCoord)\n"
"{\n"
"    return g_TextureHistory.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float3 SampleNormalWS(int2 PixelCoord)\n"
"{\n"
"    return g_TextureNormal.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float4 ComputeBlurKernelRotation(uint2 PixelCoord, uint FrameIndex)\n"
"{\n"
"    float Angle = Bayer4x4(PixelCoord, FrameIndex);\n"
"    return GetRotator(2.0 * M_PI * Angle);\n"
"}\n"
"\n"
"float ComputeSpatialReconstructionPS(in FullScreenTriangleVSOutput VSOut) : SV_Target0\n"
"{\n"
"    // samples = 8, min distance = 0.5, average samples on radius = 2\n"
"    float3 Poisson[SSAO_SPATIAL_RECONSTRUCTION_SAMPLES];\n"
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
"    float History = SampleHistory(int2(Position.xy));\n"
"    float Depth = SampleDepth(int2(Position.xy));\n"
"    float AccumulationFactor = pow(abs((History - 1.0) / float(SSAO_OCCLUSION_HISTORY_MAX_FRAMES_WITH_DENOISING)), 0.2);\n"
"\n"
"    if (IsBackground(Depth) || AccumulationFactor >= 1.0)\n"
"        return SampleOcclusion(int2(Position.xy));\n"
"\n"
"    float3 PositionSS = float3(Position.xy * g_Camera.f4ViewportSize.zw, Depth);\n"
"    float3 PositionVS = ScreenXYDepthToViewSpace(PositionSS, g_Camera.mProj);\n"
"    float3 NormalVS = mul(float4(SampleNormalWS(int2(Position.xy)), 0.0), g_Camera.mView).xyz;\n"
"    float4 Rotator = ComputeBlurKernelRotation(uint2(Position.xy), g_Camera.uiFrameIndex);\n"
"    float Radius = lerp(0.0, g_SSAOAttribs.SpatialReconstructionRadius, 1.0 - saturate(AccumulationFactor));\n"
"    float PlaneNormalFactor = 10.0 / (1.0 + DepthToCameraZ(Depth, g_Camera.mProj));\n"
"\n"
"    float OcclusionSum = 0.0;\n"
"    float WeightSum = 0.0;\n"
"\n"
"    for (int SampleIdx = 0; SampleIdx < SSAO_SPATIAL_RECONSTRUCTION_SAMPLES; SampleIdx++)\n"
"    {\n"
"        float2 Xi = RotateVector(Rotator, Poisson[SampleIdx].xy);\n"
"        int2 SampleCoord = ClampScreenCoord(int2(Position.xy + Radius * Xi), int2(g_Camera.f4ViewportSize.xy));\n"
"\n"
"        float SampledDepth = SampleDepth(SampleCoord);\n"
"        float SampledOcclusion = SampleOcclusion(SampleCoord);\n"
"\n"
"        float3 SamplePositionSS = float3((float2(SampleCoord) + 0.5) * g_Camera.f4ViewportSize.zw, SampledDepth);\n"
"        float3 SamplePositionVS = ScreenXYDepthToViewSpace(SamplePositionSS, g_Camera.mProj);\n"
"\n"
"        float WeightS = ComputeSpatialWeight(Poisson[SampleIdx].z * Poisson[SampleIdx].z, SSAO_SPATIAL_RECONSTRUCTION_SIGMA);\n"
"        float WeightZ = ComputeGeometryWeight(PositionVS, SamplePositionVS, NormalVS, PlaneNormalFactor);\n"
"\n"
"        OcclusionSum += WeightS * WeightZ * SampledOcclusion;\n"
"        WeightSum    += WeightS * WeightZ;\n"
"    }\n"
"\n"
"    return WeightSum > 0.0 ? OcclusionSum / WeightSum : SampleOcclusion(int2(Position.xy));\n"
"}\n"