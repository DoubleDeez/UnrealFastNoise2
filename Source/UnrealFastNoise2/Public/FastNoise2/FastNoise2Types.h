#pragma once

#include "CoreMinimal.h"
#include "FastNoise/Generators/Generator.h"
#include "FastNoise/Generators/Cellular.h"
#include "FastNoise2Types.generated.h"

UENUM(BlueprintType)
enum class EFastNoise2DistanceFunction : uint8
{
	Euclidean,
	EuclideanSquared,
	Manhattan,
	Hybrid,
	MaxAxis,
};

UENUM(BlueprintType)
enum class EFastNoise2CellularDistanceReturnType : uint8
{
	Index0,
	Index0Add1,
	Index0Sub1,
	Index0Mul1,
	Index0Div1
};

UENUM(BlueprintType)
enum class EFastNoise2Dimension : uint8
{
	X,
	Y,
	Z,
	W
};

class UNREALFASTNOISE2_API FFastNoise2Helpers
{
public:
	static FastNoise::DistanceFunction ConvertUnrealToFastNoiseDistanceFunction(EFastNoise2DistanceFunction InFunction);

	static FastNoise::CellularDistance::ReturnType ConvertUnrealToFastNoiseCellularDistanceReturnType(EFastNoise2CellularDistanceReturnType InCellularDistanceReturnType);

	static FastNoise::Dim ConvertUnrealToFastNoiseDimension(EFastNoise2Dimension InDimension);
};
