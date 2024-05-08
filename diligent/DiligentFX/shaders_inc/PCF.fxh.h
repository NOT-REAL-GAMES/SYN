"#ifndef _PCF_FXH_\n"
"#define _PCF_FXH_\n"
"\n"
"#if defined(PCF_FILTER_SIZE) && PCF_FILTER_SIZE > 0\n"
"\n"
"// The method used in The Witness\n"
"float FilterShadowMapFixedPCF(in Texture2DArray<float>  tex2DShadowMap,\n"
"                              in SamplerComparisonState tex2DShadowMap_sampler,\n"
"                              in float4                 f4ShadowMapSize,\n"
"                              in float2                 f2UV,\n"
"                              in float                  fSlice,\n"
"                              in float                  fLightSpaceDepth,\n"
"                              in float2                 f2ReceiverPlaneDepthBias)\n"
"{\n"
"    float2 uv = f2UV.xy * f4ShadowMapSize.xy;\n"
"    float2 base_uv = floor(uv + float2(0.5, 0.5));\n"
"    float s = (uv.x + 0.5 - base_uv.x);\n"
"    float t = (uv.y + 0.5 - base_uv.y);\n"
"    base_uv -= float2(0.5, 0.5);\n"
"    base_uv *= f4ShadowMapSize.zw;\n"
"\n"
"    float sum = 0.0;\n"
"\n"
"    // It is essential to clamp biased depth to 0 to avoid shadow leaks at near cascade depth boundary.\n"
"    //\n"
"    //            No clamping                 With clamping\n"
"    //\n"
"    //              \\ |                             ||\n"
"    //       ==>     \\|                             ||\n"
"    //                |                             ||\n"
"    // Light ==>      |\\                            |\\\n"
"    //                | \\Receiver plane             | \\ Receiver plane\n"
"    //       ==>      |  \\                          |  \\\n"
"    //                0   ...   1                   0   ...   1\n"
"    //\n"
"    // Note that clamping at far depth boundary makes no difference as 1 < 1 produces 0 and so does 1+x < 1\n"
"    const float DepthClamp = 1e-8;\n"
"#ifdef GLSL\n"
"    // There is no OpenGL counterpart for Texture2DArray.SampleCmpLevelZero()\n"
"    #define SAMPLE_SHADOW_MAP(u, v) tex2DShadowMap.SampleCmp(tex2DShadowMap_sampler, float3(base_uv.xy + float2(u,v) * f4ShadowMapSize.zw, fSlice), max(fLightSpaceDepth + dot(float2(u, v), f2ReceiverPlaneDepthBias), DepthClamp))\n"
"#else\n"
"    #define SAMPLE_SHADOW_MAP(u, v) tex2DShadowMap.SampleCmpLevelZero(tex2DShadowMap_sampler, float3(base_uv.xy + float2(u,v) * f4ShadowMapSize.zw, fSlice), max(fLightSpaceDepth + dot(float2(u, v), f2ReceiverPlaneDepthBias), DepthClamp))\n"
"#endif\n"
"\n"
"    #if PCF_FILTER_SIZE == 2\n"
"\n"
"        #ifdef GLSL\n"
"            return tex2DShadowMap.SampleCmp(tex2DShadowMap_sampler, float3(f2UV, fSlice), max(fLightSpaceDepth, DepthClamp));\n"
"        #else\n"
"            return tex2DShadowMap.SampleCmpLevelZero(tex2DShadowMap_sampler, float3(f2UV, fSlice), max(fLightSpaceDepth, DepthClamp));\n"
"        #endif\n"
"\n"
"    #elif PCF_FILTER_SIZE == 3\n"
"\n"
"        float uw0 = (3.0 - 2.0 * s);\n"
"        float uw1 = (1.0 + 2.0 * s);\n"
"\n"
"        float u0 = (2.0 - s) / uw0 - 1.0;\n"
"        float u1 = s / uw1 + 1.0;\n"
"\n"
"        float vw0 = (3.0 - 2.0 * t);\n"
"        float vw1 = (1.0 + 2.0 * t);\n"
"\n"
"        float v0 = (2.0 - t) / vw0 - 1.0;\n"
"        float v1 = t / vw1 + 1.0;\n"
"\n"
"        sum += uw0 * vw0 * SAMPLE_SHADOW_MAP(u0, v0);\n"
"        sum += uw1 * vw0 * SAMPLE_SHADOW_MAP(u1, v0);\n"
"        sum += uw0 * vw1 * SAMPLE_SHADOW_MAP(u0, v1);\n"
"        sum += uw1 * vw1 * SAMPLE_SHADOW_MAP(u1, v1);\n"
"\n"
"        return sum * 1.0 / 16.0;\n"
"\n"
"    #elif PCF_FILTER_SIZE == 5\n"
"\n"
"        float uw0 = (4.0 - 3.0 * s);\n"
"        float uw1 = 7.0;\n"
"        float uw2 = (1.0 + 3.0 * s);\n"
"\n"
"        float u0 = (3.0 - 2.0 * s) / uw0 - 2.0;\n"
"        float u1 = (3.0 + s) / uw1;\n"
"        float u2 = s / uw2 + 2.0;\n"
"\n"
"        float vw0 = (4.0 - 3.0 * t);\n"
"        float vw1 = 7.0;\n"
"        float vw2 = (1.0 + 3.0 * t);\n"
"\n"
"        float v0 = (3.0 - 2.0 * t) / vw0 - 2.0;\n"
"        float v1 = (3.0 + t) / vw1;\n"
"        float v2 = t / vw2 + 2.0;\n"
"\n"
"        sum += uw0 * vw0 * SAMPLE_SHADOW_MAP(u0, v0);\n"
"        sum += uw1 * vw0 * SAMPLE_SHADOW_MAP(u1, v0);\n"
"        sum += uw2 * vw0 * SAMPLE_SHADOW_MAP(u2, v0);\n"
"\n"
"        sum += uw0 * vw1 * SAMPLE_SHADOW_MAP(u0, v1);\n"
"        sum += uw1 * vw1 * SAMPLE_SHADOW_MAP(u1, v1);\n"
"        sum += uw2 * vw1 * SAMPLE_SHADOW_MAP(u2, v1);\n"
"\n"
"        sum += uw0 * vw2 * SAMPLE_SHADOW_MAP(u0, v2);\n"
"        sum += uw1 * vw2 * SAMPLE_SHADOW_MAP(u1, v2);\n"
"        sum += uw2 * vw2 * SAMPLE_SHADOW_MAP(u2, v2);\n"
"\n"
"        return sum * 1.0 / 144.0;\n"
"\n"
"    #elif PCF_FILTER_SIZE == 7\n"
"\n"
"        float uw0 = (5.0 * s - 6.0);\n"
"        float uw1 = (11.0 * s - 28.0);\n"
"        float uw2 = -(11.0 * s + 17.0);\n"
"        float uw3 = -(5.0 * s + 1.0);\n"
"\n"
"        float u0 = (4.0 * s - 5.0) / uw0 - 3.0;\n"
"        float u1 = (4.0 * s - 16.0) / uw1 - 1.0;\n"
"        float u2 = -(7.0 * s + 5.0) / uw2 + 1.0;\n"
"        float u3 = -s / uw3 + 3.0;\n"
"\n"
"        float vw0 = (5.0 * t - 6.0);\n"
"        float vw1 = (11.0 * t - 28.0);\n"
"        float vw2 = -(11.0 * t + 17.0);\n"
"        float vw3 = -(5.0 * t + 1.0);\n"
"\n"
"        float v0 = (4.0 * t - 5.0) / vw0 - 3.0;\n"
"        float v1 = (4.0 * t - 16.0) / vw1 - 1.0;\n"
"        float v2 = -(7.0 * t + 5.0) / vw2 + 1.0;\n"
"        float v3 = -t / vw3 + 3.0;\n"
"\n"
"        sum += uw0 * vw0 * SAMPLE_SHADOW_MAP(u0, v0);\n"
"        sum += uw1 * vw0 * SAMPLE_SHADOW_MAP(u1, v0);\n"
"        sum += uw2 * vw0 * SAMPLE_SHADOW_MAP(u2, v0);\n"
"        sum += uw3 * vw0 * SAMPLE_SHADOW_MAP(u3, v0);\n"
"\n"
"        sum += uw0 * vw1 * SAMPLE_SHADOW_MAP(u0, v1);\n"
"        sum += uw1 * vw1 * SAMPLE_SHADOW_MAP(u1, v1);\n"
"        sum += uw2 * vw1 * SAMPLE_SHADOW_MAP(u2, v1);\n"
"        sum += uw3 * vw1 * SAMPLE_SHADOW_MAP(u3, v1);\n"
"\n"
"        sum += uw0 * vw2 * SAMPLE_SHADOW_MAP(u0, v2);\n"
"        sum += uw1 * vw2 * SAMPLE_SHADOW_MAP(u1, v2);\n"
"        sum += uw2 * vw2 * SAMPLE_SHADOW_MAP(u2, v2);\n"
"        sum += uw3 * vw2 * SAMPLE_SHADOW_MAP(u3, v2);\n"
"\n"
"        sum += uw0 * vw3 * SAMPLE_SHADOW_MAP(u0, v3);\n"
"        sum += uw1 * vw3 * SAMPLE_SHADOW_MAP(u1, v3);\n"
"        sum += uw2 * vw3 * SAMPLE_SHADOW_MAP(u2, v3);\n"
"        sum += uw3 * vw3 * SAMPLE_SHADOW_MAP(u3, v3);\n"
"\n"
"        return sum * 1.0 / 2704.0;\n"
"    #else\n"
"        return 0.0;\n"
"    #endif\n"
"#undef SAMPLE_SHADOW_MAP\n"
"}\n"
"\n"
"#else\n"
"\n"
"float FilterShadowMapVaryingPCF(in Texture2DArray<float>  tex2DShadowMap,\n"
"                                in SamplerComparisonState tex2DShadowMap_sampler,\n"
"                                in float4                 f4ShadowMapSize,\n"
"                                in float2                 f2UV,\n"
"                                in float                  fSlice,\n"
"                                in float                  fLightSpaceDepth,\n"
"                                in float2                 f2ReceiverPlaneDepthBias,\n"
"                                in float2                 f2FilterSize)\n"
"{\n"
"\n"
"    f2FilterSize = max(f2FilterSize * f4ShadowMapSize.xy, float2(1.0, 1.0));\n"
"    float2 f2CenterTexel = f2UV * f4ShadowMapSize.xy;\n"
"    // Clamp to the full texture extent, no need for 0.5 texel padding\n"
"    float2 f2MinBnd = clamp(f2CenterTexel - f2FilterSize / 2.0, float2(0.0, 0.0), f4ShadowMapSize.xy);\n"
"    float2 f2MaxBnd = clamp(f2CenterTexel + f2FilterSize / 2.0, float2(0.0, 0.0), f4ShadowMapSize.xy);\n"
"    //\n"
"    // StartTexel                                     EndTexel\n"
"    //   |  MinBnd                         MaxBnd        |\n"
"    //   V    V                              V           V\n"
"    //   |    :  X       |       X       |   :   X       |\n"
"    //   n              n+1             n+2             n+3\n"
"    //\n"
"    int2 StartTexelXY = int2(floor(f2MinBnd));\n"
"    int2 EndTexelXY   = int2(ceil (f2MaxBnd));\n"
"\n"
"    float TotalWeight = 0.0;\n"
"    float Sum = 0.0;\n"
"\n"
"    // Handle as many as 2x2 texels in one iteration\n"
"    [loop]\n"
"    for (int x = StartTexelXY.x; x < EndTexelXY.x; x += 2)\n"
"    {\n"
"        float U0 = float(x) + 0.5;\n"
"        // Compute horizontal coverage of this and the adjacent texel to the right\n"
"        //\n"
"        //        U0         U1                  U0         U1                  U0         U1\n"
"        //   |    X     |    X     |        |    X     |    X     |        |    X     |    X     |\n"
"        //    ####-----------------          ------###------------          ---############------\n"
"        //     0.4          0.0                    0.3     0.0                  0.7     0.5\n"
"        //\n"
"        float LeftTexelCoverage  = max(min(U0 + 0.5, f2MaxBnd.x) - max(U0 - 0.5, f2MinBnd.x), 0.0);\n"
"        float RightTexelCoverage = max(min(U0 + 1.5, f2MaxBnd.x) - max(U0 + 0.5, f2MinBnd.x), 0.0);\n"
"        float dU = RightTexelCoverage / max(RightTexelCoverage + LeftTexelCoverage, 1e-6);\n"
"        float HorzWeight = RightTexelCoverage + LeftTexelCoverage;\n"
"\n"
"        [loop]\n"
"        for (int y = StartTexelXY.y; y < EndTexelXY.y; y += 2)\n"
"        {\n"
"            // Compute vertical coverage of this and the top adjacent texels\n"
"            float V0 = float(y) + 0.5;\n"
"            float BottomTexelCoverage = max(min(V0 + 0.5, f2MaxBnd.y) - max(V0 - 0.5, f2MinBnd.y), 0.0);\n"
"            float TopTexelCoverage    = max(min(V0 + 1.5, f2MaxBnd.y) - max(V0 + 0.5, f2MinBnd.y), 0.0);\n"
"            float dV = TopTexelCoverage / max(BottomTexelCoverage + TopTexelCoverage, 1e-6);\n"
"            float VertWeight = BottomTexelCoverage + TopTexelCoverage;\n"
"\n"
"            float2 f2UV = float2(U0 + dU, V0 + dV);\n"
"\n"
"            float Weight = HorzWeight * VertWeight;\n"
"            const float DepthClamp = 1e-8;\n"
"            float fDepth = max(fLightSpaceDepth + dot(f2UV - f2CenterTexel, f2ReceiverPlaneDepthBias), DepthClamp);\n"
"            f2UV *= f4ShadowMapSize.zw;\n"
"            #ifdef GLSL\n"
"                // There is no OpenGL counterpart for Texture2DArray.SampleCmpLevelZero()\n"
"                Sum += tex2DShadowMap.SampleCmp(tex2DShadowMap_sampler, float3(f2UV, fSlice), fDepth) * Weight;\n"
"            #else\n"
"                Sum += tex2DShadowMap.SampleCmpLevelZero(tex2DShadowMap_sampler, float3(f2UV, fSlice), fDepth) * Weight;\n"
"            #endif\n"
"            TotalWeight += Weight;\n"
"        }\n"
"    }\n"
"    return TotalWeight > 0.0 ? Sum / TotalWeight : 1.0;\n"
"}\n"
"\n"
"#endif\n"
"\n"
"#endif //_PCF_FXH_\n"