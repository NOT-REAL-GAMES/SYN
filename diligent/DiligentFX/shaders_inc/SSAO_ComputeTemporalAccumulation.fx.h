"#include \"BasicStructures.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"#include \"PostFX_Common.fxh\"\n"
"#include \"TemporalAntiAliasingStructures.fxh\"\n"
"#include \"ScreenSpaceAmbientOcclusionStructures.fxh\"\n"
"#include \"SSAO_Common.fxh\"\n"
"\n"
"cbuffer cbCameraAttribs\n"
"{\n"
"    CameraAttribs g_CurrCamera;\n"
"    CameraAttribs g_PrevCamera;\n"
"}\n"
"\n"
"cbuffer cbScreenSpaceAmbientOcclusionAttribs\n"
"{\n"
"    ScreenSpaceAmbientOcclusionAttribs g_SSAOAttribs;\n"
"}\n"
"\n"
"Texture2D<float>  g_TextureCurrOcclusion;\n"
"Texture2D<float>  g_TexturePrevOcclusion;\n"
"Texture2D<float>  g_TextureHistory;\n"
"Texture2D<float>  g_TextureCurrDepth;\n"
"Texture2D<float>  g_TexturePrevDepth;\n"
"Texture2D<float2> g_TextureMotion;\n"
"\n"
"struct PSOutput\n"
"{\n"
"    float Occlusion : SV_Target0;\n"
"    float History   : SV_Target1;\n"
"};\n"
"\n"
"struct PixelStatistic\n"
"{\n"
"    float Mean;\n"
"    float Variance;\n"
"    float StdDev;\n"
"};\n"
"\n"
"struct ProjectionDesc\n"
"{\n"
"    float  Occlusion;\n"
"    float  History;\n"
"    bool   IsSuccess;\n"
"};\n"
"\n"
"float SampleCurrOcclusion(int2 PixelCoord)\n"
"{\n"
"    return g_TextureCurrOcclusion.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float SampleCurrDepth(int2 PixelCoord)\n"
"{\n"
"    return g_TextureCurrDepth.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float SamplePrevOcclusion(int2 PixelCoord)\n"
"{\n"
"    return g_TexturePrevOcclusion.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float SamplePrevDepth(int2 PixelCoord)\n"
"{\n"
"    return g_TexturePrevDepth.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float SampleHistory(int2 PixelCoord)\n"
"{\n"
"    return g_TextureHistory.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float2 SampleMotion(int2 PixelCoord)\n"
"{\n"
"    return g_TextureMotion.Load(int3(PixelCoord, 0)) * F3NDC_XYZ_TO_UVD_SCALE.xy;\n"
"}\n"
"\n"
"bool IsDepthSimilar(float CurrDepth, float PrevDepth)\n"
"{\n"
"    float LinearDepthCurr = DepthToCameraZ(CurrDepth, g_PrevCamera.mProj);\n"
"    float LinearDepthPrev = DepthToCameraZ(PrevDepth, g_PrevCamera.mProj);\n"
"    return abs(1.0 - LinearDepthCurr / LinearDepthPrev) < SSAO_DISOCCLUSION_DEPTH_THRESHOLD;\n"
"}\n"
"\n"
"bool IsInsideScreenMinusOne(int2 PixelCoord, int2 Dimension)\n"
"{\n"
"    return PixelCoord.x > 0 &&\n"
"           PixelCoord.y > 0 &&\n"
"           PixelCoord.x < (Dimension.x - 1) &&\n"
"           PixelCoord.y < (Dimension.y - 1);\n"
"}\n"
"\n"
"PixelStatistic ComputePixelStatistic(int2 PixelCoord)\n"
"{\n"
"    PixelStatistic Desc;\n"
"    float M1 = 0.0;\n"
"    float M2 = 0.0;\n"
"\n"
"    const int SearchRadius = 1;\n"
"    for (int x = -SearchRadius; x <= SearchRadius; ++x)\n"
"    {\n"
"        for (int y = -SearchRadius; y <= SearchRadius; ++y)\n"
"        {\n"
"            int2 Location = ClampScreenCoord(PixelCoord + int2(x, y), int2(g_CurrCamera.f4ViewportSize.xy));\n"
"            float SampleOcclusion = SampleCurrOcclusion(Location);\n"
"            M1 += SampleOcclusion;\n"
"            M2 += SampleOcclusion * SampleOcclusion;\n"
"        }\n"
"    }\n"
"\n"
"    Desc.Mean = M1 / 9.0;\n"
"    Desc.Variance = (M2 / 9.0) - (Desc.Mean * Desc.Mean);\n"
"    Desc.StdDev = sqrt(max(Desc.Variance, 0.0f));\n"
"    return Desc;\n"
"}\n"
"\n"
"ProjectionDesc ComputeReprojection(float2 PrevPos, float CurrDepth)\n"
"{\n"
"    ProjectionDesc Desc;\n"
"\n"
"    int2 PrevPosi = int2(PrevPos - 0.5);\n"
"    float x = frac(PrevPos.x + 0.5);\n"
"    float y = frac(PrevPos.y + 0.5);\n"
"\n"
"    float Weight[4];\n"
"    Weight[0] = (1.0 - x) * (1.0 - y);\n"
"    Weight[1] = x * (1.0 - y);\n"
"    Weight[2] = (1.0 - x) * y;\n"
"    Weight[3] = x * y;\n"
"\n"
"    {\n"
"        for (int SampleIdx = 0; SampleIdx < 4; ++SampleIdx)\n"
"        {\n"
"            int2 Location = PrevPosi + int2(SampleIdx & 0x01, SampleIdx >> 1);\n"
"            float PrevDepth = SamplePrevDepth(Location);\n"
"            Weight[SampleIdx] *= float(IsDepthSimilar(CurrDepth, PrevDepth));\n"
"            Weight[SampleIdx] *= float(IsInsideScreenMinusOne(Location, int2(g_CurrCamera.f4ViewportSize.xy)));\n"
"        }\n"
"    }\n"
"\n"
"    float WeightSum = 0.0;\n"
"    float OcclusionSum = 0.0;\n"
"    float HistorySum = 0.0;\n"
"\n"
"    {\n"
"        for (int SampleIdx = 0; SampleIdx < 4; ++SampleIdx)\n"
"        {\n"
"            int2 Location = PrevPosi + int2(SampleIdx & 0x01, SampleIdx >> 1);\n"
"            OcclusionSum += Weight[SampleIdx] * SamplePrevOcclusion(Location);\n"
"            HistorySum += Weight[SampleIdx] * min(16.0, SampleHistory(Location) + 1.0);;\n"
"            WeightSum += Weight[SampleIdx];\n"
"        }\n"
"    }\n"
"\n"
"    Desc.IsSuccess = WeightSum > 0.0 && !g_SSAOAttribs.ResetAccumulation;\n"
"    Desc.Occlusion = Desc.IsSuccess ? OcclusionSum / WeightSum : 1.0;\n"
"    Desc.History = Desc.IsSuccess ? HistorySum / WeightSum : 1.0;\n"
"\n"
"    return Desc;\n"
"}\n"
"\n"
"PSOutput ComputeTemporalAccumulationPS(in FullScreenTriangleVSOutput VSOut)\n"
"{\n"
"    float4 Position = VSOut.f4PixelPos;\n"
"    float Depth = SampleCurrDepth(int2(Position.xy));\n"
"    if (IsBackground(Depth))\n"
"        discard;\n"
"\n"
"    float2 Motion = SampleMotion(int2(Position.xy));\n"
"    float2 PrevLocation = Position.xy - Motion * g_CurrCamera.f4ViewportSize.xy;\n"
"    ProjectionDesc Reprojection = ComputeReprojection(PrevLocation, Depth);\n"
"\n"
"    PSOutput Output;\n"
"    if (Reprojection.IsSuccess)\n"
"    {\n"
"        PixelStatistic PixelStat = ComputePixelStatistic(int2(Position.xy));\n"
"\n"
"        float AspectRatio = g_CurrCamera.f4ViewportSize.x * g_CurrCamera.f4ViewportSize.w;\n"
"        float MotionFactor = saturate(1.025 - length(float2(Motion.x * AspectRatio, Motion.y)) * SSAO_TEMPORAL_MOTION_VECTOR_DIFF_FACTOR);\n"
"        float VarianceGamma = lerp(SSAO_TEMPORAL_MIN_VARIANCE_GAMMA, SSAO_TEMPORAL_MAX_VARIANCE_GAMMA, MotionFactor * MotionFactor);\n"
"\n"
"        float OcclusionMin = PixelStat.Mean - VarianceGamma * PixelStat.StdDev;\n"
"        float OcclusionMax = PixelStat.Mean + VarianceGamma * PixelStat.StdDev;\n"
"\n"
"        bool IsInsideRange = OcclusionMin < Reprojection.Occlusion && Reprojection.Occlusion < OcclusionMax;\n"
"        Reprojection.History = IsInsideRange ? Reprojection.History : max(1.0, MotionFactor * Reprojection.History);\n"
"    }\n"
"\n"
"    float Alpha = rcp(Reprojection.History);\n"
"    Output.Occlusion = lerp(Reprojection.Occlusion, SampleCurrOcclusion(int2(Position.xy)), Alpha);\n"
"    Output.History = Reprojection.History;\n"
"    return Output;\n"
"}\n"