#include "FastNoise2/FastNoise2Types.h"

FastNoise::DistanceFunction FFastNoise2Helpers::ConvertUnrealToFastNoiseDistanceFunction(EFastNoise2DistanceFunction InFunction)
{
	switch (InFunction)
	{
	case EFastNoise2DistanceFunction::Euclidean:
		return FastNoise::DistanceFunction::Euclidean;
	case EFastNoise2DistanceFunction::EuclideanSquared:
		return FastNoise::DistanceFunction::EuclideanSquared;
	case EFastNoise2DistanceFunction::Manhattan:
		return FastNoise::DistanceFunction::Manhattan;
	case EFastNoise2DistanceFunction::Hybrid:
		return FastNoise::DistanceFunction::Hybrid;
	case EFastNoise2DistanceFunction::MaxAxis:
		return FastNoise::DistanceFunction::MaxAxis;
	}

	check(false);
	return FastNoise::DistanceFunction::Euclidean;
}

FastNoise::CellularDistance::ReturnType FFastNoise2Helpers::ConvertUnrealToFastNoiseCellularDistanceReturnType(EFastNoise2CellularDistanceReturnType InCellularDistanceReturnType)
{
	switch (InCellularDistanceReturnType)
	{
	case EFastNoise2CellularDistanceReturnType::Index0:
		return FastNoise::CellularDistance::ReturnType::Index0;
	case EFastNoise2CellularDistanceReturnType::Index0Add1:
		return FastNoise::CellularDistance::ReturnType::Index0Add1;
	case EFastNoise2CellularDistanceReturnType::Index0Sub1:
		return FastNoise::CellularDistance::ReturnType::Index0Sub1;
	case EFastNoise2CellularDistanceReturnType::Index0Mul1:
		return FastNoise::CellularDistance::ReturnType::Index0Mul1;
	case EFastNoise2CellularDistanceReturnType::Index0Div1:
		return FastNoise::CellularDistance::ReturnType::Index0Div1;
	}

	check(false);
	return FastNoise::CellularDistance::ReturnType::Index0Div1;
}

FastNoise::Dim FFastNoise2Helpers::ConvertUnrealToFastNoiseDimension(EFastNoise2Dimension InDimension)
{
	switch (InDimension)
	{
	case EFastNoise2Dimension::X:
		return FastNoise::Dim::X;
	case EFastNoise2Dimension::Y:
		return FastNoise::Dim::Y;
	case EFastNoise2Dimension::Z:
		return FastNoise::Dim::Z;
	case EFastNoise2Dimension::W:
		return FastNoise::Dim::W;
	}

	check(false);
	return FastNoise::Dim::Count;
}
