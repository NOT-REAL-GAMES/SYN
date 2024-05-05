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

#include "BlendState.h"

namespace Diligent {

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    BLEND_FACTOR, {
                      {BLEND_FACTOR_UNDEFINED, "UNDEFINED"},
                      {BLEND_FACTOR_ZERO, "ZERO"},
                      {BLEND_FACTOR_ONE, "ONE"},
                      {BLEND_FACTOR_SRC_COLOR, "SRC_COLOR"},
                      {BLEND_FACTOR_INV_SRC_COLOR, "INV_SRC_COLOR"},
                      {BLEND_FACTOR_SRC_ALPHA, "SRC_ALPHA"},
                      {BLEND_FACTOR_INV_SRC_ALPHA, "INV_SRC_ALPHA"},
                      {BLEND_FACTOR_DEST_ALPHA, "DEST_ALPHA"},
                      {BLEND_FACTOR_INV_DEST_ALPHA, "INV_DEST_ALPHA"},
                      {BLEND_FACTOR_DEST_COLOR, "DEST_COLOR"},
                      {BLEND_FACTOR_INV_DEST_COLOR, "INV_DEST_COLOR"},
                      {BLEND_FACTOR_SRC_ALPHA_SAT, "SRC_ALPHA_SAT"},
                      {BLEND_FACTOR_BLEND_FACTOR, "BLEND_FACTOR"},
                      {BLEND_FACTOR_INV_BLEND_FACTOR, "INV_BLEND_FACTOR"},
                      {BLEND_FACTOR_SRC1_COLOR, "SRC1_COLOR"},
                      {BLEND_FACTOR_INV_SRC1_COLOR, "INV_SRC1_COLOR"},
                      {BLEND_FACTOR_SRC1_ALPHA, "SRC1_ALPHA"},
                      {BLEND_FACTOR_INV_SRC1_ALPHA, "INV_SRC1_ALPHA"},
                      {BLEND_FACTOR_NUM_FACTORS, "NUM_FACTORS"},
                  })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(
    BLEND_OPERATION, {
                         {BLEND_OPERATION_UNDEFINED, "UNDEFINED"},
                         {BLEND_OPERATION_ADD, "ADD"},
                         {BLEND_OPERATION_SUBTRACT, "SUBTRACT"},
                         {BLEND_OPERATION_REV_SUBTRACT, "REV_SUBTRACT"},
                         {BLEND_OPERATION_MIN, "MIN"},
                         {BLEND_OPERATION_MAX, "MAX"},
                         {BLEND_OPERATION_NUM_OPERATIONS, "NUM_OPERATIONS"},
                     })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(COLOR_MASK, {
                                                {COLOR_MASK_NONE, "NONE"},
                                                {COLOR_MASK_RED, "RED"},
                                                {COLOR_MASK_GREEN, "GREEN"},
                                                {COLOR_MASK_BLUE, "BLUE"},
                                                {COLOR_MASK_ALPHA, "ALPHA"},
                                                {COLOR_MASK_ALL, "ALL"},
                                            })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(LOGIC_OPERATION,
                                {
                                    {LOGIC_OP_CLEAR, "CLEAR"},
                                    {LOGIC_OP_SET, "SET"},
                                    {LOGIC_OP_COPY, "COPY"},
                                    {LOGIC_OP_COPY_INVERTED, "COPY_INVERTED"},
                                    {LOGIC_OP_NOOP, "NOOP"},
                                    {LOGIC_OP_INVERT, "INVERT"},
                                    {LOGIC_OP_AND, "AND"},
                                    {LOGIC_OP_NAND, "NAND"},
                                    {LOGIC_OP_OR, "OR"},
                                    {LOGIC_OP_NOR, "NOR"},
                                    {LOGIC_OP_XOR, "XOR"},
                                    {LOGIC_OP_EQUIV, "EQUIV"},
                                    {LOGIC_OP_AND_REVERSE, "AND_REVERSE"},
                                    {LOGIC_OP_AND_INVERTED, "AND_INVERTED"},
                                    {LOGIC_OP_OR_REVERSE, "OR_REVERSE"},
                                    {LOGIC_OP_OR_INVERTED, "OR_INVERTED"},
                                    {LOGIC_OP_NUM_OPERATIONS, "NUM_OPERATIONS"},
                                })

