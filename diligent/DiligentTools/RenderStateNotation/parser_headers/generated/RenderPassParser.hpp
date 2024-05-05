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

#include "RenderPass.h"

namespace Diligent {

NLOHMANN_JSON_SERIALIZE_ENUM_EX(ATTACHMENT_LOAD_OP,
                                {
                                    {ATTACHMENT_LOAD_OP_LOAD, "LOAD"},
                                    {ATTACHMENT_LOAD_OP_CLEAR, "CLEAR"},
                                    {ATTACHMENT_LOAD_OP_DISCARD, "DISCARD"},
                                    {ATTACHMENT_LOAD_OP_COUNT, "COUNT"},
                                })

NLOHMANN_JSON_SERIALIZE_ENUM_EX(ATTACHMENT_STORE_OP,
                                {
                                    {ATTACHMENT_STORE_OP_STORE, "STORE"},
                                    {ATTACHMENT_STORE_OP_DISCARD, "DISCARD"},
                                    {ATTACHMENT_STORE_OP_COUNT, "COUNT"},
                                })

inline void WriteRSN(nlohmann::json &Json, const RenderPassAttachmentDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.Format == RenderPassAttachmentDesc{}.Format))
    WriteRSN(Json["Format"], Type.Format, Allocator);

  if (!(Type.SampleCount == RenderPassAttachmentDesc{}.SampleCount))
    WriteRSN(Json["SampleCount"], Type.SampleCount, Allocator);

  if (!(Type.LoadOp == RenderPassAttachmentDesc{}.LoadOp))
    WriteRSN(Json["LoadOp"], Type.LoadOp, Allocator);

  if (!(Type.StoreOp == RenderPassAttachmentDesc{}.StoreOp))
    WriteRSN(Json["StoreOp"], Type.StoreOp, Allocator);

  if (!(Type.StencilLoadOp == RenderPassAttachmentDesc{}.StencilLoadOp))
    WriteRSN(Json["StencilLoadOp"], Type.StencilLoadOp, Allocator);

  if (!(Type.StencilStoreOp == RenderPassAttachmentDesc{}.StencilStoreOp))
    WriteRSN(Json["StencilStoreOp"], Type.StencilStoreOp, Allocator);

  if (!(Type.InitialState == RenderPassAttachmentDesc{}.InitialState))
    SerializeBitwiseEnum(Json["InitialState"], Type.InitialState, Allocator);

  if (!(Type.FinalState == RenderPassAttachmentDesc{}.FinalState))
    SerializeBitwiseEnum(Json["FinalState"], Type.FinalState, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, RenderPassAttachmentDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Format",
                                        "SampleCount",
                                        "LoadOp",
                                        "StoreOp",
                                        "StencilLoadOp",
                                        "StencilStoreOp",
                                        "InitialState",
                                        "FinalState",
                                    });
  if (Json.contains("Format"))
    ParseRSN(Json["Format"], Type.Format, Allocator);

  if (Json.contains("SampleCount"))
    ParseRSN(Json["SampleCount"], Type.SampleCount, Allocator);

  if (Json.contains("LoadOp"))
    ParseRSN(Json["LoadOp"], Type.LoadOp, Allocator);

  if (Json.contains("StoreOp"))
    ParseRSN(Json["StoreOp"], Type.StoreOp, Allocator);

  if (Json.contains("StencilLoadOp"))
    ParseRSN(Json["StencilLoadOp"], Type.StencilLoadOp, Allocator);

  if (Json.contains("StencilStoreOp"))
    ParseRSN(Json["StencilStoreOp"], Type.StencilStoreOp, Allocator);

  if (Json.contains("InitialState"))
    DeserializeBitwiseEnum(Json["InitialState"], Type.InitialState, Allocator);

  if (Json.contains("FinalState"))
    DeserializeBitwiseEnum(Json["FinalState"], Type.FinalState, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const AttachmentReference &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.AttachmentIndex == AttachmentReference{}.AttachmentIndex))
    WriteRSN(Json["AttachmentIndex"], Type.AttachmentIndex, Allocator);

  if (!(Type.State == AttachmentReference{}.State))
    SerializeBitwiseEnum(Json["State"], Type.State, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, AttachmentReference &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "AttachmentIndex",
                                        "State",
                                    });
  if (Json.contains("AttachmentIndex"))
    ParseRSN(Json["AttachmentIndex"], Type.AttachmentIndex, Allocator);

  if (Json.contains("State"))
    DeserializeBitwiseEnum(Json["State"], Type.State, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const ShadingRateAttachment &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.Attachment == ShadingRateAttachment{}.Attachment))
    WriteRSN(Json["Attachment"], Type.Attachment, Allocator);

  if (!CompareConstArray(Type.TileSize, ShadingRateAttachment{}.TileSize))
    SerializeConstArray(Json["TileSize"], Type.TileSize, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, ShadingRateAttachment &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Attachment",
                                        "TileSize",
                                    });
  if (Json.contains("Attachment"))
    ParseRSN(Json["Attachment"], Type.Attachment, Allocator);

  if (Json.contains("TileSize"))
    DeserializeConstArray(Json["TileSize"], Type.TileSize, Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const SubpassDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.pInputAttachments == SubpassDesc{}.pInputAttachments))
    WriteRSN(Json["pInputAttachments"], Type.pInputAttachments,
             Type.InputAttachmentCount, Allocator);

  if (!(Type.pRenderTargetAttachments ==
        SubpassDesc{}.pRenderTargetAttachments))
    WriteRSN(Json["pRenderTargetAttachments"], Type.pRenderTargetAttachments,
             Type.RenderTargetAttachmentCount, Allocator);

  if (!(Type.pResolveAttachments == SubpassDesc{}.pResolveAttachments))
    WriteRSN(Json["pResolveAttachments"], Type.pResolveAttachments,
             Type.PreserveAttachmentCount, Allocator);

  if (!(Type.pDepthStencilAttachment == SubpassDesc{}.pDepthStencilAttachment))
    WriteRSN(Json["pDepthStencilAttachment"], Type.pDepthStencilAttachment,
             Allocator);

  if (!(Type.pPreserveAttachments == SubpassDesc{}.pPreserveAttachments))
    WriteRSN(Json["pPreserveAttachments"], Type.pPreserveAttachments,
             Type.PreserveAttachmentCount, Allocator);

  if (!(Type.pShadingRateAttachment == SubpassDesc{}.pShadingRateAttachment))
    WriteRSN(Json["pShadingRateAttachment"], Type.pShadingRateAttachment,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, SubpassDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "InputAttachmentCount",
                                        "pInputAttachments",
                                        "RenderTargetAttachmentCount",
                                        "pRenderTargetAttachments",
                                        "pResolveAttachments",
                                        "pDepthStencilAttachment",
                                        "PreserveAttachmentCount",
                                        "pPreserveAttachments",
                                        "pShadingRateAttachment",
                                    });
  if (Json.contains("pInputAttachments"))
    ParseRSN(Json["pInputAttachments"], Type.pInputAttachments,
             Type.InputAttachmentCount, Allocator);

  if (Json.contains("pRenderTargetAttachments"))
    ParseRSN(Json["pRenderTargetAttachments"], Type.pRenderTargetAttachments,
             Type.RenderTargetAttachmentCount, Allocator);

  if (Json.contains("pResolveAttachments"))
    ParseRSN(Json["pResolveAttachments"], Type.pResolveAttachments,
             Type.PreserveAttachmentCount, Allocator);

  if (Json.contains("pDepthStencilAttachment"))
    ParseRSN(Json["pDepthStencilAttachment"], Type.pDepthStencilAttachment,
             Allocator);

  if (Json.contains("pPreserveAttachments"))
    ParseRSN(Json["pPreserveAttachments"], Type.pPreserveAttachments,
             Type.PreserveAttachmentCount, Allocator);

  if (Json.contains("pShadingRateAttachment"))
    ParseRSN(Json["pShadingRateAttachment"], Type.pShadingRateAttachment,
             Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const SubpassDependencyDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!(Type.SrcSubpass == SubpassDependencyDesc{}.SrcSubpass))
    WriteRSN(Json["SrcSubpass"], Type.SrcSubpass, Allocator);

  if (!(Type.DstSubpass == SubpassDependencyDesc{}.DstSubpass))
    WriteRSN(Json["DstSubpass"], Type.DstSubpass, Allocator);

  if (!(Type.SrcStageMask == SubpassDependencyDesc{}.SrcStageMask))
    SerializeBitwiseEnum(Json["SrcStageMask"], Type.SrcStageMask, Allocator);

  if (!(Type.DstStageMask == SubpassDependencyDesc{}.DstStageMask))
    SerializeBitwiseEnum(Json["DstStageMask"], Type.DstStageMask, Allocator);

  if (!(Type.SrcAccessMask == SubpassDependencyDesc{}.SrcAccessMask))
    SerializeBitwiseEnum(Json["SrcAccessMask"], Type.SrcAccessMask, Allocator);

  if (!(Type.DstAccessMask == SubpassDependencyDesc{}.DstAccessMask))
    SerializeBitwiseEnum(Json["DstAccessMask"], Type.DstAccessMask, Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, SubpassDependencyDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "SrcSubpass",
                                        "DstSubpass",
                                        "SrcStageMask",
                                        "DstStageMask",
                                        "SrcAccessMask",
                                        "DstAccessMask",
                                    });
  if (Json.contains("SrcSubpass"))
    ParseRSN(Json["SrcSubpass"], Type.SrcSubpass, Allocator);

  if (Json.contains("DstSubpass"))
    ParseRSN(Json["DstSubpass"], Type.DstSubpass, Allocator);

  if (Json.contains("SrcStageMask"))
    DeserializeBitwiseEnum(Json["SrcStageMask"], Type.SrcStageMask, Allocator);

  if (Json.contains("DstStageMask"))
    DeserializeBitwiseEnum(Json["DstStageMask"], Type.DstStageMask, Allocator);

  if (Json.contains("SrcAccessMask"))
    DeserializeBitwiseEnum(Json["SrcAccessMask"], Type.SrcAccessMask,
                           Allocator);

  if (Json.contains("DstAccessMask"))
    DeserializeBitwiseEnum(Json["DstAccessMask"], Type.DstAccessMask,
                           Allocator);
}

