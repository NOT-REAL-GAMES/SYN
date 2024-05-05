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

#include "InputLayout.h"

namespace Diligent {

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    INPUT_ELEMENT_FREQUENCY,
    {
        {INPUT_ELEMENT_FREQUENCY_UNDEFINED, "UNDEFINED"},
        {INPUT_ELEMENT_FREQUENCY_PER_VERTEX, "PER_VERTEX"},
        {INPUT_ELEMENT_FREQUENCY_PER_INSTANCE, "PER_INSTANCE"},
        {INPUT_ELEMENT_FREQUENCY_NUM_FREQUENCIES, "NUM_FREQUENCIES"},
    })

inline void WriteRSN(nlohmann::json &Json, const LayoutElement &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.HLSLSemantic, LayoutElement{}.HLSLSemantic))
    WriteRSN(Json["HLSLSemantic"], Type.HLSLSemantic, Allocator);

  if (!(Type.InputIndex == LayoutElement{}.InputIndex))
    WriteRSN(Json["InputIndex"], Type.InputIndex, Allocator);

  if (!(Type.BufferSlot == LayoutElement{}.BufferSlot))
    WriteRSN(Json["BufferSlot"], Type.BufferSlot, Allocator);

  if (!(Type.NumComponents == LayoutElement{}.NumComponents))
    WriteRSN(Json["NumComponents"], Type.NumComponents, Allocator);

  if (!(Type.ValueType == LayoutElement{}.ValueType))
    WriteRSN(Json["ValueType"], Type.ValueType, Allocator);

  if (!(Type.IsNormalized == LayoutElement{}.IsNormalized))
    WriteRSN(Json["IsNormalized"], Type.IsNormalized, Allocator);

  if (!(Type.RelativeOffset == LayoutElement{}.RelativeOffset))
    WriteRSN(Json["RelativeOffset"], Type.RelativeOffset, Allocator);

  if (!(Type.Stride == LayoutElement{}.Stride))
    WriteRSN(Json["Stride"], Type.Stride, Allocator);

  if (!(Type.Frequency == LayoutElement{}.Frequency))
    WriteRSN(Json["Frequency"], Type.Frequency, Allocator);

  if (!(Type.InstanceDataStepRate == LayoutElement{}.InstanceDataStepRate))
    WriteRSN(Json["InstanceDataStepRate"], Type.InstanceDataStepRate,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, LayoutElement &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "HLSLSemantic",
                                        "InputIndex",
                                        "BufferSlot",
                                        "NumComponents",
                                        "ValueType",
                                        "IsNormalized",
                                        "RelativeOffset",
                                        "Stride",
                                        "Frequency",
                                        "InstanceDataStepRate",
                                    });
  if (Json.contains("HLSLSemantic"))
    ParseRSN(Json["HLSLSemantic"], Type.HLSLSemantic, Allocator);

  if (Json.contains("InputIndex"))
    ParseRSN(Json["InputIndex"], Type.InputIndex, Allocator);

  if (Json.contains("BufferSlot"))
    ParseRSN(Json["BufferSlot"], Type.BufferSlot, Allocator);

  if (Json.contains("NumComponents"))
    ParseRSN(Json["NumComponents"], Type.NumComponents, Allocator);

  if (Json.contains("ValueType"))
    ParseRSN(Json["ValueType"], Type.ValueType, Allocator);

  if (Json.contains("IsNormalized"))
    ParseRSN(Json["IsNormalized"], Type.IsNormalized, Allocator);

  if (Json.contains("RelativeOffset"))
    ParseRSN(Json["RelativeOffset"], Type.RelativeOffset, Allocator);

  if (Json.contains("Stride"))
    ParseRSN(Json["Stride"], Type.Stride, Allocator);

  if (Json.contains("Frequency"))
    ParseRSN(Json["Frequency"], Type.Frequency, Allocator);

  if (Json.contains("InstanceDataStepRate"))
    ParseRSN(Json["InstanceDataStepRate"], Type.InstanceDataStepRate,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const InputLayoutDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.LayoutElements == InputLayoutDesc{}.LayoutElements))
    WriteRSN(Json["LayoutElements"], Type.LayoutElements, Type.NumElements,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, InputLayoutDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "LayoutElements",
                                        "NumElements",
                                    });
  if (Json.contains("LayoutElements"))
    ParseRSN(Json["LayoutElements"], Type.LayoutElements, Type.NumElements,
             Allocator);
}

} // namespace Diligent
