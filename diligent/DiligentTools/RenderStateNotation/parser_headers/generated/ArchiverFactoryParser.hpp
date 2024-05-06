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
 *  In no event and under no legal theory, whether in tort (including negligence),
 *  contract, or otherwise, unless required by applicable law (such as deliberate
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental,
 *  or consequential damages of any character arising as a result of this License or
 *  out of the use or inability to use the software (including but not limited to damages
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and
 *  all other commercial damages or losses), even if such Contributor has been advised
 *  of the possibility of such damages.
 */

#pragma once

#include "ArchiverFactory.h"

namespace Diligent
{

inline void WriteRSN(nlohmann::json& Json, const SerializationDeviceD3D11Info& Type, DynamicLinearAllocator& Allocator)
{
    if (!(Type.FeatureLevel == SerializationDeviceD3D11Info{}.FeatureLevel))
        WriteRSN(Json["FeatureLevel"], Type.FeatureLevel, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, SerializationDeviceD3D11Info& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "FeatureLevel",
                                      });
    if (Json.contains("FeatureLevel"))
        ParseRSN(Json["FeatureLevel"], Type.FeatureLevel, Allocator);
}

inline void WriteRSN(nlohmann::json& Json, const SerializationDeviceD3D12Info& Type, DynamicLinearAllocator& Allocator)
{
    if (!(Type.ShaderVersion == SerializationDeviceD3D12Info{}.ShaderVersion))
        WriteRSN(Json["ShaderVersion"], Type.ShaderVersion, Allocator);

    if (!SafeStrEqual(Type.DxCompilerPath, SerializationDeviceD3D12Info{}.DxCompilerPath))
        WriteRSN(Json["DxCompilerPath"], Type.DxCompilerPath, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, SerializationDeviceD3D12Info& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "ShaderVersion",
                                          "DxCompilerPath",
                                      });
    if (Json.contains("ShaderVersion"))
        ParseRSN(Json["ShaderVersion"], Type.ShaderVersion, Allocator);

    if (Json.contains("DxCompilerPath"))
        ParseRSN(Json["DxCompilerPath"], Type.DxCompilerPath, Allocator);
}

inline void WriteRSN(nlohmann::json& Json, const SerializationDeviceVkInfo& Type, DynamicLinearAllocator& Allocator)
{
    if (!(Type.ApiVersion == SerializationDeviceVkInfo{}.ApiVersion))
        WriteRSN(Json["ApiVersion"], Type.ApiVersion, Allocator);

    if (!(Type.SupportsSpirv14 == SerializationDeviceVkInfo{}.SupportsSpirv14))
        WriteRSN(Json["SupportsSpirv14"], Type.SupportsSpirv14, Allocator);

    if (!SafeStrEqual(Type.DxCompilerPath, SerializationDeviceVkInfo{}.DxCompilerPath))
        WriteRSN(Json["DxCompilerPath"], Type.DxCompilerPath, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, SerializationDeviceVkInfo& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "ApiVersion",
                                          "SupportsSpirv14",
                                          "DxCompilerPath",
                                      });
    if (Json.contains("ApiVersion"))
        ParseRSN(Json["ApiVersion"], Type.ApiVersion, Allocator);

    if (Json.contains("SupportsSpirv14"))
        ParseRSN(Json["SupportsSpirv14"], Type.SupportsSpirv14, Allocator);

    if (Json.contains("DxCompilerPath"))
        ParseRSN(Json["DxCompilerPath"], Type.DxCompilerPath, Allocator);
}

inline void WriteRSN(nlohmann::json& Json, const SerializationDeviceMtlInfo& Type, DynamicLinearAllocator& Allocator)
{
    if (!SafeStrEqual(Type.CompileOptionsMacOS, SerializationDeviceMtlInfo{}.CompileOptionsMacOS))
        WriteRSN(Json["CompileOptionsMacOS"], Type.CompileOptionsMacOS, Allocator);

    if (!SafeStrEqual(Type.CompileOptionsiOS, SerializationDeviceMtlInfo{}.CompileOptionsiOS))
        WriteRSN(Json["CompileOptionsiOS"], Type.CompileOptionsiOS, Allocator);

    if (!SafeStrEqual(Type.MslPreprocessorCmd, SerializationDeviceMtlInfo{}.MslPreprocessorCmd))
        WriteRSN(Json["MslPreprocessorCmd"], Type.MslPreprocessorCmd, Allocator);

    if (!SafeStrEqual(Type.DumpDirectory, SerializationDeviceMtlInfo{}.DumpDirectory))
        WriteRSN(Json["DumpDirectory"], Type.DumpDirectory, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, SerializationDeviceMtlInfo& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "CompileOptionsMacOS",
                                          "CompileOptionsiOS",
                                          "MslPreprocessorCmd",
                                          "DumpDirectory",
                                      });
    if (Json.contains("CompileOptionsMacOS"))
        ParseRSN(Json["CompileOptionsMacOS"], Type.CompileOptionsMacOS, Allocator);

    if (Json.contains("CompileOptionsiOS"))
        ParseRSN(Json["CompileOptionsiOS"], Type.CompileOptionsiOS, Allocator);

    if (Json.contains("MslPreprocessorCmd"))
        ParseRSN(Json["MslPreprocessorCmd"], Type.MslPreprocessorCmd, Allocator);

    if (Json.contains("DumpDirectory"))
        ParseRSN(Json["DumpDirectory"], Type.DumpDirectory, Allocator);
}

inline void WriteRSN(nlohmann::json& Json, const SerializationDeviceCreateInfo& Type, DynamicLinearAllocator& Allocator)
{
    if (!(Type.DeviceInfo == SerializationDeviceCreateInfo{}.DeviceInfo))
        WriteRSN(Json["DeviceInfo"], Type.DeviceInfo, Allocator);

    if (!(Type.AdapterInfo == SerializationDeviceCreateInfo{}.AdapterInfo))
        WriteRSN(Json["AdapterInfo"], Type.AdapterInfo, Allocator);

    if (!(Type.D3D11 == SerializationDeviceCreateInfo{}.D3D11))
        WriteRSN(Json["D3D11"], Type.D3D11, Allocator);

    if (!(Type.D3D12 == SerializationDeviceCreateInfo{}.D3D12))
        WriteRSN(Json["D3D12"], Type.D3D12, Allocator);

    if (!(Type.Vulkan == SerializationDeviceCreateInfo{}.Vulkan))
        WriteRSN(Json["Vulkan"], Type.Vulkan, Allocator);

    if (!(Type.Metal == SerializationDeviceCreateInfo{}.Metal))
        WriteRSN(Json["Metal"], Type.Metal, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, SerializationDeviceCreateInfo& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "DeviceInfo",
                                          "AdapterInfo",
                                          "D3D11",
                                          "D3D12",
                                          "Vulkan",
                                          "Metal",
                                      });
    if (Json.contains("DeviceInfo"))
        ParseRSN(Json["DeviceInfo"], Type.DeviceInfo, Allocator);

    if (Json.contains("AdapterInfo"))
        ParseRSN(Json["AdapterInfo"], Type.AdapterInfo, Allocator);

    if (Json.contains("D3D11"))
        ParseRSN(Json["D3D11"], Type.D3D11, Allocator);

    if (Json.contains("D3D12"))
        ParseRSN(Json["D3D12"], Type.D3D12, Allocator);

    if (Json.contains("Vulkan"))
        ParseRSN(Json["Vulkan"], Type.Vulkan, Allocator);

    if (Json.contains("Metal"))
        ParseRSN(Json["Metal"], Type.Metal, Allocator);
}

} // namespace Diligent
