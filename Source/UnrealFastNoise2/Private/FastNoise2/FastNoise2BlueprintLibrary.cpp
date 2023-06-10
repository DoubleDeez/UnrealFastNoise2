#include "FastNoise2/FastNoise2BlueprintLibrary.h"
#include "FastNoise2/FastNoise2Generators.h"

UFastNoise2EncodedNodeTreeGenerator* UFastNoise2BlueprintLibrary::MakeEncodedNodeTreeGenerator(FString EncodedNodeTree)
{
	UFastNoise2EncodedNodeTreeGenerator* Gen = NewObject<UFastNoise2EncodedNodeTreeGenerator>();
	Gen->SetEncodedNodeTree(EncodedNodeTree);
	return Gen;
}

UFastNoise2ConstantGenerator* UFastNoise2BlueprintLibrary::MakeConstantGenerator(float ConstantValue)
{
	UFastNoise2ConstantGenerator* Gen = NewObject<UFastNoise2ConstantGenerator>();
	Gen->SetValue(ConstantValue);
	return Gen;
}

UFastNoise2WhiteGenerator* UFastNoise2BlueprintLibrary::MakeWhiteGenerator()
{
	return NewObject<UFastNoise2WhiteGenerator>();
}

UFastNoise2CheckerboardGenerator* UFastNoise2BlueprintLibrary::MakeCheckerboardGenerator(float Size)
{
	UFastNoise2CheckerboardGenerator* Gen = NewObject<UFastNoise2CheckerboardGenerator>();
	Gen->SetSize(Size);
	return Gen;
}

UFastNoise2SineWaveGenerator* UFastNoise2BlueprintLibrary::MakeSineWaveGenerator(float Scale)
{
	UFastNoise2SineWaveGenerator* Gen = NewObject<UFastNoise2SineWaveGenerator>();
	Gen->SetScale(Scale);
	return Gen;
}

UFastNoise2PositionOutputGenerator* UFastNoise2BlueprintLibrary::MakePositionOutputGenerator(FVector4 Multiplier, FVector4 Offsets)
{
	UFastNoise2PositionOutputGenerator* Gen = NewObject<UFastNoise2PositionOutputGenerator>();
	Gen->SetData(Multiplier, Offsets);
	return Gen;
}

UFastNoise2DistanceToPointGenerator* UFastNoise2BlueprintLibrary::MakeDistanceToPointGenerator(UFastNoise2GeneratorBase* Source, EFastNoise2DistanceFunction DistanceFunction, FVector4 Scale)
{
	UFastNoise2DistanceToPointGenerator* Gen = NewObject<UFastNoise2DistanceToPointGenerator>();
	Gen->SetSource(Source);
	Gen->SetDistanceFunction(DistanceFunction);
	Gen->SetScale(Scale);
	return Gen;
}

UFastNoise2ValueGenerator* UFastNoise2BlueprintLibrary::MakeValueGenerator()
{
	return NewObject<UFastNoise2ValueGenerator>();
}

UFastNoise2PerlinGenerator* UFastNoise2BlueprintLibrary::MakePerlinGenerator()
{
	return NewObject<UFastNoise2PerlinGenerator>();
}

UFastNoise2SimplexGenerator* UFastNoise2BlueprintLibrary::MakeSimplexGenerator()
{
	return NewObject<UFastNoise2SimplexGenerator>();
}

UFastNoise2OpenSimplex2Generator* UFastNoise2BlueprintLibrary::MakeOpenSimplex2Generator()
{
	return NewObject<UFastNoise2OpenSimplex2Generator>();
}

UFastNoise2OpenSimplex2SGenerator* UFastNoise2BlueprintLibrary::MakeOpenSimplex2SGenerator()
{
	return NewObject<UFastNoise2OpenSimplex2SGenerator>();
}

UFastNoise2CellularValueGenerator* UFastNoise2BlueprintLibrary::MakeCellularValueGenerator(UFastNoise2GeneratorBase* JitterModifierSource, float JitterModifierValue, EFastNoise2DistanceFunction DistanceFunction, int32 ValueIndex)
{
	UFastNoise2CellularValueGenerator* Gen = NewObject<UFastNoise2CellularValueGenerator>();
	if (JitterModifierSource != nullptr)
	{
		Gen->SetJitterModifierSource(JitterModifierSource);
	}
	else
	{
		Gen->SetJitterModifierValue(JitterModifierValue);
	}
	Gen->SetDistanceFunction(DistanceFunction);
	Gen->SetValueIndex(ValueIndex);
	return Gen;
}

