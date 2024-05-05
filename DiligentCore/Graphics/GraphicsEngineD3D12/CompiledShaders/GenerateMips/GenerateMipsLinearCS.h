#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
//
// Buffer Definitions: 
//
// cbuffer CB
// {
//
//   uint SrcMipLevel;                  // Offset:    0 Size:     4
//   uint NumMipLevels;                 // Offset:    4 Size:     4
//   uint FirstArraySlice;              // Offset:    8 Size:     4
//   uint Dummy;                        // Offset:   12 Size:     4 [unused]
//   float2 TexelSize;                  // Offset:   16 Size:     8
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim      HLSL Bind  Count
// ------------------------------ ---------- ------- ----------- -------------- ------
// BilinearClamp                     sampler      NA          NA             s0      1 
// SrcTex                            texture  float4     2darray             t0      1 
// OutMip1                               UAV  float4     2darray             u0      1 
// OutMip2                               UAV  float4     2darray             u1      1 
// OutMip3                               UAV  float4     2darray             u2      1 
// OutMip4                               UAV  float4     2darray             u3      1 
// CB                                cbuffer      NA          NA            cb0      1 
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Input
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// no Output
cs_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer CB0[2], immediateIndexed
dcl_sampler s0, mode_default
dcl_resource_texture2darray (float,float,float,float) t0
dcl_uav_typed_texture2darray (float,float,float,float) u0
dcl_uav_typed_texture2darray (float,float,float,float) u1
dcl_uav_typed_texture2darray (float,float,float,float) u2
dcl_uav_typed_texture2darray (float,float,float,float) u3
dcl_input vThreadIDInGroupFlattened
dcl_input vThreadID.xyz
dcl_temps 6
dcl_tgsm_structured g0, 4, 64
dcl_tgsm_structured g1, 4, 64
dcl_tgsm_structured g2, 4, 64
dcl_tgsm_structured g3, 4, 64
dcl_thread_group 8, 8, 1
resinfo_indexable(texture2darray)(float,float,float,float)_uint r0.xy, l(0), t0.xyzw
ushr r0.xy, r0.xyxx, cb0[0].xxxx
ult r0.xy, vThreadID.xyxx, r0.xyxx
and r0.x, r0.y, r0.x
iadd r1.zw, vThreadID.zzzz, cb0[0].zzzz
if_nz r0.x
  utof r0.yz, vThreadID.xxyx
  add r0.yz, r0.yyzy, l(0.000000, 0.500000, 0.500000, 0.000000)
  mul r2.xy, r0.yzyy, cb0[1].xyxx
  utof r2.z, r1.w
  utof r0.y, cb0[0].x
  sample_l_indexable(texture2darray)(float,float,float,float) r2.xyzw, r2.xyzx, t0.xyzw, s0, r0.y
  mov r1.xy, vThreadID.xyxx
  store_uav_typed u0.xyzw, r1.xyzw, r2.xyzw
else 
  mov r2.xyzw, l(0,0,0,0)
endif 
ieq r0.y, cb0[0].y, l(1)
if_nz r0.y
  ret 
endif 
if_nz r0.x
  store_structured g0.x, vThreadIDInGroupFlattened.x, l(0), r2.x
  store_structured g1.x, vThreadIDInGroupFlattened.x, l(0), r2.y
  store_structured g2.x, vThreadIDInGroupFlattened.x, l(0), r2.z
  store_structured g3.x, vThreadIDInGroupFlattened.x, l(0), r2.w
