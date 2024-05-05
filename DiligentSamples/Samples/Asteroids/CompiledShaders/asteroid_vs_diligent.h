#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer DrawConstantBuffer
// {
//
//   float4x4 ViewProjection;           // Offset:    0 Size:    64
//   
//   struct AsteroidData
//   {
//       
//       float4x4 World;                // Offset:   64
//       float4 SurfaceColor;           // Offset:  128
//       float DeepColorR;              // Offset:  144
//       float DeepColorG;              // Offset:  148
//       float DeepColorB;              // Offset:  152
//       uint TextureIndex;             // Offset:  156
//
//   } g_Data;                          // Offset:   64 Size:    96
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// DrawConstantBuffer                cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// ATTRIB                   0   xyz         0     NONE   float   xyz 
// ATTRIB                   1   xyz         1     NONE   float   xyz 
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0      POS   float   xyzw
// POSITIONMODEL            0   xyz         1     NONE   float   xyz 
// NORMAL                   0   xyz         2     NONE   float   xyz 
// ALBEDO                   0   xyz         3     NONE   float   xyz 
// TEXTURE_ID               0   x           4     NONE    uint   x   
//
vs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[10], immediateIndexed
dcl_input v0.xyz
dcl_input v1.xyz
dcl_output_siv o0.xyzw, position
dcl_output o1.xyz
dcl_output o2.xyz
dcl_output o3.xyz
dcl_output o4.x
dcl_temps 2
mul r0.xyz, v0.yyyy, cb0[5].xyzx
mad r0.xyz, cb0[4].xyzx, v0.xxxx, r0.xyzx
mad r0.xyz, cb0[6].xyzx, v0.zzzz, r0.xyzx
add r0.xyz, r0.xyzx, cb0[7].xyzx
mul r1.xyzw, r0.yyyy, cb0[1].xyzw
mad r1.xyzw, cb0[0].xyzw, r0.xxxx, r1.xyzw
mad r0.xyzw, cb0[2].xyzw, r0.zzzz, r1.xyzw
add o0.xyzw, r0.xyzw, cb0[3].xyzw
mov o1.xyz, v0.xyzx
mul r0.xyz, v1.yyyy, cb0[5].xyzx
mad r0.xyz, cb0[4].xyzx, v1.xxxx, r0.xyzx
mad o2.xyz, cb0[6].xyzx, v1.zzzz, r0.xyzx
dp3 r0.x, v0.xyzx, v0.xyzx
sqrt r0.x, r0.x
add r0.x, r0.x, l(-0.500000)
mul_sat r0.x, r0.x, l(5.000000)
add r0.yzw, cb0[8].xxyz, -cb0[9].xxyz
mad o3.xyz, r0.xxxx, r0.yzwy, cb0[9].xyzx
mov o4.x, cb0[9].w
ret 
// Approximately 20 instruction slots used
#endif