UFastNoise2CellularDistanceGenerator* UFastNoise2BlueprintLibrary::MakeCellularDistanceGenerator(UFastNoise2GeneratorBase* JitterModifierSource, float JitterModifierValue, EFastNoise2DistanceFunction DistanceFunction, int32 DistanceIndex0, int32 DistanceIndex1, EFastNoise2CellularDistanceReturnType ReturnType)
{
	UFastNoise2CellularDistanceGenerator* Gen = NewObject<UFastNoise2CellularDistanceGenerator>();
	if (JitterModifierSource != nullptr)
	{
		Gen->SetJitterModifierSource(JitterModifierSource);
	}
	else
	{
		Gen->SetJitterModifierValue(JitterModifierValue);
	}
	Gen->SetDistanceFunction(DistanceFunction);
	Gen->SetDistanceIndex0(DistanceIndex0);
	Gen->SetDistanceIndex1(DistanceIndex1);
	Gen->SetReturnType(ReturnType);
	return Gen;
}

UFastNoise2CellularLookupGenerator* UFastNoise2BlueprintLibrary::MakeCellularLookupGenerator(UFastNoise2GeneratorBase* JitterModifierSource, float JitterModifierValue, EFastNoise2DistanceFunction DistanceFunction, UFastNoise2GeneratorBase* LookupSource, float LookupFrequency)
{
	UFastNoise2CellularLookupGenerator* Gen = NewObject<UFastNoise2CellularLookupGenerator>();
	if (JitterModifierSource != nullptr)
	{
		Gen->SetJitterModifierSource(JitterModifierSource);
	}
	else
	{
		Gen->SetJitterModifierValue(JitterModifierValue);
	}
	Gen->SetDistanceFunction(DistanceFunction);
	Gen->SetLookupSource(JitterModifierSource);
	Gen->SetLookupFrequency(LookupFrequency);
	return Gen;
}

UFastNoise2FractalFBmGenerator* UFastNoise2BlueprintLibrary::MakeFractalFBmGenerator(UFastNoise2GeneratorBase* Source, UFastNoise2GeneratorBase* GainSource /*= nullptr*/, float Gain /*= 0.5f*/, UFastNoise2GeneratorBase* WeightedStrengthSource /*= nullptr*/, float WeightedStrength /*= 0.f*/, float Lacunarity /*= 2.0f*/, int32 Octaves /*= 3 */)
{
	UFastNoise2FractalFBmGenerator* Gen = NewObject<UFastNoise2FractalFBmGenerator>();
	Gen->SetSource(Source);
	if (GainSource != nullptr)
	{
		Gen->SetGainSource(GainSource);
	}
	else
	{
		Gen->SetGainValue(Gain);
	}
	if (WeightedStrengthSource != nullptr)
	{
		Gen->SetWeightedStrengthSource(WeightedStrengthSource);
	}
	else
	{
		Gen->SetWeightedStrengthValue(WeightedStrength);
	}
	Gen->SetLacunarityValue(Lacunarity);
	Gen->SetOctaveCount(Octaves);
	return Gen;
}

UFastNoise2FractalRidgedGenerator* UFastNoise2BlueprintLibrary::MakeFractalRidgedGenerator(UFastNoise2GeneratorBase* Source, UFastNoise2GeneratorBase* GainSource /*= nullptr*/, float Gain /*= 0.5f*/, UFastNoise2GeneratorBase* WeightedStrengthSource /*= nullptr*/, float WeightedStrength /*= 0.f*/, float Lacunarity /*= 2.0f*/, int32 Octaves /*= 3*/)
{
	UFastNoise2FractalRidgedGenerator* Gen = NewObject<UFastNoise2FractalRidgedGenerator>();
	Gen->SetSource(Source);
	if (GainSource != nullptr)
	{
		Gen->SetGainSource(GainSource);
	}
	else
	{
		Gen->SetGainValue(Gain);
	}
	if (WeightedStrengthSource != nullptr)
	{
		Gen->SetWeightedStrengthSource(WeightedStrengthSource);
	}
	else
	{
		Gen->SetWeightedStrengthValue(WeightedStrength);
	}
	Gen->SetLacunarityValue(Lacunarity);
	Gen->SetOctaveCount(Octaves);
	return Gen;
}

