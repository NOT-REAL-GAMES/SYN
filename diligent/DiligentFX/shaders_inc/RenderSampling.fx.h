"#include \"AtmosphereShadersCommon.fxh\"\n"
"\n"
"cbuffer cbPostProcessingAttribs\n"
"{\n"
"    EpipolarLightScatteringAttribs g_PPAttribs;\n"
"};\n"
"\n"
"Texture2D<float2> g_tex2DCoordinates;\n"
"Texture2D<uint2>  g_tex2DInterpolationSource;\n"
"\n"
"struct VSOutput\n"
"{\n"
"    float3 f3Color : COLOR;\n"
"    float2 f2PosXY : XY;\n"
"    float4 f4QuadCenterAndSize : QUAD_CENTER_SIZE;\n"
"};\n"
"\n"
"void RenderSampleLocationsVS(in uint VertexID : SV_VertexID,\n"
"                             in uint InstID   : SV_InstanceID,\n"
"                             out VSOutput VSOut,\n"
"                             // IMPORTANT: non-system generated pixel shader input\n"
"                             // arguments must have the exact same name as vertex shader\n"
"                             // outputs and must go in the same order.\n"
"                             // Moreover, even if the shader is not using the argument,\n"
"                             // it still must be declared.\n"
"\n"
"                             out float4 f4PosPS : SV_Position)\n"
"{\n"
"    uint2 CoordTexDim;\n"
"    g_tex2DCoordinates.GetDimensions(CoordTexDim.x, CoordTexDim.y);\n"
"    uint2 TexelIJ = uint2( InstID%CoordTexDim.x, InstID/CoordTexDim.x );\n"
"    float2 f2QuadCenterPos = g_tex2DCoordinates.Load(int3(TexelIJ,0));\n"
"\n"
"    uint2 ui2InterpolationSources = g_tex2DInterpolationSource.Load( int3(TexelIJ,0) );\n"
"    bool bIsInterpolation = ui2InterpolationSources.x != ui2InterpolationSources.y;\n"
"\n"
"    float2 f2QuadSize = (bIsInterpolation ? 2.0 : 4.0) * g_PPAttribs.f4ScreenResolution.zw;\n"
"    float4 MinMaxUV = float4(f2QuadCenterPos.x-f2QuadSize.x, f2QuadCenterPos.y - f2QuadSize.y, f2QuadCenterPos.x+f2QuadSize.x, f2QuadCenterPos.y + f2QuadSize.y);\n"
"\n"
"    float3 f3Color = bIsInterpolation ? float3(0.5,0.0,0.0) : float3(1.0,0.0,0.0);\n"
"    float4 Verts[4];\n"
"    Verts[0] = float4(MinMaxUV.xy, 1.0, 1.0);\n"
"    Verts[1] = float4(MinMaxUV.xw, 1.0, 1.0);\n"
"    Verts[2] = float4(MinMaxUV.zy, 1.0, 1.0);\n"
"    Verts[3] = float4(MinMaxUV.zw, 1.0, 1.0);\n"
"\n"
"    f4PosPS = Verts[VertexID];\n"
"    VSOut.f2PosXY = Verts[VertexID].xy;\n"
"    VSOut.f3Color = f3Color;\n"
"    VSOut.f4QuadCenterAndSize = float4(f2QuadCenterPos, f2QuadSize);\n"
"}\n"
"\n"
"\n"
"void RenderSampleLocationsPS(in VSOutput VSOut,\n"
"                             out float4 f4Color : SV_Target)\n"
"{\n"
"    f4Color = float4(VSOut.f3Color, 1.0 - pow( length( (VSOut.f2PosXY - VSOut.f4QuadCenterAndSize.xy) / VSOut.f4QuadCenterAndSize.zw),4.0) );\n"
"}\n"