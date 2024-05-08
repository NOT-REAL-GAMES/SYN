"#include \"SSAO_Common.fxh\"\n"
"#include \"BasicStructures.fxh\"\n"
"#include \"ScreenSpaceAmbientOcclusionStructures.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"#include \"PostFX_Common.fxh\"\n"
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
"#if SUPPORTED_SHADER_SRV\n"
"Texture2D<float> g_TextureLastMip;\n"
"#else\n"
"Texture2D<float> g_TextureMips;\n"
"SamplerState     g_TextureMips_sampler;\n"
"#endif\n"
"\n"
"#if SUPPORTED_SHADER_SRV\n"
"float SampleDepth(int2 Location, int2 Offset, int3 Dimension)\n"
"{\n"
"    int2 Position = ClampScreenCoord(Location + Offset, Dimension.xy);\n"
"    return g_TextureLastMip.Load(int3(Position, 0));\n"
"}\n"
"#else\n"
"float SampleDepth(int2 Location, int2 Offset, int3 Dimension)\n"
"{\n"
"    int2 Position = ClampScreenCoord(Location + Offset, Dimension.xy);\n"
"    return g_TextureMips.Load(int3(Position, Dimension.z));\n"
"}\n"
"#endif\n"
"\n"
"float SampleDepthViewSpace(int2 Location, int2 Offset, int3 Dimension)\n"
"{\n"
"    return DepthToCameraZ(SampleDepth(Location, Offset, Dimension), g_Camera.mProj);\n"
"}\n"
"\n"
"float ComputeDepthMIPFiltered(in float SampledDepth[9], uint Count)\n"
"{\n"
"    float WeightDepth = SampledDepth[0];\n"
"    {\n"
"        for (uint Idx = 1u; Idx < Count; Idx++)\n"
"            WeightDepth = min(WeightDepth, SampledDepth[Idx]);\n"
"    }\n"
"\n"
"    float DepthRangeScaleFactor = 0.75; // Found empirically :)\n"
"    float EffectRadius = DepthRangeScaleFactor * g_SSAOAttribs.EffectRadius * g_SSAOAttribs.RadiusMultiplier;\n"
"    float FalloffRange = g_SSAOAttribs.EffectFalloffRange * EffectRadius;\n"
"\n"
"    // Fadeout precompute optimisation\n"
"    float FalloffFrom = EffectRadius - FalloffRange;\n"
"    float FalloffMul = -1.0f / (FalloffRange);\n"
"    float FalloffAdd = FalloffFrom / FalloffRange + 1.0f;\n"
"\n"
"    float DepthSum = 0.0f;\n"
"    float WeightSum = 0.0f;\n"
"    {\n"
"        for (uint Idx = 0u; Idx < Count; Idx++)\n"
"        {\n"
"            float Weight = saturate(abs(WeightDepth - SampledDepth[Idx]) * FalloffMul + FalloffAdd);\n"
"            DepthSum += Weight * SampledDepth[Idx];\n"
"            WeightSum += Weight;\n"
"        }\n"
"    }\n"
"\n"
"    return DepthSum / WeightSum;\n"
"}\n"
"\n"
"void ArrayAppend(float Element, inout float Array[9], inout uint Index)\n"
"{\n"
"    Array[Index] = Element;\n"
"    Index++;\n"
"}\n"
"\n"
"float ComputePrefilteredDepthBufferPS(in FullScreenTriangleVSOutput VSOut) : SV_Target0\n"
"{\n"
"    int3 LastMipDimension;\n"
"#if SUPPORTED_SHADER_SRV\n"
"    g_TextureLastMip.GetDimensions(LastMipDimension.x, LastMipDimension.y);\n"
"#else\n"
"    int Dummy;\n"
"    g_TextureMips.GetDimensions(0, LastMipDimension.x, LastMipDimension.y, Dummy);\n"
"    LastMipDimension.x = int(floor(float(LastMipDimension.x) / exp2(float(VSOut.uInstID))));\n"
"    LastMipDimension.y = int(floor(float(LastMipDimension.y) / exp2(float(VSOut.uInstID))));\n"
"    LastMipDimension.z = int(VSOut.uInstID);\n"
"#endif\n"
"\n"
"    int2 RemappedPosition = int2(2.0 * floor(VSOut.f4PixelPos.xy));\n"
"\n"
"    uint SampleCount = 0u;\n"
"    float SampledPixels[9];\n"
"    ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(0, 0), LastMipDimension), SampledPixels, SampleCount);\n"
"    ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(0, 1), LastMipDimension), SampledPixels, SampleCount);\n"
"    ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(1, 0), LastMipDimension), SampledPixels, SampleCount);\n"
"    ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(1, 1), LastMipDimension), SampledPixels, SampleCount);\n"
"\n"
"    bool IsWidthOdd  = (LastMipDimension.x & 1) != 0;\n"
"    bool IsHeightOdd = (LastMipDimension.y & 1) != 0;\n"
"\n"
"    if (IsWidthOdd)\n"
"    {\n"
"        ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(2, 0), LastMipDimension), SampledPixels, SampleCount);\n"
"        ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(2, 1), LastMipDimension), SampledPixels, SampleCount);\n"
"    }\n"
"\n"
"    if (IsHeightOdd)\n"
"    {\n"
"        ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(0, 2), LastMipDimension), SampledPixels, SampleCount);\n"
"        ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(1, 2), LastMipDimension), SampledPixels, SampleCount);\n"
"    }\n"
"\n"
"    if (IsWidthOdd && IsHeightOdd)\n"
"    {\n"
"        ArrayAppend(SampleDepthViewSpace(RemappedPosition, int2(2, 2), LastMipDimension), SampledPixels, SampleCount);\n"
"    }\n"
"\n"
"    return saturate(CameraZToDepth(ComputeDepthMIPFiltered(SampledPixels, SampleCount), g_Camera.mProj));\n"
"}\n"