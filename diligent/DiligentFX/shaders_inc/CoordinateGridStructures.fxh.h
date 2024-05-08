"#ifndef _COORDINATE_GRID_STRUCTURES_FXH_\n"
"#define _COORDINATE_GRID_STRUCTURES_FXH_\n"
"\n"
"#include \"ShaderDefinitions.fxh\"\n"
"\n"
"struct CoordinateGridAttribs\n"
"{\n"
"    float4 XAxisColor       DEFAULT_VALUE(float4(1, 0, 0, 1));\n"
"    float4 YAxisColor       DEFAULT_VALUE(float4(0, 1, 0, 1));\n"
"    float4 ZAxisColor       DEFAULT_VALUE(float4(0, 0, 1, 1));\n"
"\n"
"    float XAxisWidth        DEFAULT_VALUE(2); // in pixels\n"
"    float YAxisWidth        DEFAULT_VALUE(2); // in pixels\n"
"    float ZAxisWidth        DEFAULT_VALUE(2); // in pixels\n"
"    float Padding0          DEFAULT_VALUE(0);\n"
"\n"
"    float4 GridMajorColor   DEFAULT_VALUE(float4(0.4f, 0.4f, 0.4f, 1));\n"
"    float4 GridMinorColor   DEFAULT_VALUE(float4(0.1f, 0.1f, 0.1f, 1));\n"
"    float4 GridScale        DEFAULT_VALUE(float4(1, 1, 1, 0));    // YZ, XZ, XY\n"
"    float4 GridSubdivision  DEFAULT_VALUE(float4(10, 10, 10, 0)); // YZ, XZ, XY\n"
"\n"
"    float  GridLineWidth    DEFAULT_VALUE(2); // in pixels\n"
"    float  GridMinCellWidth DEFAULT_VALUE(4); // in pixels\n"
"    float  GridMinCellSize  DEFAULT_VALUE(0.0001f);\n"
"    float  Padding1         DEFAULT_VALUE(0);\n"
"};\n"
"#ifdef CHECK_STRUCT_ALIGNMENT\n"
"    CHECK_STRUCT_ALIGNMENT(CoordinateGridAttribs);\n"
"#endif\n"
"\n"
"#endif //_COORDINATE_GRID_STRUCTURES_FXH_\n"
