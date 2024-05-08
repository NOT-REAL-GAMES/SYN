"#include \"BasicStructures.fxh\"\n"
"#include \"BoundBoxStructures.fxh\"\n"
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
"float4 GetBoxCorner(uint id)\n"
"{\n"
"    //               5________________6\n"
"    //               /|              /|\n"
"    //              / |             / |\n"
"    //             /  |            /  |\n"
"    //            /   |           /   |\n"
"    //          4/____|__________/7   |\n"
"    //           |    |__________|____|\n"
"    //           |   /1          |    /2\n"
"    //           |  /            |   /\n"
"    //           | /             |  /\n"
"    //           |/              | /\n"
"    //           /_______________|/\n"
"    //           0               3\n"
"    //\n"
"\n"
"    if (id < 8u)\n"
"    {\n"
"        // 0,1, 1,2, 2,3, 3,0\n"
"        id = ((id + 1u) >> 1u) & 0x03u;\n"
"    }\n"
"    else if (id < 16u)\n"
"    {\n"
"        // 4,5, 5,6, 6,7, 7,4\n"
"        id = 4u + (((id + 1u) >> 1u) & 0x03u);\n"
"    }\n"
"    else\n"
"    {\n"
"        // 0,4, 1,5, 2,6, 3,7\n"
"        id = ((id - 16u) >> 1u) + (id & 0x01u) * 4u;\n"
"    }\n"
"\n"
"    float4 BoxCorner;\n"
"    BoxCorner.x = (id & 0x02u) == 0u ? 0.0 : 1.0;\n"
"    BoxCorner.y = ((id + 1u) & 0x02u) == 0u ? 0.0 : 1.0;\n"
"    BoxCorner.z = (id & 0x04u) == 0u ? 0.0 : 1.0;\n"
"    BoxCorner.w = 1.0;\n"
"\n"
"    BoxCorner = mul(BoxCorner, g_Attribs.Transform);\n"
"\n"
"    return BoxCorner;\n"
"}\n"
"\n"
"void BoundBoxVS(uint id : SV_VertexID,\n"
"                out  BoundBoxVSOutput VSOut)\n"
"{\n"
"    float4 BoxCorner = GetBoxCorner(id);\n"
"    float4 EdgeStart = GetBoxCorner(id & ~0x01u);\n"
"\n"
"    VSOut.Pos = mul(BoxCorner, g_Camera.mViewProj);\n"
"\n"
"    VSOut.ClipPos = VSOut.Pos;\n"
"    VSOut.EdgeStartClipPos = mul(EdgeStart, g_Camera.mViewProj);\n"
"#if COMPUTE_MOTION_VECTORS\n"
"    VSOut.PrevClipPos = mul(BoxCorner, g_PrevCamera.mViewProj);\n"
"#else\n"
"    VSOut.PrevClipPos = VSOut.ClipPos;\n"
"#endif\n"
"}\n"