UFastNoise2FractalPingPongGenerator* UFastNoise2BlueprintLibrary::MakeFractalPingPongGenerator(UFastNoise2GeneratorBase* Source, UFastNoise2GeneratorBase* PingPongStrengthSource /*= nullptr*/, float PingPongStrength /*= 0.0f*/, UFastNoise2GeneratorBase* GainSource /*= nullptr*/, float Gain /*= 0.5f*/, UFastNoise2GeneratorBase* WeightedStrengthSource /*= nullptr*/, float WeightedStrength /*= 0.f*/, float Lacunarity /*= 2.0f*/, int32 Octaves /*= 3*/)
{
	UFastNoise2FractalPingPongGenerator* Gen = NewObject<UFastNoise2FractalPingPongGenerator>();
	Gen->SetSource(Source);
	if (PingPongStrengthSource != nullptr)
	{
		Gen->SetPingPongStrengthSource(PingPongStrengthSource);
	}
	else
	{
		Gen->SetPingPongStrengthValue(PingPongStrength);
	}
	if (GainSource != nullptr)
	{
		Gen->SetGainSource(GainSource);
	}
	else
	{
		Gen->SetGainValue(Gain);
	}
	if (WeightedStrengthSource != nullptr)
	{
		Gen->SetWeightedStrengthSource(WeightedStrengthSource);
	}
	else
	{
		Gen->SetWeightedStrengthValue(WeightedStrength);
	}
	Gen->SetLacunarityValue(Lacunarity);
	Gen->SetOctaveCount(Octaves);
	return Gen;
}

UFastNoise2DomainWarpGradientGenerator* UFastNoise2BlueprintLibrary::MakeDomainWarpGradientGenerator(UFastNoise2GeneratorBase* Source, UFastNoise2GeneratorBase* WarpAmplitudeSource /*= nullptr*/, float WarpAmplitude /*= 1.0f*/, float WarpFrequency /*= 0.5f*/)
{
	UFastNoise2DomainWarpGradientGenerator* Gen = NewObject<UFastNoise2DomainWarpGradientGenerator>();
	Gen->SetSource(Source);
	if (WarpAmplitudeSource != nullptr)
	{
		Gen->SetWarpAmplitudeSource(WarpAmplitudeSource);
	}
	else
	{
		Gen->SetWarpAmplitudeValue(WarpAmplitude);
	}
	Gen->SetWarpFrequencyValue(WarpFrequency);
	return Gen;
}

UFastNoise2DomainWarpFractalProgressiveGenerator* UFastNoise2BlueprintLibrary::MakeDomainWarpFractalProgressiveGenerator(UFastNoise2DomainWarpGeneratorBase* DomainWarpSource, UFastNoise2GeneratorBase* GainSource /*= nullptr*/, float Gain /*= 0.5f*/, UFastNoise2GeneratorBase* WeightedStrengthSource /*= nullptr*/, float WeightedStrength /*= 0.f*/, float Lacunarity /*= 2.0f*/, int32 Octaves /*= 3*/)
{
	UFastNoise2DomainWarpFractalProgressiveGenerator* Gen = NewObject<UFastNoise2DomainWarpFractalProgressiveGenerator>();
	Gen->SetDomainWarpSource(DomainWarpSource);
	if (GainSource != nullptr)
	{
		Gen->SetGainSource(GainSource);
	}
	else
	{
		Gen->SetGainValue(Gain);
	}
	if (WeightedStrengthSource != nullptr)
	{
		Gen->SetWeightedStrengthSource(WeightedStrengthSource);
	}
	else
	{
		Gen->SetWeightedStrengthValue(WeightedStrength);
	}
	Gen->SetLacunarityValue(Lacunarity);
	Gen->SetOctaveCount(Octaves);
	return Gen;
}

