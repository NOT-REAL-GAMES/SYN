"#include \"FullScreenTriangleVSOutput.fxh\"\n"
"#include \"BloomStructures.fxh\"\n"
"#include \"SRGBUtilities.fxh\"\n"
"#include \"PostFX_Common.fxh\"\n"
"\n"
"cbuffer cbBloomAttribs\n"
"{\n"
"    BloomAttribs g_BloomAttribs;\n"
"}\n"
"\n"
"Texture2D<float3> g_TextureInput;\n"
"SamplerState      g_TextureInput_sampler;\n"
"\n"
"float3 SampleColor(float2 Texcoord, float2 Offset)\n"
"{\n"
"    return g_TextureInput.SampleLevel(g_TextureInput_sampler, Texcoord + Offset, 0.0);\n"
"}\n"
"\n"
"float KarisAverage(float3 Color)\n"
"{\n"
"    return 1.0 / (1.0 + Luminance(Color));\n"
"}\n"
"\n"
"float3 Prefilter(float3 Color)\n"
"{\n"
"	float Brightness = max(Color.r, max(Color.g, Color.b));\n"
"    float Knee = g_BloomAttribs.Threshold * g_BloomAttribs.SoftTreshold;\n"
"    float Soft = Brightness - g_BloomAttribs.Threshold + Knee;\n"
"    Soft = clamp(Soft, 0.0, 2.0 * Knee);\n"
"    Soft = Soft * Soft * 0.25 / (Knee + 1.0e-5);\n"
"\n"
"	float Contribution = max(Soft, Brightness - g_BloomAttribs.Threshold);\n"
"	Contribution /= max(Brightness, 1.0e-5);\n"
"	return Color * Contribution;\n"
"}\n"
"\n"
"float3 ComputePrefilteredTexturePS(in FullScreenTriangleVSOutput VSOut) : SV_Target0\n"
"{\n"
"    float2 TextureResolution;\n"
"    g_TextureInput.GetDimensions(TextureResolution.x, TextureResolution.y);\n"
"\n"
"    float2 TexelSize = rcp(TextureResolution);\n"
"    float2 CenterTexcoord = NormalizedDeviceXYToTexUV(VSOut.f2NormalizedXY.xy);\n"
"\n"
"    float3 A = SampleColor(CenterTexcoord, TexelSize * float2(-2.0, +2.0));\n"
"    float3 B = SampleColor(CenterTexcoord, TexelSize * float2(+0.0, +2.0));\n"
"    float3 C = SampleColor(CenterTexcoord, TexelSize * float2(+2.0, +2.0));\n"
"\n"
"    float3 D = SampleColor(CenterTexcoord, TexelSize * float2(-2.0, +0.0));\n"
"    float3 E = SampleColor(CenterTexcoord, TexelSize * float2(+0.0, +0.0));\n"
"    float3 F = SampleColor(CenterTexcoord, TexelSize * float2(+2.0, +0.0));\n"
"\n"
"    float3 G = SampleColor(CenterTexcoord, TexelSize * float2(-2.0, -2.0));\n"
"    float3 H = SampleColor(CenterTexcoord, TexelSize * float2(+0.0, -2.0));\n"
"    float3 I = SampleColor(CenterTexcoord, TexelSize * float2(+2.0, -2.0));\n"
"\n"
"    float3 J = SampleColor(CenterTexcoord, TexelSize * float2(-1.0, +1.0));\n"
"    float3 K = SampleColor(CenterTexcoord, TexelSize * float2(+1.0, +1.0));\n"
"    float3 L = SampleColor(CenterTexcoord, TexelSize * float2(-1.0, -1.0));\n"
"    float3 M = SampleColor(CenterTexcoord, TexelSize * float2(+1.0, -1.0));\n"
"\n"
"    float Weights[5];\n"
"    Weights[0] = 0.125f;\n"
"    Weights[1] = 0.125f;\n"
"    Weights[2] = 0.125f;\n"
"    Weights[3] = 0.125f;\n"
"    Weights[4] = 0.5f;\n"
"\n"
"    float3 Groups[5];\n"
"    Groups[0] = (A + B + D + E) / 4.0f;\n"
"    Groups[1] = (B + C + E + F) / 4.0f;\n"
"    Groups[2] = (D + E + G + H) / 4.0f;\n"
"    Groups[3] = (E + F + H + I) / 4.0f;\n"
"    Groups[4] = (J + K + L + M) / 4.0f;\n"
"\n"
"    float4 ColorSum = float4(0.0, 0.0, 0.0, 0.0);\n"
"    for (int GroupId = 0; GroupId < 5; ++GroupId) {\n"
"        float Weight = Weights[GroupId] * KarisAverage(Groups[GroupId]);\n"
"        ColorSum += float4(Groups[GroupId], 1.0) * Weight;\n"
"    }\n"
"\n"
"    return Prefilter(ColorSum.xyz / (ColorSum.w + 1.0e-5));\n"
"}\n"