const BYTE g_asteroid_vs_diligent[] =
{
     68,  88,  66,  67,  50,  12, 
     52, 120, 216, 224,  34,  79, 
    233, 102, 121, 219,  80, 223, 
    182, 225,   1,   0,   0,   0, 
    128,   7,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    228,   2,   0,   0,  44,   3, 
      0,   0, 232,   3,   0,   0, 
    228,   6,   0,   0,  82,  68, 
     69,  70, 168,   2,   0,   0, 
      1,   0,   0,   0, 112,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    254, 255,   0,   1,   0,   0, 
    128,   2,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  68, 114,  97, 119, 
     67, 111, 110, 115, 116,  97, 
    110, 116,  66, 117, 102, 102, 
    101, 114,   0, 171,  92,   0, 
      0,   0,   2,   0,   0,   0, 
    136,   0,   0,   0, 160,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 216,   0, 
      0,   0,   0,   0,   0,   0, 
     64,   0,   0,   0,   2,   0, 
      0,   0, 240,   0,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  20,   1,   0,   0, 
     64,   0,   0,   0,  96,   0, 
      0,   0,   2,   0,   0,   0, 
     92,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
     86, 105, 101, 119,  80, 114, 
    111, 106, 101,  99, 116, 105, 
    111, 110,   0, 102, 108, 111, 
     97, 116,  52, 120,  52,   0, 
      3,   0,   3,   0,   4,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 231,   0,   0,   0, 
    103,  95,  68,  97, 116,  97, 
      0,  65, 115, 116, 101, 114, 
    111, 105, 100,  68,  97, 116, 
     97,   0,  87, 111, 114, 108, 
    100,   0, 171, 171,   3,   0, 
      3,   0,   4,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    231,   0,   0,   0,  83, 117, 
    114, 102,  97,  99, 101,  67, 
    111, 108, 111, 114,   0, 102, 
    108, 111,  97, 116,  52,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  97,   1,   0,   0, 
     68, 101, 101, 112,  67, 111, 
    108, 111, 114,  82,   0, 102, 
    108, 111,  97, 116,   0, 171, 
    171, 171,   0,   0,   3,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 151,   1, 
      0,   0,  68, 101, 101, 112, 
     67, 111, 108, 111, 114,  71, 
      0,  68, 101, 101, 112,  67, 
    111, 108, 111, 114,  66,   0, 
     84, 101, 120, 116, 117, 114, 
    101,  73, 110, 100, 101, 120, 
      0, 100, 119, 111, 114, 100, 
      0, 171, 171, 171,   0,   0, 
     19,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    231,   1,   0,   0,  40,   1, 
      0,   0,  48,   1,   0,   0, 
      0,   0,   0,   0,  84,   1, 
      0,   0, 104,   1,   0,   0, 
     64,   0,   0,   0, 140,   1, 
      0,   0, 160,   1,   0,   0, 
     80,   0,   0,   0, 196,   1, 
      0,   0, 160,   1,   0,   0, 
     84,   0,   0,   0, 207,   1, 
      0,   0, 160,   1,   0,   0, 
     88,   0,   0,   0, 218,   1, 
      0,   0, 240,   1,   0,   0, 
     92,   0,   0,   0,   5,   0, 
      0,   0,   1,   0,  24,   0, 
      0,   0,   6,   0,  20,   2, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     27,   1,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  73,  83,  71,  78, 
     64,   0,   0,   0,   2,   0, 
      0,   0,   8,   0,   0,   0, 
     56,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   7,   7,   0,   0, 
     56,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   7,   0,   0, 
     65,  84,  84,  82,  73,  66, 
      0, 171,  79,  83,  71,  78, 
    180,   0,   0,   0,   5,   0, 
      0,   0,   8,   0,   0,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,   0,   0,   0, 
    140,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   8,   0,   0, 
    154,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   7,   8,   0,   0, 
    161,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   7,   8,   0,   0, 
    168,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,   1,  14,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
     80,  79,  83,  73,  84,  73, 
     79,  78,  77,  79,  68,  69, 
     76,   0,  78,  79,  82,  77, 
     65,  76,   0,  65,  76,  66, 
     69,  68,  79,   0,  84,  69, 
     88,  84,  85,  82,  69,  95, 
     73,  68,   0, 171,  83,  72, 
     69,  88, 244,   2,   0,   0, 
     80,   0,   1,   0, 189,   0, 
      0,   0, 106,   8,   0,   1, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     10,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      0,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      1,   0,   0,   0, 103,   0, 
      0,   4, 242,  32,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    114,  32,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    114,  32,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
    114,  32,  16,   0,   3,   0, 
      0,   0, 101,   0,   0,   3, 
     18,  32,  16,   0,   4,   0, 
      0,   0, 104,   0,   0,   2, 
      2,   0,   0,   0,  56,   0, 
      0,   8, 114,   0,  16,   0, 
      0,   0,   0,   0,  86,  21, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     50,   0,   0,  10, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      6,  16,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  50,   0, 
      0,  10, 114,   0,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      6,   0,   0,   0, 166,  26, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      1,   0,   0,   0,  86,   5, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0, 166,  10, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,   0,   0,   0,   8, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  54,   0, 
      0,   5, 114,  32,  16,   0, 
      1,   0,   0,   0,  70,  18, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     86,  21,  16,   0,   1,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  50,   0,   0,  10, 
    114,   0,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   6,  16,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  10, 114,  32, 
     16,   0,   2,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
    166,  26,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   0,   0, 
      0,   0,  75,   0,   0,   5, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0, 191,  56,  32,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   1,   0, 160,  64, 
      0,   0,   0,  10, 226,   0, 
     16,   0,   0,   0,   0,   0, 
      6, 137,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
      6, 137,  32, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  50,   0, 
      0,  10, 114,  32,  16,   0, 
      3,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
    150,   7,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  54,   0,   0,   6, 
     18,  32,  16,   0,   4,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0,  20,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
     17,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
