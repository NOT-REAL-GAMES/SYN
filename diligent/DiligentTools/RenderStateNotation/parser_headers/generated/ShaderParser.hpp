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

#include "Shader.h"

namespace Diligent {

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SHADER_SOURCE_LANGUAGE,
    {
        {SHADER_SOURCE_LANGUAGE_DEFAULT, "DEFAULT"},
        {SHADER_SOURCE_LANGUAGE_HLSL, "HLSL"},
        {SHADER_SOURCE_LANGUAGE_GLSL, "GLSL"},
        {SHADER_SOURCE_LANGUAGE_GLSL_VERBATIM, "GLSL_VERBATIM"},
        {SHADER_SOURCE_LANGUAGE_MSL, "MSL"},
        {SHADER_SOURCE_LANGUAGE_MSL_VERBATIM, "MSL_VERBATIM"},
        {SHADER_SOURCE_LANGUAGE_MTLB, "MTLB"},
        {SHADER_SOURCE_LANGUAGE_COUNT, "COUNT"},
    })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(SHADER_COMPILER,
                                {
                                    {SHADER_COMPILER_DEFAULT, "DEFAULT"},
                                    {SHADER_COMPILER_GLSLANG, "GLSLANG"},
                                    {SHADER_COMPILER_DXC, "DXC"},
                                    {SHADER_COMPILER_FXC, "FXC"},
                                    {SHADER_COMPILER_LAST, "LAST"},
                                    {SHADER_COMPILER_COUNT, "COUNT"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SHADER_RESOURCE_TYPE,
    {
        {SHADER_RESOURCE_TYPE_UNKNOWN, "UNKNOWN"},
        {SHADER_RESOURCE_TYPE_CONSTANT_BUFFER, "CONSTANT_BUFFER"},
        {SHADER_RESOURCE_TYPE_TEXTURE_SRV, "TEXTURE_SRV"},
        {SHADER_RESOURCE_TYPE_BUFFER_SRV, "BUFFER_SRV"},
        {SHADER_RESOURCE_TYPE_TEXTURE_UAV, "TEXTURE_UAV"},
        {SHADER_RESOURCE_TYPE_BUFFER_UAV, "BUFFER_UAV"},
        {SHADER_RESOURCE_TYPE_SAMPLER, "SAMPLER"},
        {SHADER_RESOURCE_TYPE_INPUT_ATTACHMENT, "INPUT_ATTACHMENT"},
        {SHADER_RESOURCE_TYPE_ACCEL_STRUCT, "ACCEL_STRUCT"},
        {SHADER_RESOURCE_TYPE_LAST, "LAST"},
    })

inline void WriteRSN(nlohmann::json &Json, const ShaderDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.Name, ShaderDesc{}.Name))
    WriteRSN(Json["Name"], Type.Name, Allocator);

  if (!(Type.ShaderType == ShaderDesc{}.ShaderType))
    SerializeBitwiseEnum(Json["ShaderType"], Type.ShaderType, Allocator);

  if (!(Type.UseCombinedTextureSamplers ==
        ShaderDesc{}.UseCombinedTextureSamplers))
    WriteRSN(Json["UseCombinedTextureSamplers"],
             Type.UseCombinedTextureSamplers, Allocator);

  if (!SafeStrEqual(Type.CombinedSamplerSuffix,
                    ShaderDesc{}.CombinedSamplerSuffix))
    WriteRSN(Json["CombinedSamplerSuffix"], Type.CombinedSamplerSuffix,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ShaderDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Name",
                                        "ShaderType",
                                        "UseCombinedTextureSamplers",
                                        "CombinedSamplerSuffix",
                                    });
  if (Json.contains("Name"))
    ParseRSN(Json["Name"], Type.Name, Allocator);

  if (Json.contains("ShaderType"))
    DeserializeBitwiseEnum(Json["ShaderType"], Type.ShaderType, Allocator);

  if (Json.contains("UseCombinedTextureSamplers"))
    ParseRSN(Json["UseCombinedTextureSamplers"],
             Type.UseCombinedTextureSamplers, Allocator);

  if (Json.contains("CombinedSamplerSuffix"))
    ParseRSN(Json["CombinedSamplerSuffix"], Type.CombinedSamplerSuffix,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const ShaderMacro &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.Name, ShaderMacro{}.Name))
    WriteRSN(Json["Name"], Type.Name, Allocator);

  if (!SafeStrEqual(Type.Definition, ShaderMacro{}.Definition))
    WriteRSN(Json["Definition"], Type.Definition, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ShaderMacro &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Name",
                                        "Definition",
                                    });
  if (Json.contains("Name"))
    ParseRSN(Json["Name"], Type.Name, Allocator);

  if (Json.contains("Definition"))
    ParseRSN(Json["Definition"], Type.Definition, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const ShaderCreateInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.FilePath, ShaderCreateInfo{}.FilePath))
    WriteRSN(Json["FilePath"], Type.FilePath, Allocator);

  if (!SafeStrEqual(Type.Source, ShaderCreateInfo{}.Source))
    WriteRSN(Json["Source"], Type.Source, Allocator);

  if (!(Type.ByteCode == ShaderCreateInfo{}.ByteCode))
    WriteRSN(Json["ByteCode"], Type.ByteCode, Type.ByteCodeSize, Allocator);

  if (!(Type.SourceLength == ShaderCreateInfo{}.SourceLength))
    WriteRSN(Json["SourceLength"], Type.SourceLength, Allocator);

  if (!SafeStrEqual(Type.EntryPoint, ShaderCreateInfo{}.EntryPoint))
    WriteRSN(Json["EntryPoint"], Type.EntryPoint, Allocator);

  if (!(Type.Macros == ShaderCreateInfo{}.Macros))
    WriteRSN(Json["Macros"], Type.Macros, Allocator);

  if (!(Type.Desc == ShaderCreateInfo{}.Desc))
    WriteRSN(Json["Desc"], Type.Desc, Allocator);

  if (!(Type.SourceLanguage == ShaderCreateInfo{}.SourceLanguage))
    WriteRSN(Json["SourceLanguage"], Type.SourceLanguage, Allocator);

  if (!(Type.ShaderCompiler == ShaderCreateInfo{}.ShaderCompiler))
    WriteRSN(Json["ShaderCompiler"], Type.ShaderCompiler, Allocator);

  if (!(Type.HLSLVersion == ShaderCreateInfo{}.HLSLVersion))
    WriteRSN(Json["HLSLVersion"], Type.HLSLVersion, Allocator);

  if (!(Type.GLSLVersion == ShaderCreateInfo{}.GLSLVersion))
    WriteRSN(Json["GLSLVersion"], Type.GLSLVersion, Allocator);

  if (!(Type.GLESSLVersion == ShaderCreateInfo{}.GLESSLVersion))
    WriteRSN(Json["GLESSLVersion"], Type.GLESSLVersion, Allocator);

  if (!(Type.MSLVersion == ShaderCreateInfo{}.MSLVersion))
    WriteRSN(Json["MSLVersion"], Type.MSLVersion, Allocator);

  if (!(Type.CompileFlags == ShaderCreateInfo{}.CompileFlags))
    WriteRSN(Json["CompileFlags"], Type.CompileFlags, Allocator);

  if (!(Type.LoadConstantBufferReflection ==
        ShaderCreateInfo{}.LoadConstantBufferReflection))
    WriteRSN(Json["LoadConstantBufferReflection"],
             Type.LoadConstantBufferReflection, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ShaderCreateInfo &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "FilePath",
                                        "Source",
                                        "ByteCode",
                                        "SourceLength",
                                        "ByteCodeSize",
                                        "EntryPoint",
                                        "Macros",
                                        "Desc",
                                        "SourceLanguage",
                                        "ShaderCompiler",
                                        "HLSLVersion",
                                        "GLSLVersion",
                                        "GLESSLVersion",
                                        "MSLVersion",
                                        "CompileFlags",
                                        "LoadConstantBufferReflection",
                                    });
  if (Json.contains("FilePath"))
    ParseRSN(Json["FilePath"], Type.FilePath, Allocator);

  if (Json.contains("Source"))
    ParseRSN(Json["Source"], Type.Source, Allocator);

  if (Json.contains("ByteCode"))
    ParseRSN(Json["ByteCode"], Type.ByteCode, Type.ByteCodeSize, Allocator);

  if (Json.contains("SourceLength"))
    ParseRSN(Json["SourceLength"], Type.SourceLength, Allocator);

  if (Json.contains("EntryPoint"))
    ParseRSN(Json["EntryPoint"], Type.EntryPoint, Allocator);

  if (Json.contains("Macros"))
    ParseRSN(Json["Macros"], Type.Macros, Allocator);

  if (Json.contains("Desc"))
    ParseRSN(Json["Desc"], Type.Desc, Allocator);

  if (Json.contains("SourceLanguage"))
    ParseRSN(Json["SourceLanguage"], Type.SourceLanguage, Allocator);

  if (Json.contains("ShaderCompiler"))
    ParseRSN(Json["ShaderCompiler"], Type.ShaderCompiler, Allocator);

  if (Json.contains("HLSLVersion"))
    ParseRSN(Json["HLSLVersion"], Type.HLSLVersion, Allocator);

  if (Json.contains("GLSLVersion"))
    ParseRSN(Json["GLSLVersion"], Type.GLSLVersion, Allocator);

  if (Json.contains("GLESSLVersion"))
    ParseRSN(Json["GLESSLVersion"], Type.GLESSLVersion, Allocator);

  if (Json.contains("MSLVersion"))
    ParseRSN(Json["MSLVersion"], Type.MSLVersion, Allocator);

  if (Json.contains("CompileFlags"))
    ParseRSN(Json["CompileFlags"], Type.CompileFlags, Allocator);

  if (Json.contains("LoadConstantBufferReflection"))
    ParseRSN(Json["LoadConstantBufferReflection"],
             Type.LoadConstantBufferReflection, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const ShaderResourceDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.Name, ShaderResourceDesc{}.Name))
    WriteRSN(Json["Name"], Type.Name, Allocator);

  if (!(Type.Type == ShaderResourceDesc{}.Type))
    WriteRSN(Json["Type"], Type.Type, Allocator);

  if (!(Type.ArraySize == ShaderResourceDesc{}.ArraySize))
    WriteRSN(Json["ArraySize"], Type.ArraySize, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ShaderResourceDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Name",
                                        "Type",
                                        "ArraySize",
                                    });
  if (Json.contains("Name"))
    ParseRSN(Json["Name"], Type.Name, Allocator);

  if (Json.contains("Type"))
    ParseRSN(Json["Type"], Type.Type, Allocator);

  if (Json.contains("ArraySize"))
    ParseRSN(Json["ArraySize"], Type.ArraySize, Allocator);
}

} // namespace Diligent
