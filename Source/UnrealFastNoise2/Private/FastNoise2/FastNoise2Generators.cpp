#include "FastNoise2/FastNoise2Generators.h"
#include "FastNoise/FastNoise.h"
#include "FastSIMD/FastSIMD.h"

void UFastNoise2GeneratorBase::PostInitProperties()
{
	Super::PostInitProperties();

	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		ResetGenerator();
	}
}

FFloatRange UFastNoise2GeneratorBase::GenUniformGrid2D(TArray<float>& OutValues, const FIntPoint& Start, const FIntPoint& Size, float Frequency, int32 Seed) const
{
	check(GeneratorInst.get());
	OutValues.SetNum(Size.X * Size.Y);
	const FastNoise::OutputMinMax MinMax = GeneratorInst->GenUniformGrid2D(OutValues.GetData(), Start.X, Start.Y, Size.X, Size.Y, Frequency, Seed);
	return FFloatRange(MinMax.min, MinMax.max);
}

FFloatRange UFastNoise2GeneratorBase::GenUniformGrid3D(TArray<float>& OutValues, const FIntVector& Start, const FIntVector& Size, float Frequency, int32 Seed) const
{
	check(GeneratorInst.get());
	OutValues.SetNum(Size.X * Size.Y * Size.Z);
	const FastNoise::OutputMinMax MinMax = GeneratorInst->GenUniformGrid3D(OutValues.GetData(), Start.X, Start.Y, Start.Z, Size.X, Size.Y, Size.Z, Frequency, Seed);
	return FFloatRange(MinMax.min, MinMax.max);
}

FFloatRange UFastNoise2GeneratorBase::GenUniformGrid4D(TArray<float>& OutValues, const FVector4& Start, const FVector4& Size, float Frequency, int32 Seed) const
{
	check(GeneratorInst.get());
	OutValues.SetNum(Size.X * Size.Y * Size.Z * Size.W);
	const FastNoise::OutputMinMax MinMax = GeneratorInst->GenUniformGrid4D(OutValues.GetData(), Start.X, Start.Y, Start.Z, Start.W, Size.X, Size.Y, Size.Z, Size.W, Frequency, Seed);
	return FFloatRange(MinMax.min, MinMax.max);
}

FFloatRange UFastNoise2GeneratorBase::GenTileable2D(TArray<float>& OutValues, const FIntPoint& Size, float Frequency, int32 Seed) const
{
	check(GeneratorInst.get());
	OutValues.SetNum(Size.X * Size.Y);
	const FastNoise::OutputMinMax MinMax = GeneratorInst->GenTileable2D(OutValues.GetData(), Size.X, Size.Y, Frequency, Seed);
	return FFloatRange(MinMax.min, MinMax.max);
}

FFloatRange UFastNoise2GeneratorBase::GenPositionArray2D(TArray<float>& OutValues, const TArray<FVector2D>& PosArray, const FVector2D& Offset, int32 Seed) const
{
	check(GeneratorInst.get());
	OutValues.SetNum(PosArray.Num());
	TArray<float> XPositions;
	XPositions.Reserve(PosArray.Num());
	TArray<float> YPositions;
	YPositions.Reserve(PosArray.Num());

	for (const FVector2D& Pos : PosArray)
	{
		XPositions.Add(Pos.X);
		YPositions.Add(Pos.Y);
	}

	const FastNoise::OutputMinMax MinMax = GeneratorInst->GenPositionArray2D(OutValues.GetData(), PosArray.Num(), XPositions.GetData(), YPositions.GetData(), Offset.X, Offset.Y, Seed);
	return FFloatRange(MinMax.min, MinMax.max);
}

FFloatRange UFastNoise2GeneratorBase::GenPositionArray3D(TArray<float>& OutValues, const TArray<FVector>& PosArray, const FVector& Offset, int32 Seed) const
{
	check(GeneratorInst.get());
	OutValues.SetNum(PosArray.Num());
	TArray<float> XPositions;
	XPositions.Reserve(PosArray.Num());
	TArray<float> YPositions;
	YPositions.Reserve(PosArray.Num());
	TArray<float> ZPositions;
	ZPositions.Reserve(PosArray.Num());

	for (const FVector& Pos : PosArray)
	{
		XPositions.Add(Pos.X);
		YPositions.Add(Pos.Y);
		ZPositions.Add(Pos.Z);
	}

	const FastNoise::OutputMinMax MinMax = GeneratorInst->GenPositionArray3D(OutValues.GetData(), PosArray.Num(), XPositions.GetData(), YPositions.GetData(), ZPositions.GetData(), Offset.X, Offset.Y, Offset.Z, Seed);
	return FFloatRange(MinMax.min, MinMax.max);
}