inline void WriteRSN(nlohmann::json &Json, const RenderPassDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  if (!SafeStrEqual(Type.Name, RenderPassDesc{}.Name))
    WriteRSN(Json["Name"], Type.Name, Allocator);

  if (!(Type.pAttachments == RenderPassDesc{}.pAttachments))
    WriteRSN(Json["pAttachments"], Type.pAttachments, Type.AttachmentCount,
             Allocator);

  if (!(Type.pSubpasses == RenderPassDesc{}.pSubpasses))
    WriteRSN(Json["pSubpasses"], Type.pSubpasses, Type.SubpassCount, Allocator);

  if (!(Type.pDependencies == RenderPassDesc{}.pDependencies))
    WriteRSN(Json["pDependencies"], Type.pDependencies, Type.DependencyCount,
             Allocator);
}

inline void ParseRSN(const nlohmann::json &Json, RenderPassDesc &Type,
                     DynamicLinearAllocator &Allocator) {
  NLOHMANN_JSON_VALIDATE_KEYS(Json, {
                                        "Name",
                                        "AttachmentCount",
                                        "pAttachments",
                                        "SubpassCount",
                                        "pSubpasses",
                                        "DependencyCount",
                                        "pDependencies",
                                    });
  if (Json.contains("Name"))
    ParseRSN(Json["Name"], Type.Name, Allocator);

  if (Json.contains("pAttachments"))
    ParseRSN(Json["pAttachments"], Type.pAttachments, Type.AttachmentCount,
             Allocator);

  if (Json.contains("pSubpasses"))
    ParseRSN(Json["pSubpasses"], Type.pSubpasses, Type.SubpassCount, Allocator);

  if (Json.contains("pDependencies"))
    ParseRSN(Json["pDependencies"], Type.pDependencies, Type.DependencyCount,
             Allocator);
}

} // namespace Diligent
