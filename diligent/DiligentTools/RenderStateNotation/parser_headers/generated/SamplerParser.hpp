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

#include "Sampler.h"

namespace Diligent
{

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    SAMPLER_FLAGS,
    {
        {SAMPLER_FLAG_NONE, "NONE"},
        {SAMPLER_FLAG_SUBSAMPLED, "SUBSAMPLED"},
        {SAMPLER_FLAG_SUBSAMPLED_COARSE_RECONSTRUCTION, "SUBSAMPLED_COARSE_RECONSTRUCTION"},
        {SAMPLER_FLAG_LAST, "LAST"},
    })

inline void WriteRSN(nlohmann::json& Json, const SamplerDesc& Type, DynamicLinearAllocator& Allocator)
{
    if (!SafeStrEqual(Type.Name, SamplerDesc{}.Name))
        WriteRSN(Json["Name"], Type.Name, Allocator);

    if (!(Type.MinFilter == SamplerDesc{}.MinFilter))
        WriteRSN(Json["MinFilter"], Type.MinFilter, Allocator);

    if (!(Type.MagFilter == SamplerDesc{}.MagFilter))
        WriteRSN(Json["MagFilter"], Type.MagFilter, Allocator);

    if (!(Type.MipFilter == SamplerDesc{}.MipFilter))
        WriteRSN(Json["MipFilter"], Type.MipFilter, Allocator);

    if (!(Type.AddressU == SamplerDesc{}.AddressU))
        WriteRSN(Json["AddressU"], Type.AddressU, Allocator);

    if (!(Type.AddressV == SamplerDesc{}.AddressV))
        WriteRSN(Json["AddressV"], Type.AddressV, Allocator);

    if (!(Type.AddressW == SamplerDesc{}.AddressW))
        WriteRSN(Json["AddressW"], Type.AddressW, Allocator);

    if (!(Type.Flags == SamplerDesc{}.Flags))
        SerializeBitwiseEnum(Json["Flags"], Type.Flags, Allocator);

    if (!(Type.UnnormalizedCoords == SamplerDesc{}.UnnormalizedCoords))
        WriteRSN(Json["UnnormalizedCoords"], Type.UnnormalizedCoords, Allocator);

    if (!(Type.MipLODBias == SamplerDesc{}.MipLODBias))
        WriteRSN(Json["MipLODBias"], Type.MipLODBias, Allocator);

    if (!(Type.MaxAnisotropy == SamplerDesc{}.MaxAnisotropy))
        WriteRSN(Json["MaxAnisotropy"], Type.MaxAnisotropy, Allocator);

    if (!(Type.ComparisonFunc == SamplerDesc{}.ComparisonFunc))
        WriteRSN(Json["ComparisonFunc"], Type.ComparisonFunc, Allocator);

    if (!CompareConstArray(Type.BorderColor, SamplerDesc{}.BorderColor))
        SerializeConstArray(Json["BorderColor"], Type.BorderColor, Allocator);

    if (!(Type.MinLOD == SamplerDesc{}.MinLOD))
        WriteRSN(Json["MinLOD"], Type.MinLOD, Allocator);

    if (!(Type.MaxLOD == SamplerDesc{}.MaxLOD))
        WriteRSN(Json["MaxLOD"], Type.MaxLOD, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, SamplerDesc& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "Name",
                                          "MinFilter",
                                          "MagFilter",
                                          "MipFilter",
                                          "AddressU",
                                          "AddressV",
                                          "AddressW",
                                          "Flags",
                                          "UnnormalizedCoords",
                                          "MipLODBias",
                                          "MaxAnisotropy",
                                          "ComparisonFunc",
                                          "BorderColor",
                                          "MinLOD",
                                          "MaxLOD",
                                      });
    if (Json.contains("Name"))
        ParseRSN(Json["Name"], Type.Name, Allocator);

    if (Json.contains("MinFilter"))
        ParseRSN(Json["MinFilter"], Type.MinFilter, Allocator);

    if (Json.contains("MagFilter"))
        ParseRSN(Json["MagFilter"], Type.MagFilter, Allocator);

    if (Json.contains("MipFilter"))
        ParseRSN(Json["MipFilter"], Type.MipFilter, Allocator);

    if (Json.contains("AddressU"))
        ParseRSN(Json["AddressU"], Type.AddressU, Allocator);

    if (Json.contains("AddressV"))
        ParseRSN(Json["AddressV"], Type.AddressV, Allocator);

    if (Json.contains("AddressW"))
        ParseRSN(Json["AddressW"], Type.AddressW, Allocator);

    if (Json.contains("Flags"))
        DeserializeBitwiseEnum(Json["Flags"], Type.Flags, Allocator);

    if (Json.contains("UnnormalizedCoords"))
        ParseRSN(Json["UnnormalizedCoords"], Type.UnnormalizedCoords, Allocator);

    if (Json.contains("MipLODBias"))
        ParseRSN(Json["MipLODBias"], Type.MipLODBias, Allocator);

    if (Json.contains("MaxAnisotropy"))
        ParseRSN(Json["MaxAnisotropy"], Type.MaxAnisotropy, Allocator);

    if (Json.contains("ComparisonFunc"))
        ParseRSN(Json["ComparisonFunc"], Type.ComparisonFunc, Allocator);

    if (Json.contains("BorderColor"))
        DeserializeConstArray(Json["BorderColor"], Type.BorderColor, Allocator);

    if (Json.contains("MinLOD"))
        ParseRSN(Json["MinLOD"], Type.MinLOD, Allocator);

    if (Json.contains("MaxLOD"))
        ParseRSN(Json["MaxLOD"], Type.MaxLOD, Allocator);
}

} // namespace Diligent