UFastNoise2DomainWarpFractalIndependantGenerator* UFastNoise2BlueprintLibrary::MakeDomainWarpFractalIndependantGenerator(UFastNoise2DomainWarpGeneratorBase* DomainWarpSource, UFastNoise2GeneratorBase* GainSource /*= nullptr*/, float Gain /*= 0.5f*/, UFastNoise2GeneratorBase* WeightedStrengthSource /*= nullptr*/, float WeightedStrength /*= 0.f*/, float Lacunarity /*= 2.0f*/, int32 Octaves /*= 3*/)
{
	UFastNoise2DomainWarpFractalIndependantGenerator* Gen = NewObject<UFastNoise2DomainWarpFractalIndependantGenerator>();
	Gen->SetDomainWarpSource(DomainWarpSource);
	if (GainSource != nullptr)
	{
		Gen->SetGainSource(GainSource);
	}
	else
	{
		Gen->SetGainValue(Gain);
	}
	if (WeightedStrengthSource != nullptr)
	{
		Gen->SetWeightedStrengthSource(WeightedStrengthSource);
	}
	else
	{
		Gen->SetWeightedStrengthValue(WeightedStrength);
	}
	Gen->SetLacunarityValue(Lacunarity);
	Gen->SetOctaveCount(Octaves);
	return Gen;
}

UFastNoise2AddGenerator* UFastNoise2BlueprintLibrary::AddValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/)
{
	UFastNoise2AddGenerator* Gen = NewObject<UFastNoise2AddGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	return Gen;
}

UFastNoise2AddGenerator* UFastNoise2BlueprintLibrary::AddSources(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2AddGenerator* Gen = NewObject<UFastNoise2AddGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2SubtractGenerator* UFastNoise2BlueprintLibrary::SubtractValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/)
{
	UFastNoise2SubtractGenerator* Gen = NewObject<UFastNoise2SubtractGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	return Gen;
}

UFastNoise2SubtractGenerator* UFastNoise2BlueprintLibrary::SubtractSource(float LHS /*= 0.0f*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2SubtractGenerator* Gen = NewObject<UFastNoise2SubtractGenerator>();
	Gen->SetLHSValue(LHS);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2SubtractGenerator* UFastNoise2BlueprintLibrary::SubtractSources(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2SubtractGenerator* Gen = NewObject<UFastNoise2SubtractGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2MultiplyGenerator* UFastNoise2BlueprintLibrary::MultiplyValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/)
{
	UFastNoise2MultiplyGenerator* Gen = NewObject<UFastNoise2MultiplyGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	return Gen;
}

UFastNoise2MultiplyGenerator* UFastNoise2BlueprintLibrary::MultiplySources(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2MultiplyGenerator* Gen = NewObject<UFastNoise2MultiplyGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2DivideGenerator* UFastNoise2BlueprintLibrary::DivideValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/)
{
	UFastNoise2DivideGenerator* Gen = NewObject<UFastNoise2DivideGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	return Gen;
}

UFastNoise2DivideGenerator* UFastNoise2BlueprintLibrary::DivideSource(float LHS /*= 0.0f*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2DivideGenerator* Gen = NewObject<UFastNoise2DivideGenerator>();
	Gen->SetLHSValue(LHS);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2DivideGenerator* UFastNoise2BlueprintLibrary::DivideSources(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2DivideGenerator* Gen = NewObject<UFastNoise2DivideGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2MinGenerator* UFastNoise2BlueprintLibrary::MinValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/)
{
	UFastNoise2MinGenerator* Gen = NewObject<UFastNoise2MinGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	return Gen;
}

UFastNoise2MinGenerator* UFastNoise2BlueprintLibrary::MinSources(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2MinGenerator* Gen = NewObject<UFastNoise2MinGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2MaxGenerator* UFastNoise2BlueprintLibrary::MaxValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/)
{
	UFastNoise2MaxGenerator* Gen = NewObject<UFastNoise2MaxGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	return Gen;
}

UFastNoise2MaxGenerator* UFastNoise2BlueprintLibrary::MaxSources(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/)
{
	UFastNoise2MaxGenerator* Gen = NewObject<UFastNoise2MaxGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	return Gen;
}

UFastNoise2MinSmoothGenerator* UFastNoise2BlueprintLibrary::MinValueSmoothValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/, float Smoothness /*= 0.1f*/)
{
	UFastNoise2MinSmoothGenerator* Gen = NewObject<UFastNoise2MinSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	Gen->SetSmoothnessValue(Smoothness);
	return Gen;
}

