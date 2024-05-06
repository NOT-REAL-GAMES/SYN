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

#include "DepthStencilState.h"

namespace Diligent
{

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    STENCIL_OP,
    {
        {STENCIL_OP_UNDEFINED, "UNDEFINED"},
        {STENCIL_OP_KEEP, "KEEP"},
        {STENCIL_OP_ZERO, "ZERO"},
        {STENCIL_OP_REPLACE, "REPLACE"},
        {STENCIL_OP_INCR_SAT, "INCR_SAT"},
        {STENCIL_OP_DECR_SAT, "DECR_SAT"},
        {STENCIL_OP_INVERT, "INVERT"},
        {STENCIL_OP_INCR_WRAP, "INCR_WRAP"},
        {STENCIL_OP_DECR_WRAP, "DECR_WRAP"},
        {STENCIL_OP_NUM_OPS, "NUM_OPS"},
    })

inline void WriteRSN(nlohmann::json& Json, const StencilOpDesc& Type, DynamicLinearAllocator& Allocator)
{
    if (!(Type.StencilFailOp == StencilOpDesc{}.StencilFailOp))
        WriteRSN(Json["StencilFailOp"], Type.StencilFailOp, Allocator);

    if (!(Type.StencilDepthFailOp == StencilOpDesc{}.StencilDepthFailOp))
        WriteRSN(Json["StencilDepthFailOp"], Type.StencilDepthFailOp, Allocator);

    if (!(Type.StencilPassOp == StencilOpDesc{}.StencilPassOp))
        WriteRSN(Json["StencilPassOp"], Type.StencilPassOp, Allocator);

    if (!(Type.StencilFunc == StencilOpDesc{}.StencilFunc))
        WriteRSN(Json["StencilFunc"], Type.StencilFunc, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, StencilOpDesc& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "StencilFailOp",
                                          "StencilDepthFailOp",
                                          "StencilPassOp",
                                          "StencilFunc",
                                      });
    if (Json.contains("StencilFailOp"))
        ParseRSN(Json["StencilFailOp"], Type.StencilFailOp, Allocator);

    if (Json.contains("StencilDepthFailOp"))
        ParseRSN(Json["StencilDepthFailOp"], Type.StencilDepthFailOp, Allocator);

    if (Json.contains("StencilPassOp"))
        ParseRSN(Json["StencilPassOp"], Type.StencilPassOp, Allocator);

    if (Json.contains("StencilFunc"))
        ParseRSN(Json["StencilFunc"], Type.StencilFunc, Allocator);
}

inline void WriteRSN(nlohmann::json& Json, const DepthStencilStateDesc& Type, DynamicLinearAllocator& Allocator)
{
    if (!(Type.DepthEnable == DepthStencilStateDesc{}.DepthEnable))
        WriteRSN(Json["DepthEnable"], Type.DepthEnable, Allocator);

    if (!(Type.DepthWriteEnable == DepthStencilStateDesc{}.DepthWriteEnable))
        WriteRSN(Json["DepthWriteEnable"], Type.DepthWriteEnable, Allocator);

    if (!(Type.DepthFunc == DepthStencilStateDesc{}.DepthFunc))
        WriteRSN(Json["DepthFunc"], Type.DepthFunc, Allocator);

    if (!(Type.StencilEnable == DepthStencilStateDesc{}.StencilEnable))
        WriteRSN(Json["StencilEnable"], Type.StencilEnable, Allocator);

    if (!(Type.StencilReadMask == DepthStencilStateDesc{}.StencilReadMask))
        WriteRSN(Json["StencilReadMask"], Type.StencilReadMask, Allocator);

    if (!(Type.StencilWriteMask == DepthStencilStateDesc{}.StencilWriteMask))
        WriteRSN(Json["StencilWriteMask"], Type.StencilWriteMask, Allocator);

    if (!(Type.FrontFace == DepthStencilStateDesc{}.FrontFace))
        WriteRSN(Json["FrontFace"], Type.FrontFace, Allocator);

    if (!(Type.BackFace == DepthStencilStateDesc{}.BackFace))
        WriteRSN(Json["BackFace"], Type.BackFace, Allocator);
}

inline void ParseRSN(const nlohmann::json& Json, DepthStencilStateDesc& Type, DynamicLinearAllocator& Allocator)
{
    NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                          "DepthEnable",
                                          "DepthWriteEnable",
                                          "DepthFunc",
                                          "StencilEnable",
                                          "StencilReadMask",
                                          "StencilWriteMask",
                                          "FrontFace",
                                          "BackFace",
                                      });
    if (Json.contains("DepthEnable"))
        ParseRSN(Json["DepthEnable"], Type.DepthEnable, Allocator);

    if (Json.contains("DepthWriteEnable"))
        ParseRSN(Json["DepthWriteEnable"], Type.DepthWriteEnable, Allocator);

    if (Json.contains("DepthFunc"))
        ParseRSN(Json["DepthFunc"], Type.DepthFunc, Allocator);

    if (Json.contains("StencilEnable"))
        ParseRSN(Json["StencilEnable"], Type.StencilEnable, Allocator);

    if (Json.contains("StencilReadMask"))
        ParseRSN(Json["StencilReadMask"], Type.StencilReadMask, Allocator);

    if (Json.contains("StencilWriteMask"))
        ParseRSN(Json["StencilWriteMask"], Type.StencilWriteMask, Allocator);

    if (Json.contains("FrontFace"))
        ParseRSN(Json["FrontFace"], Type.FrontFace, Allocator);

    if (Json.contains("BackFace"))
        ParseRSN(Json["BackFace"], Type.BackFace, Allocator);
}

} // namespace Diligent