endif 
sync_g_t
if_nz r0.x
  and r0.y, vThreadIDInGroupFlattened.x, l(9)
  if_z r0.y
    iadd r0.yzw, vThreadIDInGroupFlattened.xxxx, l(0, 1, 8, 9)
    ld_structured r3.x, r0.y, l(0), g0.xxxx
    ld_structured r3.y, r0.y, l(0), g1.xxxx
    ld_structured r3.z, r0.y, l(0), g2.xxxx
    ld_structured r3.w, r0.y, l(0), g3.xxxx
    ld_structured r4.x, r0.z, l(0), g0.xxxx
    ld_structured r4.y, r0.z, l(0), g1.xxxx
    ld_structured r4.z, r0.z, l(0), g2.xxxx
    ld_structured r4.w, r0.z, l(0), g3.xxxx
    ld_structured r5.x, r0.w, l(0), g0.xxxx
    ld_structured r5.y, r0.w, l(0), g1.xxxx
    ld_structured r5.z, r0.w, l(0), g2.xxxx
    ld_structured r5.w, r0.w, l(0), g3.xxxx
    add r3.xyzw, r2.xyzw, r3.xyzw
    add r3.xyzw, r4.xyzw, r3.xyzw
    add r3.xyzw, r5.xyzw, r3.xyzw
    mul r2.xyzw, r3.xyzw, l(0.250000, 0.250000, 0.250000, 0.250000)
    ushr r3.xy, vThreadID.xyxx, l(1, 1, 0, 0)
    mov r3.zw, r1.wwww
    store_uav_typed u1.xyzw, r3.xyzw, r2.xyzw
    store_structured g0.x, vThreadIDInGroupFlattened.x, l(0), r2.x
    store_structured g1.x, vThreadIDInGroupFlattened.x, l(0), r2.y
    store_structured g2.x, vThreadIDInGroupFlattened.x, l(0), r2.z
    store_structured g3.x, vThreadIDInGroupFlattened.x, l(0), r2.w
  endif 
endif 
ieq r0.y, cb0[0].y, l(2)
if_nz r0.y
  ret 
endif 
sync_g_t
if_nz r0.x
  and r0.y, vThreadIDInGroupFlattened.x, l(27)
  if_z r0.y
    iadd r0.yzw, vThreadIDInGroupFlattened.xxxx, l(0, 2, 16, 18)
    ld_structured r3.x, r0.y, l(0), g0.xxxx
    ld_structured r3.y, r0.y, l(0), g1.xxxx
    ld_structured r3.z, r0.y, l(0), g2.xxxx
    ld_structured r3.w, r0.y, l(0), g3.xxxx
    ld_structured r4.x, r0.z, l(0), g0.xxxx
    ld_structured r4.y, r0.z, l(0), g1.xxxx
    ld_structured r4.z, r0.z, l(0), g2.xxxx
    ld_structured r4.w, r0.z, l(0), g3.xxxx
    ld_structured r5.x, r0.w, l(0), g0.xxxx
    ld_structured r5.y, r0.w, l(0), g1.xxxx
    ld_structured r5.z, r0.w, l(0), g2.xxxx
    ld_structured r5.w, r0.w, l(0), g3.xxxx
    add r3.xyzw, r2.xyzw, r3.xyzw
    add r3.xyzw, r4.xyzw, r3.xyzw
    add r3.xyzw, r5.xyzw, r3.xyzw
    mul r2.xyzw, r3.xyzw, l(0.250000, 0.250000, 0.250000, 0.250000)
    ushr r3.xy, vThreadID.xyxx, l(2, 2, 0, 0)
    mov r3.zw, r1.wwww
    store_uav_typed u2.xyzw, r3.xyzw, r2.xyzw
    store_structured g0.x, vThreadIDInGroupFlattened.x, l(0), r2.x
    store_structured g1.x, vThreadIDInGroupFlattened.x, l(0), r2.y
    store_structured g2.x, vThreadIDInGroupFlattened.x, l(0), r2.z
    store_structured g3.x, vThreadIDInGroupFlattened.x, l(0), r2.w
  endif 
endif 
ieq r0.y, cb0[0].y, l(3)
if_nz r0.y
  ret 
endif 
sync_g_t
if_nz r0.x
  if_z vThreadIDInGroupFlattened.x
    ld_structured r0.x, l(4), l(0), g0.xxxx
    ld_structured r0.y, l(4), l(0), g1.xxxx
    ld_structured r0.z, l(4), l(0), g2.xxxx
    ld_structured r0.w, l(4), l(0), g3.xxxx
    ld_structured r3.x, l(32), l(0), g0.xxxx
    ld_structured r3.y, l(32), l(0), g1.xxxx
    ld_structured r3.z, l(32), l(0), g2.xxxx
    ld_structured r3.w, l(32), l(0), g3.xxxx
    ld_structured r4.x, l(36), l(0), g0.xxxx
    ld_structured r4.y, l(36), l(0), g1.xxxx
    ld_structured r4.z, l(36), l(0), g2.xxxx
    ld_structured r4.w, l(36), l(0), g3.xxxx
    add r0.xyzw, r0.xyzw, r2.xyzw
    add r0.xyzw, r3.xyzw, r0.xyzw
    add r0.xyzw, r4.xyzw, r0.xyzw
    mul r0.xyzw, r0.xyzw, l(0.250000, 0.250000, 0.250000, 0.250000)
    ushr r2.xy, vThreadID.xyxx, l(3, 3, 0, 0)
    mov r2.zw, r1.wwww
    store_uav_typed u3.xyzw, r2.xyzw, r0.xyzw
  endif 
