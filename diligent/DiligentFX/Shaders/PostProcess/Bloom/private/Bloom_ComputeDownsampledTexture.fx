#include "FullScreenTriangleVSOutput.fxh"

Texture2D<float3> g_TextureInput;
SamplerState      g_TextureInput_sampler;

float3 SampleColor(float2 Texcoord, float2 Offset)
{
    return g_TextureInput.SampleLevel(g_TextureInput_sampler, Texcoord + Offset, 0.0);
}

float3 ComputeDownsampledTexturePS(in FullScreenTriangleVSOutput VSOut) : SV_Target0
{
    float2 TextureResolution;
    g_TextureInput.GetDimensions(TextureResolution.x, TextureResolution.y);

    float2 TexelSize = rcp(TextureResolution);
    float2 CenterTexcoord = NormalizedDeviceXYToTexUV(VSOut.f2NormalizedXY.xy);
   
    float3 A = SampleColor(CenterTexcoord, TexelSize * float2(-2.0, +2.0));
    float3 B = SampleColor(CenterTexcoord, TexelSize * float2(+0.0, +2.0));
    float3 C = SampleColor(CenterTexcoord, TexelSize * float2(+2.0, +2.0));

    float3 D = SampleColor(CenterTexcoord, TexelSize * float2(-2.0, +0.0));
    float3 E = SampleColor(CenterTexcoord, TexelSize * float2(+0.0, +0.0));
    float3 F = SampleColor(CenterTexcoord, TexelSize * float2(+2.0, +0.0));

    float3 G = SampleColor(CenterTexcoord, TexelSize * float2(-2.0, -2.0));
    float3 H = SampleColor(CenterTexcoord, TexelSize * float2(+0.0, -2.0));
    float3 I = SampleColor(CenterTexcoord, TexelSize * float2(+2.0, -2.0));

    float3 J = SampleColor(CenterTexcoord, TexelSize * float2(-1.0, +1.0));
    float3 K = SampleColor(CenterTexcoord, TexelSize * float2(+1.0, +1.0));
    float3 L = SampleColor(CenterTexcoord, TexelSize * float2(-1.0, -1.0));
    float3 M = SampleColor(CenterTexcoord, TexelSize * float2(+1.0, -1.0));

    float3 OutColor = float3(0.0f, 0.0f, 0.0f);
    OutColor += (A + C + G + I) * 0.03125;
    OutColor += (B + D + F + H) * 0.0625;
    OutColor += (E + J + K + L + M) * 0.125;
    return OutColor;
}
