/*
 *  Copyright 2019-2022 Diligent Graphics LLC
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  In no event and under no legal theory, whether in tort (including
 * negligence), contract, or otherwise, unless required by applicable law (such
 * as deliberate and grossly negligent acts) or agreed to in writing, shall any
 * Contributor be liable for any damages, including any direct, indirect,
 * special, incidental, or consequential damages of any character arising as a
 * result of this License or out of the use or inability to use the software
 * (including but not limited to damages for loss of goodwill, work stoppage,
 * computer failure or malfunction, or any and all other commercial damages or
 * losses), even if such Contributor has been advised of the possibility of such
 * damages.
 */

#pragma once

#include "GraphicsTypes.h"

namespace Diligent {

NLOHMANN_JSON_SERIALIZE_ENUM_EX(VALUE_TYPE, {
                                                {VT_UNDEFINED, "UNDEFINED"},
                                                {VT_INT8, "INT8"},
                                                {VT_INT16, "INT16"},
                                                {VT_INT32, "INT32"},
                                                {VT_UINT8, "UINT8"},
                                                {VT_UINT16, "UINT16"},
                                                {VT_UINT32, "UINT32"},
                                                {VT_FLOAT16, "FLOAT16"},
                                                {VT_FLOAT32, "FLOAT32"},
                                                {VT_FLOAT64, "FLOAT64"},
                                                {VT_NUM_TYPES, "NUM_TYPES"},
                                            })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SHADER_TYPE, {
                     {SHADER_TYPE_UNKNOWN, "UNKNOWN"},
                     {SHADER_TYPE_VERTEX, "VERTEX"},
                     {SHADER_TYPE_PIXEL, "PIXEL"},
                     {SHADER_TYPE_GEOMETRY, "GEOMETRY"},
                     {SHADER_TYPE_HULL, "HULL"},
                     {SHADER_TYPE_DOMAIN, "DOMAIN"},
                     {SHADER_TYPE_COMPUTE, "COMPUTE"},
                     {SHADER_TYPE_AMPLIFICATION, "AMPLIFICATION"},
                     {SHADER_TYPE_MESH, "MESH"},
                     {SHADER_TYPE_RAY_GEN, "RAY_GEN"},
                     {SHADER_TYPE_RAY_MISS, "RAY_MISS"},
                     {SHADER_TYPE_RAY_CLOSEST_HIT, "RAY_CLOSEST_HIT"},
                     {SHADER_TYPE_RAY_ANY_HIT, "RAY_ANY_HIT"},
                     {SHADER_TYPE_RAY_INTERSECTION, "RAY_INTERSECTION"},
                     {SHADER_TYPE_CALLABLE, "CALLABLE"},
                     {SHADER_TYPE_TILE, "TILE"},
                     {SHADER_TYPE_LAST, "LAST"},
                     {SHADER_TYPE_ALL_GRAPHICS, "ALL_GRAPHICS"},
                     {SHADER_TYPE_ALL_MESH, "ALL_MESH"},
                     {SHADER_TYPE_ALL_RAY_TRACING, "ALL_RAY_TRACING"},
                     {SHADER_TYPE_ALL, "ALL"},
                 })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(BIND_FLAGS,
                                {
                                    {BIND_NONE, "NONE"},
                                    {BIND_VERTEX_BUFFER, "VERTEX_BUFFER"},
                                    {BIND_INDEX_BUFFER, "INDEX_BUFFER"},
                                    {BIND_UNIFORM_BUFFER, "UNIFORM_BUFFER"},
                                    {BIND_SHADER_RESOURCE, "SHADER_RESOURCE"},
                                    {BIND_STREAM_OUTPUT, "STREAM_OUTPUT"},
                                    {BIND_RENDER_TARGET, "RENDER_TARGET"},
                                    {BIND_DEPTH_STENCIL, "DEPTH_STENCIL"},
                                    {BIND_UNORDERED_ACCESS, "UNORDERED_ACCESS"},
                                    {BIND_INDIRECT_DRAW_ARGS,
                                     "INDIRECT_DRAW_ARGS"},
                                    {BIND_INPUT_ATTACHMENT, "INPUT_ATTACHMENT"},
                                    {BIND_RAY_TRACING, "RAY_TRACING"},
                                    {BIND_SHADING_RATE, "SHADING_RATE"},
                                    {BIND_FLAG_LAST, "FLAG_LAST"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(CPU_ACCESS_FLAGS,
                                {
                                    {CPU_ACCESS_NONE, "NONE"},
                                    {CPU_ACCESS_READ, "READ"},
                                    {CPU_ACCESS_WRITE, "WRITE"},
                                    {CPU_ACCESS_FLAG_LAST, "FLAG_LAST"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    TEXTURE_FORMAT,
    {
        {TEX_FORMAT_UNKNOWN, "UNKNOWN"},
        {TEX_FORMAT_RGBA32_TYPELESS, "RGBA32_TYPELESS"},
        {TEX_FORMAT_RGBA32_FLOAT, "RGBA32_FLOAT"},
        {TEX_FORMAT_RGBA32_UINT, "RGBA32_UINT"},
        {TEX_FORMAT_RGBA32_SINT, "RGBA32_SINT"},
        {TEX_FORMAT_RGB32_TYPELESS, "RGB32_TYPELESS"},
        {TEX_FORMAT_RGB32_FLOAT, "RGB32_FLOAT"},
        {TEX_FORMAT_RGB32_UINT, "RGB32_UINT"},
        {TEX_FORMAT_RGB32_SINT, "RGB32_SINT"},
        {TEX_FORMAT_RGBA16_TYPELESS, "RGBA16_TYPELESS"},
        {TEX_FORMAT_RGBA16_FLOAT, "RGBA16_FLOAT"},
        {TEX_FORMAT_RGBA16_UNORM, "RGBA16_UNORM"},
        {TEX_FORMAT_RGBA16_UINT, "RGBA16_UINT"},
        {TEX_FORMAT_RGBA16_SNORM, "RGBA16_SNORM"},
        {TEX_FORMAT_RGBA16_SINT, "RGBA16_SINT"},
        {TEX_FORMAT_RG32_TYPELESS, "RG32_TYPELESS"},
        {TEX_FORMAT_RG32_FLOAT, "RG32_FLOAT"},
        {TEX_FORMAT_RG32_UINT, "RG32_UINT"},
        {TEX_FORMAT_RG32_SINT, "RG32_SINT"},
        {TEX_FORMAT_R32G8X24_TYPELESS, "R32G8X24_TYPELESS"},
        {TEX_FORMAT_D32_FLOAT_S8X24_UINT, "D32_FLOAT_S8X24_UINT"},
        {TEX_FORMAT_R32_FLOAT_X8X24_TYPELESS, "R32_FLOAT_X8X24_TYPELESS"},
        {TEX_FORMAT_X32_TYPELESS_G8X24_UINT, "X32_TYPELESS_G8X24_UINT"},
        {TEX_FORMAT_RGB10A2_TYPELESS, "RGB10A2_TYPELESS"},
        {TEX_FORMAT_RGB10A2_UNORM, "RGB10A2_UNORM"},
        {TEX_FORMAT_RGB10A2_UINT, "RGB10A2_UINT"},
        {TEX_FORMAT_R11G11B10_FLOAT, "R11G11B10_FLOAT"},
        {TEX_FORMAT_RGBA8_TYPELESS, "RGBA8_TYPELESS"},
        {TEX_FORMAT_RGBA8_UNORM, "RGBA8_UNORM"},
        {TEX_FORMAT_RGBA8_UNORM_SRGB, "RGBA8_UNORM_SRGB"},
        {TEX_FORMAT_RGBA8_UINT, "RGBA8_UINT"},
        {TEX_FORMAT_RGBA8_SNORM, "RGBA8_SNORM"},
        {TEX_FORMAT_RGBA8_SINT, "RGBA8_SINT"},
        {TEX_FORMAT_RG16_TYPELESS, "RG16_TYPELESS"},
        {TEX_FORMAT_RG16_FLOAT, "RG16_FLOAT"},
        {TEX_FORMAT_RG16_UNORM, "RG16_UNORM"},
        {TEX_FORMAT_RG16_UINT, "RG16_UINT"},
        {TEX_FORMAT_RG16_SNORM, "RG16_SNORM"},
        {TEX_FORMAT_RG16_SINT, "RG16_SINT"},
        {TEX_FORMAT_R32_TYPELESS, "R32_TYPELESS"},
        {TEX_FORMAT_D32_FLOAT, "D32_FLOAT"},
        {TEX_FORMAT_R32_FLOAT, "R32_FLOAT"},
        {TEX_FORMAT_R32_UINT, "R32_UINT"},
        {TEX_FORMAT_R32_SINT, "R32_SINT"},
        {TEX_FORMAT_R24G8_TYPELESS, "R24G8_TYPELESS"},
        {TEX_FORMAT_D24_UNORM_S8_UINT, "D24_UNORM_S8_UINT"},
        {TEX_FORMAT_R24_UNORM_X8_TYPELESS, "R24_UNORM_X8_TYPELESS"},
        {TEX_FORMAT_X24_TYPELESS_G8_UINT, "X24_TYPELESS_G8_UINT"},
        {TEX_FORMAT_RG8_TYPELESS, "RG8_TYPELESS"},
        {TEX_FORMAT_RG8_UNORM, "RG8_UNORM"},
        {TEX_FORMAT_RG8_UINT, "RG8_UINT"},
        {TEX_FORMAT_RG8_SNORM, "RG8_SNORM"},
        {TEX_FORMAT_RG8_SINT, "RG8_SINT"},
        {TEX_FORMAT_R16_TYPELESS, "R16_TYPELESS"},
        {TEX_FORMAT_R16_FLOAT, "R16_FLOAT"},
        {TEX_FORMAT_D16_UNORM, "D16_UNORM"},
        {TEX_FORMAT_R16_UNORM, "R16_UNORM"},
        {TEX_FORMAT_R16_UINT, "R16_UINT"},
        {TEX_FORMAT_R16_SNORM, "R16_SNORM"},
        {TEX_FORMAT_R16_SINT, "R16_SINT"},
        {TEX_FORMAT_R8_TYPELESS, "R8_TYPELESS"},
        {TEX_FORMAT_R8_UNORM, "R8_UNORM"},
        {TEX_FORMAT_R8_UINT, "R8_UINT"},
        {TEX_FORMAT_R8_SNORM, "R8_SNORM"},
        {TEX_FORMAT_R8_SINT, "R8_SINT"},
        {TEX_FORMAT_A8_UNORM, "A8_UNORM"},
        {TEX_FORMAT_R1_UNORM, "R1_UNORM"},
        {TEX_FORMAT_RGB9E5_SHAREDEXP, "RGB9E5_SHAREDEXP"},
        {TEX_FORMAT_RG8_B8G8_UNORM, "RG8_B8G8_UNORM"},
        {TEX_FORMAT_G8R8_G8B8_UNORM, "G8R8_G8B8_UNORM"},
        {TEX_FORMAT_BC1_TYPELESS, "BC1_TYPELESS"},
        {TEX_FORMAT_BC1_UNORM, "BC1_UNORM"},
        {TEX_FORMAT_BC1_UNORM_SRGB, "BC1_UNORM_SRGB"},
        {TEX_FORMAT_BC2_TYPELESS, "BC2_TYPELESS"},
        {TEX_FORMAT_BC2_UNORM, "BC2_UNORM"},
        {TEX_FORMAT_BC2_UNORM_SRGB, "BC2_UNORM_SRGB"},
        {TEX_FORMAT_BC3_TYPELESS, "BC3_TYPELESS"},
        {TEX_FORMAT_BC3_UNORM, "BC3_UNORM"},
        {TEX_FORMAT_BC3_UNORM_SRGB, "BC3_UNORM_SRGB"},
        {TEX_FORMAT_BC4_TYPELESS, "BC4_TYPELESS"},
        {TEX_FORMAT_BC4_UNORM, "BC4_UNORM"},
        {TEX_FORMAT_BC4_SNORM, "BC4_SNORM"},
        {TEX_FORMAT_BC5_TYPELESS, "BC5_TYPELESS"},
        {TEX_FORMAT_BC5_UNORM, "BC5_UNORM"},
        {TEX_FORMAT_BC5_SNORM, "BC5_SNORM"},
        {TEX_FORMAT_B5G6R5_UNORM, "B5G6R5_UNORM"},
        {TEX_FORMAT_B5G5R5A1_UNORM, "B5G5R5A1_UNORM"},
        {TEX_FORMAT_BGRA8_UNORM, "BGRA8_UNORM"},
        {TEX_FORMAT_BGRX8_UNORM, "BGRX8_UNORM"},
        {TEX_FORMAT_R10G10B10_XR_BIAS_A2_UNORM, "R10G10B10_XR_BIAS_A2_UNORM"},
        {TEX_FORMAT_BGRA8_TYPELESS, "BGRA8_TYPELESS"},
        {TEX_FORMAT_BGRA8_UNORM_SRGB, "BGRA8_UNORM_SRGB"},
        {TEX_FORMAT_BGRX8_TYPELESS, "BGRX8_TYPELESS"},
        {TEX_FORMAT_BGRX8_UNORM_SRGB, "BGRX8_UNORM_SRGB"},
        {TEX_FORMAT_BC6H_TYPELESS, "BC6H_TYPELESS"},
        {TEX_FORMAT_BC6H_UF16, "BC6H_UF16"},
        {TEX_FORMAT_BC6H_SF16, "BC6H_SF16"},
        {TEX_FORMAT_BC7_TYPELESS, "BC7_TYPELESS"},
        {TEX_FORMAT_BC7_UNORM, "BC7_UNORM"},
        {TEX_FORMAT_BC7_UNORM_SRGB, "BC7_UNORM_SRGB"},
        {TEX_FORMAT_NUM_FORMATS, "NUM_FORMATS"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    FILTER_TYPE,
    {
        {FILTER_TYPE_UNKNOWN, "UNKNOWN"},
        {FILTER_TYPE_POINT, "POINT"},
        {FILTER_TYPE_LINEAR, "LINEAR"},
        {FILTER_TYPE_ANISOTROPIC, "ANISOTROPIC"},
        {FILTER_TYPE_COMPARISON_POINT, "COMPARISON_POINT"},
        {FILTER_TYPE_COMPARISON_LINEAR, "COMPARISON_LINEAR"},
        {FILTER_TYPE_COMPARISON_ANISOTROPIC, "COMPARISON_ANISOTROPIC"},
        {FILTER_TYPE_MINIMUM_POINT, "MINIMUM_POINT"},
        {FILTER_TYPE_MINIMUM_LINEAR, "MINIMUM_LINEAR"},
        {FILTER_TYPE_MINIMUM_ANISOTROPIC, "MINIMUM_ANISOTROPIC"},
        {FILTER_TYPE_MAXIMUM_POINT, "MAXIMUM_POINT"},
        {FILTER_TYPE_MAXIMUM_LINEAR, "MAXIMUM_LINEAR"},
        {FILTER_TYPE_MAXIMUM_ANISOTROPIC, "MAXIMUM_ANISOTROPIC"},
        {FILTER_TYPE_NUM_FILTERS, "NUM_FILTERS"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(TEXTURE_ADDRESS_MODE,
                                {
                                    {TEXTURE_ADDRESS_UNKNOWN, "UNKNOWN"},
                                    {TEXTURE_ADDRESS_WRAP, "WRAP"},
                                    {TEXTURE_ADDRESS_MIRROR, "MIRROR"},
                                    {TEXTURE_ADDRESS_CLAMP, "CLAMP"},
                                    {TEXTURE_ADDRESS_BORDER, "BORDER"},
                                    {TEXTURE_ADDRESS_MIRROR_ONCE,
                                     "MIRROR_ONCE"},
                                    {TEXTURE_ADDRESS_NUM_MODES, "NUM_MODES"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    COMPARISON_FUNCTION, {
                             {COMPARISON_FUNC_UNKNOWN, "UNKNOWN"},
                             {COMPARISON_FUNC_NEVER, "NEVER"},
                             {COMPARISON_FUNC_LESS, "LESS"},
                             {COMPARISON_FUNC_EQUAL, "EQUAL"},
                             {COMPARISON_FUNC_LESS_EQUAL, "LESS_EQUAL"},
                             {COMPARISON_FUNC_GREATER, "GREATER"},
                             {COMPARISON_FUNC_NOT_EQUAL, "NOT_EQUAL"},
                             {COMPARISON_FUNC_GREATER_EQUAL, "GREATER_EQUAL"},
                             {COMPARISON_FUNC_ALWAYS, "ALWAYS"},
                             {COMPARISON_FUNC_NUM_FUNCTIONS, "NUM_FUNCTIONS"},
                         })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    PRIMITIVE_TOPOLOGY,
    {
        {PRIMITIVE_TOPOLOGY_UNDEFINED, "UNDEFINED"},
        {PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, "TRIANGLE_LIST"},
        {PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP, "TRIANGLE_STRIP"},
        {PRIMITIVE_TOPOLOGY_POINT_LIST, "POINT_LIST"},
        {PRIMITIVE_TOPOLOGY_LINE_LIST, "LINE_LIST"},
        {PRIMITIVE_TOPOLOGY_LINE_STRIP, "LINE_STRIP"},
        {PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_ADJ, "TRIANGLE_LIST_ADJ"},
        {PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_ADJ, "TRIANGLE_STRIP_ADJ"},
        {PRIMITIVE_TOPOLOGY_LINE_LIST_ADJ, "LINE_LIST_ADJ"},
        {PRIMITIVE_TOPOLOGY_LINE_STRIP_ADJ, "LINE_STRIP_ADJ"},
        {PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST,
         "1_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST,
         "2_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST,
         "3_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST,
         "4_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST,
         "5_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST,
         "6_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST,
         "7_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST,
         "8_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST,
         "9_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST,
         "10_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST,
         "11_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST,
         "12_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST,
         "13_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST,
         "14_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST,
         "15_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST,
         "16_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST,
         "17_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST,
         "18_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST,
         "19_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST,
         "20_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST,
         "21_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST,
         "22_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST,
         "23_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST,
         "24_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST,
         "25_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST,
         "26_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST,
         "27_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST,
         "28_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST,
         "29_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST,
         "30_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST,
         "31_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST,
         "32_CONTROL_POINT_PATCHLIST"},
        {PRIMITIVE_TOPOLOGY_NUM_TOPOLOGIES, "NUM_TOPOLOGIES"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(ADAPTER_TYPE,
                                {
                                    {ADAPTER_TYPE_UNKNOWN, "UNKNOWN"},
                                    {ADAPTER_TYPE_SOFTWARE, "SOFTWARE"},
                                    {ADAPTER_TYPE_INTEGRATED, "INTEGRATED"},
                                    {ADAPTER_TYPE_DISCRETE, "DISCRETE"},
                                    {ADAPTER_TYPE_COUNT, "COUNT"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(RENDER_DEVICE_TYPE,
                                {
                                    {RENDER_DEVICE_TYPE_UNDEFINED, "UNDEFINED"},
                                    {RENDER_DEVICE_TYPE_D3D11, "D3D11"},
                                    {RENDER_DEVICE_TYPE_D3D12, "D3D12"},
                                    {RENDER_DEVICE_TYPE_GL, "GL"},
                                    {RENDER_DEVICE_TYPE_GLES, "GLES"},
                                    {RENDER_DEVICE_TYPE_VULKAN, "VULKAN"},
                                    {RENDER_DEVICE_TYPE_METAL, "METAL"},
                                    {RENDER_DEVICE_TYPE_COUNT, "COUNT"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(DEVICE_FEATURE_STATE,
                                {
                                    {DEVICE_FEATURE_STATE_DISABLED, "DISABLED"},
                                    {DEVICE_FEATURE_STATE_ENABLED, "ENABLED"},
                                    {DEVICE_FEATURE_STATE_OPTIONAL, "OPTIONAL"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(ADAPTER_VENDOR,
                                {
                                    {ADAPTER_VENDOR_UNKNOWN, "UNKNOWN"},
                                    {ADAPTER_VENDOR_NVIDIA, "NVIDIA"},
                                    {ADAPTER_VENDOR_AMD, "AMD"},
                                    {ADAPTER_VENDOR_INTEL, "INTEL"},
                                    {ADAPTER_VENDOR_ARM, "ARM"},
                                    {ADAPTER_VENDOR_QUALCOMM, "QUALCOMM"},
                                    {ADAPTER_VENDOR_IMGTECH, "IMGTECH"},
                                    {ADAPTER_VENDOR_MSFT, "MSFT"},
                                    {ADAPTER_VENDOR_APPLE, "APPLE"},
                                    {ADAPTER_VENDOR_MESA, "MESA"},
                                    {ADAPTER_VENDOR_BROADCOM, "BROADCOM"},
                                    {ADAPTER_VENDOR_LAST, "LAST"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(WAVE_FEATURE,
                                {
                                    {WAVE_FEATURE_UNKNOWN, "UNKNOWN"},
                                    {WAVE_FEATURE_BASIC, "BASIC"},
                                    {WAVE_FEATURE_VOTE, "VOTE"},
                                    {WAVE_FEATURE_ARITHMETIC, "ARITHMETIC"},
                                    {WAVE_FEATURE_BALLOUT, "BALLOUT"},
                                    {WAVE_FEATURE_SHUFFLE, "SHUFFLE"},
                                    {WAVE_FEATURE_SHUFFLE_RELATIVE,
                                     "SHUFFLE_RELATIVE"},
                                    {WAVE_FEATURE_CLUSTERED, "CLUSTERED"},
                                    {WAVE_FEATURE_QUAD, "QUAD"},
                                    {WAVE_FEATURE_LAST, "LAST"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    RAY_TRACING_CAP_FLAGS,
    {
        {RAY_TRACING_CAP_FLAG_NONE, "NONE"},
        {RAY_TRACING_CAP_FLAG_STANDALONE_SHADERS, "STANDALONE_SHADERS"},
        {RAY_TRACING_CAP_FLAG_INLINE_RAY_TRACING, "INLINE_RAY_TRACING"},
        {RAY_TRACING_CAP_FLAG_INDIRECT_RAY_TRACING, "INDIRECT_RAY_TRACING"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    COMMAND_QUEUE_TYPE,
    {
        {COMMAND_QUEUE_TYPE_UNKNOWN, "UNKNOWN"},
        {COMMAND_QUEUE_TYPE_TRANSFER, "TRANSFER"},
        {COMMAND_QUEUE_TYPE_COMPUTE, "COMPUTE"},
        {COMMAND_QUEUE_TYPE_GRAPHICS, "GRAPHICS"},
        {COMMAND_QUEUE_TYPE_PRIMARY_MASK, "PRIMARY_MASK"},
        {COMMAND_QUEUE_TYPE_SPARSE_BINDING, "SPARSE_BINDING"},
        {COMMAND_QUEUE_TYPE_MAX_BIT, "MAX_BIT"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SHADING_RATE_COMBINER,
    {
        {SHADING_RATE_COMBINER_PASSTHROUGH, "PASSTHROUGH"},
        {SHADING_RATE_COMBINER_OVERRIDE, "OVERRIDE"},
        {SHADING_RATE_COMBINER_MIN, "MIN"},
        {SHADING_RATE_COMBINER_MAX, "MAX"},
        {SHADING_RATE_COMBINER_SUM, "SUM"},
        {SHADING_RATE_COMBINER_MUL, "MUL"},
        {SHADING_RATE_COMBINER_LAST, "LAST"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(SHADING_RATE_FORMAT,
                                {
                                    {SHADING_RATE_FORMAT_UNKNOWN, "UNKNOWN"},
                                    {SHADING_RATE_FORMAT_PALETTE, "PALETTE"},
                                    {SHADING_RATE_FORMAT_UNORM8, "UNORM8"},
                                    {SHADING_RATE_FORMAT_COL_ROW_FP32,
                                     "COL_ROW_FP32"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(SHADING_RATE, {
                                                  {SHADING_RATE_1X1, "1X1"},
                                                  {SHADING_RATE_1X2, "1X2"},
                                                  {SHADING_RATE_1X4, "1X4"},
                                                  {SHADING_RATE_2X1, "2X1"},
                                                  {SHADING_RATE_2X2, "2X2"},
                                                  {SHADING_RATE_2X4, "2X4"},
                                                  {SHADING_RATE_4X1, "4X1"},
                                                  {SHADING_RATE_4X2, "4X2"},
                                                  {SHADING_RATE_4X4, "4X4"},
                                                  {SHADING_RATE_MAX, "MAX"},
                                              })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(SAMPLE_COUNT, {
                                                  {SAMPLE_COUNT_NONE, "NONE"},
                                                  {SAMPLE_COUNT_1, "1"},
                                                  {SAMPLE_COUNT_2, "2"},
                                                  {SAMPLE_COUNT_4, "4"},
                                                  {SAMPLE_COUNT_8, "8"},
                                                  {SAMPLE_COUNT_16, "16"},
                                                  {SAMPLE_COUNT_32, "32"},
                                                  {SAMPLE_COUNT_64, "64"},
                                                  {SAMPLE_COUNT_MAX, "MAX"},
                                                  {SAMPLE_COUNT_ALL, "ALL"},
                                              })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SHADING_RATE_CAP_FLAGS,
    {
        {SHADING_RATE_CAP_FLAG_NONE, "NONE"},
        {SHADING_RATE_CAP_FLAG_PER_DRAW, "PER_DRAW"},
        {SHADING_RATE_CAP_FLAG_PER_PRIMITIVE, "PER_PRIMITIVE"},
        {SHADING_RATE_CAP_FLAG_TEXTURE_BASED, "TEXTURE_BASED"},
        {SHADING_RATE_CAP_FLAG_SAMPLE_MASK, "SAMPLE_MASK"},
        {SHADING_RATE_CAP_FLAG_SHADER_SAMPLE_MASK, "SHADER_SAMPLE_MASK"},
        {SHADING_RATE_CAP_FLAG_SHADER_DEPTH_STENCIL_WRITE,
         "SHADER_DEPTH_STENCIL_WRITE"},
        {SHADING_RATE_CAP_FLAG_PER_PRIMITIVE_WITH_MULTIPLE_VIEWPORTS,
         "PER_PRIMITIVE_WITH_MULTIPLE_VIEWPORTS"},
        {SHADING_RATE_CAP_FLAG_SAME_TEXTURE_FOR_WHOLE_RENDERPASS,
         "SAME_TEXTURE_FOR_WHOLE_RENDERPASS"},
        {SHADING_RATE_CAP_FLAG_TEXTURE_ARRAY, "TEXTURE_ARRAY"},
        {SHADING_RATE_CAP_FLAG_SHADING_RATE_SHADER_INPUT,
         "SHADING_RATE_SHADER_INPUT"},
        {SHADING_RATE_CAP_FLAG_ADDITIONAL_INVOCATIONS,
         "ADDITIONAL_INVOCATIONS"},
        {SHADING_RATE_CAP_FLAG_NON_SUBSAMPLED_RENDER_TARGET,
         "NON_SUBSAMPLED_RENDER_TARGET"},
        {SHADING_RATE_CAP_FLAG_SUBSAMPLED_RENDER_TARGET,
         "SUBSAMPLED_RENDER_TARGET"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SHADING_RATE_TEXTURE_ACCESS,
    {
        {SHADING_RATE_TEXTURE_ACCESS_UNKNOWN, "UNKNOWN"},
        {SHADING_RATE_TEXTURE_ACCESS_ON_GPU, "ON_GPU"},
        {SHADING_RATE_TEXTURE_ACCESS_ON_SUBMIT, "ON_SUBMIT"},
        {SHADING_RATE_TEXTURE_ACCESS_ON_SET_RTV, "ON_SET_RTV"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    DRAW_COMMAND_CAP_FLAGS,
    {
        {DRAW_COMMAND_CAP_FLAG_NONE, "NONE"},
        {DRAW_COMMAND_CAP_FLAG_BASE_VERTEX, "BASE_VERTEX"},
        {DRAW_COMMAND_CAP_FLAG_DRAW_INDIRECT, "DRAW_INDIRECT"},
        {DRAW_COMMAND_CAP_FLAG_DRAW_INDIRECT_FIRST_INSTANCE,
         "DRAW_INDIRECT_FIRST_INSTANCE"},
        {DRAW_COMMAND_CAP_FLAG_NATIVE_MULTI_DRAW_INDIRECT,
         "NATIVE_MULTI_DRAW_INDIRECT"},
        {DRAW_COMMAND_CAP_FLAG_DRAW_INDIRECT_COUNTER_BUFFER,
         "DRAW_INDIRECT_COUNTER_BUFFER"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SPARSE_RESOURCE_CAP_FLAGS,
    {
        {SPARSE_RESOURCE_CAP_FLAG_NONE, "NONE"},
        {SPARSE_RESOURCE_CAP_FLAG_SHADER_RESOURCE_RESIDENCY,
         "SHADER_RESOURCE_RESIDENCY"},
        {SPARSE_RESOURCE_CAP_FLAG_BUFFER, "BUFFER"},
        {SPARSE_RESOURCE_CAP_FLAG_TEXTURE_2D, "TEXTURE_2D"},
        {SPARSE_RESOURCE_CAP_FLAG_TEXTURE_3D, "TEXTURE_3D"},
        {SPARSE_RESOURCE_CAP_FLAG_TEXTURE_2_SAMPLES, "TEXTURE_2_SAMPLES"},
        {SPARSE_RESOURCE_CAP_FLAG_TEXTURE_4_SAMPLES, "TEXTURE_4_SAMPLES"},
        {SPARSE_RESOURCE_CAP_FLAG_TEXTURE_8_SAMPLES, "TEXTURE_8_SAMPLES"},
        {SPARSE_RESOURCE_CAP_FLAG_TEXTURE_16_SAMPLES, "TEXTURE_16_SAMPLES"},
        {SPARSE_RESOURCE_CAP_FLAG_ALIASED, "ALIASED"},
        {SPARSE_RESOURCE_CAP_FLAG_STANDARD_2D_TILE_SHAPE,
         "STANDARD_2D_TILE_SHAPE"},
        {SPARSE_RESOURCE_CAP_FLAG_STANDARD_2DMS_TILE_SHAPE,
         "STANDARD_2DMS_TILE_SHAPE"},
        {SPARSE_RESOURCE_CAP_FLAG_STANDARD_3D_TILE_SHAPE,
         "STANDARD_3D_TILE_SHAPE"},
        {SPARSE_RESOURCE_CAP_FLAG_ALIGNED_MIP_SIZE, "ALIGNED_MIP_SIZE"},
        {SPARSE_RESOURCE_CAP_FLAG_NON_RESIDENT_STRICT, "NON_RESIDENT_STRICT"},
        {SPARSE_RESOURCE_CAP_FLAG_TEXTURE_2D_ARRAY_MIP_TAIL,
         "TEXTURE_2D_ARRAY_MIP_TAIL"},
        {SPARSE_RESOURCE_CAP_FLAG_BUFFER_STANDARD_BLOCK,
         "BUFFER_STANDARD_BLOCK"},
        {SPARSE_RESOURCE_CAP_FLAG_NON_RESIDENT_SAFE, "NON_RESIDENT_SAFE"},
        {SPARSE_RESOURCE_CAP_FLAG_MIXED_RESOURCE_TYPE_SUPPORT,
         "MIXED_RESOURCE_TYPE_SUPPORT"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    PIPELINE_STAGE_FLAGS,
    {
        {PIPELINE_STAGE_FLAG_UNDEFINED, "UNDEFINED"},
        {PIPELINE_STAGE_FLAG_TOP_OF_PIPE, "TOP_OF_PIPE"},
        {PIPELINE_STAGE_FLAG_DRAW_INDIRECT, "DRAW_INDIRECT"},
        {PIPELINE_STAGE_FLAG_VERTEX_INPUT, "VERTEX_INPUT"},
        {PIPELINE_STAGE_FLAG_VERTEX_SHADER, "VERTEX_SHADER"},
        {PIPELINE_STAGE_FLAG_HULL_SHADER, "HULL_SHADER"},
        {PIPELINE_STAGE_FLAG_DOMAIN_SHADER, "DOMAIN_SHADER"},
        {PIPELINE_STAGE_FLAG_GEOMETRY_SHADER, "GEOMETRY_SHADER"},
        {PIPELINE_STAGE_FLAG_PIXEL_SHADER, "PIXEL_SHADER"},
        {PIPELINE_STAGE_FLAG_EARLY_FRAGMENT_TESTS, "EARLY_FRAGMENT_TESTS"},
        {PIPELINE_STAGE_FLAG_LATE_FRAGMENT_TESTS, "LATE_FRAGMENT_TESTS"},
        {PIPELINE_STAGE_FLAG_RENDER_TARGET, "RENDER_TARGET"},
        {PIPELINE_STAGE_FLAG_COMPUTE_SHADER, "COMPUTE_SHADER"},
        {PIPELINE_STAGE_FLAG_TRANSFER, "TRANSFER"},
        {PIPELINE_STAGE_FLAG_BOTTOM_OF_PIPE, "BOTTOM_OF_PIPE"},
        {PIPELINE_STAGE_FLAG_HOST, "HOST"},
        {PIPELINE_STAGE_FLAG_CONDITIONAL_RENDERING, "CONDITIONAL_RENDERING"},
        {PIPELINE_STAGE_FLAG_SHADING_RATE_TEXTURE, "SHADING_RATE_TEXTURE"},
        {PIPELINE_STAGE_FLAG_RAY_TRACING_SHADER, "RAY_TRACING_SHADER"},
        {PIPELINE_STAGE_FLAG_ACCELERATION_STRUCTURE_BUILD,
         "ACCELERATION_STRUCTURE_BUILD"},
        {PIPELINE_STAGE_FLAG_TASK_SHADER, "TASK_SHADER"},
        {PIPELINE_STAGE_FLAG_MESH_SHADER, "MESH_SHADER"},
        {PIPELINE_STAGE_FLAG_FRAGMENT_DENSITY_PROCESS,
         "FRAGMENT_DENSITY_PROCESS"},
        {PIPELINE_STAGE_FLAG_DEFAULT, "DEFAULT"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    ACCESS_FLAGS,
    {
        {ACCESS_FLAG_NONE, "NONE"},
        {ACCESS_FLAG_INDIRECT_COMMAND_READ, "INDIRECT_COMMAND_READ"},
        {ACCESS_FLAG_INDEX_READ, "INDEX_READ"},
        {ACCESS_FLAG_VERTEX_READ, "VERTEX_READ"},
        {ACCESS_FLAG_UNIFORM_READ, "UNIFORM_READ"},
        {ACCESS_FLAG_INPUT_ATTACHMENT_READ, "INPUT_ATTACHMENT_READ"},
        {ACCESS_FLAG_SHADER_READ, "SHADER_READ"},
        {ACCESS_FLAG_SHADER_WRITE, "SHADER_WRITE"},
        {ACCESS_FLAG_RENDER_TARGET_READ, "RENDER_TARGET_READ"},
        {ACCESS_FLAG_RENDER_TARGET_WRITE, "RENDER_TARGET_WRITE"},
        {ACCESS_FLAG_DEPTH_STENCIL_READ, "DEPTH_STENCIL_READ"},
        {ACCESS_FLAG_DEPTH_STENCIL_WRITE, "DEPTH_STENCIL_WRITE"},
        {ACCESS_FLAG_COPY_SRC, "COPY_SRC"},
        {ACCESS_FLAG_COPY_DST, "COPY_DST"},
        {ACCESS_FLAG_HOST_READ, "HOST_READ"},
        {ACCESS_FLAG_HOST_WRITE, "HOST_WRITE"},
        {ACCESS_FLAG_MEMORY_READ, "MEMORY_READ"},
        {ACCESS_FLAG_MEMORY_WRITE, "MEMORY_WRITE"},
        {ACCESS_FLAG_CONDITIONAL_RENDERING_READ, "CONDITIONAL_RENDERING_READ"},
        {ACCESS_FLAG_SHADING_RATE_TEXTURE_READ, "SHADING_RATE_TEXTURE_READ"},
        {ACCESS_FLAG_ACCELERATION_STRUCTURE_READ,
         "ACCELERATION_STRUCTURE_READ"},
        {ACCESS_FLAG_ACCELERATION_STRUCTURE_WRITE,
         "ACCELERATION_STRUCTURE_WRITE"},
        {ACCESS_FLAG_FRAGMENT_DENSITY_MAP_READ, "FRAGMENT_DENSITY_MAP_READ"},
        {ACCESS_FLAG_DEFAULT, "DEFAULT"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    RESOURCE_STATE, {
                        {RESOURCE_STATE_UNKNOWN, "UNKNOWN"},
                        {RESOURCE_STATE_UNDEFINED, "UNDEFINED"},
                        {RESOURCE_STATE_VERTEX_BUFFER, "VERTEX_BUFFER"},
                        {RESOURCE_STATE_CONSTANT_BUFFER, "CONSTANT_BUFFER"},
                        {RESOURCE_STATE_INDEX_BUFFER, "INDEX_BUFFER"},
                        {RESOURCE_STATE_RENDER_TARGET, "RENDER_TARGET"},
                        {RESOURCE_STATE_UNORDERED_ACCESS, "UNORDERED_ACCESS"},
                        {RESOURCE_STATE_DEPTH_WRITE, "DEPTH_WRITE"},
                        {RESOURCE_STATE_DEPTH_READ, "DEPTH_READ"},
                        {RESOURCE_STATE_SHADER_RESOURCE, "SHADER_RESOURCE"},
                        {RESOURCE_STATE_STREAM_OUT, "STREAM_OUT"},
                        {RESOURCE_STATE_INDIRECT_ARGUMENT, "INDIRECT_ARGUMENT"},
                        {RESOURCE_STATE_COPY_DEST, "COPY_DEST"},
                        {RESOURCE_STATE_COPY_SOURCE, "COPY_SOURCE"},
                        {RESOURCE_STATE_RESOLVE_DEST, "RESOLVE_DEST"},
                        {RESOURCE_STATE_RESOLVE_SOURCE, "RESOLVE_SOURCE"},
                        {RESOURCE_STATE_INPUT_ATTACHMENT, "INPUT_ATTACHMENT"},
                        {RESOURCE_STATE_PRESENT, "PRESENT"},
                        {RESOURCE_STATE_BUILD_AS_READ, "BUILD_AS_READ"},
                        {RESOURCE_STATE_BUILD_AS_WRITE, "BUILD_AS_WRITE"},
                        {RESOURCE_STATE_RAY_TRACING, "RAY_TRACING"},
                        {RESOURCE_STATE_COMMON, "COMMON"},
                        {RESOURCE_STATE_SHADING_RATE, "SHADING_RATE"},
                        {RESOURCE_STATE_MAX_BIT, "MAX_BIT"},
                        {RESOURCE_STATE_GENERIC_READ, "GENERIC_READ"},
                    })

inline void WriteRSN(nlohmann::json &Json, const DeviceFeatures &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.SeparablePrograms == DeviceFeatures{}.SeparablePrograms))
    WriteRSN(Json["SeparablePrograms"], Type.SeparablePrograms, Allocator);

  if (!(Type.ShaderResourceQueries == DeviceFeatures{}.ShaderResourceQueries))
    WriteRSN(Json["ShaderResourceQueries"], Type.ShaderResourceQueries,
             Allocator);

  if (!(Type.WireframeFill == DeviceFeatures{}.WireframeFill))
    WriteRSN(Json["WireframeFill"], Type.WireframeFill, Allocator);

  if (!(Type.MultithreadedResourceCreation ==
        DeviceFeatures{}.MultithreadedResourceCreation))
    WriteRSN(Json["MultithreadedResourceCreation"],
             Type.MultithreadedResourceCreation, Allocator);

  if (!(Type.ComputeShaders == DeviceFeatures{}.ComputeShaders))
    WriteRSN(Json["ComputeShaders"], Type.ComputeShaders, Allocator);

  if (!(Type.GeometryShaders == DeviceFeatures{}.GeometryShaders))
    WriteRSN(Json["GeometryShaders"], Type.GeometryShaders, Allocator);

  if (!(Type.Tessellation == DeviceFeatures{}.Tessellation))
    WriteRSN(Json["Tessellation"], Type.Tessellation, Allocator);

  if (!(Type.MeshShaders == DeviceFeatures{}.MeshShaders))
    WriteRSN(Json["MeshShaders"], Type.MeshShaders, Allocator);

  if (!(Type.RayTracing == DeviceFeatures{}.RayTracing))
    WriteRSN(Json["RayTracing"], Type.RayTracing, Allocator);

  if (!(Type.BindlessResources == DeviceFeatures{}.BindlessResources))
    WriteRSN(Json["BindlessResources"], Type.BindlessResources, Allocator);

  if (!(Type.OcclusionQueries == DeviceFeatures{}.OcclusionQueries))
    WriteRSN(Json["OcclusionQueries"], Type.OcclusionQueries, Allocator);

  if (!(Type.BinaryOcclusionQueries == DeviceFeatures{}.BinaryOcclusionQueries))
    WriteRSN(Json["BinaryOcclusionQueries"], Type.BinaryOcclusionQueries,
             Allocator);

  if (!(Type.TimestampQueries == DeviceFeatures{}.TimestampQueries))
    WriteRSN(Json["TimestampQueries"], Type.TimestampQueries, Allocator);

  if (!(Type.PipelineStatisticsQueries ==
        DeviceFeatures{}.PipelineStatisticsQueries))
    WriteRSN(Json["PipelineStatisticsQueries"], Type.PipelineStatisticsQueries,
             Allocator);

  if (!(Type.DurationQueries == DeviceFeatures{}.DurationQueries))
    WriteRSN(Json["DurationQueries"], Type.DurationQueries, Allocator);

  if (!(Type.DepthBiasClamp == DeviceFeatures{}.DepthBiasClamp))
    WriteRSN(Json["DepthBiasClamp"], Type.DepthBiasClamp, Allocator);

  if (!(Type.DepthClamp == DeviceFeatures{}.DepthClamp))
    WriteRSN(Json["DepthClamp"], Type.DepthClamp, Allocator);

  if (!(Type.IndependentBlend == DeviceFeatures{}.IndependentBlend))
    WriteRSN(Json["IndependentBlend"], Type.IndependentBlend, Allocator);

  if (!(Type.DualSourceBlend == DeviceFeatures{}.DualSourceBlend))
    WriteRSN(Json["DualSourceBlend"], Type.DualSourceBlend, Allocator);

  if (!(Type.MultiViewport == DeviceFeatures{}.MultiViewport))
    WriteRSN(Json["MultiViewport"], Type.MultiViewport, Allocator);

  if (!(Type.TextureCompressionBC == DeviceFeatures{}.TextureCompressionBC))
    WriteRSN(Json["TextureCompressionBC"], Type.TextureCompressionBC,
             Allocator);

  if (!(Type.VertexPipelineUAVWritesAndAtomics ==
        DeviceFeatures{}.VertexPipelineUAVWritesAndAtomics))
    WriteRSN(Json["VertexPipelineUAVWritesAndAtomics"],
             Type.VertexPipelineUAVWritesAndAtomics, Allocator);

  if (!(Type.PixelUAVWritesAndAtomics ==
        DeviceFeatures{}.PixelUAVWritesAndAtomics))
    WriteRSN(Json["PixelUAVWritesAndAtomics"], Type.PixelUAVWritesAndAtomics,
             Allocator);

  if (!(Type.TextureUAVExtendedFormats ==
        DeviceFeatures{}.TextureUAVExtendedFormats))
    WriteRSN(Json["TextureUAVExtendedFormats"], Type.TextureUAVExtendedFormats,
             Allocator);

  if (!(Type.ShaderFloat16 == DeviceFeatures{}.ShaderFloat16))
    WriteRSN(Json["ShaderFloat16"], Type.ShaderFloat16, Allocator);

  if (!(Type.ResourceBuffer16BitAccess ==
        DeviceFeatures{}.ResourceBuffer16BitAccess))
    WriteRSN(Json["ResourceBuffer16BitAccess"], Type.ResourceBuffer16BitAccess,
             Allocator);

  if (!(Type.UniformBuffer16BitAccess ==
        DeviceFeatures{}.UniformBuffer16BitAccess))
    WriteRSN(Json["UniformBuffer16BitAccess"], Type.UniformBuffer16BitAccess,
             Allocator);

  if (!(Type.ShaderInputOutput16 == DeviceFeatures{}.ShaderInputOutput16))
    WriteRSN(Json["ShaderInputOutput16"], Type.ShaderInputOutput16, Allocator);

  if (!(Type.ShaderInt8 == DeviceFeatures{}.ShaderInt8))
    WriteRSN(Json["ShaderInt8"], Type.ShaderInt8, Allocator);

  if (!(Type.ResourceBuffer8BitAccess ==
        DeviceFeatures{}.ResourceBuffer8BitAccess))
    WriteRSN(Json["ResourceBuffer8BitAccess"], Type.ResourceBuffer8BitAccess,
             Allocator);

  if (!(Type.UniformBuffer8BitAccess ==
        DeviceFeatures{}.UniformBuffer8BitAccess))
    WriteRSN(Json["UniformBuffer8BitAccess"], Type.UniformBuffer8BitAccess,
             Allocator);

  if (!(Type.ShaderResourceRuntimeArray ==
        DeviceFeatures{}.ShaderResourceRuntimeArray))
    WriteRSN(Json["ShaderResourceRuntimeArray"],
             Type.ShaderResourceRuntimeArray, Allocator);

  if (!(Type.WaveOp == DeviceFeatures{}.WaveOp))
    WriteRSN(Json["WaveOp"], Type.WaveOp, Allocator);

  if (!(Type.InstanceDataStepRate == DeviceFeatures{}.InstanceDataStepRate))
    WriteRSN(Json["InstanceDataStepRate"], Type.InstanceDataStepRate,
             Allocator);

  if (!(Type.NativeFence == DeviceFeatures{}.NativeFence))
    WriteRSN(Json["NativeFence"], Type.NativeFence, Allocator);

  if (!(Type.TileShaders == DeviceFeatures{}.TileShaders))
    WriteRSN(Json["TileShaders"], Type.TileShaders, Allocator);

  if (!(Type.TransferQueueTimestampQueries ==
        DeviceFeatures{}.TransferQueueTimestampQueries))
    WriteRSN(Json["TransferQueueTimestampQueries"],
             Type.TransferQueueTimestampQueries, Allocator);

  if (!(Type.VariableRateShading == DeviceFeatures{}.VariableRateShading))
    WriteRSN(Json["VariableRateShading"], Type.VariableRateShading, Allocator);

  if (!(Type.SparseResources == DeviceFeatures{}.SparseResources))
    WriteRSN(Json["SparseResources"], Type.SparseResources, Allocator);

  if (!(Type.SubpassFramebufferFetch ==
        DeviceFeatures{}.SubpassFramebufferFetch))
    WriteRSN(Json["SubpassFramebufferFetch"], Type.SubpassFramebufferFetch,
             Allocator);

  if (!(Type.TextureComponentSwizzle ==
        DeviceFeatures{}.TextureComponentSwizzle))
    WriteRSN(Json["TextureComponentSwizzle"], Type.TextureComponentSwizzle,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, DeviceFeatures &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "SeparablePrograms",
                                        "ShaderResourceQueries",
                                        "WireframeFill",
                                        "MultithreadedResourceCreation",
                                        "ComputeShaders",
                                        "GeometryShaders",
                                        "Tessellation",
                                        "MeshShaders",
                                        "RayTracing",
                                        "BindlessResources",
                                        "OcclusionQueries",
                                        "BinaryOcclusionQueries",
                                        "TimestampQueries",
                                        "PipelineStatisticsQueries",
                                        "DurationQueries",
                                        "DepthBiasClamp",
                                        "DepthClamp",
                                        "IndependentBlend",
                                        "DualSourceBlend",
                                        "MultiViewport",
                                        "TextureCompressionBC",
                                        "VertexPipelineUAVWritesAndAtomics",
                                        "PixelUAVWritesAndAtomics",
                                        "TextureUAVExtendedFormats",
                                        "ShaderFloat16",
                                        "ResourceBuffer16BitAccess",
                                        "UniformBuffer16BitAccess",
                                        "ShaderInputOutput16",
                                        "ShaderInt8",
                                        "ResourceBuffer8BitAccess",
                                        "UniformBuffer8BitAccess",
                                        "ShaderResourceRuntimeArray",
                                        "WaveOp",
                                        "InstanceDataStepRate",
                                        "NativeFence",
                                        "TileShaders",
                                        "TransferQueueTimestampQueries",
                                        "VariableRateShading",
                                        "SparseResources",
                                        "SubpassFramebufferFetch",
                                        "TextureComponentSwizzle",
                                    });
  if (Json.contains("SeparablePrograms"))
    ParseRSN(Json["SeparablePrograms"], Type.SeparablePrograms, Allocator);

  if (Json.contains("ShaderResourceQueries"))
    ParseRSN(Json["ShaderResourceQueries"], Type.ShaderResourceQueries,
             Allocator);

  if (Json.contains("WireframeFill"))
    ParseRSN(Json["WireframeFill"], Type.WireframeFill, Allocator);

  if (Json.contains("MultithreadedResourceCreation"))
    ParseRSN(Json["MultithreadedResourceCreation"],
             Type.MultithreadedResourceCreation, Allocator);

  if (Json.contains("ComputeShaders"))
    ParseRSN(Json["ComputeShaders"], Type.ComputeShaders, Allocator);

  if (Json.contains("GeometryShaders"))
    ParseRSN(Json["GeometryShaders"], Type.GeometryShaders, Allocator);

  if (Json.contains("Tessellation"))
    ParseRSN(Json["Tessellation"], Type.Tessellation, Allocator);

  if (Json.contains("MeshShaders"))
    ParseRSN(Json["MeshShaders"], Type.MeshShaders, Allocator);

  if (Json.contains("RayTracing"))
    ParseRSN(Json["RayTracing"], Type.RayTracing, Allocator);

  if (Json.contains("BindlessResources"))
    ParseRSN(Json["BindlessResources"], Type.BindlessResources, Allocator);

  if (Json.contains("OcclusionQueries"))
    ParseRSN(Json["OcclusionQueries"], Type.OcclusionQueries, Allocator);

  if (Json.contains("BinaryOcclusionQueries"))
    ParseRSN(Json["BinaryOcclusionQueries"], Type.BinaryOcclusionQueries,
             Allocator);

  if (Json.contains("TimestampQueries"))
    ParseRSN(Json["TimestampQueries"], Type.TimestampQueries, Allocator);

  if (Json.contains("PipelineStatisticsQueries"))
    ParseRSN(Json["PipelineStatisticsQueries"], Type.PipelineStatisticsQueries,
             Allocator);

  if (Json.contains("DurationQueries"))
    ParseRSN(Json["DurationQueries"], Type.DurationQueries, Allocator);

  if (Json.contains("DepthBiasClamp"))
    ParseRSN(Json["DepthBiasClamp"], Type.DepthBiasClamp, Allocator);

  if (Json.contains("DepthClamp"))
    ParseRSN(Json["DepthClamp"], Type.DepthClamp, Allocator);

  if (Json.contains("IndependentBlend"))
    ParseRSN(Json["IndependentBlend"], Type.IndependentBlend, Allocator);

  if (Json.contains("DualSourceBlend"))
    ParseRSN(Json["DualSourceBlend"], Type.DualSourceBlend, Allocator);

  if (Json.contains("MultiViewport"))
    ParseRSN(Json["MultiViewport"], Type.MultiViewport, Allocator);

  if (Json.contains("TextureCompressionBC"))
    ParseRSN(Json["TextureCompressionBC"], Type.TextureCompressionBC,
             Allocator);

  if (Json.contains("VertexPipelineUAVWritesAndAtomics"))
    ParseRSN(Json["VertexPipelineUAVWritesAndAtomics"],
             Type.VertexPipelineUAVWritesAndAtomics, Allocator);

  if (Json.contains("PixelUAVWritesAndAtomics"))
    ParseRSN(Json["PixelUAVWritesAndAtomics"], Type.PixelUAVWritesAndAtomics,
             Allocator);

  if (Json.contains("TextureUAVExtendedFormats"))
    ParseRSN(Json["TextureUAVExtendedFormats"], Type.TextureUAVExtendedFormats,
             Allocator);

  if (Json.contains("ShaderFloat16"))
    ParseRSN(Json["ShaderFloat16"], Type.ShaderFloat16, Allocator);

  if (Json.contains("ResourceBuffer16BitAccess"))
    ParseRSN(Json["ResourceBuffer16BitAccess"], Type.ResourceBuffer16BitAccess,
             Allocator);

  if (Json.contains("UniformBuffer16BitAccess"))
    ParseRSN(Json["UniformBuffer16BitAccess"], Type.UniformBuffer16BitAccess,
             Allocator);

  if (Json.contains("ShaderInputOutput16"))
    ParseRSN(Json["ShaderInputOutput16"], Type.ShaderInputOutput16, Allocator);

  if (Json.contains("ShaderInt8"))
    ParseRSN(Json["ShaderInt8"], Type.ShaderInt8, Allocator);

  if (Json.contains("ResourceBuffer8BitAccess"))
    ParseRSN(Json["ResourceBuffer8BitAccess"], Type.ResourceBuffer8BitAccess,
             Allocator);

  if (Json.contains("UniformBuffer8BitAccess"))
    ParseRSN(Json["UniformBuffer8BitAccess"], Type.UniformBuffer8BitAccess,
             Allocator);

  if (Json.contains("ShaderResourceRuntimeArray"))
    ParseRSN(Json["ShaderResourceRuntimeArray"],
             Type.ShaderResourceRuntimeArray, Allocator);

  if (Json.contains("WaveOp"))
    ParseRSN(Json["WaveOp"], Type.WaveOp, Allocator);

  if (Json.contains("InstanceDataStepRate"))
    ParseRSN(Json["InstanceDataStepRate"], Type.InstanceDataStepRate,
             Allocator);

  if (Json.contains("NativeFence"))
    ParseRSN(Json["NativeFence"], Type.NativeFence, Allocator);

  if (Json.contains("TileShaders"))
    ParseRSN(Json["TileShaders"], Type.TileShaders, Allocator);

  if (Json.contains("TransferQueueTimestampQueries"))
    ParseRSN(Json["TransferQueueTimestampQueries"],
             Type.TransferQueueTimestampQueries, Allocator);

  if (Json.contains("VariableRateShading"))
    ParseRSN(Json["VariableRateShading"], Type.VariableRateShading, Allocator);

  if (Json.contains("SparseResources"))
    ParseRSN(Json["SparseResources"], Type.SparseResources, Allocator);

  if (Json.contains("SubpassFramebufferFetch"))
    ParseRSN(Json["SubpassFramebufferFetch"], Type.SubpassFramebufferFetch,
             Allocator);

  if (Json.contains("TextureComponentSwizzle"))
    ParseRSN(Json["TextureComponentSwizzle"], Type.TextureComponentSwizzle,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const Version &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.Major == Version{}.Major))
    WriteRSN(Json["Major"], Type.Major, Allocator);

  if (!(Type.Minor == Version{}.Minor))
    WriteRSN(Json["Minor"], Type.Minor, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, Version &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Major",
                                        "Minor",
                                    });
  if (Json.contains("Major"))
    ParseRSN(Json["Major"], Type.Major, Allocator);

  if (Json.contains("Minor"))
    ParseRSN(Json["Minor"], Type.Minor, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const TextureProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.MaxTexture1DDimension ==
        TextureProperties{}.MaxTexture1DDimension))
    WriteRSN(Json["MaxTexture1DDimension"], Type.MaxTexture1DDimension,
             Allocator);

  if (!(Type.MaxTexture1DArraySlices ==
        TextureProperties{}.MaxTexture1DArraySlices))
    WriteRSN(Json["MaxTexture1DArraySlices"], Type.MaxTexture1DArraySlices,
             Allocator);

  if (!(Type.MaxTexture2DDimension ==
        TextureProperties{}.MaxTexture2DDimension))
    WriteRSN(Json["MaxTexture2DDimension"], Type.MaxTexture2DDimension,
             Allocator);

  if (!(Type.MaxTexture2DArraySlices ==
        TextureProperties{}.MaxTexture2DArraySlices))
    WriteRSN(Json["MaxTexture2DArraySlices"], Type.MaxTexture2DArraySlices,
             Allocator);

  if (!(Type.MaxTexture3DDimension ==
        TextureProperties{}.MaxTexture3DDimension))
    WriteRSN(Json["MaxTexture3DDimension"], Type.MaxTexture3DDimension,
             Allocator);

  if (!(Type.MaxTextureCubeDimension ==
        TextureProperties{}.MaxTextureCubeDimension))
    WriteRSN(Json["MaxTextureCubeDimension"], Type.MaxTextureCubeDimension,
             Allocator);

  if (!(Type.Texture2DMSSupported == TextureProperties{}.Texture2DMSSupported))
    WriteRSN(Json["Texture2DMSSupported"], Type.Texture2DMSSupported,
             Allocator);

  if (!(Type.Texture2DMSArraySupported ==
        TextureProperties{}.Texture2DMSArraySupported))
    WriteRSN(Json["Texture2DMSArraySupported"], Type.Texture2DMSArraySupported,
             Allocator);

  if (!(Type.TextureViewSupported == TextureProperties{}.TextureViewSupported))
    WriteRSN(Json["TextureViewSupported"], Type.TextureViewSupported,
             Allocator);

  if (!(Type.CubemapArraysSupported ==
        TextureProperties{}.CubemapArraysSupported))
    WriteRSN(Json["CubemapArraysSupported"], Type.CubemapArraysSupported,
             Allocator);

  if (!(Type.TextureView2DOn3DSupported ==
        TextureProperties{}.TextureView2DOn3DSupported))
    WriteRSN(Json["TextureView2DOn3DSupported"],
             Type.TextureView2DOn3DSupported, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, TextureProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "MaxTexture1DDimension",
                                        "MaxTexture1DArraySlices",
                                        "MaxTexture2DDimension",
                                        "MaxTexture2DArraySlices",
                                        "MaxTexture3DDimension",
                                        "MaxTextureCubeDimension",
                                        "Texture2DMSSupported",
                                        "Texture2DMSArraySupported",
                                        "TextureViewSupported",
                                        "CubemapArraysSupported",
                                        "TextureView2DOn3DSupported",
                                    });
  if (Json.contains("MaxTexture1DDimension"))
    ParseRSN(Json["MaxTexture1DDimension"], Type.MaxTexture1DDimension,
             Allocator);

  if (Json.contains("MaxTexture1DArraySlices"))
    ParseRSN(Json["MaxTexture1DArraySlices"], Type.MaxTexture1DArraySlices,
             Allocator);

  if (Json.contains("MaxTexture2DDimension"))
    ParseRSN(Json["MaxTexture2DDimension"], Type.MaxTexture2DDimension,
             Allocator);

  if (Json.contains("MaxTexture2DArraySlices"))
    ParseRSN(Json["MaxTexture2DArraySlices"], Type.MaxTexture2DArraySlices,
             Allocator);

  if (Json.contains("MaxTexture3DDimension"))
    ParseRSN(Json["MaxTexture3DDimension"], Type.MaxTexture3DDimension,
             Allocator);

  if (Json.contains("MaxTextureCubeDimension"))
    ParseRSN(Json["MaxTextureCubeDimension"], Type.MaxTextureCubeDimension,
             Allocator);

  if (Json.contains("Texture2DMSSupported"))
    ParseRSN(Json["Texture2DMSSupported"], Type.Texture2DMSSupported,
             Allocator);

  if (Json.contains("Texture2DMSArraySupported"))
    ParseRSN(Json["Texture2DMSArraySupported"], Type.Texture2DMSArraySupported,
             Allocator);

  if (Json.contains("TextureViewSupported"))
    ParseRSN(Json["TextureViewSupported"], Type.TextureViewSupported,
             Allocator);

  if (Json.contains("CubemapArraysSupported"))
    ParseRSN(Json["CubemapArraysSupported"], Type.CubemapArraysSupported,
             Allocator);

  if (Json.contains("TextureView2DOn3DSupported"))
    ParseRSN(Json["TextureView2DOn3DSupported"],
             Type.TextureView2DOn3DSupported, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const SamplerProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.BorderSamplingModeSupported ==
        SamplerProperties{}.BorderSamplingModeSupported))
    WriteRSN(Json["BorderSamplingModeSupported"],
             Type.BorderSamplingModeSupported, Allocator);

  if (!(Type.AnisotropicFilteringSupported ==
        SamplerProperties{}.AnisotropicFilteringSupported))
    WriteRSN(Json["AnisotropicFilteringSupported"],
             Type.AnisotropicFilteringSupported, Allocator);

  if (!(Type.LODBiasSupported == SamplerProperties{}.LODBiasSupported))
    WriteRSN(Json["LODBiasSupported"], Type.LODBiasSupported, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, SamplerProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "BorderSamplingModeSupported",
                                        "AnisotropicFilteringSupported",
                                        "LODBiasSupported",
                                    });
  if (Json.contains("BorderSamplingModeSupported"))
    ParseRSN(Json["BorderSamplingModeSupported"],
             Type.BorderSamplingModeSupported, Allocator);

  if (Json.contains("AnisotropicFilteringSupported"))
    ParseRSN(Json["AnisotropicFilteringSupported"],
             Type.AnisotropicFilteringSupported, Allocator);

  if (Json.contains("LODBiasSupported"))
    ParseRSN(Json["LODBiasSupported"], Type.LODBiasSupported, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const WaveOpProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.MinSize == WaveOpProperties{}.MinSize))
    WriteRSN(Json["MinSize"], Type.MinSize, Allocator);

  if (!(Type.MaxSize == WaveOpProperties{}.MaxSize))
    WriteRSN(Json["MaxSize"], Type.MaxSize, Allocator);

  if (!(Type.SupportedStages == WaveOpProperties{}.SupportedStages))
    SerializeBitwiseEnum(Json["SupportedStages"], Type.SupportedStages,
                         Allocator);

  if (!(Type.Features == WaveOpProperties{}.Features))
    SerializeBitwiseEnum(Json["Features"], Type.Features, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, WaveOpProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "MinSize",
                                        "MaxSize",
                                        "SupportedStages",
                                        "Features",
                                    });
  if (Json.contains("MinSize"))
    ParseRSN(Json["MinSize"], Type.MinSize, Allocator);

  if (Json.contains("MaxSize"))
    ParseRSN(Json["MaxSize"], Type.MaxSize, Allocator);

  if (Json.contains("SupportedStages"))
    DeserializeBitwiseEnum(Json["SupportedStages"], Type.SupportedStages,
                           Allocator);

  if (Json.contains("Features"))
    DeserializeBitwiseEnum(Json["Features"], Type.Features, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const BufferProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.ConstantBufferOffsetAlignment ==
        BufferProperties{}.ConstantBufferOffsetAlignment))
    WriteRSN(Json["ConstantBufferOffsetAlignment"],
             Type.ConstantBufferOffsetAlignment, Allocator);

  if (!(Type.StructuredBufferOffsetAlignment ==
        BufferProperties{}.StructuredBufferOffsetAlignment))
    WriteRSN(Json["StructuredBufferOffsetAlignment"],
             Type.StructuredBufferOffsetAlignment, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, BufferProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "ConstantBufferOffsetAlignment",
                                        "StructuredBufferOffsetAlignment",
                                    });
  if (Json.contains("ConstantBufferOffsetAlignment"))
    ParseRSN(Json["ConstantBufferOffsetAlignment"],
             Type.ConstantBufferOffsetAlignment, Allocator);

  if (Json.contains("StructuredBufferOffsetAlignment"))
    ParseRSN(Json["StructuredBufferOffsetAlignment"],
             Type.StructuredBufferOffsetAlignment, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const RayTracingProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.MaxRecursionDepth == RayTracingProperties{}.MaxRecursionDepth))
    WriteRSN(Json["MaxRecursionDepth"], Type.MaxRecursionDepth, Allocator);

  if (!(Type.ShaderGroupHandleSize ==
        RayTracingProperties{}.ShaderGroupHandleSize))
    WriteRSN(Json["ShaderGroupHandleSize"], Type.ShaderGroupHandleSize,
             Allocator);

  if (!(Type.MaxShaderRecordStride ==
        RayTracingProperties{}.MaxShaderRecordStride))
    WriteRSN(Json["MaxShaderRecordStride"], Type.MaxShaderRecordStride,
             Allocator);

  if (!(Type.ShaderGroupBaseAlignment ==
        RayTracingProperties{}.ShaderGroupBaseAlignment))
    WriteRSN(Json["ShaderGroupBaseAlignment"], Type.ShaderGroupBaseAlignment,
             Allocator);

  if (!(Type.MaxRayGenThreads == RayTracingProperties{}.MaxRayGenThreads))
    WriteRSN(Json["MaxRayGenThreads"], Type.MaxRayGenThreads, Allocator);

  if (!(Type.MaxInstancesPerTLAS == RayTracingProperties{}.MaxInstancesPerTLAS))
    WriteRSN(Json["MaxInstancesPerTLAS"], Type.MaxInstancesPerTLAS, Allocator);

  if (!(Type.MaxPrimitivesPerBLAS ==
        RayTracingProperties{}.MaxPrimitivesPerBLAS))
    WriteRSN(Json["MaxPrimitivesPerBLAS"], Type.MaxPrimitivesPerBLAS,
             Allocator);

  if (!(Type.MaxGeometriesPerBLAS ==
        RayTracingProperties{}.MaxGeometriesPerBLAS))
    WriteRSN(Json["MaxGeometriesPerBLAS"], Type.MaxGeometriesPerBLAS,
             Allocator);

  if (!(Type.VertexBufferAlignment ==
        RayTracingProperties{}.VertexBufferAlignment))
    WriteRSN(Json["VertexBufferAlignment"], Type.VertexBufferAlignment,
             Allocator);

  if (!(Type.IndexBufferAlignment ==
        RayTracingProperties{}.IndexBufferAlignment))
    WriteRSN(Json["IndexBufferAlignment"], Type.IndexBufferAlignment,
             Allocator);

  if (!(Type.TransformBufferAlignment ==
        RayTracingProperties{}.TransformBufferAlignment))
    WriteRSN(Json["TransformBufferAlignment"], Type.TransformBufferAlignment,
             Allocator);

  if (!(Type.BoxBufferAlignment == RayTracingProperties{}.BoxBufferAlignment))
    WriteRSN(Json["BoxBufferAlignment"], Type.BoxBufferAlignment, Allocator);

  if (!(Type.ScratchBufferAlignment ==
        RayTracingProperties{}.ScratchBufferAlignment))
    WriteRSN(Json["ScratchBufferAlignment"], Type.ScratchBufferAlignment,
             Allocator);

  if (!(Type.InstanceBufferAlignment ==
        RayTracingProperties{}.InstanceBufferAlignment))
    WriteRSN(Json["InstanceBufferAlignment"], Type.InstanceBufferAlignment,
             Allocator);

  if (!(Type.CapFlags == RayTracingProperties{}.CapFlags))
    SerializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, RayTracingProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "MaxRecursionDepth",
                                        "ShaderGroupHandleSize",
                                        "MaxShaderRecordStride",
                                        "ShaderGroupBaseAlignment",
                                        "MaxRayGenThreads",
                                        "MaxInstancesPerTLAS",
                                        "MaxPrimitivesPerBLAS",
                                        "MaxGeometriesPerBLAS",
                                        "VertexBufferAlignment",
                                        "IndexBufferAlignment",
                                        "TransformBufferAlignment",
                                        "BoxBufferAlignment",
                                        "ScratchBufferAlignment",
                                        "InstanceBufferAlignment",
                                        "CapFlags",
                                    });
  if (Json.contains("MaxRecursionDepth"))
    ParseRSN(Json["MaxRecursionDepth"], Type.MaxRecursionDepth, Allocator);

  if (Json.contains("ShaderGroupHandleSize"))
    ParseRSN(Json["ShaderGroupHandleSize"], Type.ShaderGroupHandleSize,
             Allocator);

  if (Json.contains("MaxShaderRecordStride"))
    ParseRSN(Json["MaxShaderRecordStride"], Type.MaxShaderRecordStride,
             Allocator);

  if (Json.contains("ShaderGroupBaseAlignment"))
    ParseRSN(Json["ShaderGroupBaseAlignment"], Type.ShaderGroupBaseAlignment,
             Allocator);

  if (Json.contains("MaxRayGenThreads"))
    ParseRSN(Json["MaxRayGenThreads"], Type.MaxRayGenThreads, Allocator);

  if (Json.contains("MaxInstancesPerTLAS"))
    ParseRSN(Json["MaxInstancesPerTLAS"], Type.MaxInstancesPerTLAS, Allocator);

  if (Json.contains("MaxPrimitivesPerBLAS"))
    ParseRSN(Json["MaxPrimitivesPerBLAS"], Type.MaxPrimitivesPerBLAS,
             Allocator);

  if (Json.contains("MaxGeometriesPerBLAS"))
    ParseRSN(Json["MaxGeometriesPerBLAS"], Type.MaxGeometriesPerBLAS,
             Allocator);

  if (Json.contains("VertexBufferAlignment"))
    ParseRSN(Json["VertexBufferAlignment"], Type.VertexBufferAlignment,
             Allocator);

  if (Json.contains("IndexBufferAlignment"))
    ParseRSN(Json["IndexBufferAlignment"], Type.IndexBufferAlignment,
             Allocator);

  if (Json.contains("TransformBufferAlignment"))
    ParseRSN(Json["TransformBufferAlignment"], Type.TransformBufferAlignment,
             Allocator);

  if (Json.contains("BoxBufferAlignment"))
    ParseRSN(Json["BoxBufferAlignment"], Type.BoxBufferAlignment, Allocator);

  if (Json.contains("ScratchBufferAlignment"))
    ParseRSN(Json["ScratchBufferAlignment"], Type.ScratchBufferAlignment,
             Allocator);

  if (Json.contains("InstanceBufferAlignment"))
    ParseRSN(Json["InstanceBufferAlignment"], Type.InstanceBufferAlignment,
             Allocator);

  if (Json.contains("CapFlags"))
    DeserializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const MeshShaderProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.MaxThreadGroupCountX ==
        MeshShaderProperties{}.MaxThreadGroupCountX))
    WriteRSN(Json["MaxThreadGroupCountX"], Type.MaxThreadGroupCountX,
             Allocator);

  if (!(Type.MaxThreadGroupCountY ==
        MeshShaderProperties{}.MaxThreadGroupCountY))
    WriteRSN(Json["MaxThreadGroupCountY"], Type.MaxThreadGroupCountY,
             Allocator);

  if (!(Type.MaxThreadGroupCountZ ==
        MeshShaderProperties{}.MaxThreadGroupCountZ))
    WriteRSN(Json["MaxThreadGroupCountZ"], Type.MaxThreadGroupCountZ,
             Allocator);

  if (!(Type.MaxThreadGroupTotalCount ==
        MeshShaderProperties{}.MaxThreadGroupTotalCount))
    WriteRSN(Json["MaxThreadGroupTotalCount"], Type.MaxThreadGroupTotalCount,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, MeshShaderProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "MaxThreadGroupCountX",
                                        "MaxThreadGroupCountY",
                                        "MaxThreadGroupCountZ",
                                        "MaxThreadGroupTotalCount",
                                    });
  if (Json.contains("MaxThreadGroupCountX"))
    ParseRSN(Json["MaxThreadGroupCountX"], Type.MaxThreadGroupCountX,
             Allocator);

  if (Json.contains("MaxThreadGroupCountY"))
    ParseRSN(Json["MaxThreadGroupCountY"], Type.MaxThreadGroupCountY,
             Allocator);

  if (Json.contains("MaxThreadGroupCountZ"))
    ParseRSN(Json["MaxThreadGroupCountZ"], Type.MaxThreadGroupCountZ,
             Allocator);

  if (Json.contains("MaxThreadGroupTotalCount"))
    ParseRSN(Json["MaxThreadGroupTotalCount"], Type.MaxThreadGroupTotalCount,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const ComputeShaderProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.SharedMemorySize == ComputeShaderProperties{}.SharedMemorySize))
    WriteRSN(Json["SharedMemorySize"], Type.SharedMemorySize, Allocator);

  if (!(Type.MaxThreadGroupInvocations ==
        ComputeShaderProperties{}.MaxThreadGroupInvocations))
    WriteRSN(Json["MaxThreadGroupInvocations"], Type.MaxThreadGroupInvocations,
             Allocator);

  if (!(Type.MaxThreadGroupSizeX ==
        ComputeShaderProperties{}.MaxThreadGroupSizeX))
    WriteRSN(Json["MaxThreadGroupSizeX"], Type.MaxThreadGroupSizeX, Allocator);

  if (!(Type.MaxThreadGroupSizeY ==
        ComputeShaderProperties{}.MaxThreadGroupSizeY))
    WriteRSN(Json["MaxThreadGroupSizeY"], Type.MaxThreadGroupSizeY, Allocator);

  if (!(Type.MaxThreadGroupSizeZ ==
        ComputeShaderProperties{}.MaxThreadGroupSizeZ))
    WriteRSN(Json["MaxThreadGroupSizeZ"], Type.MaxThreadGroupSizeZ, Allocator);

  if (!(Type.MaxThreadGroupCountX ==
        ComputeShaderProperties{}.MaxThreadGroupCountX))
    WriteRSN(Json["MaxThreadGroupCountX"], Type.MaxThreadGroupCountX,
             Allocator);

  if (!(Type.MaxThreadGroupCountY ==
        ComputeShaderProperties{}.MaxThreadGroupCountY))
    WriteRSN(Json["MaxThreadGroupCountY"], Type.MaxThreadGroupCountY,
             Allocator);

  if (!(Type.MaxThreadGroupCountZ ==
        ComputeShaderProperties{}.MaxThreadGroupCountZ))
    WriteRSN(Json["MaxThreadGroupCountZ"], Type.MaxThreadGroupCountZ,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ComputeShaderProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "SharedMemorySize",
                                        "MaxThreadGroupInvocations",
                                        "MaxThreadGroupSizeX",
                                        "MaxThreadGroupSizeY",
                                        "MaxThreadGroupSizeZ",
                                        "MaxThreadGroupCountX",
                                        "MaxThreadGroupCountY",
                                        "MaxThreadGroupCountZ",
                                    });
  if (Json.contains("SharedMemorySize"))
    ParseRSN(Json["SharedMemorySize"], Type.SharedMemorySize, Allocator);

  if (Json.contains("MaxThreadGroupInvocations"))
    ParseRSN(Json["MaxThreadGroupInvocations"], Type.MaxThreadGroupInvocations,
             Allocator);

  if (Json.contains("MaxThreadGroupSizeX"))
    ParseRSN(Json["MaxThreadGroupSizeX"], Type.MaxThreadGroupSizeX, Allocator);

  if (Json.contains("MaxThreadGroupSizeY"))
    ParseRSN(Json["MaxThreadGroupSizeY"], Type.MaxThreadGroupSizeY, Allocator);

  if (Json.contains("MaxThreadGroupSizeZ"))
    ParseRSN(Json["MaxThreadGroupSizeZ"], Type.MaxThreadGroupSizeZ, Allocator);

  if (Json.contains("MaxThreadGroupCountX"))
    ParseRSN(Json["MaxThreadGroupCountX"], Type.MaxThreadGroupCountX,
             Allocator);

  if (Json.contains("MaxThreadGroupCountY"))
    ParseRSN(Json["MaxThreadGroupCountY"], Type.MaxThreadGroupCountY,
             Allocator);

  if (Json.contains("MaxThreadGroupCountZ"))
    ParseRSN(Json["MaxThreadGroupCountZ"], Type.MaxThreadGroupCountZ,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const NDCAttribs &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.MinZ == NDCAttribs{}.MinZ))
    WriteRSN(Json["MinZ"], Type.MinZ, Allocator);

  if (!(Type.ZtoDepthScale == NDCAttribs{}.ZtoDepthScale))
    WriteRSN(Json["ZtoDepthScale"], Type.ZtoDepthScale, Allocator);

  if (!(Type.YtoVScale == NDCAttribs{}.YtoVScale))
    WriteRSN(Json["YtoVScale"], Type.YtoVScale, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, NDCAttribs &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "MinZ",
                                        "ZtoDepthScale",
                                        "YtoVScale",
                                    });
  if (Json.contains("MinZ"))
    ParseRSN(Json["MinZ"], Type.MinZ, Allocator);

  if (Json.contains("ZtoDepthScale"))
    ParseRSN(Json["ZtoDepthScale"], Type.ZtoDepthScale, Allocator);

  if (Json.contains("YtoVScale"))
    ParseRSN(Json["YtoVScale"], Type.YtoVScale, Allocator);
}

inline void WriteRSN(nlohmann::json &Json,
                     const RenderDeviceShaderVersionInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.HLSL == RenderDeviceShaderVersionInfo{}.HLSL))
    WriteRSN(Json["HLSL"], Type.HLSL, Allocator);

  if (!(Type.GLSL == RenderDeviceShaderVersionInfo{}.GLSL))
    WriteRSN(Json["GLSL"], Type.GLSL, Allocator);

  if (!(Type.GLESSL == RenderDeviceShaderVersionInfo{}.GLESSL))
    WriteRSN(Json["GLESSL"], Type.GLESSL, Allocator);

  if (!(Type.MSL == RenderDeviceShaderVersionInfo{}.MSL))
    WriteRSN(Json["MSL"], Type.MSL, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json,
                     RenderDeviceShaderVersionInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "HLSL",
                                        "GLSL",
                                        "GLESSL",
                                        "MSL",
                                    });
  if (Json.contains("HLSL"))
    ParseRSN(Json["HLSL"], Type.HLSL, Allocator);

  if (Json.contains("GLSL"))
    ParseRSN(Json["GLSL"], Type.GLSL, Allocator);

  if (Json.contains("GLESSL"))
    ParseRSN(Json["GLESSL"], Type.GLESSL, Allocator);

  if (Json.contains("MSL"))
    ParseRSN(Json["MSL"], Type.MSL, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const RenderDeviceInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.Type == RenderDeviceInfo{}.Type))
    WriteRSN(Json["Type"], Type.Type, Allocator);

  if (!(Type.APIVersion == RenderDeviceInfo{}.APIVersion))
    WriteRSN(Json["APIVersion"], Type.APIVersion, Allocator);

  if (!(Type.Features == RenderDeviceInfo{}.Features))
    WriteRSN(Json["Features"], Type.Features, Allocator);

  if (!(Type.NDC == RenderDeviceInfo{}.NDC))
    WriteRSN(Json["NDC"], Type.NDC, Allocator);

  if (!(Type.MaxShaderVersion == RenderDeviceInfo{}.MaxShaderVersion))
    WriteRSN(Json["MaxShaderVersion"], Type.MaxShaderVersion, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, RenderDeviceInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Type",
                                        "APIVersion",
                                        "Features",
                                        "NDC",
                                        "MaxShaderVersion",
                                    });
  if (Json.contains("Type"))
    ParseRSN(Json["Type"], Type.Type, Allocator);

  if (Json.contains("APIVersion"))
    ParseRSN(Json["APIVersion"], Type.APIVersion, Allocator);

  if (Json.contains("Features"))
    ParseRSN(Json["Features"], Type.Features, Allocator);

  if (Json.contains("NDC"))
    ParseRSN(Json["NDC"], Type.NDC, Allocator);

  if (Json.contains("MaxShaderVersion"))
    ParseRSN(Json["MaxShaderVersion"], Type.MaxShaderVersion, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const AdapterMemoryInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.LocalMemory == AdapterMemoryInfo{}.LocalMemory))
    WriteRSN(Json["LocalMemory"], Type.LocalMemory, Allocator);

  if (!(Type.HostVisibleMemory == AdapterMemoryInfo{}.HostVisibleMemory))
    WriteRSN(Json["HostVisibleMemory"], Type.HostVisibleMemory, Allocator);

  if (!(Type.UnifiedMemory == AdapterMemoryInfo{}.UnifiedMemory))
    WriteRSN(Json["UnifiedMemory"], Type.UnifiedMemory, Allocator);

  if (!(Type.MaxMemoryAllocation == AdapterMemoryInfo{}.MaxMemoryAllocation))
    WriteRSN(Json["MaxMemoryAllocation"], Type.MaxMemoryAllocation, Allocator);

  if (!(Type.UnifiedMemoryCPUAccess ==
        AdapterMemoryInfo{}.UnifiedMemoryCPUAccess))
    SerializeBitwiseEnum(Json["UnifiedMemoryCPUAccess"],
                         Type.UnifiedMemoryCPUAccess, Allocator);

  if (!(Type.MemorylessTextureBindFlags ==
        AdapterMemoryInfo{}.MemorylessTextureBindFlags))
    SerializeBitwiseEnum(Json["MemorylessTextureBindFlags"],
                         Type.MemorylessTextureBindFlags, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, AdapterMemoryInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "LocalMemory",
                                        "HostVisibleMemory",
                                        "UnifiedMemory",
                                        "MaxMemoryAllocation",
                                        "UnifiedMemoryCPUAccess",
                                        "MemorylessTextureBindFlags",
                                    });
  if (Json.contains("LocalMemory"))
    ParseRSN(Json["LocalMemory"], Type.LocalMemory, Allocator);

  if (Json.contains("HostVisibleMemory"))
    ParseRSN(Json["HostVisibleMemory"], Type.HostVisibleMemory, Allocator);

  if (Json.contains("UnifiedMemory"))
    ParseRSN(Json["UnifiedMemory"], Type.UnifiedMemory, Allocator);

  if (Json.contains("MaxMemoryAllocation"))
    ParseRSN(Json["MaxMemoryAllocation"], Type.MaxMemoryAllocation, Allocator);

  if (Json.contains("UnifiedMemoryCPUAccess"))
    DeserializeBitwiseEnum(Json["UnifiedMemoryCPUAccess"],
                           Type.UnifiedMemoryCPUAccess, Allocator);

  if (Json.contains("MemorylessTextureBindFlags"))
    DeserializeBitwiseEnum(Json["MemorylessTextureBindFlags"],
                           Type.MemorylessTextureBindFlags, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const ShadingRateMode &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.Rate == ShadingRateMode{}.Rate))
    WriteRSN(Json["Rate"], Type.Rate, Allocator);

  if (!(Type.SampleBits == ShadingRateMode{}.SampleBits))
    SerializeBitwiseEnum(Json["SampleBits"], Type.SampleBits, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ShadingRateMode &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Rate",
                                        "SampleBits",
                                    });
  if (Json.contains("Rate"))
    ParseRSN(Json["Rate"], Type.Rate, Allocator);

  if (Json.contains("SampleBits"))
    DeserializeBitwiseEnum(Json["SampleBits"], Type.SampleBits, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const ShadingRateProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!CompareConstArray(Type.ShadingRates,
                         ShadingRateProperties{}.ShadingRates))
    SerializeConstArray(Json["ShadingRates"], Type.ShadingRates, Allocator);

  if (!(Type.NumShadingRates == ShadingRateProperties{}.NumShadingRates))
    WriteRSN(Json["NumShadingRates"], Type.NumShadingRates, Allocator);

  if (!(Type.CapFlags == ShadingRateProperties{}.CapFlags))
    SerializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);

  if (!(Type.Combiners == ShadingRateProperties{}.Combiners))
    SerializeBitwiseEnum(Json["Combiners"], Type.Combiners, Allocator);

  if (!(Type.Format == ShadingRateProperties{}.Format))
    WriteRSN(Json["Format"], Type.Format, Allocator);

  if (!(Type.ShadingRateTextureAccess ==
        ShadingRateProperties{}.ShadingRateTextureAccess))
    WriteRSN(Json["ShadingRateTextureAccess"], Type.ShadingRateTextureAccess,
             Allocator);

  if (!(Type.BindFlags == ShadingRateProperties{}.BindFlags))
    SerializeBitwiseEnum(Json["BindFlags"], Type.BindFlags, Allocator);

  if (!CompareConstArray(Type.MinTileSize, ShadingRateProperties{}.MinTileSize))
    SerializeConstArray(Json["MinTileSize"], Type.MinTileSize, Allocator);

  if (!CompareConstArray(Type.MaxTileSize, ShadingRateProperties{}.MaxTileSize))
    SerializeConstArray(Json["MaxTileSize"], Type.MaxTileSize, Allocator);

  if (!(Type.MaxSabsampledArraySlices ==
        ShadingRateProperties{}.MaxSabsampledArraySlices))
    WriteRSN(Json["MaxSabsampledArraySlices"], Type.MaxSabsampledArraySlices,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ShadingRateProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "ShadingRates",
                                        "NumShadingRates",
                                        "CapFlags",
                                        "Combiners",
                                        "Format",
                                        "ShadingRateTextureAccess",
                                        "BindFlags",
                                        "MinTileSize",
                                        "MaxTileSize",
                                        "MaxSabsampledArraySlices",
                                    });
  if (Json.contains("ShadingRates"))
    DeserializeConstArray(Json["ShadingRates"], Type.ShadingRates, Allocator);

  if (Json.contains("NumShadingRates"))
    ParseRSN(Json["NumShadingRates"], Type.NumShadingRates, Allocator);

  if (Json.contains("CapFlags"))
    DeserializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);

  if (Json.contains("Combiners"))
    DeserializeBitwiseEnum(Json["Combiners"], Type.Combiners, Allocator);

  if (Json.contains("Format"))
    ParseRSN(Json["Format"], Type.Format, Allocator);

  if (Json.contains("ShadingRateTextureAccess"))
    ParseRSN(Json["ShadingRateTextureAccess"], Type.ShadingRateTextureAccess,
             Allocator);

  if (Json.contains("BindFlags"))
    DeserializeBitwiseEnum(Json["BindFlags"], Type.BindFlags, Allocator);

  if (Json.contains("MinTileSize"))
    DeserializeConstArray(Json["MinTileSize"], Type.MinTileSize, Allocator);

  if (Json.contains("MaxTileSize"))
    DeserializeConstArray(Json["MaxTileSize"], Type.MaxTileSize, Allocator);

  if (Json.contains("MaxSabsampledArraySlices"))
    ParseRSN(Json["MaxSabsampledArraySlices"], Type.MaxSabsampledArraySlices,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const DrawCommandProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.CapFlags == DrawCommandProperties{}.CapFlags))
    SerializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);

  if (!(Type.MaxIndexValue == DrawCommandProperties{}.MaxIndexValue))
    WriteRSN(Json["MaxIndexValue"], Type.MaxIndexValue, Allocator);

  if (!(Type.MaxDrawIndirectCount ==
        DrawCommandProperties{}.MaxDrawIndirectCount))
    WriteRSN(Json["MaxDrawIndirectCount"], Type.MaxDrawIndirectCount,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, DrawCommandProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "CapFlags",
                                        "MaxIndexValue",
                                        "MaxDrawIndirectCount",
                                    });
  if (Json.contains("CapFlags"))
    DeserializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);

  if (Json.contains("MaxIndexValue"))
    ParseRSN(Json["MaxIndexValue"], Type.MaxIndexValue, Allocator);

  if (Json.contains("MaxDrawIndirectCount"))
    ParseRSN(Json["MaxDrawIndirectCount"], Type.MaxDrawIndirectCount,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const SparseResourceProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.AddressSpaceSize == SparseResourceProperties{}.AddressSpaceSize))
    WriteRSN(Json["AddressSpaceSize"], Type.AddressSpaceSize, Allocator);

  if (!(Type.ResourceSpaceSize == SparseResourceProperties{}.ResourceSpaceSize))
    WriteRSN(Json["ResourceSpaceSize"], Type.ResourceSpaceSize, Allocator);

  if (!(Type.CapFlags == SparseResourceProperties{}.CapFlags))
    SerializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);

  if (!(Type.StandardBlockSize == SparseResourceProperties{}.StandardBlockSize))
    WriteRSN(Json["StandardBlockSize"], Type.StandardBlockSize, Allocator);

  if (!(Type.BufferBindFlags == SparseResourceProperties{}.BufferBindFlags))
    SerializeBitwiseEnum(Json["BufferBindFlags"], Type.BufferBindFlags,
                         Allocator);

  if (!(Type._Padding == SparseResourceProperties{}._Padding))
    WriteRSN(Json["_Padding"], Type._Padding, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, SparseResourceProperties &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "AddressSpaceSize",
                                        "ResourceSpaceSize",
                                        "CapFlags",
                                        "StandardBlockSize",
                                        "BufferBindFlags",
                                        "_Padding",
                                    });
  if (Json.contains("AddressSpaceSize"))
    ParseRSN(Json["AddressSpaceSize"], Type.AddressSpaceSize, Allocator);

  if (Json.contains("ResourceSpaceSize"))
    ParseRSN(Json["ResourceSpaceSize"], Type.ResourceSpaceSize, Allocator);

  if (Json.contains("CapFlags"))
    DeserializeBitwiseEnum(Json["CapFlags"], Type.CapFlags, Allocator);

  if (Json.contains("StandardBlockSize"))
    ParseRSN(Json["StandardBlockSize"], Type.StandardBlockSize, Allocator);

  if (Json.contains("BufferBindFlags"))
    DeserializeBitwiseEnum(Json["BufferBindFlags"], Type.BufferBindFlags,
                           Allocator);

  if (Json.contains("_Padding"))
    ParseRSN(Json["_Padding"], Type._Padding, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const CommandQueueInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.QueueType == CommandQueueInfo{}.QueueType))
    SerializeBitwiseEnum(Json["QueueType"], Type.QueueType, Allocator);

  if (!(Type.MaxDeviceContexts == CommandQueueInfo{}.MaxDeviceContexts))
    WriteRSN(Json["MaxDeviceContexts"], Type.MaxDeviceContexts, Allocator);

  if (!CompareConstArray(Type.TextureCopyGranularity,
                         CommandQueueInfo{}.TextureCopyGranularity))
    SerializeConstArray(Json["TextureCopyGranularity"],
                        Type.TextureCopyGranularity, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, CommandQueueInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "QueueType",
                                        "MaxDeviceContexts",
                                        "TextureCopyGranularity",
                                    });
  if (Json.contains("QueueType"))
    DeserializeBitwiseEnum(Json["QueueType"], Type.QueueType, Allocator);

  if (Json.contains("MaxDeviceContexts"))
    ParseRSN(Json["MaxDeviceContexts"], Type.MaxDeviceContexts, Allocator);

  if (Json.contains("TextureCopyGranularity"))
    DeserializeConstArray(Json["TextureCopyGranularity"],
                          Type.TextureCopyGranularity, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const GraphicsAdapterInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!CompareConstArray(Type.Description, GraphicsAdapterInfo{}.Description))
    SerializeConstArray(Json["Description"], Type.Description, Allocator);

  if (!(Type.Type == GraphicsAdapterInfo{}.Type))
    WriteRSN(Json["Type"], Type.Type, Allocator);

  if (!(Type.Vendor == GraphicsAdapterInfo{}.Vendor))
    WriteRSN(Json["Vendor"], Type.Vendor, Allocator);

  if (!(Type.VendorId == GraphicsAdapterInfo{}.VendorId))
    WriteRSN(Json["VendorId"], Type.VendorId, Allocator);

  if (!(Type.DeviceId == GraphicsAdapterInfo{}.DeviceId))
    WriteRSN(Json["DeviceId"], Type.DeviceId, Allocator);

  if (!(Type.NumOutputs == GraphicsAdapterInfo{}.NumOutputs))
    WriteRSN(Json["NumOutputs"], Type.NumOutputs, Allocator);

  if (!(Type.Memory == GraphicsAdapterInfo{}.Memory))
    WriteRSN(Json["Memory"], Type.Memory, Allocator);

  if (!(Type.RayTracing == GraphicsAdapterInfo{}.RayTracing))
    WriteRSN(Json["RayTracing"], Type.RayTracing, Allocator);

  if (!(Type.WaveOp == GraphicsAdapterInfo{}.WaveOp))
    WriteRSN(Json["WaveOp"], Type.WaveOp, Allocator);

  if (!(Type.Buffer == GraphicsAdapterInfo{}.Buffer))
    WriteRSN(Json["Buffer"], Type.Buffer, Allocator);

  if (!(Type.Texture == GraphicsAdapterInfo{}.Texture))
    WriteRSN(Json["Texture"], Type.Texture, Allocator);

  if (!(Type.Sampler == GraphicsAdapterInfo{}.Sampler))
    WriteRSN(Json["Sampler"], Type.Sampler, Allocator);

  if (!(Type.MeshShader == GraphicsAdapterInfo{}.MeshShader))
    WriteRSN(Json["MeshShader"], Type.MeshShader, Allocator);

  if (!(Type.ShadingRate == GraphicsAdapterInfo{}.ShadingRate))
    WriteRSN(Json["ShadingRate"], Type.ShadingRate, Allocator);

  if (!(Type.ComputeShader == GraphicsAdapterInfo{}.ComputeShader))
    WriteRSN(Json["ComputeShader"], Type.ComputeShader, Allocator);

  if (!(Type.DrawCommand == GraphicsAdapterInfo{}.DrawCommand))
    WriteRSN(Json["DrawCommand"], Type.DrawCommand, Allocator);

  if (!(Type.SparseResources == GraphicsAdapterInfo{}.SparseResources))
    WriteRSN(Json["SparseResources"], Type.SparseResources, Allocator);

  if (!(Type.Features == GraphicsAdapterInfo{}.Features))
    WriteRSN(Json["Features"], Type.Features, Allocator);

  if (!CompareConstArray(Type.Queues, GraphicsAdapterInfo{}.Queues))
    SerializeConstArray(Json["Queues"], Type.Queues, Allocator);

  if (!(Type.NumQueues == GraphicsAdapterInfo{}.NumQueues))
    WriteRSN(Json["NumQueues"], Type.NumQueues, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, GraphicsAdapterInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(
      Json,
      {
          "Description",     "Type",        "Vendor",        "VendorId",
          "DeviceId",        "NumOutputs",  "Memory",        "RayTracing",
          "WaveOp",          "Buffer",      "Texture",       "Sampler",
          "MeshShader",      "ShadingRate", "ComputeShader", "DrawCommand",
          "SparseResources", "Features",    "Queues",        "NumQueues",
      });
  if (Json.contains("Description"))
    DeserializeConstArray(Json["Description"], Type.Description, Allocator);

  if (Json.contains("Type"))
    ParseRSN(Json["Type"], Type.Type, Allocator);

  if (Json.contains("Vendor"))
    ParseRSN(Json["Vendor"], Type.Vendor, Allocator);

  if (Json.contains("VendorId"))
    ParseRSN(Json["VendorId"], Type.VendorId, Allocator);

  if (Json.contains("DeviceId"))
    ParseRSN(Json["DeviceId"], Type.DeviceId, Allocator);

  if (Json.contains("NumOutputs"))
    ParseRSN(Json["NumOutputs"], Type.NumOutputs, Allocator);

  if (Json.contains("Memory"))
    ParseRSN(Json["Memory"], Type.Memory, Allocator);

  if (Json.contains("RayTracing"))
    ParseRSN(Json["RayTracing"], Type.RayTracing, Allocator);

  if (Json.contains("WaveOp"))
    ParseRSN(Json["WaveOp"], Type.WaveOp, Allocator);

  if (Json.contains("Buffer"))
    ParseRSN(Json["Buffer"], Type.Buffer, Allocator);

  if (Json.contains("Texture"))
    ParseRSN(Json["Texture"], Type.Texture, Allocator);

  if (Json.contains("Sampler"))
    ParseRSN(Json["Sampler"], Type.Sampler, Allocator);

  if (Json.contains("MeshShader"))
    ParseRSN(Json["MeshShader"], Type.MeshShader, Allocator);

  if (Json.contains("ShadingRate"))
    ParseRSN(Json["ShadingRate"], Type.ShadingRate, Allocator);

  if (Json.contains("ComputeShader"))
    ParseRSN(Json["ComputeShader"], Type.ComputeShader, Allocator);

  if (Json.contains("DrawCommand"))
    ParseRSN(Json["DrawCommand"], Type.DrawCommand, Allocator);

  if (Json.contains("SparseResources"))
    ParseRSN(Json["SparseResources"], Type.SparseResources, Allocator);

  if (Json.contains("Features"))
    ParseRSN(Json["Features"], Type.Features, Allocator);

  if (Json.contains("Queues"))
    DeserializeConstArray(Json["Queues"], Type.Queues, Allocator);

  if (Json.contains("NumQueues"))
    ParseRSN(Json["NumQueues"], Type.NumQueues, Allocator);
}

} // namespace Diligent
