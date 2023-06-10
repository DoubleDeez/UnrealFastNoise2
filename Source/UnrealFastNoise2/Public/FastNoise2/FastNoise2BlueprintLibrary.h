#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FastNoise2/FastNoise2Generators.h"
#include "FastNoise2BlueprintLibrary.generated.h"

UCLASS(meta = (ScriptName = "FastNoise2Library"))
class UNREALFASTNOISE2_API UFastNoise2BlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Basic Generators")
	static UFastNoise2EncodedNodeTreeGenerator* MakeEncodedNodeTreeGenerator(FString EncodedNodeTree);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Basic Generators")
	static UFastNoise2ConstantGenerator* MakeConstantGenerator(float ConstantValue);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Basic Generators")
	static UFastNoise2WhiteGenerator* MakeWhiteGenerator();

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Basic Generators")
	static UFastNoise2CheckerboardGenerator* MakeCheckerboardGenerator(float Size);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Basic Generators")
	static UFastNoise2SineWaveGenerator* MakeSineWaveGenerator(float Scale);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Basic Generators")
	static UFastNoise2PositionOutputGenerator* MakePositionOutputGenerator(FVector4 Multiplier, FVector4 Offsets);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Basic Generators")
	static UFastNoise2DistanceToPointGenerator* MakeDistanceToPointGenerator(UFastNoise2GeneratorBase* Source, EFastNoise2DistanceFunction DistanceFunction, FVector4 Scale);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2ValueGenerator* MakeValueGenerator();

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2PerlinGenerator* MakePerlinGenerator();

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2SimplexGenerator* MakeSimplexGenerator();

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2OpenSimplex2Generator* MakeOpenSimplex2Generator();

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2OpenSimplex2SGenerator* MakeOpenSimplex2SGenerator();

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2CellularValueGenerator* MakeCellularValueGenerator(
		UFastNoise2GeneratorBase* JitterModifierSource
		, float JitterModifierValue = 1.0f
		, EFastNoise2DistanceFunction DistanceFunction = EFastNoise2DistanceFunction::Euclidean, int32 ValueIndex = 0);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2CellularDistanceGenerator* MakeCellularDistanceGenerator(
		UFastNoise2GeneratorBase* JitterModifierSource
		, float JitterModifierValue = 1.0f
		, EFastNoise2DistanceFunction DistanceFunction = EFastNoise2DistanceFunction::Euclidean
		, int32 DistanceIndex0 = 0
		, int32 DistanceIndex1 = 1
		, EFastNoise2CellularDistanceReturnType ReturnType = EFastNoise2CellularDistanceReturnType::Index0);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Coherent Noise")
	static UFastNoise2CellularLookupGenerator* MakeCellularLookupGenerator(
		UFastNoise2GeneratorBase* JitterModifierSource
		, float JitterModifierValue = 1.0f
		, EFastNoise2DistanceFunction DistanceFunction = EFastNoise2DistanceFunction::Euclidean
		, UFastNoise2GeneratorBase* LookupSource = nullptr
		, float LookupFrequency = 0.1f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Fractal")
	static UFastNoise2FractalFBmGenerator* MakeFractalFBmGenerator(
		UFastNoise2GeneratorBase* Source,
		UFastNoise2GeneratorBase* GainSource = nullptr,
		float Gain = 0.5f,
		UFastNoise2GeneratorBase* WeightedStrengthSource = nullptr,
		float WeightedStrength = 0.f,
		float Lacunarity = 2.0f,
		int32 Octaves = 3
	);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Fractal")
	static UFastNoise2FractalRidgedGenerator* MakeFractalRidgedGenerator(
		UFastNoise2GeneratorBase* Source,
		UFastNoise2GeneratorBase* GainSource = nullptr,
		float Gain = 0.5f,
		UFastNoise2GeneratorBase* WeightedStrengthSource = nullptr,
		float WeightedStrength = 0.f,
		float Lacunarity = 2.0f,
		int32 Octaves = 3);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Fractal")
	static UFastNoise2FractalPingPongGenerator* MakeFractalPingPongGenerator(
		UFastNoise2GeneratorBase* Source,
		UFastNoise2GeneratorBase* PingPongStrengthSource = nullptr,
		float PingPongStrength = 0.0f,
		UFastNoise2GeneratorBase* GainSource = nullptr,
		float Gain = 0.5f,
		UFastNoise2GeneratorBase* WeightedStrengthSource = nullptr,
		float WeightedStrength = 0.f,
		float Lacunarity = 2.0f,
		int32 Octaves = 3);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Domain Warp")
	static UFastNoise2DomainWarpGradientGenerator* MakeDomainWarpGradientGenerator(
		UFastNoise2GeneratorBase* Source,
		UFastNoise2GeneratorBase* WarpAmplitudeSource = nullptr,
		float WarpAmplitude = 1.0f,
		float WarpFrequency = 0.5f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Fractal|Domain Warp")
	static UFastNoise2DomainWarpFractalProgressiveGenerator* MakeDomainWarpFractalProgressiveGenerator(
		UFastNoise2DomainWarpGeneratorBase* DomainWarpSource,
		UFastNoise2GeneratorBase* GainSource = nullptr,
		float Gain = 0.5f,
		UFastNoise2GeneratorBase* WeightedStrengthSource = nullptr,
		float WeightedStrength = 0.f,
		float Lacunarity = 2.0f,
		int32 Octaves = 3);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Fractal|Domain Warp")
	static UFastNoise2DomainWarpFractalIndependantGenerator* MakeDomainWarpFractalIndependantGenerator(
		UFastNoise2DomainWarpGeneratorBase* DomainWarpSource,
		UFastNoise2GeneratorBase* GainSource = nullptr,
		float Gain = 0.5f,
		UFastNoise2GeneratorBase* WeightedStrengthSource = nullptr,
		float WeightedStrength = 0.f,
		float Lacunarity = 2.0f,
		int32 Octaves = 3);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2AddGenerator* AddValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2AddGenerator* AddSources(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2SubtractGenerator* SubtractValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2SubtractGenerator* SubtractSource(float LHS = 0.0f, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2SubtractGenerator* SubtractSources(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MultiplyGenerator* MultiplyValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MultiplyGenerator* MultiplySources(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2DivideGenerator* DivideValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2DivideGenerator* DivideSource(float LHS = 0.0f, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2DivideGenerator* DivideSources(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MinGenerator* MinValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MinGenerator* MinSources(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MaxGenerator* MaxValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MaxGenerator* MaxSources(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MinSmoothGenerator* MinValueSmoothValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f, float Smoothness = 0.1f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MinSmoothGenerator* MinSourcesSmoothValue(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr, float Smoothness = 0.1f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MinSmoothGenerator* MinValueSmoothSource(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f, UFastNoise2GeneratorBase* SmoothnessSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MinSmoothGenerator* MinSourcesSmoothSource(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr, UFastNoise2GeneratorBase* SmoothnessSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MaxSmoothGenerator* MaxValueSmoothValue(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f, float Smoothness = 0.1f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MaxSmoothGenerator* MaxSourcesSmoothValue(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr, float Smoothness = 0.1f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MaxSmoothGenerator* MaxValueSmoothSource(UFastNoise2GeneratorBase* LHSSource = nullptr, float RHS = 0.0f, UFastNoise2GeneratorBase* SmoothnessSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2MaxSmoothGenerator* MaxSourcesSmoothSource(UFastNoise2GeneratorBase* LHSSource = nullptr, UFastNoise2GeneratorBase* RHSSource = nullptr, UFastNoise2GeneratorBase* SmoothnessSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2PowFloatGenerator* ExponentValueBaseSource(UFastNoise2GeneratorBase* BaseSource = nullptr, float Exponent = 2.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2PowFloatGenerator* ExponentSourceBaseValue(float Base = 2.0f, UFastNoise2GeneratorBase* ExponentSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2PowFloatGenerator* ExponentSourceBaseSource(UFastNoise2GeneratorBase* BaseSource = nullptr, UFastNoise2GeneratorBase* ExponentSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2PowIntGenerator* ExponentInt(UFastNoise2GeneratorBase* BaseSource = nullptr, int32 Exponent = 2);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2FadeGenerator* FadeByValue(UFastNoise2GeneratorBase* SourceA = nullptr, UFastNoise2GeneratorBase* SourceB = nullptr, float Fade = 0.5f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Blends")
	static UFastNoise2FadeGenerator* FadeBySource(UFastNoise2GeneratorBase* SourceA = nullptr, UFastNoise2GeneratorBase* SourceB = nullptr, UFastNoise2GeneratorBase* FadeSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2DomainScaleGenerator* DomainScale(UFastNoise2GeneratorBase* Source = nullptr, float Scale = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2DomainOffsetGenerator* DomainOffsetByValues(UFastNoise2GeneratorBase* Source, FVector4 Offsets);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2DomainOffsetGenerator* DomainOffsetBySources(UFastNoise2GeneratorBase* Source, UFastNoise2GeneratorBase* OffsetSourceX, UFastNoise2GeneratorBase* OffsetSourceY, UFastNoise2GeneratorBase* OffsetSourceZ, UFastNoise2GeneratorBase* OffsetSourceW);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2DomainRotateGenerator* DomainRotate(UFastNoise2GeneratorBase* Source, FRotator Rotation);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2DomainAxisScaleGenerator* DomainAxisScale(UFastNoise2GeneratorBase* Source, FVector4 Scale);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2SeedOffsetGenerator* SeedOffset(UFastNoise2GeneratorBase* Source = nullptr, int32 Offset = 1);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2RemapGenerator* Remap(UFastNoise2GeneratorBase* Source = nullptr, FVector2D FromRange = FVector2D(-1.f, 1.f), FVector2D ToRange = FVector2D(0.f, 1.f));

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2ConvertRGBA8Generator* ConvertRGBA8(UFastNoise2GeneratorBase* Source = nullptr, FVector2D Range = FVector2D(-1.f, 1.f));

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2TerraceGenerator* Terrace(UFastNoise2GeneratorBase* Source = nullptr, float Multiplier = 1.0f, float Smoothness = 0.f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2AddDimensionGenerator* AddDimensionWithPositionValue(UFastNoise2GeneratorBase* Source = nullptr, float DimensionPosition= 0.f);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2AddDimensionGenerator* AddDimensionWithPositionSource(UFastNoise2GeneratorBase* Source = nullptr, UFastNoise2GeneratorBase* DimensionPositionSource = nullptr);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2RemoveDimensionGenerator* RemoveDimension(UFastNoise2GeneratorBase* Source = nullptr, EFastNoise2Dimension DimensionToRemove = EFastNoise2Dimension::Y);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2|Modifiers")
	static UFastNoise2GeneratorCacheGenerator* MakeGeneratorCache(UFastNoise2GeneratorBase* Source = nullptr);
};
