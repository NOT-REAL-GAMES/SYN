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

#include "PipelineState.h"

namespace Diligent {

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SHADER_VARIABLE_FLAGS,
    {
        {SHADER_VARIABLE_FLAG_NONE, "NONE"},
        {SHADER_VARIABLE_FLAG_NO_DYNAMIC_BUFFERS, "NO_DYNAMIC_BUFFERS"},
        {SHADER_VARIABLE_FLAG_GENERAL_INPUT_ATTACHMENT,
         "GENERAL_INPUT_ATTACHMENT"},
        {SHADER_VARIABLE_FLAG_LAST, "LAST"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    PIPELINE_SHADING_RATE_FLAGS,
    {
        {PIPELINE_SHADING_RATE_FLAG_NONE, "NONE"},
        {PIPELINE_SHADING_RATE_FLAG_PER_PRIMITIVE, "PER_PRIMITIVE"},
        {PIPELINE_SHADING_RATE_FLAG_TEXTURE_BASED, "TEXTURE_BASED"},
        {PIPELINE_SHADING_RATE_FLAG_LAST, "LAST"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(PIPELINE_TYPE,
                                {
                                    {PIPELINE_TYPE_GRAPHICS, "GRAPHICS"},
                                    {PIPELINE_TYPE_COMPUTE, "COMPUTE"},
                                    {PIPELINE_TYPE_MESH, "MESH"},
                                    {PIPELINE_TYPE_RAY_TRACING, "RAY_TRACING"},
                                    {PIPELINE_TYPE_TILE, "TILE"},
                                    {PIPELINE_TYPE_LAST, "LAST"},
                                    {PIPELINE_TYPE_COUNT, "COUNT"},
                                    {PIPELINE_TYPE_INVALID, "INVALID"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    PSO_CREATE_FLAGS,
    {
        {PSO_CREATE_FLAG_NONE, "NONE"},
        {PSO_CREATE_FLAG_IGNORE_MISSING_VARIABLES, "IGNORE_MISSING_VARIABLES"},
        {PSO_CREATE_FLAG_IGNORE_MISSING_IMMUTABLE_SAMPLERS,
         "IGNORE_MISSING_IMMUTABLE_SAMPLERS"},
        {PSO_CREATE_FLAG_DONT_REMAP_SHADER_RESOURCES,
         "DONT_REMAP_SHADER_RESOURCES"},
        {PSO_CREATE_FLAG_LAST, "LAST"},
    })

inline void WriteRSN(nlohmann::json &Json, const SampleDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.Count == SampleDesc{}.Count))
    WriteRSN(Json["Count"], Type.Count, Allocator);

  if (!(Type.Quality == SampleDesc{}.Quality))
    WriteRSN(Json["Quality"], Type.Quality, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, SampleDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Count",
                                        "Quality",
                                    });
  if (Json.contains("Count"))
    ParseRSN(Json["Count"], Type.Count, Allocator);

  if (Json.contains("Quality"))
    ParseRSN(Json["Quality"], Type.Quality, Allocator);
}

inline void WriteRSN(nlohmann::json &Json,
                     const ShaderResourceVariableDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.Name, ShaderResourceVariableDesc{}.Name))
    WriteRSN(Json["Name"], Type.Name, Allocator);

  if (!(Type.ShaderStages == ShaderResourceVariableDesc{}.ShaderStages))
    SerializeBitwiseEnum(Json["ShaderStages"], Type.ShaderStages, Allocator);

  if (!(Type.Type == ShaderResourceVariableDesc{}.Type))
    WriteRSN(Json["Type"], Type.Type, Allocator);

  if (!(Type.Flags == ShaderResourceVariableDesc{}.Flags))
    SerializeBitwiseEnum(Json["Flags"], Type.Flags, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json,
                     ShaderResourceVariableDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Name",
                                        "ShaderStages",
                                        "Type",
                                        "Flags",
                                    });
  if (Json.contains("Name"))
    ParseRSN(Json["Name"], Type.Name, Allocator);

  if (Json.contains("ShaderStages"))
    DeserializeBitwiseEnum(Json["ShaderStages"], Type.ShaderStages, Allocator);

  if (Json.contains("Type"))
    ParseRSN(Json["Type"], Type.Type, Allocator);

  if (Json.contains("Flags"))
    DeserializeBitwiseEnum(Json["Flags"], Type.Flags, Allocator);
}

inline void WriteRSN(nlohmann::json &Json,
                     const PipelineResourceLayoutDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.DefaultVariableType ==
        PipelineResourceLayoutDesc{}.DefaultVariableType))
    WriteRSN(Json["DefaultVariableType"], Type.DefaultVariableType, Allocator);

  if (!(Type.DefaultVariableMergeStages ==
        PipelineResourceLayoutDesc{}.DefaultVariableMergeStages))
    SerializeBitwiseEnum(Json["DefaultVariableMergeStages"],
                         Type.DefaultVariableMergeStages, Allocator);

  if (!(Type.Variables == PipelineResourceLayoutDesc{}.Variables))
    WriteRSN(Json["Variables"], Type.Variables, Type.NumVariables, Allocator);

  if (!(Type.ImmutableSamplers ==
        PipelineResourceLayoutDesc{}.ImmutableSamplers))
    WriteRSN(Json["ImmutableSamplers"], Type.ImmutableSamplers,
             Type.NumImmutableSamplers, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json,
                     PipelineResourceLayoutDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "DefaultVariableType",
                                        "DefaultVariableMergeStages",
                                        "NumVariables",
                                        "Variables",
                                        "NumImmutableSamplers",
                                        "ImmutableSamplers",
                                    });
  if (Json.contains("DefaultVariableType"))
    ParseRSN(Json["DefaultVariableType"], Type.DefaultVariableType, Allocator);

  if (Json.contains("DefaultVariableMergeStages"))
    DeserializeBitwiseEnum(Json["DefaultVariableMergeStages"],
                           Type.DefaultVariableMergeStages, Allocator);

  if (Json.contains("Variables"))
    ParseRSN(Json["Variables"], Type.Variables, Type.NumVariables, Allocator);

  if (Json.contains("ImmutableSamplers"))
    ParseRSN(Json["ImmutableSamplers"], Type.ImmutableSamplers,
             Type.NumImmutableSamplers, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const GraphicsPipelineDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.BlendDesc == GraphicsPipelineDesc{}.BlendDesc))
    WriteRSN(Json["BlendDesc"], Type.BlendDesc, Allocator);

  if (!(Type.SampleMask == GraphicsPipelineDesc{}.SampleMask))
    WriteRSN(Json["SampleMask"], Type.SampleMask, Allocator);

  if (!(Type.RasterizerDesc == GraphicsPipelineDesc{}.RasterizerDesc))
    WriteRSN(Json["RasterizerDesc"], Type.RasterizerDesc, Allocator);

  if (!(Type.DepthStencilDesc == GraphicsPipelineDesc{}.DepthStencilDesc))
    WriteRSN(Json["DepthStencilDesc"], Type.DepthStencilDesc, Allocator);

  if (!(Type.InputLayout == GraphicsPipelineDesc{}.InputLayout))
    WriteRSN(Json["InputLayout"], Type.InputLayout, Allocator);

  if (!(Type.PrimitiveTopology == GraphicsPipelineDesc{}.PrimitiveTopology))
    WriteRSN(Json["PrimitiveTopology"], Type.PrimitiveTopology, Allocator);

  if (!(Type.NumViewports == GraphicsPipelineDesc{}.NumViewports))
    WriteRSN(Json["NumViewports"], Type.NumViewports, Allocator);

  if (!(Type.NumRenderTargets == GraphicsPipelineDesc{}.NumRenderTargets))
    WriteRSN(Json["NumRenderTargets"], Type.NumRenderTargets, Allocator);

  if (!(Type.SubpassIndex == GraphicsPipelineDesc{}.SubpassIndex))
    WriteRSN(Json["SubpassIndex"], Type.SubpassIndex, Allocator);

  if (!(Type.ShadingRateFlags == GraphicsPipelineDesc{}.ShadingRateFlags))
    SerializeBitwiseEnum(Json["ShadingRateFlags"], Type.ShadingRateFlags,
                         Allocator);

  if (!CompareConstArray(Type.RTVFormats, GraphicsPipelineDesc{}.RTVFormats))
    SerializeConstArray(Json["RTVFormats"], Type.RTVFormats, Allocator);

  if (!(Type.DSVFormat == GraphicsPipelineDesc{}.DSVFormat))
    WriteRSN(Json["DSVFormat"], Type.DSVFormat, Allocator);

  if (!(Type.ReadOnlyDSV == GraphicsPipelineDesc{}.ReadOnlyDSV))
    WriteRSN(Json["ReadOnlyDSV"], Type.ReadOnlyDSV, Allocator);

  if (!(Type.SmplDesc == GraphicsPipelineDesc{}.SmplDesc))
    WriteRSN(Json["SmplDesc"], Type.SmplDesc, Allocator);

  if (!(Type.NodeMask == GraphicsPipelineDesc{}.NodeMask))
    WriteRSN(Json["NodeMask"], Type.NodeMask, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, GraphicsPipelineDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "BlendDesc",
                                        "SampleMask",
                                        "RasterizerDesc",
                                        "DepthStencilDesc",
                                        "InputLayout",
                                        "PrimitiveTopology",
                                        "NumViewports",
                                        "NumRenderTargets",
                                        "SubpassIndex",
                                        "ShadingRateFlags",
                                        "RTVFormats",
                                        "DSVFormat",
                                        "ReadOnlyDSV",
                                        "SmplDesc",
                                        "NodeMask",
                                        "pRenderPass",
                                    });
  if (Json.contains("BlendDesc"))
    ParseRSN(Json["BlendDesc"], Type.BlendDesc, Allocator);

  if (Json.contains("SampleMask"))
    ParseRSN(Json["SampleMask"], Type.SampleMask, Allocator);

  if (Json.contains("RasterizerDesc"))
    ParseRSN(Json["RasterizerDesc"], Type.RasterizerDesc, Allocator);

  if (Json.contains("DepthStencilDesc"))
    ParseRSN(Json["DepthStencilDesc"], Type.DepthStencilDesc, Allocator);

  if (Json.contains("InputLayout"))
    ParseRSN(Json["InputLayout"], Type.InputLayout, Allocator);

  if (Json.contains("PrimitiveTopology"))
    ParseRSN(Json["PrimitiveTopology"], Type.PrimitiveTopology, Allocator);

  if (Json.contains("NumViewports"))
    ParseRSN(Json["NumViewports"], Type.NumViewports, Allocator);

  if (Json.contains("NumRenderTargets"))
    ParseRSN(Json["NumRenderTargets"], Type.NumRenderTargets, Allocator);

  if (Json.contains("SubpassIndex"))
    ParseRSN(Json["SubpassIndex"], Type.SubpassIndex, Allocator);

  if (Json.contains("ShadingRateFlags"))
    DeserializeBitwiseEnum(Json["ShadingRateFlags"], Type.ShadingRateFlags,
                           Allocator);

  if (Json.contains("RTVFormats"))
    DeserializeConstArray(Json["RTVFormats"], Type.RTVFormats, Allocator);

  if (Json.contains("DSVFormat"))
    ParseRSN(Json["DSVFormat"], Type.DSVFormat, Allocator);

  if (Json.contains("ReadOnlyDSV"))
    ParseRSN(Json["ReadOnlyDSV"], Type.ReadOnlyDSV, Allocator);

  if (Json.contains("SmplDesc"))
    ParseRSN(Json["SmplDesc"], Type.SmplDesc, Allocator);

  if (Json.contains("NodeMask"))
    ParseRSN(Json["NodeMask"], Type.NodeMask, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const RayTracingPipelineDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.ShaderRecordSize == RayTracingPipelineDesc{}.ShaderRecordSize))
    WriteRSN(Json["ShaderRecordSize"], Type.ShaderRecordSize, Allocator);

  if (!(Type.MaxRecursionDepth == RayTracingPipelineDesc{}.MaxRecursionDepth))
    WriteRSN(Json["MaxRecursionDepth"], Type.MaxRecursionDepth, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, RayTracingPipelineDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "ShaderRecordSize",
                                        "MaxRecursionDepth",
                                    });
  if (Json.contains("ShaderRecordSize"))
    ParseRSN(Json["ShaderRecordSize"], Type.ShaderRecordSize, Allocator);

  if (Json.contains("MaxRecursionDepth"))
    ParseRSN(Json["MaxRecursionDepth"], Type.MaxRecursionDepth, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const PipelineStateDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.Name, PipelineStateDesc{}.Name))
    WriteRSN(Json["Name"], Type.Name, Allocator);

  if (!(Type.PipelineType == PipelineStateDesc{}.PipelineType))
    WriteRSN(Json["PipelineType"], Type.PipelineType, Allocator);

  if (!(Type.SRBAllocationGranularity ==
        PipelineStateDesc{}.SRBAllocationGranularity))
    WriteRSN(Json["SRBAllocationGranularity"], Type.SRBAllocationGranularity,
             Allocator);

  if (!(Type.ImmediateContextMask == PipelineStateDesc{}.ImmediateContextMask))
    WriteRSN(Json["ImmediateContextMask"], Type.ImmediateContextMask,
             Allocator);

  if (!(Type.ResourceLayout == PipelineStateDesc{}.ResourceLayout))
    WriteRSN(Json["ResourceLayout"], Type.ResourceLayout, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, PipelineStateDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Name",
                                        "PipelineType",
                                        "SRBAllocationGranularity",
                                        "ImmediateContextMask",
                                        "ResourceLayout",
                                    });
  if (Json.contains("Name"))
    ParseRSN(Json["Name"], Type.Name, Allocator);

  if (Json.contains("PipelineType"))
    ParseRSN(Json["PipelineType"], Type.PipelineType, Allocator);

  if (Json.contains("SRBAllocationGranularity"))
    ParseRSN(Json["SRBAllocationGranularity"], Type.SRBAllocationGranularity,
             Allocator);

  if (Json.contains("ImmediateContextMask"))
    ParseRSN(Json["ImmediateContextMask"], Type.ImmediateContextMask,
             Allocator);

  if (Json.contains("ResourceLayout"))
    ParseRSN(Json["ResourceLayout"], Type.ResourceLayout, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const TilePipelineDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.NumRenderTargets == TilePipelineDesc{}.NumRenderTargets))
    WriteRSN(Json["NumRenderTargets"], Type.NumRenderTargets, Allocator);

  if (!(Type.SampleCount == TilePipelineDesc{}.SampleCount))
    WriteRSN(Json["SampleCount"], Type.SampleCount, Allocator);

  if (!CompareConstArray(Type.RTVFormats, TilePipelineDesc{}.RTVFormats))
    SerializeConstArray(Json["RTVFormats"], Type.RTVFormats, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, TilePipelineDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "NumRenderTargets",
                                        "SampleCount",
                                        "RTVFormats",
                                    });
  if (Json.contains("NumRenderTargets"))
    ParseRSN(Json["NumRenderTargets"], Type.NumRenderTargets, Allocator);

  if (Json.contains("SampleCount"))
    ParseRSN(Json["SampleCount"], Type.SampleCount, Allocator);

  if (Json.contains("RTVFormats"))
    DeserializeConstArray(Json["RTVFormats"], Type.RTVFormats, Allocator);
}

} // namespace Diligent