UFastNoise2MinSmoothGenerator* UFastNoise2BlueprintLibrary::MinSourcesSmoothValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/, float Smoothness /*= 0.1f*/)
{
	UFastNoise2MinSmoothGenerator* Gen = NewObject<UFastNoise2MinSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	Gen->SetSmoothnessValue(Smoothness);
	return Gen;
}

UFastNoise2MinSmoothGenerator* UFastNoise2BlueprintLibrary::MinValueSmoothSource(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/, UFastNoise2GeneratorBase* SmoothnessSource /*= nullptr*/)
{
	UFastNoise2MinSmoothGenerator* Gen = NewObject<UFastNoise2MinSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	Gen->SetSmoothnessSource(SmoothnessSource);
	return Gen;
}

UFastNoise2MinSmoothGenerator* UFastNoise2BlueprintLibrary::MinSourcesSmoothSource(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/, UFastNoise2GeneratorBase* SmoothnessSource /*= nullptr*/)
{
	UFastNoise2MinSmoothGenerator* Gen = NewObject<UFastNoise2MinSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	Gen->SetSmoothnessSource(SmoothnessSource);
	return Gen;
}

UFastNoise2MaxSmoothGenerator* UFastNoise2BlueprintLibrary::MaxValueSmoothValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/, float Smoothness /*= 0.1f*/)
{
	UFastNoise2MaxSmoothGenerator* Gen = NewObject<UFastNoise2MaxSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	Gen->SetSmoothnessValue(Smoothness);
	return Gen;
}

UFastNoise2MaxSmoothGenerator* UFastNoise2BlueprintLibrary::MaxSourcesSmoothValue(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/, float Smoothness /*= 0.1f*/)
{
	UFastNoise2MaxSmoothGenerator* Gen = NewObject<UFastNoise2MaxSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	Gen->SetSmoothnessValue(Smoothness);
	return Gen;
}

UFastNoise2MaxSmoothGenerator* UFastNoise2BlueprintLibrary::MaxValueSmoothSource(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, float RHS /*= 0.0f*/, UFastNoise2GeneratorBase* SmoothnessSource /*= nullptr*/)
{
	UFastNoise2MaxSmoothGenerator* Gen = NewObject<UFastNoise2MaxSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSValue(RHS);
	Gen->SetSmoothnessSource(SmoothnessSource);
	return Gen;
}

UFastNoise2MaxSmoothGenerator* UFastNoise2BlueprintLibrary::MaxSourcesSmoothSource(UFastNoise2GeneratorBase* LHSSource /*= nullptr*/, UFastNoise2GeneratorBase* RHSSource /*= nullptr*/, UFastNoise2GeneratorBase* SmoothnessSource /*= nullptr*/)
{
	UFastNoise2MaxSmoothGenerator* Gen = NewObject<UFastNoise2MaxSmoothGenerator>();
	Gen->SetLHSSource(LHSSource);
	Gen->SetRHSSource(RHSSource);
	Gen->SetSmoothnessSource(SmoothnessSource);
	return Gen;
}

UFastNoise2PowFloatGenerator* UFastNoise2BlueprintLibrary::ExponentValueBaseSource(UFastNoise2GeneratorBase* BaseSource /*= nullptr*/, float Exponent /*= 2.0f*/)
{
	UFastNoise2PowFloatGenerator* Gen = NewObject<UFastNoise2PowFloatGenerator>();
	Gen->SetValueSource(BaseSource);
	Gen->SetPow(Exponent);
	return Gen;
}

UFastNoise2PowFloatGenerator* UFastNoise2BlueprintLibrary::ExponentSourceBaseValue(float Base /*= 2.0f*/, UFastNoise2GeneratorBase* ExponentSource /*= nullptr*/)
{
	UFastNoise2PowFloatGenerator* Gen = NewObject<UFastNoise2PowFloatGenerator>();
	Gen->SetValue(Base);
	Gen->SetPowSource(ExponentSource);
	return Gen;
}

UFastNoise2PowFloatGenerator* UFastNoise2BlueprintLibrary::ExponentSourceBaseSource(UFastNoise2GeneratorBase* BaseSource /*= nullptr*/, UFastNoise2GeneratorBase* ExponentSource /*= nullptr*/)
{
	UFastNoise2PowFloatGenerator* Gen = NewObject<UFastNoise2PowFloatGenerator>();
	Gen->SetValueSource(BaseSource);
	Gen->SetPowSource(ExponentSource);
	return Gen;
}

