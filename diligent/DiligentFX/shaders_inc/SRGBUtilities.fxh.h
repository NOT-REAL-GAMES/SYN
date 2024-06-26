"#ifndef _SRGB_UTILITIES_FXH_\n"
"#define _SRGB_UTILITIES_FXH_\n"
"\n"
"float3 SRGBToLinear(float3 sRGB)\n"
"{\n"
"    float3 bLess = step(float3(0.04045, 0.04045, 0.04045), sRGB);\n"
"    return lerp(sRGB / 12.92,\n"
"                pow(saturate((sRGB + float3(0.055, 0.055, 0.055)) / 1.055), float3(2.4, 2.4, 2.4)),\n"
"                bLess);\n"
"}\n"
"\n"
"float4 SRGBAToLinear(float4 sRGBA)\n"
"{\n"
"    return float4(SRGBToLinear(sRGBA.rgb), sRGBA.a);\n"
"}\n"
"\n"
"float3 FastSRGBToLinear(float3 sRGB)\n"
"{\n"
"    return pow(sRGB, float3(2.2, 2.2, 2.2));\n"
"}\n"
"\n"
"float4 FastSRGBAToLinear(float4 sRGBA)\n"
"{\n"
"    return float4(FastSRGBToLinear(sRGBA.rgb), sRGBA.a);\n"
"}\n"
"\n"
"float3 LinearToSRGB(float3 RGB)\n"
"{\n"
"    float3 bGreater = step(float3(0.0031308, 0.0031308, 0.0031308), RGB);\n"
"    return lerp(RGB * 12.92,\n"
"                (pow(RGB, float3(1.0 / 2.4, 1.0 / 2.4, 1.0 / 2.4)) * 1.055) - float3(0.055, 0.055, 0.055),\n"
"                bGreater);\n"
"}\n"
"\n"
"float4 LinearToSRGBA(float4 RGBA)\n"
"{\n"
"    return float4(LinearToSRGB(RGBA.rgb), RGBA.a);\n"
"}\n"
"\n"
"float3 FastLinearToSRGB(float3 RGB)\n"
"{\n"
"    return pow(RGB, float3(1.0 / 2.2, 1.0 / 2.2, 1.0 / 2.2));\n"
"}\n"
"\n"
"float4 FastLinearToSRGBA(float4 RGBA)\n"
"{\n"
"    return float4(FastLinearToSRGB(RGBA.rgb), RGBA.a);\n"
"}\n"
"\n"
"#endif // _SRGB_UTILITIES_FXH_\n"
