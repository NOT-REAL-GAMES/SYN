"#ifndef _SSR_COMMON_FXH_\n"
"#define _SSR_COMMON_FXH_\n"
"\n"
"#include \"PostFX_Common.fxh\"\n"
"\n"
"#if SSR_OPTION_INVERTED_DEPTH\n"
"    #define MipConvFunc max\n"
"    #define DepthFarPlane 0.0\n"
"#else\n"
"    #define MipConvFunc min\n"
"    #define DepthFarPlane 1.0\n"
"#endif // SSR_OPTION_INVERTED_DEPTH\n"
"\n"
"#if !defined(DESKTOP_GL) && !defined(GL_ES)\n"
"    #define SSR_ATTRIBUTE_EARLY_DEPTH_STENCIL [earlydepthstencil]\n"
"#else\n"
"    #define SSR_ATTRIBUTE_EARLY_DEPTH_STENCIL\n"
"#endif\n"
"\n"
"float VanDerCorputSequenceBase2(uint SampleIdx)\n"
"{\n"
"    return float(reversebits(SampleIdx)) / exp2(32.0);\n"
"}\n"
"\n"
"float2 HammersleySequence(uint SampleIdx, uint N)\n"
"{\n"
"    return float2(float(SampleIdx) / float(N), VanDerCorputSequenceBase2(SampleIdx));\n"
"}\n"
"\n"
"float2 VogelDiskSample(uint SampleIdx, uint N, float Phi)\n"
"{\n"
"    float GoldenAngle = 2.4;\n"
"    float R = sqrt(float(SampleIdx) + 0.5) / sqrt(float(N));\n"
"    float Theta = float(SampleIdx) * GoldenAngle + Phi;\n"
"\n"
"    float Sine, Cosine;\n"
"    sincos(Theta, Sine, Cosine);\n"
"    return float2(R * Cosine, R * Sine);\n"
"}\n"
"\n"
"float2 MapSquareToDisk(float2 Point)\n"
"{\n"
"    float Lam = sqrt(Point.x);\n"
"    float Phi = 2.0 * M_PI * Point.y;\n"
"    return float2(cos(Phi) * Lam, sin(Phi) * Lam);\n"
"}\n"
"\n"
"bool IsBackground(float Depth)\n"
"{\n"
"#if SSR_OPTION_INVERTED_DEPTH\n"
"    return Depth < 1.0e-6f;\n"
"#else\n"
"    return Depth >= (1.0f - 1.0e-6f);\n"
"#endif // SSR_OPTION_INVERTED_DEPTH\n"
"}\n"
"\n"
"bool IsReflectionSample(float Roughness, float Depth, float RoughnessThreshold)\n"
"{\n"
"    return Roughness <= RoughnessThreshold && !IsBackground(Depth);\n"
"}\n"
"\n"
"bool IsMirrorReflection(float Roughness)\n"
"{\n"
"    return Roughness < 0.01;\n"
"}\n"
"\n"
"#endif // _SSR_COMMON_FXH_\n"