UFastNoise2PowIntGenerator* UFastNoise2BlueprintLibrary::ExponentInt(UFastNoise2GeneratorBase* BaseSource /*= nullptr*/, int32 Exponent /*= 2*/)
{
	UFastNoise2PowIntGenerator* Gen = NewObject<UFastNoise2PowIntGenerator>();
	Gen->SetValueSource(BaseSource);
	Gen->SetPow(Exponent);
	return Gen;
}

UFastNoise2FadeGenerator* UFastNoise2BlueprintLibrary::FadeByValue(UFastNoise2GeneratorBase* SourceA /*= nullptr*/, UFastNoise2GeneratorBase* SourceB /*= nullptr*/, float Fade /*= 0.5f*/)
{
	UFastNoise2FadeGenerator* Gen = NewObject<UFastNoise2FadeGenerator>();
	Gen->SetASource(SourceA);
	Gen->SetBSource(SourceB);
	Gen->SetFadeValue(Fade);
	return Gen;
}

UFastNoise2FadeGenerator* UFastNoise2BlueprintLibrary::FadeBySource(UFastNoise2GeneratorBase* SourceA /*= nullptr*/, UFastNoise2GeneratorBase* SourceB /*= nullptr*/, UFastNoise2GeneratorBase* FadeSource /*= nullptr*/)
{
	UFastNoise2FadeGenerator* Gen = NewObject<UFastNoise2FadeGenerator>();
	Gen->SetASource(SourceA);
	Gen->SetBSource(SourceB);
	Gen->SetFadeSource(FadeSource);
	return Gen;
}

UFastNoise2DomainScaleGenerator* UFastNoise2BlueprintLibrary::DomainScale(UFastNoise2GeneratorBase* Source /*= nullptr*/, float Scale /*= 1.0f*/)
{
	UFastNoise2DomainScaleGenerator* Gen = NewObject<UFastNoise2DomainScaleGenerator>();
	Gen->SetSource(Source);
	Gen->SetScale(Scale);
	return Gen;
}

UFastNoise2DomainOffsetGenerator* UFastNoise2BlueprintLibrary::DomainOffsetByValues(UFastNoise2GeneratorBase* Source /*= nullptr*/, FVector4 Offsets)
{
	UFastNoise2DomainOffsetGenerator* Gen = NewObject<UFastNoise2DomainOffsetGenerator>();
	Gen->SetSource(Source);
	Gen->SetOffsetValues(Offsets);
	return Gen;
}

UFastNoise2DomainOffsetGenerator* UFastNoise2BlueprintLibrary::DomainOffsetBySources(UFastNoise2GeneratorBase* Source /*= nullptr*/, UFastNoise2GeneratorBase* OffsetSourceX, UFastNoise2GeneratorBase* OffsetSourceY, UFastNoise2GeneratorBase* OffsetSourceZ, UFastNoise2GeneratorBase* OffsetSourceW)
{
	UFastNoise2DomainOffsetGenerator* Gen = NewObject<UFastNoise2DomainOffsetGenerator>();
	Gen->SetSource(Source);
	Gen->SetOffsetSources(OffsetSourceX, OffsetSourceY, OffsetSourceZ, OffsetSourceW);
	return Gen;
}

UFastNoise2DomainRotateGenerator* UFastNoise2BlueprintLibrary::DomainRotate(UFastNoise2GeneratorBase* Source /*= nullptr*/, FRotator Rotation)
{
	UFastNoise2DomainRotateGenerator* Gen = NewObject<UFastNoise2DomainRotateGenerator>();
	Gen->SetSource(Source);
	Gen->SetRotation(Rotation);
	return Gen;
}

UFastNoise2DomainAxisScaleGenerator* UFastNoise2BlueprintLibrary::DomainAxisScale(UFastNoise2GeneratorBase* Source /*= nullptr*/, FVector4 Scale /*= FVector4(1.f, 1.f, 1.f, 1.f)*/)
{
	UFastNoise2DomainAxisScaleGenerator* Gen = NewObject<UFastNoise2DomainAxisScaleGenerator>();
	Gen->SetSource(Source);
	Gen->SetScale(Scale);
	return Gen;
}

