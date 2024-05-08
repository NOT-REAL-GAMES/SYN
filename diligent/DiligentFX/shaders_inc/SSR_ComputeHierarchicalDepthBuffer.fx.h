"#include \"SSR_Common.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
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
"float ComputeHierarchicalDepthBufferPS(in FullScreenTriangleVSOutput VSOut) : SV_Target0\n"
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
"    float4 SampledPixels;\n"
"    SampledPixels.x = SampleDepth(RemappedPosition, int2(0, 0), LastMipDimension);\n"
"    SampledPixels.y = SampleDepth(RemappedPosition, int2(0, 1), LastMipDimension);\n"
"    SampledPixels.z = SampleDepth(RemappedPosition, int2(1, 0), LastMipDimension);\n"
"    SampledPixels.w = SampleDepth(RemappedPosition, int2(1, 1), LastMipDimension);\n"
"\n"
"    float MinDepth = MipConvFunc(MipConvFunc(SampledPixels.x, SampledPixels.y), MipConvFunc(SampledPixels.z, SampledPixels.w));\n"
"\n"
"    bool IsWidthOdd  = (LastMipDimension.x & 1) != 0;\n"
"    bool IsHeightOdd = (LastMipDimension.y & 1) != 0;\n"
"\n"
"    if (IsWidthOdd)\n"
"    {\n"
"        SampledPixels.x = SampleDepth(RemappedPosition, int2(2, 0), LastMipDimension);\n"
"        SampledPixels.y = SampleDepth(RemappedPosition, int2(2, 1), LastMipDimension);\n"
"        MinDepth = MipConvFunc(MinDepth, MipConvFunc(SampledPixels.x, SampledPixels.y));\n"
"    }\n"
"\n"
"    if (IsHeightOdd)\n"
"    {\n"
"        SampledPixels.x = SampleDepth(RemappedPosition, int2(0, 2), LastMipDimension);\n"
"        SampledPixels.y = SampleDepth(RemappedPosition, int2(1, 2), LastMipDimension);\n"
"        MinDepth = MipConvFunc(MinDepth, MipConvFunc(SampledPixels.x, SampledPixels.y));\n"
"    }\n"
"\n"
"    if (IsWidthOdd && IsHeightOdd)\n"
"    {\n"
"        MinDepth = MipConvFunc(MinDepth, SampleDepth(RemappedPosition, int2(2, 2), LastMipDimension));\n"
"    }\n"
"\n"
"    return MinDepth;\n"
"}\n"