FFloatRange UFastNoise2GeneratorBase::GenPositionArray4D(TArray<float>& OutValues, const TArray<FVector4>& PosArray, const FVector4& Offset, int32 Seed) const
{
	check(GeneratorInst.get());
	OutValues.SetNum(PosArray.Num());
	TArray<float> XPositions;
	XPositions.Reserve(PosArray.Num());
	TArray<float> YPositions;
	YPositions.Reserve(PosArray.Num());
	TArray<float> ZPositions;
	ZPositions.Reserve(PosArray.Num());
	TArray<float> WPositions;
	WPositions.Reserve(PosArray.Num());

	for (const FVector4& Pos : PosArray)
	{
		XPositions.Add(Pos.X);
		YPositions.Add(Pos.Y);
		ZPositions.Add(Pos.Z);
		WPositions.Add(Pos.W);
	}

	const FastNoise::OutputMinMax MinMax = GeneratorInst->GenPositionArray4D(OutValues.GetData(), PosArray.Num(), XPositions.GetData(), YPositions.GetData(), ZPositions.GetData(), WPositions.GetData(), Offset.X, Offset.Y, Offset.Z, Offset.W, Seed);
	return FFloatRange(MinMax.min, MinMax.max);
}

float UFastNoise2GeneratorBase::GenSingle2D(const FVector2D& Location, int32 Seed) const
{
	check(GeneratorInst.get());
	return GeneratorInst->GenSingle2D(Location.X, Location.Y, Seed);
}

float UFastNoise2GeneratorBase::GenSingle3D(const FVector& Location, int32 Seed) const
{
	check(GeneratorInst.get());
	return GeneratorInst->GenSingle3D(Location.X, Location.Y, Location.Z, Seed);
}

float UFastNoise2GeneratorBase::GenSingle4D(const FVector4& Location, int32 Seed) const
{
	check(GeneratorInst.get());
	return GeneratorInst->GenSingle4D(Location.X, Location.Y, Location.Z, Location.W, Seed);
}

void UFastNoise2GeneratorBase::ResetGenerator()
{
	if (GeneratorInst.get() != nullptr)
	{
		GeneratorInst.reset();
	}
	InitGenerator_Internal();
}