UFastNoise2SeedOffsetGenerator* UFastNoise2BlueprintLibrary::SeedOffset(UFastNoise2GeneratorBase* Source /*= nullptr*/, int32 Offset /*= 1*/)
{
	UFastNoise2SeedOffsetGenerator* Gen = NewObject<UFastNoise2SeedOffsetGenerator>();
	Gen->SetSource(Source);
	Gen->SetOffset(Offset);
	return Gen;
}

UFastNoise2RemapGenerator* UFastNoise2BlueprintLibrary::Remap(UFastNoise2GeneratorBase* Source /*= nullptr*/, FVector2D FromRange /*= FVector2D(-1.f, 1.f)*/, FVector2D ToRange /*= FVector2D(0.f, 1.f)*/)
{
	UFastNoise2RemapGenerator* Gen = NewObject<UFastNoise2RemapGenerator>();
	Gen->SetSource(Source);
	Gen->SetRemapFromLowerBound(FromRange.X);
	Gen->SetRemapFromUpperBound(FromRange.Y);
	Gen->SetRemapToLowerBound(ToRange.X);
	Gen->SetRemapToUpperBound(ToRange.Y);
	return Gen;
}

UFastNoise2ConvertRGBA8Generator* UFastNoise2BlueprintLibrary::ConvertRGBA8(UFastNoise2GeneratorBase* Source /*= nullptr*/, FVector2D Range /*= FVector2D(-1.f, 1.f)*/)
{
	UFastNoise2ConvertRGBA8Generator* Gen = NewObject<UFastNoise2ConvertRGBA8Generator>();
	Gen->SetSource(Source);
	Gen->SetLowerBound(Range.X);
	Gen->SetUpperBound(Range.Y);
	return Gen;
}

UFastNoise2TerraceGenerator* UFastNoise2BlueprintLibrary::Terrace(UFastNoise2GeneratorBase* Source /*= nullptr*/, float Multiplier /*= 1.0f*/, float Smoothness /*= 0.f*/)
{
	UFastNoise2TerraceGenerator* Gen = NewObject<UFastNoise2TerraceGenerator>();
	Gen->SetSource(Source);
	Gen->SetMultiplier(Multiplier);
	Gen->SetSmoothness(Smoothness);
	return Gen;
}

UFastNoise2AddDimensionGenerator* UFastNoise2BlueprintLibrary::AddDimensionWithPositionValue(UFastNoise2GeneratorBase* Source /*= nullptr*/, float DimensionPosition/*= 0.f*/)
{
	UFastNoise2AddDimensionGenerator* Gen = NewObject<UFastNoise2AddDimensionGenerator>();
	Gen->SetSource(Source);
	Gen->SetNewDimensionPositionValue(DimensionPosition);
	return Gen;
}

UFastNoise2AddDimensionGenerator* UFastNoise2BlueprintLibrary::AddDimensionWithPositionSource(UFastNoise2GeneratorBase* Source /*= nullptr*/, UFastNoise2GeneratorBase* DimensionPositionSource /*= nullptr*/)
{
	UFastNoise2AddDimensionGenerator* Gen = NewObject<UFastNoise2AddDimensionGenerator>();
	Gen->SetSource(Source);
	Gen->SetNewDimensionPositionSource(DimensionPositionSource);
	return Gen;
}

UFastNoise2RemoveDimensionGenerator* UFastNoise2BlueprintLibrary::RemoveDimension(UFastNoise2GeneratorBase* Source /*= nullptr*/, EFastNoise2Dimension DimensionToRemove /*= EFastNoise2Dimension::Y*/)
{
	UFastNoise2RemoveDimensionGenerator* Gen = NewObject<UFastNoise2RemoveDimensionGenerator>();
	Gen->SetSource(Source);
	Gen->SetDimensionToRemove(DimensionToRemove);
	return Gen;
}

UFastNoise2GeneratorCacheGenerator* UFastNoise2BlueprintLibrary::MakeGeneratorCache(UFastNoise2GeneratorBase* Source /*= nullptr*/)
{
	UFastNoise2GeneratorCacheGenerator* Gen = NewObject<UFastNoise2GeneratorCacheGenerator>();
	Gen->SetSource(Source);
	return Gen;
}
