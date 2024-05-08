"#ifndef _POST_FX_COMMON_FXH_\n"
"#define _POST_FX_COMMON_FXH_\n"
"\n"
"#include \"ShaderUtilities.fxh\"\n"
"\n"
"#define M_PI                      3.14159265358979\n"
"#define M_HALF_PI                 1.57079632679490\n"
"#define M_EPSILON                 1e-3\n"
"#define M_GOLDEN_RATIO            1.61803398875\n"
"\n"
"#define FLT_EPS                   5.960464478e-8\n"
"#define FLT_MAX                   3.402823466e+38\n"
"#define FLT_MIN                   1.175494351e-38\n"
"\n"
"struct CRNG\n"
"{\n"
"    uint Seed;\n"
"};\n"
"\n"
"uint PCGHash(uint Seed)\n"
"{\n"
"    uint State = Seed * 747796405u + 2891336453u;\n"
"    uint Word = ((State >> ((State >> 28u) + 4u)) ^ State) * 277803737u;\n"
"    return (Word >> 22u) ^ Word;\n"
"}\n"
"\n"
"CRNG InitCRND(uint2 id, uint FrameIndex)\n"
"{\n"
"    CRNG Rng;\n"
"    Rng.Seed = FrameIndex + PCGHash((id.x << 16u) | id.y);\n"
"    return Rng;\n"
"}\n"
"\n"
"float Rand(inout CRNG Rng)\n"
"{\n"
"    Rng.Seed = PCGHash(Rng.Seed);\n"
"    return asfloat(0x3f800000u | (Rng.Seed >> 9u)) - 1.0;\n"
"}\n"
"\n"
"float Luminance(float3 Color)\n"
"{\n"
"    return dot(Color, float3(0.299f, 0.587f, 0.114f));\n"
"}\n"
"\n"
"uint ComputeHalfResolutionOffset(uint2 PixelCoord)\n"
"{\n"
"    // This is the packed matrix:\n"
"    //  0 1 2 3\n"
"    //  3 2 1 0\n"
"    //  1 0 3 2\n"
"    //  2 3 0 1\n"
"    uint PackedOffsets = 1320229860u;\n"
"    uint Idx = ((PixelCoord.x & 0x3u) << 3u) + ((PixelCoord.y & 0x3u) << 1u);\n"
"    return (PackedOffsets >> Idx) & 0x3u;\n"
"}\n"
"\n"
"float Bayer4x4(uint2 SamplePos, uint FrameIndex)\n"
"{\n"
"    uint2 SamplePosWrap = SamplePos & 3u;\n"
"    uint A = 2068378560u * (1u - (SamplePosWrap.x >> 1u)) + 1500172770u * (SamplePosWrap.x >> 1u);\n"
"    uint B = (SamplePosWrap.y + ((SamplePosWrap.x & 1u) << 2u)) << 2u;\n"
"    uint SampleOffset = FrameIndex;\n"
"    uint Bayer = ((A >> B) + SampleOffset) & 0xFu;\n"
"    return float(Bayer) / 16.0;\n"
"}\n"
"\n"
"float4 GetRotator(float Angle)\n"
"{\n"
"    float Sin = 0.0;\n"
"    float Cos = 0.0;\n"
"    sincos(Angle, Sin, Cos);\n"
"    return float4(Cos, Sin, -Sin, Cos);\n"
"}\n"
"\n"
"float4 CombineRotators(float4 R1, float4 R2)\n"
"{\n"
"    return R1.xyxy * R2.xxzz + R1.zwzw * R2.yyww;\n"
"}\n"
"\n"
"float2 RotateVector(float4 Rotator, float2 Vec)\n"
"{\n"
"    return Vec.x * Rotator.xz + Vec.y * Rotator.yw;\n"
"}\n"
"\n"
"float3 ProjectPosition(float3 Origin, float4x4 Transform)\n"
"{\n"
"    float4 Projected = mul(float4(Origin, 1.0), Transform);\n"
"    Projected.xyz /= Projected.w;\n"
"    Projected.xy = NormalizedDeviceXYToTexUV(Projected.xy);\n"
"    Projected.z = NormalizedDeviceZToDepth(Projected.z);\n"
"    return Projected.xyz;\n"
"}\n"
"\n"
"float3 ProjectDirection(float3 Origin, float3 Direction, float3 OriginSS, float4x4 Mat)\n"
"{\n"
"    return ProjectPosition(Origin + Direction, Mat) - OriginSS;\n"
"}\n"
"\n"
"float3 InvProjectPosition(float3 Coord, float4x4 Transform)\n"
"{\n"
"    Coord.xy = TexUVToNormalizedDeviceXY(Coord.xy);\n"
"    Coord.z = DepthToNormalizedDeviceZ(Coord.z);\n"
"    float4 Projected = mul(float4(Coord, 1.0), Transform);\n"
"    return Projected.xyz /= Projected.w;\n"
"}\n"
"\n"
"float3 ScreenXYDepthToViewSpace(float3 Coord, float4x4 Transform)\n"
"{\n"
"    float3 NDC = float3(TexUVToNormalizedDeviceXY(Coord.xy), DepthToCameraZ(Coord.z, Transform));\n"
"    return float3(NDC.z * NDC.x / MATRIX_ELEMENT(Transform, 0, 0), NDC.z * NDC.y / MATRIX_ELEMENT(Transform, 1, 1), NDC.z);\n"
"}\n"
"\n"
"bool IsInsideScreen(int2 PixelCoord, int2 Dimension)\n"
"{\n"
"    return PixelCoord.x >= 0 &&\n"
"           PixelCoord.y >= 0 &&\n"
"           PixelCoord.x < Dimension.x &&\n"
"           PixelCoord.y < Dimension.y;\n"
"}\n"
"\n"
"bool IsInsideScreen(float2 PixelCoord, float2 Dimension)\n"
"{\n"
"    return PixelCoord.x >= 0.0 &&\n"
"           PixelCoord.y >= 0.0 &&\n"
"           PixelCoord.x < Dimension.x &&\n"
"           PixelCoord.y < Dimension.y;\n"
"}\n"
"\n"
"int2 ClampScreenCoord(int2 PixelCoord, int2 Dimension)\n"
"{\n"
"    return clamp(PixelCoord, int2(0, 0), Dimension - int2(1, 1));\n"
"}\n"
"\n"
"float ComputeSpatialWeight(float Distance, float Sigma)\n"
"{\n"
"    return exp(-(Distance) / (2.0 * Sigma * Sigma));\n"
"}\n"
"\n"
"#endif // _POST_FX_COMMON_FXH_\n"