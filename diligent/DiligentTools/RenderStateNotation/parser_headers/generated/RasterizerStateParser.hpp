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

#include "RasterizerState.h"

namespace Diligent {

NLOHMANN_JSON_SERIALIZE_ENUM_EX(FILL_MODE,
                                {
                                    {FILL_MODE_UNDEFINED, "UNDEFINED"},
                                    {FILL_MODE_WIREFRAME, "WIREFRAME"},
                                    {FILL_MODE_SOLID, "SOLID"},
                                    {FILL_MODE_NUM_MODES, "NUM_MODES"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(CULL_MODE,
                                {
                                    {CULL_MODE_UNDEFINED, "UNDEFINED"},
                                    {CULL_MODE_NONE, "NONE"},
                                    {CULL_MODE_FRONT, "FRONT"},
                                    {CULL_MODE_BACK, "BACK"},
                                    {CULL_MODE_NUM_MODES, "NUM_MODES"},
                                })

inline void WriteRSN(nlohmann::json &Json, const RasterizerStateDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.FillMode == RasterizerStateDesc{}.FillMode))
    WriteRSN(Json["FillMode"], Type.FillMode, Allocator);

  if (!(Type.CullMode == RasterizerStateDesc{}.CullMode))
    WriteRSN(Json["CullMode"], Type.CullMode, Allocator);

  if (!(Type.FrontCounterClockwise ==
        RasterizerStateDesc{}.FrontCounterClockwise))
    WriteRSN(Json["FrontCounterClockwise"], Type.FrontCounterClockwise,
             Allocator);

  if (!(Type.DepthClipEnable == RasterizerStateDesc{}.DepthClipEnable))
    WriteRSN(Json["DepthClipEnable"], Type.DepthClipEnable, Allocator);

  if (!(Type.ScissorEnable == RasterizerStateDesc{}.ScissorEnable))
    WriteRSN(Json["ScissorEnable"], Type.ScissorEnable, Allocator);

  if (!(Type.AntialiasedLineEnable ==
        RasterizerStateDesc{}.AntialiasedLineEnable))
    WriteRSN(Json["AntialiasedLineEnable"], Type.AntialiasedLineEnable,
             Allocator);

  if (!(Type.DepthBias == RasterizerStateDesc{}.DepthBias))
    WriteRSN(Json["DepthBias"], Type.DepthBias, Allocator);

  if (!(Type.DepthBiasClamp == RasterizerStateDesc{}.DepthBiasClamp))
    WriteRSN(Json["DepthBiasClamp"], Type.DepthBiasClamp, Allocator);

  if (!(Type.SlopeScaledDepthBias ==
        RasterizerStateDesc{}.SlopeScaledDepthBias))
    WriteRSN(Json["SlopeScaledDepthBias"], Type.SlopeScaledDepthBias,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, RasterizerStateDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "FillMode",
                                        "CullMode",
                                        "FrontCounterClockwise",
                                        "DepthClipEnable",
                                        "ScissorEnable",
                                        "AntialiasedLineEnable",
                                        "DepthBias",
                                        "DepthBiasClamp",
                                        "SlopeScaledDepthBias",
                                    });
  if (Json.contains("FillMode"))
    ParseRSN(Json["FillMode"], Type.FillMode, Allocator);

  if (Json.contains("CullMode"))
    ParseRSN(Json["CullMode"], Type.CullMode, Allocator);

  if (Json.contains("FrontCounterClockwise"))
    ParseRSN(Json["FrontCounterClockwise"], Type.FrontCounterClockwise,
             Allocator);

  if (Json.contains("DepthClipEnable"))
    ParseRSN(Json["DepthClipEnable"], Type.DepthClipEnable, Allocator);

  if (Json.contains("ScissorEnable"))
    ParseRSN(Json["ScissorEnable"], Type.ScissorEnable, Allocator);

  if (Json.contains("AntialiasedLineEnable"))
    ParseRSN(Json["AntialiasedLineEnable"], Type.AntialiasedLineEnable,
             Allocator);

  if (Json.contains("DepthBias"))
    ParseRSN(Json["DepthBias"], Type.DepthBias, Allocator);

  if (Json.contains("DepthBiasClamp"))
    ParseRSN(Json["DepthBiasClamp"], Type.DepthBiasClamp, Allocator);

  if (Json.contains("SlopeScaledDepthBias"))
    ParseRSN(Json["SlopeScaledDepthBias"], Type.SlopeScaledDepthBias,
             Allocator);
}

} // namespace Diligent
