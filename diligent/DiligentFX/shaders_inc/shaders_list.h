static const MemoryShaderSourceFileInfo g_Shaders[] =
{
    {
        "BoundBox.psh",
        #include "BoundBox.psh.h"
    },
    {
        "BoundBox.vsh",
        #include "BoundBox.vsh.h"
    },
    {
        "BoundBoxStructures.fxh",
        #include "BoundBoxStructures.fxh.h"
    },
    {
        "ComputeBlueNoiseTexture.fx",
        #include "ComputeBlueNoiseTexture.fx.h"
    },
    {
        "ComputeClosestMotion.fx",
        #include "ComputeClosestMotion.fx.h"
    },
    {
        "ComputeReprojectedDepth.fx",
        #include "ComputeReprojectedDepth.fx.h"
    },
    {
        "CoordinateGridPS.psh",
        #include "CoordinateGridPS.psh.h"
    },
    {
        "CopyTextureDepth.fx",
        #include "CopyTextureDepth.fx.h"
    },
    {
        "EnvMap.psh",
        #include "EnvMap.psh.h"
    },
    {
        "EnvMap.vsh",
        #include "EnvMap.vsh.h"
    },
    {
        "FullScreenTriangleVS.fx",
        #include "FullScreenTriangleVS.fx.h"
    },
    {
        "FullScreenTriangleVSOutput.fxh",
        #include "FullScreenTriangleVSOutput.fxh.h"
    },
    {
        "VectorField.vsh",
        #include "VectorField.vsh.h"
    },
    {
        "AtlasSampling.fxh",
        #include "AtlasSampling.fxh.h"
    },
    {
        "BasicStructures.fxh",
        #include "BasicStructures.fxh.h"
    },
    {
        "CoordinateGrid.fxh",
        #include "CoordinateGrid.fxh.h"
    },
    {
        "CoordinateGridStructures.fxh",
        #include "CoordinateGridStructures.fxh.h"
    },
    {
        "PBR_Common.fxh",
        #include "PBR_Common.fxh.h"
    },
    {
        "PCF.fxh",
        #include "PCF.fxh.h"
    },
    {
        "PostFX_Common.fxh",
        #include "PostFX_Common.fxh.h"
    },
    {
        "SRGBUtilities.fxh",
        #include "SRGBUtilities.fxh.h"
    },
    {
        "ShaderDefinitions.fxh",
        #include "ShaderDefinitions.fxh.h"
    },
    {
        "ShaderUtilities.fxh",
        #include "ShaderUtilities.fxh.h"
    },
    {
        "Shadows.fxh",
        #include "Shadows.fxh.h"
    },
    {
        "ComputeIrradianceMap.psh",
        #include "ComputeIrradianceMap.psh.h"
    },
    {
        "CubemapFace.vsh",
        #include "CubemapFace.vsh.h"
    },
    {
        "Iridescence.fxh",
        #include "Iridescence.fxh.h"
    },
    {
        "PBR_PrecomputeCommon.fxh",
        #include "PBR_PrecomputeCommon.fxh.h"
    },
    {
        "PBR_Textures.fxh",
        #include "PBR_Textures.fxh.h"
    },
    {
        "PrecomputeBRDF.psh",
        #include "PrecomputeBRDF.psh.h"
    },
    {
        "PrefilterEnvMap.psh",
        #include "PrefilterEnvMap.psh.h"
    },
    {
        "RenderPBR.psh",
        #include "RenderPBR.psh.h"
    },
    {
        "RenderPBR.vsh",
        #include "RenderPBR.vsh.h"
    },
    {
        "RenderPBR_Structures.fxh",
        #include "RenderPBR_Structures.fxh.h"
    },
    {
        "RenderUnshaded.psh",
        #include "RenderUnshaded.psh.h"
    },
    {
        "PBR_Shading.fxh",
        #include "PBR_Shading.fxh.h"
    },
    {
        "PBR_Structures.fxh",
        #include "PBR_Structures.fxh.h"
    },
    {
        "VertexProcessing.fxh",
        #include "VertexProcessing.fxh.h"
    },
    {
        "Bloom_ComputeDownsampledTexture.fx",
        #include "Bloom_ComputeDownsampledTexture.fx.h"
    },
    {
        "Bloom_ComputePrefilteredTexture.fx",
        #include "Bloom_ComputePrefilteredTexture.fx.h"
    },
    {
        "Bloom_ComputeUpsampledTexture.fx",
        #include "Bloom_ComputeUpsampledTexture.fx.h"
    },
    {
        "BloomStructures.fxh",
        #include "BloomStructures.fxh.h"
    },
    {
        "DOF_ComputeBokeh.fx",
        #include "DOF_ComputeBokeh.fx.h"
    },
    {
        "DOF_ComputeCircleOfConfusion.fx",
        #include "DOF_ComputeCircleOfConfusion.fx.h"
    },
    {
        "DOF_ComputeCombinedTexture.fx",
        #include "DOF_ComputeCombinedTexture.fx.h"
    },
    {
        "DOF_ComputePostfilteredTexture.fx",
        #include "DOF_ComputePostfilteredTexture.fx.h"
    },
    {
        "DOF_ComputePrefilteredTexture.fx",
        #include "DOF_ComputePrefilteredTexture.fx.h"
    },
    {
        "DepthOfFieldStructures.fxh",
        #include "DepthOfFieldStructures.fxh.h"
    },
    {
        "AtmosphereShadersCommon.fxh",
        #include "AtmosphereShadersCommon.fxh.h"
    },
    {
        "CoarseInsctr.fx",
        #include "CoarseInsctr.fx.h"
    },
    {
        "ComputeMinMaxShadowMapLevel.fx",
        #include "ComputeMinMaxShadowMapLevel.fx.h"
    },
    {
        "Extinction.fxh",
        #include "Extinction.fxh.h"
    },
    {
        "InitializeMinMaxShadowMap.fx",
        #include "InitializeMinMaxShadowMap.fx.h"
    },
    {
        "InterpolateIrradiance.fx",
        #include "InterpolateIrradiance.fx.h"
    },
    {
        "LookUpTables.fxh",
        #include "LookUpTables.fxh.h"
    },
    {
        "MarkRayMarchingSamples.fx",
        #include "MarkRayMarchingSamples.fx.h"
    },
    {
        "RayMarch.fx",
        #include "RayMarch.fx.h"
    },
    {
        "ReconstructCameraSpaceZ.fx",
        #include "ReconstructCameraSpaceZ.fx.h"
    },
    {
        "RefineSampleLocations.fx",
        #include "RefineSampleLocations.fx.h"
    },
    {
        "RenderCoordinateTexture.fx",
        #include "RenderCoordinateTexture.fx.h"
    },
    {
        "RenderSampling.fx",
        #include "RenderSampling.fx.h"
    },
    {
        "RenderSliceEndPoints.fx",
        #include "RenderSliceEndPoints.fx.h"
    },
    {
        "ScatteringIntegrals.fxh",
        #include "ScatteringIntegrals.fxh.h"
    },
    {
        "SliceUVDirection.fx",
        #include "SliceUVDirection.fx.h"
    },
    {
        "Sun.fx",
        #include "Sun.fx.h"
    },
    {
        "UnshadowedScattering.fxh",
        #include "UnshadowedScattering.fxh.h"
    },
    {
        "UnwarpEpipolarScattering.fx",
        #include "UnwarpEpipolarScattering.fx.h"
    },
    {
        "UpdateAverageLuminance.fx",
        #include "UpdateAverageLuminance.fx.h"
    },
    {
        "CombineScatteringOrders.fx",
        #include "CombineScatteringOrders.fx.h"
    },
    {
        "ComputeScatteringOrder.fx",
        #include "ComputeScatteringOrder.fx.h"
    },
    {
        "ComputeSctrRadiance.fx",
        #include "ComputeSctrRadiance.fx.h"
    },
    {
        "InitHighOrderScattering.fx",
        #include "InitHighOrderScattering.fx.h"
    },
    {
        "PrecomputeAmbientSkyLight.fx",
        #include "PrecomputeAmbientSkyLight.fx.h"
    },
    {
        "PrecomputeCommon.fxh",
        #include "PrecomputeCommon.fxh.h"
    },
    {
        "PrecomputeNetDensityToAtmTop.fx",
        #include "PrecomputeNetDensityToAtmTop.fx.h"
    },
    {
        "PrecomputeSingleScattering.fx",
        #include "PrecomputeSingleScattering.fx.h"
    },
    {
        "UpdateHighOrderScattering.fx",
        #include "UpdateHighOrderScattering.fx.h"
    },
    {
        "EpipolarLightScatteringFunctions.fxh",
        #include "EpipolarLightScatteringFunctions.fxh.h"
    },
    {
        "EpipolarLightScatteringStructures.fxh",
        #include "EpipolarLightScatteringStructures.fxh.h"
    },
    {
        "SSAO_Common.fxh",
        #include "SSAO_Common.fxh.h"
    },
    {
        "SSAO_ComputeAmbientOcclusion.fx",
        #include "SSAO_ComputeAmbientOcclusion.fx.h"
    },
    {
        "SSAO_ComputeBilateralUpsampling.fx",
        #include "SSAO_ComputeBilateralUpsampling.fx.h"
    },
    {
        "SSAO_ComputeConvolutedDepthHistory.fx",
        #include "SSAO_ComputeConvolutedDepthHistory.fx.h"
    },
    {
        "SSAO_ComputeDownsampledDepth.fx",
        #include "SSAO_ComputeDownsampledDepth.fx.h"
    },
    {
        "SSAO_ComputePrefilteredDepthBuffer.fx",
        #include "SSAO_ComputePrefilteredDepthBuffer.fx.h"
    },
    {
        "SSAO_ComputeResampledHistory.fx",
        #include "SSAO_ComputeResampledHistory.fx.h"
    },
    {
        "SSAO_ComputeSpatialReconstruction.fx",
        #include "SSAO_ComputeSpatialReconstruction.fx.h"
    },
    {
        "SSAO_ComputeTemporalAccumulation.fx",
        #include "SSAO_ComputeTemporalAccumulation.fx.h"
    },
    {
        "ScreenSpaceAmbientOcclusionStructures.fxh",
        #include "ScreenSpaceAmbientOcclusionStructures.fxh.h"
    },
    {
        "SSR_Common.fxh",
        #include "SSR_Common.fxh.h"
    },
    {
        "SSR_ComputeBilateralCleanup.fx",
        #include "SSR_ComputeBilateralCleanup.fx.h"
    },
    {
        "SSR_ComputeDownsampledStencilMask.fx",
        #include "SSR_ComputeDownsampledStencilMask.fx.h"
    },
    {
        "SSR_ComputeHierarchicalDepthBuffer.fx",
        #include "SSR_ComputeHierarchicalDepthBuffer.fx.h"
    },
    {
        "SSR_ComputeIntersection.fx",
        #include "SSR_ComputeIntersection.fx.h"
    },
    {
        "SSR_ComputeSpatialReconstruction.fx",
        #include "SSR_ComputeSpatialReconstruction.fx.h"
    },
    {
        "SSR_ComputeStencilMaskAndExtractRoughness.fx",
        #include "SSR_ComputeStencilMaskAndExtractRoughness.fx.h"
    },
    {
        "SSR_ComputeTemporalAccumulation.fx",
        #include "SSR_ComputeTemporalAccumulation.fx.h"
    },
    {
        "ScreenSpaceReflectionStructures.fxh",
        #include "ScreenSpaceReflectionStructures.fxh.h"
    },
    {
        "TAA_ComputeTemporalAccumulation.fx",
        #include "TAA_ComputeTemporalAccumulation.fx.h"
    },
    {
        "TemporalAntiAliasingStructures.fxh",
        #include "TemporalAntiAliasingStructures.fxh.h"
    },
    {
        "ToneMapping.fxh",
        #include "ToneMapping.fxh.h"
    },
    {
        "ToneMappingStructures.fxh",
        #include "ToneMappingStructures.fxh.h"
    },
    {
        "ShadowConversions.fx",
        #include "ShadowConversions.fx.h"
    },
};
