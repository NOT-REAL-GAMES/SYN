"#include \"BasicStructures.fxh\"\n"
"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"#include \"PostFX_Common.fxh\"\n"
"\n"
"cbuffer cbCameraAttribs\n"
"{\n"
"    CameraAttribs g_CurrCamera;\n"
"    CameraAttribs g_PrevCamera;\n"
"}\n"
"\n"
"Texture2D<float> g_TextureDepth;\n"
"\n"
"float SampleDepth(int2 PixelCoord)\n"
"{\n"
"    return g_TextureDepth.Load(int3(PixelCoord, 0));\n"
"}\n"
"\n"
"float ComputeReprojectedDepthPS(in FullScreenTriangleVSOutput VSOut) : SV_Target0\n"
"{\n"
"    float4 Position = VSOut.f4PixelPos;\n"
"    float Depth = SampleDepth(int2(Position.xy));\n"
"\n"
"    float3 CurrScreenCoord = float3(Position.xy * g_CurrCamera.f4ViewportSize.zw, Depth);\n"
"    CurrScreenCoord.xy += F3NDC_XYZ_TO_UVD_SCALE.xy * g_CurrCamera.f2Jitter;\n"
"\n"
"    float3 WorldPosition = InvProjectPosition(CurrScreenCoord, g_CurrCamera.mViewProjInv);\n"
"    float3 PrevScreenCoord = ProjectPosition(WorldPosition, g_PrevCamera.mViewProj);\n"
"\n"
"    return PrevScreenCoord.z;\n"
"}\n"