inline void WriteRSN(nlohmann::json &Json, const RenderTargetBlendDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.BlendEnable == RenderTargetBlendDesc{}.BlendEnable))
    WriteRSN(Json["BlendEnable"], Type.BlendEnable, Allocator);

  if (!(Type.LogicOperationEnable ==
        RenderTargetBlendDesc{}.LogicOperationEnable))
    WriteRSN(Json["LogicOperationEnable"], Type.LogicOperationEnable,
             Allocator);

  if (!(Type.SrcBlend == RenderTargetBlendDesc{}.SrcBlend))
    WriteRSN(Json["SrcBlend"], Type.SrcBlend, Allocator);

  if (!(Type.DestBlend == RenderTargetBlendDesc{}.DestBlend))
    WriteRSN(Json["DestBlend"], Type.DestBlend, Allocator);

  if (!(Type.BlendOp == RenderTargetBlendDesc{}.BlendOp))
    WriteRSN(Json["BlendOp"], Type.BlendOp, Allocator);

  if (!(Type.SrcBlendAlpha == RenderTargetBlendDesc{}.SrcBlendAlpha))
    WriteRSN(Json["SrcBlendAlpha"], Type.SrcBlendAlpha, Allocator);

  if (!(Type.DestBlendAlpha == RenderTargetBlendDesc{}.DestBlendAlpha))
    WriteRSN(Json["DestBlendAlpha"], Type.DestBlendAlpha, Allocator);

  if (!(Type.BlendOpAlpha == RenderTargetBlendDesc{}.BlendOpAlpha))
    WriteRSN(Json["BlendOpAlpha"], Type.BlendOpAlpha, Allocator);

  if (!(Type.LogicOp == RenderTargetBlendDesc{}.LogicOp))
    WriteRSN(Json["LogicOp"], Type.LogicOp, Allocator);

  if (!(Type.RenderTargetWriteMask ==
        RenderTargetBlendDesc{}.RenderTargetWriteMask))
    SerializeBitwiseEnum(Json["RenderTargetWriteMask"],
                         Type.RenderTargetWriteMask, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, RenderTargetBlendDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "BlendEnable",
                                        "LogicOperationEnable",
                                        "SrcBlend",
                                        "DestBlend",
                                        "BlendOp",
                                        "SrcBlendAlpha",
                                        "DestBlendAlpha",
                                        "BlendOpAlpha",
                                        "LogicOp",
                                        "RenderTargetWriteMask",
                                    });
  if (Json.contains("BlendEnable"))
    ParseRSN(Json["BlendEnable"], Type.BlendEnable, Allocator);

  if (Json.contains("LogicOperationEnable"))
    ParseRSN(Json["LogicOperationEnable"], Type.LogicOperationEnable,
             Allocator);

  if (Json.contains("SrcBlend"))
    ParseRSN(Json["SrcBlend"], Type.SrcBlend, Allocator);

  if (Json.contains("DestBlend"))
    ParseRSN(Json["DestBlend"], Type.DestBlend, Allocator);

  if (Json.contains("BlendOp"))
    ParseRSN(Json["BlendOp"], Type.BlendOp, Allocator);

  if (Json.contains("SrcBlendAlpha"))
    ParseRSN(Json["SrcBlendAlpha"], Type.SrcBlendAlpha, Allocator);

  if (Json.contains("DestBlendAlpha"))
    ParseRSN(Json["DestBlendAlpha"], Type.DestBlendAlpha, Allocator);

  if (Json.contains("BlendOpAlpha"))
    ParseRSN(Json["BlendOpAlpha"], Type.BlendOpAlpha, Allocator);

  if (Json.contains("LogicOp"))
    ParseRSN(Json["LogicOp"], Type.LogicOp, Allocator);

  if (Json.contains("RenderTargetWriteMask"))
    DeserializeBitwiseEnum(Json["RenderTargetWriteMask"],
                           Type.RenderTargetWriteMask, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const BlendStateDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.AlphaToCoverageEnable == BlendStateDesc{}.AlphaToCoverageEnable))
    WriteRSN(Json["AlphaToCoverageEnable"], Type.AlphaToCoverageEnable,
             Allocator);

  if (!(Type.IndependentBlendEnable == BlendStateDesc{}.IndependentBlendEnable))
    WriteRSN(Json["IndependentBlendEnable"], Type.IndependentBlendEnable,
             Allocator);

  if (!CompareConstArray(Type.RenderTargets, BlendStateDesc{}.RenderTargets))
    SerializeConstArray(Json["RenderTargets"], Type.RenderTargets, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, BlendStateDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "AlphaToCoverageEnable",
                                        "IndependentBlendEnable",
                                        "RenderTargets",
                                    });
  if (Json.contains("AlphaToCoverageEnable"))
    ParseRSN(Json["AlphaToCoverageEnable"], Type.AlphaToCoverageEnable,
             Allocator);

  if (Json.contains("IndependentBlendEnable"))
    ParseRSN(Json["IndependentBlendEnable"], Type.IndependentBlendEnable,
             Allocator);

  if (Json.contains("RenderTargets"))
    DeserializeConstArray(Json["RenderTargets"], Type.RenderTargets, Allocator);
}

} // namespace Diligent