void UFastNoise2GeneratorBase::InitGenerator_Internal()
{
	GeneratorInst = InitGenerator();
	check(GeneratorInst.get());
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2EncodedNodeTreeGenerator::PostInitProperties()
{
	if (EncodedNodeTree.IsEmpty())
	{
		// Skip initialization if we don't have data
		UObject::PostInitProperties();
	}
	else
	{
		Super::PostInitProperties();
	}
}

void UFastNoise2EncodedNodeTreeGenerator::SetEncodedNodeTree(const FString& InValue)
{
	EncodedNodeTree = InValue;
	ResetGenerator();
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2EncodedNodeTreeGenerator::InitGenerator()
{
	return FastNoise::NewFromEncodedNodeTree(TCHAR_TO_ANSI(*EncodedNodeTree));
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2ConstantGenerator::SetValue(float InValue)
{
	check(ConstantGeneratorInst.get());
	Value = InValue;
	ConstantGeneratorInst->SetValue(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2ConstantGenerator::InitGenerator()
{
	ConstantGeneratorInst = FastNoise::New<FastNoise::Constant>();
	SetValue(Value);
	return ConstantGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2WhiteGenerator::InitGenerator()
{
	WhiteGeneratorInst = FastNoise::New<FastNoise::White>();
	return WhiteGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2CheckerboardGenerator::SetSize(float InSize)
{
	check(CheckerboardGeneratorInst.get());
	Size = InSize;
	CheckerboardGeneratorInst->SetSize(InSize);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2CheckerboardGenerator::InitGenerator()
{
	CheckerboardGeneratorInst = FastNoise::New<FastNoise::Checkerboard>();
	SetSize(Size);
	return CheckerboardGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2SineWaveGenerator::SetScale(float InScale)
{
	check(SineWaveGeneratorInst.get());
	Scale = InScale;
	SineWaveGeneratorInst->SetScale(InScale);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2SineWaveGenerator::InitGenerator()
{
	SineWaveGeneratorInst = FastNoise::New<FastNoise::SineWave>();
	SetScale(Scale);
	return SineWaveGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2PositionOutputGenerator::SetData(const FVector4& InMultipliers, const FVector4& InOffsets)
{
	check(PositionOutputGeneratorInst.get());
	Offsets = InOffsets;
	PositionOutputGeneratorInst->Set<FastNoise::Dim::X>(InMultipliers.X, InOffsets.X);
	PositionOutputGeneratorInst->Set<FastNoise::Dim::Y>(InMultipliers.Y, InOffsets.Y);
	PositionOutputGeneratorInst->Set<FastNoise::Dim::Z>(InMultipliers.Z, InOffsets.Z);
	PositionOutputGeneratorInst->Set<FastNoise::Dim::W>(InMultipliers.W, InOffsets.W);
}

void UFastNoise2PositionOutputGenerator::SetMultipliers(const FVector4& InMultipliers)
{
	SetData(InMultipliers, Offsets);
}

void UFastNoise2PositionOutputGenerator::SetOffsets(const FVector4& InOffsets)
{
	SetData(Multipliers, InOffsets);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2PositionOutputGenerator::InitGenerator()
{
	PositionOutputGeneratorInst = FastNoise::New<FastNoise::PositionOutput>();
	SetData(Multipliers, Offsets);
	return PositionOutputGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2DistanceToPointGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(DistanceToPointGeneratorInst.get());
		DistanceToPointGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2DistanceToPointGenerator::SetDistanceFunction(EFastNoise2DistanceFunction InDistanceFunction)
{
	check(DistanceToPointGeneratorInst.get());
	DistanceFunction = InDistanceFunction;
	DistanceToPointGeneratorInst->SetDistanceFunction(FFastNoise2Helpers::ConvertUnrealToFastNoiseDistanceFunction(InDistanceFunction));
}

void UFastNoise2DistanceToPointGenerator::SetScale(const FVector4& InScale)
{
	check(DistanceToPointGeneratorInst.get());
	Scale = InScale;
	DistanceToPointGeneratorInst->SetScale<FastNoise::Dim::X>(InScale.X);
	DistanceToPointGeneratorInst->SetScale<FastNoise::Dim::Y>(InScale.Y);
	DistanceToPointGeneratorInst->SetScale<FastNoise::Dim::Z>(InScale.Z);
	DistanceToPointGeneratorInst->SetScale<FastNoise::Dim::W>(InScale.W);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DistanceToPointGenerator::InitGenerator()
{
	DistanceToPointGeneratorInst = FastNoise::New<FastNoise::DistanceToPoint>();
	SetDistanceFunction(DistanceFunction);
	SetScale(Scale);
	return DistanceToPointGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2ValueGenerator::InitGenerator()
{
	ValueGeneratorInst = FastNoise::New<FastNoise::Value>();
	return ValueGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2PerlinGenerator::InitGenerator()
{
	PerlinGeneratorInst = FastNoise::New<FastNoise::Perlin>();
	return PerlinGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2SimplexGenerator::InitGenerator()
{
	SimplexGeneratorInst = FastNoise::New<FastNoise::Simplex>();
	return SimplexGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2OpenSimplex2Generator::InitGenerator()
{
	OpenSimplex2GeneratorInst = FastNoise::New<FastNoise::OpenSimplex2>();
	return OpenSimplex2GeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2OpenSimplex2SGenerator::InitGenerator()
{
	OpenSimplex2SGeneratorInst = FastNoise::New<FastNoise::OpenSimplex2S>();
	return OpenSimplex2SGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2CellularGeneratorBase::SetJitterModifierSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(CellularGeneratorInst.get());
		CellularGeneratorInst->SetJitterModifier(InSource->GetGenerator());
	}
}

void UFastNoise2CellularGeneratorBase::SetJitterModifierValue(float InValue)
{
	check(CellularGeneratorInst.get());
	JitterModifierValue = InValue;
	CellularGeneratorInst->SetJitterModifier(InValue);
}

void UFastNoise2CellularGeneratorBase::SetDistanceFunction(EFastNoise2DistanceFunction InDistanceFunction)
{
	check(CellularGeneratorInst.get());
	DistanceFunction = InDistanceFunction;
	CellularGeneratorInst->SetDistanceFunction(FFastNoise2Helpers::ConvertUnrealToFastNoiseDistanceFunction(InDistanceFunction));
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2CellularValueGenerator::SetValueIndex(int32 InValueIndex)
{
	check(CellularValueGeneratorInst.get());
	ValueIndex = InValueIndex;
	CellularValueGeneratorInst->SetValueIndex(InValueIndex);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2CellularValueGenerator::InitGenerator()
{
	CellularValueGeneratorInst = FastNoise::New<FastNoise::CellularValue>();
	CellularGeneratorInst = CellularValueGeneratorInst;
	SetDistanceFunction(DistanceFunction);
	SetJitterModifierValue(JitterModifierValue);
	SetValueIndex(ValueIndex);
	return CellularValueGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2CellularDistanceGenerator::SetDistanceIndex0(int32 InDistanceIndex0)
{
	check(CellularDistanceGeneratorInst.get());
	DistanceIndex0 = InDistanceIndex0;
	CellularDistanceGeneratorInst->SetDistanceIndex0(InDistanceIndex0);
}

void UFastNoise2CellularDistanceGenerator::SetDistanceIndex1(int32 InDistanceIndex1)
{
	check(CellularDistanceGeneratorInst.get());
	DistanceIndex1 = InDistanceIndex1;
	CellularDistanceGeneratorInst->SetDistanceIndex1(InDistanceIndex1);
}

void UFastNoise2CellularDistanceGenerator::SetReturnType(EFastNoise2CellularDistanceReturnType InReturnType)
{
	check(CellularDistanceGeneratorInst.get());
	ReturnType = InReturnType;
	CellularDistanceGeneratorInst->SetReturnType(FFastNoise2Helpers::ConvertUnrealToFastNoiseCellularDistanceReturnType(InReturnType));
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2CellularDistanceGenerator::InitGenerator()
{
	CellularDistanceGeneratorInst = FastNoise::New<FastNoise::CellularDistance>();
	CellularGeneratorInst = CellularDistanceGeneratorInst;
	SetDistanceFunction(DistanceFunction);
	SetJitterModifierValue(JitterModifierValue);
	SetDistanceIndex0(DistanceIndex0);
	SetDistanceIndex1(DistanceIndex1);
	return CellularDistanceGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2CellularLookupGenerator::SetLookupSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(CellularLookupGeneratorInst.get());
		CellularLookupGeneratorInst->SetLookup(InSource->GetGenerator());
	}
}

void UFastNoise2CellularLookupGenerator::SetLookupFrequency(float InLookupFrequency)
{
	check(CellularLookupGeneratorInst.get());
	LookupFrequency = InLookupFrequency;
	CellularLookupGeneratorInst->SetLookupFrequency(InLookupFrequency);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2CellularLookupGenerator::InitGenerator()
{
	CellularLookupGeneratorInst = FastNoise::New<FastNoise::CellularLookup>();
	CellularGeneratorInst = CellularLookupGeneratorInst;
	SetDistanceFunction(DistanceFunction);
	SetJitterModifierValue(JitterModifierValue);
	SetLookupFrequency(LookupFrequency);
	return CellularLookupGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2FractalGeneratorBase::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FractalGeneratorInst.get());
		FractalGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2FractalGeneratorBase::SetGainSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FractalGeneratorInst.get());
		FractalGeneratorInst->SetGain(InSource->GetGenerator());
	}
}

void UFastNoise2FractalGeneratorBase::SetWeightedStrengthSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FractalGeneratorInst.get());
		FractalGeneratorInst->SetWeightedStrength(InSource->GetGenerator());
	}
}

void UFastNoise2FractalGeneratorBase::SetGainValue(float InValue)
{
	check(FractalGeneratorInst.get());
	Gain = InValue;
	FractalGeneratorInst->SetGain(InValue);
}

void UFastNoise2FractalGeneratorBase::SetWeightedStrengthValue(float InValue)
{
	check(FractalGeneratorInst.get());
	WeightedStrength = InValue;
	FractalGeneratorInst->SetWeightedStrength(InValue);
}

void UFastNoise2FractalGeneratorBase::SetLacunarityValue(float InValue)
{
	check(FractalGeneratorInst.get());
	Lacunarity = InValue;
	FractalGeneratorInst->SetLacunarity(InValue);
}

void UFastNoise2FractalGeneratorBase::SetOctaveCount(int32 InOctaveCount)
{
	check(FractalGeneratorInst.get());
	Octaves = InOctaveCount;
	FractalGeneratorInst->SetOctaveCount(InOctaveCount);
}

void UFastNoise2FractalGeneratorBase::InitFractalBase(FastNoise::SmartNode<FastNoise::Fractal<>> InFractalGeneratorInst)
{
	FractalGeneratorInst = InFractalGeneratorInst;
	SetGainValue(Gain);
	SetWeightedStrengthValue(WeightedStrength);
	SetLacunarityValue(Lacunarity);
	SetOctaveCount(Octaves);
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2FractalFBmGenerator::InitGenerator()
{
	FractalFBmGeneratorInst = FastNoise::New<FastNoise::FractalFBm>();
	InitFractalBase(FractalFBmGeneratorInst);
	return FractalFBmGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2FractalRidgedGenerator::InitGenerator()
{
	FractalRidgedGeneratorInst = FastNoise::New<FastNoise::FractalRidged>();
	InitFractalBase(FractalRidgedGeneratorInst);
	return FractalRidgedGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2FractalPingPongGenerator::SetPingPongStrengthSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FractalPingPongGeneratorInst.get());
		FractalPingPongGeneratorInst->SetPingPongStrength(InSource->GetGenerator());
	}
}

void UFastNoise2FractalPingPongGenerator::SetPingPongStrengthValue(float InPingPongStrength)
{
	check(FractalPingPongGeneratorInst.get());
	PingPongStrength = InPingPongStrength;
	FractalPingPongGeneratorInst->SetPingPongStrength(InPingPongStrength);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2FractalPingPongGenerator::InitGenerator()
{
	FractalPingPongGeneratorInst = FastNoise::New<FastNoise::FractalPingPong>();
	InitFractalBase(FractalPingPongGeneratorInst);
	SetPingPongStrengthValue(PingPongStrength);
	return FractalPingPongGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2DomainWarpGeneratorBase::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(DomainWarpGeneratorInst.get());
		DomainWarpGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2DomainWarpGeneratorBase::SetWarpAmplitudeSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(DomainWarpGeneratorInst.get());
		DomainWarpGeneratorInst->SetWarpAmplitude(InSource->GetGenerator());
	}
}

void UFastNoise2DomainWarpGeneratorBase::SetWarpAmplitudeValue(float InValue)
{
	check(DomainWarpGeneratorInst.get());
	WarpAmplitude = InValue;
	DomainWarpGeneratorInst->SetWarpAmplitude(InValue);
}

void UFastNoise2DomainWarpGeneratorBase::SetWarpFrequencyValue(float InValue)
{
	check(DomainWarpGeneratorInst.get());
	WarpFrequency = InValue;
	DomainWarpGeneratorInst->SetWarpFrequency(InValue);
}

void UFastNoise2DomainWarpGeneratorBase::InitDomainWarpBase(FastNoise::SmartNode<FastNoise::DomainWarp> InDomainWarpGeneratorInst)
{
	DomainWarpGeneratorInst = InDomainWarpGeneratorInst;
	SetWarpAmplitudeValue(WarpAmplitude);
	SetWarpFrequencyValue(WarpFrequency);
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DomainWarpGradientGenerator::InitGenerator()
{
	DomainWarpGradientGeneratorInst = FastNoise::New<FastNoise::DomainWarpGradient>();
	InitDomainWarpBase(DomainWarpGradientGeneratorInst);
	return DomainWarpGradientGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2FractalDomainWarpGeneratorBase::SetDomainWarpSource(UFastNoise2DomainWarpGeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FractalDomainWarpGeneratorInst.get());
		FractalDomainWarpGeneratorInst->SetSource(InSource->GetDomainWarpGenerator());
	}
}

void UFastNoise2FractalDomainWarpGeneratorBase::SetGainSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FractalDomainWarpGeneratorInst.get());
		FractalDomainWarpGeneratorInst->SetGain(InSource->GetGenerator());
	}
}

void UFastNoise2FractalDomainWarpGeneratorBase::SetWeightedStrengthSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FractalDomainWarpGeneratorInst.get());
		FractalDomainWarpGeneratorInst->SetWeightedStrength(InSource->GetGenerator());
	}
}

void UFastNoise2FractalDomainWarpGeneratorBase::SetGainValue(float InValue)
{
	check(FractalDomainWarpGeneratorInst.get());
	Gain = InValue;
	FractalDomainWarpGeneratorInst->SetGain(InValue);
}

void UFastNoise2FractalDomainWarpGeneratorBase::SetWeightedStrengthValue(float InValue)
{
	check(FractalDomainWarpGeneratorInst.get());
	WeightedStrength = InValue;
	FractalDomainWarpGeneratorInst->SetWeightedStrength(InValue);
}

void UFastNoise2FractalDomainWarpGeneratorBase::SetLacunarityValue(float InValue)
{
	check(FractalDomainWarpGeneratorInst.get());
	Lacunarity = InValue;
	FractalDomainWarpGeneratorInst->SetLacunarity(InValue);
}

void UFastNoise2FractalDomainWarpGeneratorBase::SetOctaveCount(int32 InOctaveCount)
{
	check(FractalDomainWarpGeneratorInst.get());
	Octaves = InOctaveCount;
	FractalDomainWarpGeneratorInst->SetOctaveCount(InOctaveCount);
}

void UFastNoise2FractalDomainWarpGeneratorBase::InitFractalDomainWarpBase(FastNoise::SmartNode<FastNoise::Fractal<FastNoise::DomainWarp>> InFractalDomainWarpGeneratorInst)
{
	FractalDomainWarpGeneratorInst = InFractalDomainWarpGeneratorInst;
	SetGainValue(Gain);
	SetWeightedStrengthValue(WeightedStrength);
	SetLacunarityValue(Lacunarity);
	SetOctaveCount(Octaves);
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DomainWarpFractalProgressiveGenerator::InitGenerator()
{
	DomainWarpFractalProgressiveGeneratorInst = FastNoise::New<FastNoise::DomainWarpFractalProgressive>();
	InitFractalDomainWarpBase(DomainWarpFractalProgressiveGeneratorInst);
	return DomainWarpFractalProgressiveGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DomainWarpFractalIndependantGenerator::InitGenerator()
{
	DomainWarpFractalIndependantGeneratorInst = FastNoise::New<FastNoise::DomainWarpFractalIndependant>();
	InitFractalDomainWarpBase(DomainWarpFractalIndependantGeneratorInst);
	return DomainWarpFractalIndependantGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2OperatorSourceLHSGeneratorBase::SetLHSSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(OperatorSourceLHSGeneratorInst.get());
		OperatorSourceLHSGeneratorInst->SetLHS(InSource->GetGenerator());
	}
}

void UFastNoise2OperatorSourceLHSGeneratorBase::SetRHSSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(OperatorSourceLHSGeneratorInst.get());
		OperatorSourceLHSGeneratorInst->SetRHS(InSource->GetGenerator());
	}
}

void UFastNoise2OperatorSourceLHSGeneratorBase::SetRHSValue(float InValue)
{
	check(OperatorSourceLHSGeneratorInst.get());
	RHSValue = InValue;
	OperatorSourceLHSGeneratorInst->SetRHS(InValue);
}

void UFastNoise2OperatorSourceLHSGeneratorBase::InitOperatorSourceLHSGenerator(FastNoise::SmartNode<FastNoise::OperatorSourceLHS> InOperatorSourceLHSGeneratorInst)
{
	OperatorSourceLHSGeneratorInst = InOperatorSourceLHSGeneratorInst;
	SetRHSValue(RHSValue);

}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2OperatorHybridLHSGeneratorBase::SetLHSSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(OperatorHybridLHSGeneratorInst.get());
		OperatorHybridLHSGeneratorInst->SetLHS(InSource->GetGenerator());
	}
}

void UFastNoise2OperatorHybridLHSGeneratorBase::SetLHSValue(float InValue)
{
	check(OperatorHybridLHSGeneratorInst.get());
	LHSValue = InValue;
	OperatorHybridLHSGeneratorInst->SetLHS(InValue);
}

void UFastNoise2OperatorHybridLHSGeneratorBase::SetRHSSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(OperatorHybridLHSGeneratorInst.get());
		OperatorHybridLHSGeneratorInst->SetRHS(InSource->GetGenerator());
	}
}

void UFastNoise2OperatorHybridLHSGeneratorBase::SetRHSValue(float InValue)
{
	check(OperatorHybridLHSGeneratorInst.get());
	RHSValue = InValue;
	OperatorHybridLHSGeneratorInst->SetRHS(InValue);
}

void UFastNoise2OperatorHybridLHSGeneratorBase::InitOperatorHybridLHSGenerator(FastNoise::SmartNode<FastNoise::OperatorHybridLHS> InOperatorHybridLHSGeneratorInst)
{
	OperatorHybridLHSGeneratorInst = InOperatorHybridLHSGeneratorInst;
	SetRHSValue(LHSValue);
	SetRHSValue(RHSValue);
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2AddGenerator::InitGenerator()
{
	AddGeneratorInst = FastNoise::New<FastNoise::Add>();
	InitOperatorSourceLHSGenerator(AddGeneratorInst);
	return AddGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2SubtractGenerator::InitGenerator()
{
	SubtractGeneratorInst = FastNoise::New<FastNoise::Subtract>();
	InitOperatorHybridLHSGenerator(SubtractGeneratorInst);
	return SubtractGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2MultiplyGenerator::InitGenerator()
{
	MultiplyGeneratorInst = FastNoise::New<FastNoise::Multiply>();
	InitOperatorSourceLHSGenerator(MultiplyGeneratorInst);
	return MultiplyGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DivideGenerator::InitGenerator()
{
	DivideGeneratorInst = FastNoise::New<FastNoise::Divide>();
	InitOperatorHybridLHSGenerator(DivideGeneratorInst);
	return DivideGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2MinGenerator::InitGenerator()
{
	MinGeneratorInst = FastNoise::New<FastNoise::Min>();
	InitOperatorSourceLHSGenerator(MinGeneratorInst);
	return MinGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2MaxGenerator::InitGenerator()
{
	MaxGeneratorInst = FastNoise::New<FastNoise::Max>();
	InitOperatorSourceLHSGenerator(MaxGeneratorInst);
	return MaxGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2PowFloatGenerator::SetValueSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(PowFloatGeneratorInst.get());
		PowFloatGeneratorInst->SetValue(InSource->GetGenerator());
	}
}

void UFastNoise2PowFloatGenerator::SetValue(float InValue)
{
	check(PowFloatGeneratorInst.get());
	Value = InValue;
	PowFloatGeneratorInst->SetValue(InValue);
}

void UFastNoise2PowFloatGenerator::SetPowSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(PowFloatGeneratorInst.get());
		PowFloatGeneratorInst->SetPow(InSource->GetGenerator());
	}
}

void UFastNoise2PowFloatGenerator::SetPow(float InValue)
{
	check(PowFloatGeneratorInst.get());
	Pow = InValue;
	PowFloatGeneratorInst->SetPow(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2PowFloatGenerator::InitGenerator()
{
	PowFloatGeneratorInst = FastNoise::New<FastNoise::PowFloat>();
	SetValue(Value);
	SetPow(Pow);
	return PowFloatGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2PowIntGenerator::SetValueSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(PowIntGeneratorInst.get());
		PowIntGeneratorInst->SetValue(InSource->GetGenerator());
	}
}

void UFastNoise2PowIntGenerator::SetPow(int32 InValue)
{
	check(PowIntGeneratorInst.get());
	Pow = InValue;
	PowIntGeneratorInst->SetPow(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2PowIntGenerator::InitGenerator()
{
	PowIntGeneratorInst = FastNoise::New<FastNoise::PowInt>();
	SetPow(Pow);
	return PowIntGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2MinSmoothGenerator::SetSmoothnessSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(MinSmoothGeneratorInst.get());
		MinSmoothGeneratorInst->SetSmoothness(InSource->GetGenerator());
	}
}

void UFastNoise2MinSmoothGenerator::SetSmoothnessValue(float InValue)
{
	check(MinSmoothGeneratorInst.get());
	Smoothness = InValue;
	MinSmoothGeneratorInst->SetSmoothness(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2MinSmoothGenerator::InitGenerator()
{
	MinSmoothGeneratorInst = FastNoise::New<FastNoise::MinSmooth>();
	InitOperatorSourceLHSGenerator(MinSmoothGeneratorInst);
	SetSmoothnessValue(Smoothness);
	return MinSmoothGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2MaxSmoothGenerator::SetSmoothnessSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(MaxSmoothGeneratorInst.get());
		MaxSmoothGeneratorInst->SetSmoothness(InSource->GetGenerator());
	}
}

void UFastNoise2MaxSmoothGenerator::SetSmoothnessValue(float InValue)
{
	check(MaxSmoothGeneratorInst.get());
	Smoothness = InValue;
	MaxSmoothGeneratorInst->SetSmoothness(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2MaxSmoothGenerator::InitGenerator()
{
	MaxSmoothGeneratorInst = FastNoise::New<FastNoise::MaxSmooth>();
	InitOperatorSourceLHSGenerator(MaxSmoothGeneratorInst);
	SetSmoothnessValue(Smoothness);
	return MaxSmoothGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2FadeGenerator::SetASource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FadeGeneratorInst.get());
		FadeGeneratorInst->SetA(InSource->GetGenerator());
	}
}

void UFastNoise2FadeGenerator::SetBSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FadeGeneratorInst.get());
		FadeGeneratorInst->SetB(InSource->GetGenerator());
	}
}

void UFastNoise2FadeGenerator::SetFadeSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(FadeGeneratorInst.get());
		FadeGeneratorInst->SetFade(InSource->GetGenerator());
	}
}

void UFastNoise2FadeGenerator::SetFadeValue(float InValue)
{
	check(FadeGeneratorInst.get());
	Fade = InValue;
	FadeGeneratorInst->SetFade(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2FadeGenerator::InitGenerator()
{
	FadeGeneratorInst = FastNoise::New<FastNoise::Fade>();
	SetFadeValue(Fade);
	return FadeGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2DomainScaleGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(DomainScaleGeneratorInst.get());
		DomainScaleGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2DomainScaleGenerator::SetScale(float InValue)
{
	check(DomainScaleGeneratorInst.get());
	Scale = InValue;
	DomainScaleGeneratorInst->SetScale(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DomainScaleGenerator::InitGenerator()
{
	DomainScaleGeneratorInst = FastNoise::New<FastNoise::DomainScale>();
	SetScale(Scale);
	return DomainScaleGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2DomainOffsetGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(DomainOffsetGeneratorInst.get());
		DomainOffsetGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2DomainOffsetGenerator::SetOffsetSources(UFastNoise2GeneratorBase* InSourceX, UFastNoise2GeneratorBase* InSourceY, UFastNoise2GeneratorBase* InSourceZ, UFastNoise2GeneratorBase* InSourceW)
{
	if (InSourceX != nullptr)
	{
		check(DomainOffsetGeneratorInst.get());
		DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::X>(InSourceX->GetGenerator());
	}
	if (InSourceY != nullptr)
	{
		check(DomainOffsetGeneratorInst.get());
		DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::Y>(InSourceY->GetGenerator());
	}
	if (InSourceZ != nullptr)
	{
		check(DomainOffsetGeneratorInst.get());
		DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::Z>(InSourceZ->GetGenerator());
	}
	if (InSourceW != nullptr)
	{
		check(DomainOffsetGeneratorInst.get());
		DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::W>(InSourceW->GetGenerator());
	}
}

void UFastNoise2DomainOffsetGenerator::SetOffsetValues(const FVector4& InValue)
{
	check(DomainOffsetGeneratorInst.get());
	Offsets = InValue;
	DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::X>(InValue.X);
	DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::Y>(InValue.Y);
	DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::Z>(InValue.Z);
	DomainOffsetGeneratorInst->SetOffset<FastNoise::Dim::W>(InValue.W);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DomainOffsetGenerator::InitGenerator()
{
	DomainOffsetGeneratorInst = FastNoise::New<FastNoise::DomainOffset>();
	SetOffsetValues(Offsets);
	return DomainOffsetGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2DomainRotateGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(DomainRotateGeneratorInst.get());
		DomainRotateGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2DomainRotateGenerator::SetRotation(const FRotator& InValue)
{
	check(DomainRotateGeneratorInst.get());
	Rotation = InValue;
	DomainRotateGeneratorInst->SetYaw(Rotation.Yaw);
	DomainRotateGeneratorInst->SetPitch(Rotation.Pitch);
	DomainRotateGeneratorInst->SetRoll(Rotation.Roll);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DomainRotateGenerator::InitGenerator()
{
	DomainRotateGeneratorInst = FastNoise::New<FastNoise::DomainRotate>();
	SetRotation(Rotation);
	return DomainRotateGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2SeedOffsetGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(SeedOffsetGeneratorInst.get());
		SeedOffsetGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2SeedOffsetGenerator::SetOffset(int32 InValue)
{
	check(SeedOffsetGeneratorInst.get());
	Offset = InValue;
	SeedOffsetGeneratorInst->SetOffset(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2SeedOffsetGenerator::InitGenerator()
{
	SeedOffsetGeneratorInst = FastNoise::New<FastNoise::SeedOffset>();
	SetOffset(Offset);
	return SeedOffsetGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2RemapGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(RemapGeneratorInst.get());
		RemapGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2RemapGenerator::SetRemapFromLowerBound(float InValue)
{
	check(RemapGeneratorInst.get());
	FromLowerBound = InValue;
	RemapGeneratorInst->SetRemap(InValue, FromUpperBound, ToLowerBound, ToUpperBound);
}

void UFastNoise2RemapGenerator::SetRemapFromUpperBound(float InValue)
{
	check(RemapGeneratorInst.get());
	FromUpperBound = InValue;
	RemapGeneratorInst->SetRemap(FromLowerBound, InValue, ToLowerBound, ToUpperBound);
}

void UFastNoise2RemapGenerator::SetRemapToLowerBound(float InValue)
{
	check(RemapGeneratorInst.get());
	ToLowerBound = InValue;
	RemapGeneratorInst->SetRemap(FromLowerBound, FromUpperBound, InValue, ToUpperBound);
}

void UFastNoise2RemapGenerator::SetRemapToUpperBound(float InValue)
{
	check(RemapGeneratorInst.get());
	ToUpperBound = InValue;
	RemapGeneratorInst->SetRemap(FromLowerBound, FromUpperBound, ToLowerBound, InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2RemapGenerator::InitGenerator()
{
	RemapGeneratorInst = FastNoise::New<FastNoise::Remap>();
	SetRemapFromLowerBound(FromLowerBound);
	SetRemapFromUpperBound(FromUpperBound);
	SetRemapToLowerBound(ToLowerBound);
	SetRemapToUpperBound(ToUpperBound);
	return RemapGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2ConvertRGBA8Generator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(ConvertRGBA8GeneratorInst.get());
		ConvertRGBA8GeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2ConvertRGBA8Generator::SetLowerBound(float InValue)
{
	check(ConvertRGBA8GeneratorInst.get());
	LowerBound = InValue;
	ConvertRGBA8GeneratorInst->SetMinMax(InValue, UpperBound);
}

void UFastNoise2ConvertRGBA8Generator::SetUpperBound(float InValue)
{
	check(ConvertRGBA8GeneratorInst.get());
	UpperBound = InValue;
	ConvertRGBA8GeneratorInst->SetMinMax(LowerBound, InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2ConvertRGBA8Generator::InitGenerator()
{
	ConvertRGBA8GeneratorInst = FastNoise::New<FastNoise::ConvertRGBA8>();
	SetLowerBound(LowerBound);
	SetUpperBound(UpperBound);
	return ConvertRGBA8GeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2TerraceGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(TerraceGeneratorInst.get());
		TerraceGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2TerraceGenerator::SetMultiplier(float InValue)
{
	check(TerraceGeneratorInst.get());
	Multiplier = InValue;
	TerraceGeneratorInst->SetMultiplier(InValue);
}

void UFastNoise2TerraceGenerator::SetSmoothness(float InValue)
{
	check(TerraceGeneratorInst.get());
	Smoothness = InValue;
	TerraceGeneratorInst->SetSmoothness(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2TerraceGenerator::InitGenerator()
{
	TerraceGeneratorInst = FastNoise::New<FastNoise::Terrace>();
	SetMultiplier(Multiplier);
	SetSmoothness(Smoothness);
	return TerraceGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2DomainAxisScaleGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(DomainAxisScaleGeneratorInst.get());
		DomainAxisScaleGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2DomainAxisScaleGenerator::SetScale(const FVector4& InValue)
{
	check(DomainAxisScaleGeneratorInst.get());
	Scale = InValue;
	DomainAxisScaleGeneratorInst->SetScale<FastNoise::Dim::X>(InValue.X);
	DomainAxisScaleGeneratorInst->SetScale<FastNoise::Dim::Y>(InValue.Y);
	DomainAxisScaleGeneratorInst->SetScale<FastNoise::Dim::Z>(InValue.Z);
	DomainAxisScaleGeneratorInst->SetScale<FastNoise::Dim::W>(InValue.W);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2DomainAxisScaleGenerator::InitGenerator()
{
	DomainAxisScaleGeneratorInst = FastNoise::New<FastNoise::DomainAxisScale>();
	SetScale(Scale);
	return DomainAxisScaleGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2AddDimensionGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(AddDimensionGeneratorInst.get());
		AddDimensionGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2AddDimensionGenerator::SetNewDimensionPositionSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(AddDimensionGeneratorInst.get());
		AddDimensionGeneratorInst->SetNewDimensionPosition(InSource->GetGenerator());
	}
}

void UFastNoise2AddDimensionGenerator::SetNewDimensionPositionValue(float InValue)
{
	check(AddDimensionGeneratorInst.get());
	NewDimensionPosition = InValue;
	AddDimensionGeneratorInst->SetNewDimensionPosition(InValue);
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2AddDimensionGenerator::InitGenerator()
{
	AddDimensionGeneratorInst = FastNoise::New<FastNoise::AddDimension>();
	SetNewDimensionPositionValue(NewDimensionPosition);
	return AddDimensionGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2RemoveDimensionGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(RemoveDimensionGeneratorInst.get());
		RemoveDimensionGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

void UFastNoise2RemoveDimensionGenerator::SetDimensionToRemove(EFastNoise2Dimension InValue)
{
	check(RemoveDimensionGeneratorInst.get());
	DimensionToRemove = InValue;
	RemoveDimensionGeneratorInst->SetRemoveDimension(FFastNoise2Helpers::ConvertUnrealToFastNoiseDimension(DimensionToRemove));
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2RemoveDimensionGenerator::InitGenerator()
{
	RemoveDimensionGeneratorInst = FastNoise::New<FastNoise::RemoveDimension>();
	SetDimensionToRemove(DimensionToRemove);
	return RemoveDimensionGeneratorInst;
}

//////////////////////////////////////////////////////////////////////////

void UFastNoise2GeneratorCacheGenerator::SetSource(UFastNoise2GeneratorBase* InSource)
{
	if (InSource != nullptr)
	{
		check(GeneratorCacheGeneratorInst.get());
		GeneratorCacheGeneratorInst->SetSource(InSource->GetGenerator());
	}
}

FastNoise::SmartNode<FastNoise::Generator> UFastNoise2GeneratorCacheGenerator::InitGenerator()
{
	GeneratorCacheGeneratorInst = FastNoise::New<FastNoise::GeneratorCache>();
	return GeneratorCacheGeneratorInst;
}
