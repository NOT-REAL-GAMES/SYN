"#include \"BasicStructures.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"#include \"SRGBUtilities.fxh\"\n"
"#include \"CoordinateGrid.fxh\"\n"
"\n"
"#pragma warning(disable : 3078)\n"
"\n"
"cbuffer cbCameraAttribs\n"
"{\n"
"    CameraAttribs g_Camera;\n"
"}\n"
"\n"
"cbuffer cbGridAxesAttribs\n"
"{\n"
"    CoordinateGridAttribs g_GridAxesAttribs;\n"
"}\n"
"\n"
"Texture2D<float>  g_TextureDepth;\n"
"\n"
"float SampleDepth(int2 PixelCoord)\n"
"{\n"
"    return g_TextureDepth.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"\n"
"float4 ComputeGridAxesPS(in FullScreenTriangleVSOutput VSOut) : SV_Target0\n"
"{\n"
"    float GeometryDepth = SampleDepth(int2(VSOut.f4PixelPos.xy));\n"
"\n"
"    float4 Result = ComputeCoordinateGrid(VSOut.f2NormalizedXY + g_Camera.f2Jitter,\n"
"                                          g_Camera,\n"
"                                          GeometryDepth, GeometryDepth,\n"
"                                          g_GridAxesAttribs);\n"
"\n"
"#if COORDINATE_GRID_CONVERT_OUTPUT_TO_SRGB\n"
"    Result.rgb = LinearToSRGB(Result.rgb);\n"
"#endif\n"
"\n"
"    return Result;\n"
"}\n"