endif 
ret 
// Approximately 120 instruction slots used
#endif

const BYTE g_pGenerateMipsLinearCS[] =
{
     68,  88,  66,  67,  31, 225, 
     60, 168, 138, 225,  60, 156, 
    150, 228,  15, 228,  93,  98, 
    133, 228,   1,   0,   0,   0, 
    224,  17,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
     44,   3,   0,   0,  60,   3, 
      0,   0,  76,   3,   0,   0, 
    128,  16,   0,   0,  28,  17, 
      0,   0,  82,  68,  69,  70, 
    236,   2,   0,   0,   1,   0, 
      0,   0,  84,   1,   0,   0, 
      7,   0,   0,   0,  60,   0, 
      0,   0,   0,   5,  83,  67, 
      0,   1,   0,   0, 196,   2, 
      0,   0,  82,  68,  49,  49, 
     60,   0,   0,   0,  24,   0, 
      0,   0,  32,   0,   0,   0, 
     40,   0,   0,   0,  36,   0, 
      0,   0,  12,   0,   0,   0, 
      0,   0,   0,   0,  28,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     42,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      5,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,  49,   1,   0,   0, 
      4,   0,   0,   0,   5,   0, 
      0,   0,   5,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,  57,   1, 
      0,   0,   4,   0,   0,   0, 
      5,   0,   0,   0,   5,   0, 
      0,   0, 255, 255, 255, 255, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
     65,   1,   0,   0,   4,   0, 
      0,   0,   5,   0,   0,   0, 
      5,   0,   0,   0, 255, 255, 
    255, 255,   2,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,  73,   1,   0,   0, 
      4,   0,   0,   0,   5,   0, 
      0,   0,   5,   0,   0,   0, 
    255, 255, 255, 255,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     13,   0,   0,   0,  81,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     66, 105, 108, 105, 110, 101, 
     97, 114,  67, 108,  97, 109, 
    112,   0,  83, 114,  99,  84, 
    101, 120,   0,  79, 117, 116, 
     77, 105, 112,  49,   0,  79, 
    117, 116,  77, 105, 112,  50, 
      0,  79, 117, 116,  77, 105, 
    112,  51,   0,  79, 117, 116, 
     77, 105, 112,  52,   0,  67, 
     66,   0,  81,   1,   0,   0, 
      5,   0,   0,   0, 108,   1, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  52,   2,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   2,   0,   0,   0, 
     72,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    108,   2,   0,   0,   4,   0, 
      0,   0,   4,   0,   0,   0, 
      2,   0,   0,   0,  72,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 121,   2, 
      0,   0,   8,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0,  72,   2,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 137,   2,   0,   0, 
     12,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
     72,   2,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    143,   2,   0,   0,  16,   0, 
      0,   0,   8,   0,   0,   0, 
      2,   0,   0,   0, 160,   2, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,  83, 114, 
     99,  77, 105, 112,  76, 101, 
    118, 101, 108,   0, 100, 119, 
    111, 114, 100,   0, 171, 171, 
      0,   0,  19,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  64,   2,   0,   0, 
     78, 117, 109,  77, 105, 112, 
     76, 101, 118, 101, 108, 115, 
      0,  70, 105, 114, 115, 116, 
     65, 114, 114,  97, 121,  83, 
    108, 105,  99, 101,   0,  68, 
    117, 109, 109, 121,   0,  84, 
    101, 120, 101, 108,  83, 105, 
    122, 101,   0, 102, 108, 111, 
     97, 116,  50,   0,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    153,   2,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  49,  48,  46, 
     49,   0,  73,  83,  71,  78, 
      8,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     79,  83,  71,  78,   8,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  83,  72, 
     69,  88,  44,  13,   0,   0, 
     80,   0,   5,   0,  75,   3, 
      0,   0, 106,   8,   0,   1, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  90,   0, 
      0,   3,   0,  96,  16,   0, 
      0,   0,   0,   0,  88,  64, 
      0,   4,   0, 112,  16,   0, 
      0,   0,   0,   0,  85,  85, 
      0,   0, 156,  64,   0,   4, 
      0, 224,  17,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
    156,  64,   0,   4,   0, 224, 
     17,   0,   1,   0,   0,   0, 
     85,  85,   0,   0, 156,  64, 
      0,   4,   0, 224,  17,   0, 
      2,   0,   0,   0,  85,  85, 
      0,   0, 156,  64,   0,   4, 
      0, 224,  17,   0,   3,   0, 
      0,   0,  85,  85,   0,   0, 
     95,   0,   0,   2,   0,  64, 
      2,   0,  95,   0,   0,   2, 
    114,   0,   2,   0, 104,   0, 
      0,   2,   6,   0,   0,   0, 
    160,   0,   0,   5,   0, 240, 
     17,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  64,   0, 
      0,   0, 160,   0,   0,   5, 
      0, 240,  17,   0,   1,   0, 
      0,   0,   4,   0,   0,   0, 
     64,   0,   0,   0, 160,   0, 
      0,   5,   0, 240,  17,   0, 
      2,   0,   0,   0,   4,   0, 
      0,   0,  64,   0,   0,   0, 
    160,   0,   0,   5,   0, 240, 
     17,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,  64,   0, 
      0,   0, 155,   0,   0,   4, 
      8,   0,   0,   0,   8,   0, 
      0,   0,   1,   0,   0,   0, 
     61,  16,   0, 137,   2,   2, 
      0, 128,  67,  85,  21,   0, 
     50,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
     85,   0,   0,   8,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  79,   0,   0,   6, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,   2,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     30,   0,   0,   7, 194,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  10,   2,   0, 166, 138, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  31,   0, 
      4,   3,  10,   0,  16,   0, 
      0,   0,   0,   0,  86,   0, 
      0,   4,  98,   0,  16,   0, 
      0,   0,   0,   0,   6,   1, 
      2,   0,   0,   0,   0,  10, 
     98,   0,  16,   0,   0,   0, 
      0,   0,  86,   6,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,  63,   0,   0, 
      0,  63,   0,   0,   0,   0, 
     56,   0,   0,   8,  50,   0, 
     16,   0,   2,   0,   0,   0, 
    150,   5,  16,   0,   0,   0, 
      0,   0,  70, 128,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  86,   0,   0,   5, 
     66,   0,  16,   0,   2,   0, 
      0,   0,  58,   0,  16,   0, 
      1,   0,   0,   0,  86,   0, 
      0,   6,  34,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  72,   0, 
      0, 141,   2,   2,   0, 128, 
     67,  85,  21,   0, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   2,  16,   0,   2,   0, 
      0,   0,  70, 126,  16,   0, 
      0,   0,   0,   0,   0,  96, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   4, 
     50,   0,  16,   0,   1,   0, 
      0,   0,  70,   0,   2,   0, 
    164,   0,   0,   7, 242, 224, 
     17,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  18,   0, 
      0,   1,  54,   0,   0,   8, 
    242,   0,  16,   0,   2,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  32,   0,   0,   8, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  26, 128,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  31,   0, 
      4,   3,  26,   0,  16,   0, 
      0,   0,   0,   0,  62,   0, 
      0,   1,  21,   0,   0,   1, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   0,   0,   0,   0, 
    168,   0,   0,   8,  18, 240, 
     17,   0,   0,   0,   0,   0, 
     10,  64,   2,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0, 168,   0,   0,   8, 
     18, 240,  17,   0,   1,   0, 
      0,   0,  10,  64,   2,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0, 168,   0, 
      0,   8,  18, 240,  17,   0, 
      2,   0,   0,   0,  10,  64, 
      2,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
    168,   0,   0,   8,  18, 240, 
     17,   0,   3,   0,   0,   0, 
     10,  64,   2,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  21,   0,   0,   1, 
    190,  24,   0,   1,  31,   0, 
      4,   3,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   6,  34,   0,  16,   0, 
      0,   0,   0,   0,  10,  64, 
      2,   0,   1,  64,   0,   0, 
      9,   0,   0,   0,  31,   0, 
      0,   3,  26,   0,  16,   0, 
      0,   0,   0,   0,  30,   0, 
      0,   9, 226,   0,  16,   0, 
      0,   0,   0,   0,   6,  64, 
      2,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   8,   0,   0,   0, 
      9,   0,   0,   0, 167,   0, 
      0,   9,  18,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      0,   0,   0,   0, 167,   0, 
      0,   9,  34,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      1,   0,   0,   0, 167,   0, 
      0,   9,  66,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      2,   0,   0,   0, 167,   0, 
      0,   9, 130,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      3,   0,   0,   0, 167,   0, 
      0,   9,  18,   0,  16,   0, 
      4,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      0,   0,   0,   0, 167,   0, 
      0,   9,  34,   0,  16,   0, 
      4,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      1,   0,   0,   0, 167,   0, 
      0,   9,  66,   0,  16,   0, 
      4,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      2,   0,   0,   0, 167,   0, 
      0,   9, 130,   0,  16,   0, 
      4,   0,   0,   0,  42,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      3,   0,   0,   0, 167,   0, 
      0,   9,  18,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      0,   0,   0,   0, 167,   0, 
      0,   9,  34,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      1,   0,   0,   0, 167,   0, 
      0,   9,  66,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      2,   0,   0,   0, 167,   0, 
      0,   9, 130,   0,  16,   0, 
      5,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,   6, 240,  17,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   7, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,   0,   0,   0,   7, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      4,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
      0,   0,   0,   7, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   5,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  56,   0, 
      0,  10, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  62,   0,   0, 128,  62, 
      0,   0, 128,  62,   0,   0, 
    128,  62,  85,   0,   0,   9, 
     50,   0,  16,   0,   3,   0, 
      0,   0,  70,   0,   2,   0, 
      2,  64,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    194,   0,  16,   0,   3,   0, 
      0,   0, 246,  15,  16,   0, 
      1,   0,   0,   0, 164,   0, 
      0,   7, 242, 224,  17,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0, 168,   0,   0,   8, 
     18, 240,  17,   0,   0,   0, 
      0,   0,  10,  64,   2,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      2,   0,   0,   0, 168,   0, 
      0,   8,  18, 240,  17,   0, 
      1,   0,   0,   0,  10,  64, 
      2,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   2,   0,   0,   0, 
    168,   0,   0,   8,  18, 240, 
     17,   0,   2,   0,   0,   0, 
     10,  64,   2,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   2,   0, 
      0,   0, 168,   0,   0,   8, 
     18, 240,  17,   0,   3,   0, 
      0,   0,  10,  64,   2,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      2,   0,   0,   0,  21,   0, 
      0,   1,  21,   0,   0,   1, 
     32,   0,   0,   8,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,  31,   0,   4,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  62,   0,   0,   1, 
     21,   0,   0,   1, 190,  24, 
      0,   1,  31,   0,   4,   3, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   1,   0,   0,   6, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10,  64,   2,   0, 
      1,  64,   0,   0,  27,   0, 
      0,   0,  31,   0,   0,   3, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  30,   0,   0,   9, 
    226,   0,  16,   0,   0,   0, 
      0,   0,   6,  64,   2,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     16,   0,   0,   0,  18,   0, 
      0,   0, 167,   0,   0,   9, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     34,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   1,   0, 
      0,   0, 167,   0,   0,   9, 
     66,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   2,   0, 
      0,   0, 167,   0,   0,   9, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   3,   0, 
      0,   0, 167,   0,   0,   9, 
     18,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     34,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   1,   0, 
      0,   0, 167,   0,   0,   9, 
     66,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   2,   0, 
      0,   0, 167,   0,   0,   9, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   3,   0, 
      0,   0, 167,   0,   0,   9, 
     18,   0,  16,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     34,   0,  16,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   1,   0, 
      0,   0, 167,   0,   0,   9, 
     66,   0,  16,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   2,   0, 
      0,   0, 167,   0,   0,   9, 
    130,   0,  16,   0,   5,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   3,   0, 
      0,   0,   0,   0,   0,   7, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
      0,   0,   0,   7, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   7, 242,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   5,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  62, 
      0,   0, 128,  62,   0,   0, 
    128,  62,   0,   0, 128,  62, 
     85,   0,   0,   9,  50,   0, 
     16,   0,   3,   0,   0,   0, 
     70,   0,   2,   0,   2,  64, 
      0,   0,   2,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 194,   0, 
     16,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0, 164,   0,   0,   7, 
    242, 224,  17,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
    168,   0,   0,   8,  18, 240, 
     17,   0,   0,   0,   0,   0, 
     10,  64,   2,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   2,   0, 
      0,   0, 168,   0,   0,   8, 
     18, 240,  17,   0,   1,   0, 
      0,   0,  10,  64,   2,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  26,   0,  16,   0, 
      2,   0,   0,   0, 168,   0, 
      0,   8,  18, 240,  17,   0, 
      2,   0,   0,   0,  10,  64, 
      2,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  42,   0, 
     16,   0,   2,   0,   0,   0, 
    168,   0,   0,   8,  18, 240, 
     17,   0,   3,   0,   0,   0, 
     10,  64,   2,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   2,   0, 
      0,   0,  21,   0,   0,   1, 
     21,   0,   0,   1,  32,   0, 
      0,   8,  34,   0,  16,   0, 
      0,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   3,   0,   0,   0, 
     31,   0,   4,   3,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  21,   0, 
      0,   1, 190,  24,   0,   1, 
     31,   0,   4,   3,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,  10,  64, 
      2,   0, 167,   0,   0,   9, 
     18,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      4,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     34,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      4,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   1,   0, 
      0,   0, 167,   0,   0,   9, 
     66,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      4,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   2,   0, 
      0,   0, 167,   0,   0,   9, 
    130,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      4,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   3,   0, 
      0,   0, 167,   0,   0,   9, 
     18,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
     32,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     34,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
     32,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   1,   0, 
      0,   0, 167,   0,   0,   9, 
     66,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
     32,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   2,   0, 
      0,   0, 167,   0,   0,   9, 
    130,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
     32,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   3,   0, 
      0,   0, 167,   0,   0,   9, 
     18,   0,  16,   0,   4,   0, 
      0,   0,   1,  64,   0,   0, 
     36,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   0,   0, 
      0,   0, 167,   0,   0,   9, 
     34,   0,  16,   0,   4,   0, 
      0,   0,   1,  64,   0,   0, 
     36,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   1,   0, 
      0,   0, 167,   0,   0,   9, 
     66,   0,  16,   0,   4,   0, 
      0,   0,   1,  64,   0,   0, 
     36,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   2,   0, 
      0,   0, 167,   0,   0,   9, 
    130,   0,  16,   0,   4,   0, 
      0,   0,   1,  64,   0,   0, 
     36,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
      6, 240,  17,   0,   3,   0, 
      0,   0,   0,   0,   0,   7, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
      0,   0,   0,   7, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   7, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,  10, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  62, 
      0,   0, 128,  62,   0,   0, 
    128,  62,   0,   0, 128,  62, 
     85,   0,   0,   9,  50,   0, 
     16,   0,   2,   0,   0,   0, 
     70,   0,   2,   0,   2,  64, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 194,   0, 
     16,   0,   2,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0, 164,   0,   0,   7, 
    242, 224,  17,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     21,   0,   0,   1,  21,   0, 
      0,   1,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0, 120,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     14,   0,   0,   0,   6,   0, 
      0,   0,   8,   0,   0,   0, 
      5,   0,   0,   0,  11,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
     82,  84,  83,  48, 188,   0, 
      0,   0,   2,   0,   0,   0, 
      3,   0,   0,   0,  24,   0, 
      0,   0,   1,   0,   0,   0, 
    136,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  72,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,   1,   0,   0,   0, 
     80,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   1,   0, 
      0,   0, 112,   0,   0,   0, 
      1,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
     21,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      4,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 127, 127,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
