"#include \"ScreenSpaceReflectionStructures.fxh\"\n"
"#include \"SSR_Common.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"\n"
"#pragma warning(disable : 3078)\n"
"\n"
"cbuffer cbScreenSpaceReflectionAttribs\n"
"{\n"
"    ScreenSpaceReflectionAttribs g_SSRAttribs;\n"
"}\n"
"\n"
"Texture2D<float> g_TextureRoughness;\n"
"Texture2D<float> g_TextureDepth;\n"
"\n"
"float SampleRoughness(uint2 Location, uint2 Offset, uint2 Dimension)\n"
"{\n"
"    uint2 Position = Location + Offset;\n"
"    if (Position.x >= Dimension.x || Position.y >= Dimension.y)\n"
"        return g_TextureRoughness.Load(int3(Location, 0));\n"
"    return g_TextureRoughness.Load(int3(Position, 0));\n"
"}\n"
"\n"
"float SampleDepth(uint2 Location, uint2 Offset, uint2 Dimension)\n"
"{\n"
"    uint2 Position = Location + Offset;\n"
"    if (Position.x >= Dimension.x || Position.y >= Dimension.y)\n"
"        return g_TextureDepth.Load(int3(Location, 0));\n"
"    return g_TextureDepth.Load(int3(Position, 0));\n"
"}\n"
"\n"
"void ComputeDownsampledStencilMaskPS(in FullScreenTriangleVSOutput VSOut)\n"
"{\n"
"    uint2 RemappedPosition = uint2(2.0 * floor(VSOut.f4PixelPos.xy));\n"
"\n"
"    uint2 TextureDimension;\n"
"    g_TextureDepth.GetDimensions(TextureDimension.x, TextureDimension.y);\n"
"\n"
"    float MinDepth = DepthFarPlane;\n"
"    float MaxRoughness = 0.0f;\n"
"\n"
"    for (uint SampleIdx = 0u; SampleIdx < 4u; ++SampleIdx)\n"
"    {\n"
"        uint2 Offset = uint2(SampleIdx & 0x01u, SampleIdx >> 1u);\n"
"        MinDepth = MipConvFunc(MinDepth, SampleDepth(RemappedPosition, Offset, TextureDimension));\n"
"        MaxRoughness = max(MaxRoughness, SampleRoughness(RemappedPosition, Offset, TextureDimension));\n"
"    }\n"
"\n"
"    bool IsWidthOdd  = (TextureDimension.x & 1u) != 0u;\n"
"    bool IsHeightOdd = (TextureDimension.y & 1u) != 0u;\n"
"\n"
"    if (IsWidthOdd)\n"
"    {\n"
"        for (uint SampleIdx = 0u; SampleIdx < 2u; ++SampleIdx)\n"
"        {\n"
"            uint2 Offset = uint2(2u, SampleIdx);\n"
"            MinDepth = MipConvFunc(MinDepth, SampleDepth(RemappedPosition, Offset, TextureDimension));\n"
"            MaxRoughness = max(MaxRoughness, SampleRoughness(RemappedPosition, Offset, TextureDimension));\n"
"        }\n"
"    }\n"
"\n"
"    if (IsHeightOdd)\n"
"    {\n"
"        for (uint SampleIdx = 0u; SampleIdx < 2u; ++SampleIdx)\n"
"        {\n"
"            uint2 Offset = uint2(SampleIdx, 2);\n"
"            MinDepth = MipConvFunc(MinDepth, SampleDepth(RemappedPosition, Offset, TextureDimension));\n"
"            MaxRoughness = max(MaxRoughness, SampleRoughness(RemappedPosition, Offset, TextureDimension));\n"
"        }\n"
"    }\n"
"\n"
"    if (IsWidthOdd && IsHeightOdd)\n"
"    {\n"
"        MinDepth = MipConvFunc(MinDepth, SampleDepth(RemappedPosition, uint2(2, 2), TextureDimension));\n"
"        MaxRoughness = max(MaxRoughness, SampleRoughness(RemappedPosition, uint2(2, 2), TextureDimension));\n"
"    }\n"
"\n"
"    if (!IsReflectionSample(MaxRoughness, MinDepth, g_SSRAttribs.RoughnessThreshold))\n"
"        discard;\n"
"}\n"
