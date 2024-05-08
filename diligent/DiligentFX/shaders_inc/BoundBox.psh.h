"#include \"BasicStructures.fxh\"\n"
"#include \"BoundBoxStructures.fxh\"\n"
"\n"
"#if COMPUTE_MOTION_VECTORS\n"
"#include \"ShaderUtilities.fxh\"\n"
"#endif\n"
"\n"
"cbuffer cbCameraAttribs\n"
"{\n"
"    CameraAttribs g_Camera;\n"
"    CameraAttribs g_PrevCamera;\n"
"}\n"
"\n"
"cbuffer cbBoundBoxAttribs\n"
"{\n"
"    BoundBoxAttribs g_Attribs;\n"
"}\n"
"\n"
"struct BoundBoxOutput\n"
"{\n"
"    float4 Color;\n"
"#if COMPUTE_MOTION_VECTORS\n"
"    float2 MotionVector;\n"
"#endif\n"
"};\n"
"\n"
"BoundBoxOutput GetBoundBoxOutput(BoundBoxVSOutput VSOut)\n"
"{\n"
"    BoundBoxOutput Output;\n"
"    Output.Color = g_Attribs.Color;\n"
"\n"
"    float DistToEdgeStart = length((VSOut.ClipPos.xy / VSOut.ClipPos.w - VSOut.EdgeStartClipPos.xy / VSOut.EdgeStartClipPos.w) * g_Camera.f4ViewportSize.xy);\n"
"    float PatternPos      = frac(DistToEdgeStart / g_Attribs.PatternLength);\n"
"    uint  PatternBit      = min(uint(PatternPos * g_Attribs.PatternLength), 31u);\n"
"    if ((g_Attribs.PatternMask & (1u << PatternBit)) == 0u)\n"
"        discard;\n"
"\n"
"#if COMPUTE_MOTION_VECTORS\n"
"    Output.MotionVector = GetMotionVector(\n"
"        VSOut.ClipPos.xy / VSOut.ClipPos.w,\n"
"        VSOut.PrevClipPos.xy / VSOut.PrevClipPos.w,\n"
"        g_Camera.f2Jitter,\n"
"        g_PrevCamera.f2Jitter\n"
"    );\n"
"#endif\n"
"\n"
"    return Output;\n"
"}\n"
"\n"
"#include \"PSMainGenerated.generated\"\n"
"//void main(in BoundBoxVSOutput VSOut,\n"
"//          out float4 Color : SV_Target)\n"
"//{\n"
"//    Color = GetBoundBoxOutput(VSOut).Color;\n"
"//}\n"
