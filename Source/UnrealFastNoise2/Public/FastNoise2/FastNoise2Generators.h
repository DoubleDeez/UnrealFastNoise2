#pragma once

#include "CoreMinimal.h"
#include "FastNoise/Generators/BasicGenerators.h"
#include "FastNoise/Generators/Value.h"
#include "FastNoise/Generators/Perlin.h"
#include "FastNoise/Generators/Simplex.h"
#include "FastNoise/Generators/Cellular.h"
#include "FastNoise/Generators/Fractal.h"
#include "FastNoise/Generators/DomainWarp.h"
#include "FastNoise/Generators/DomainWarpFractal.h"
#include "FastNoise/Generators/Modifiers.h"
#include "FastNoise/Generators/Blends.h"
#include "FastNoise/SmartNode.h"
#include "FastNoise2Types.h"
#include "FastNoise2Generators.generated.h"

UCLASS(Abstract, BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2GeneratorBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Start,Size"))
	FFloatRange GenUniformGrid2D(TArray<float>& OutValues, const FIntPoint& Start, const FIntPoint& Size, float Frequency = 0.01f, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Start,Size"))
	FFloatRange GenUniformGrid3D(TArray<float>& OutValues, const FIntVector& Start, const FIntVector& Size, float Frequency = 0.01f, int32 Seed = 1337) const;

	// FIntVector4 doesn't support BP, so use FVector4
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Start,Size"))
	FFloatRange GenUniformGrid4D(TArray<float>& OutValues, const FVector4& Start, const FVector4& Size, float Frequency = 0.01f, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Size"))
	FFloatRange GenTileable2D(TArray<float>& OutValues, const FIntPoint& Size, float Frequency = 0.01f, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Offset"))
	FFloatRange GenPositionArray2D(TArray<float>& OutValues, const TArray<FVector2D>& PosArray, const FVector2D& Offset, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Offset"))
	FFloatRange GenPositionArray3D(TArray<float>& OutValues, const TArray<FVector>& PosArray, const FVector& Offset, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Offset"))
	FFloatRange GenPositionArray4D(TArray<float>& OutValues, const TArray<FVector4>& PosArray, const FVector4& Offset, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Location"))
	float GenSingle2D(const FVector2D& Location, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Location"))
	float GenSingle3D(const FVector& Location, int32 Seed = 1337) const;

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "Location"))
	float GenSingle4D(const FVector4& Location, int32 Seed = 1337) const;

	const FastNoise::SmartNode<FastNoise::Generator>& GetGenerator() const { return GeneratorInst; }

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() { return nullptr; }

	void ResetGenerator();

private:
	void InitGenerator_Internal();

	FastNoise::SmartNode<FastNoise::Generator> GeneratorInst = nullptr;

	friend class UFastNoise2GeneratorWithSourceBase;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2EncodedNodeTreeGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InValue"))
	void SetEncodedNodeTree(const FString& InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetEncodedNodeTree)
	FString EncodedNodeTree;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2ConstantGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetValue(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetValue)
	float Value = 1.0f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Constant> ConstantGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2WhiteGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::White> WhiteGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2CheckerboardGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSize(float InSize);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetSize)
	float Size = 1.0f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Checkerboard> CheckerboardGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2SineWaveGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetScale(float InScale);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetScale)
	float Scale = 1.0f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::SineWave> SineWaveGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2PositionOutputGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InMultipliers,InOffsets"))
	void SetData(const FVector4& InMultipliers, const FVector4& InOffsets);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InMultipliers"))
	void SetMultipliers(const FVector4& InMultipliers);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InOffsets"))
	void SetOffsets(const FVector4& InOffsets);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetMultipliers)
	FVector4 Multipliers;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetOffsets)
	FVector4 Offsets;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::PositionOutput> PositionOutputGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DistanceToPointGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetDistanceFunction(EFastNoise2DistanceFunction InDistanceFunction);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InScale"))
	void SetScale(const FVector4& InScale);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetScale)
	FVector4 Scale;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetDistanceFunction)
	EFastNoise2DistanceFunction DistanceFunction;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DistanceToPoint> DistanceToPointGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2ValueGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Value> ValueGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2PerlinGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Perlin> PerlinGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2SimplexGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Simplex> SimplexGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2OpenSimplex2Generator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::OpenSimplex2> OpenSimplex2GeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2OpenSimplex2SGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::OpenSimplex2S> OpenSimplex2SGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(Abstract, BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2CellularGeneratorBase : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetJitterModifierSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetJitterModifierValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetDistanceFunction(EFastNoise2DistanceFunction InDistanceFunction);


protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetJitterModifierValue)
	float JitterModifierValue = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetDistanceFunction)
	EFastNoise2DistanceFunction DistanceFunction;

	FastNoise::SmartNode<FastNoise::Cellular> CellularGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2CellularValueGenerator : public UFastNoise2CellularGeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetValueIndex(int32 InValueIndex);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetValueIndex, meta = (ClampMin = 0, ClampMax = 3))
	int32 ValueIndex = 0;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::CellularValue> CellularValueGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2CellularDistanceGenerator : public UFastNoise2CellularGeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetDistanceIndex0(int32 InDistanceIndex0);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetDistanceIndex1(int32 InDistanceIndex1);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetReturnType(EFastNoise2CellularDistanceReturnType InReturnType);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetDistanceIndex0, meta = (ClampMin = 0, ClampMax = 3))
	int32 DistanceIndex0 = 0;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetDistanceIndex1, meta = (ClampMin = 0, ClampMax = 3))
	int32 DistanceIndex1 = 1;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetReturnType)
	EFastNoise2CellularDistanceReturnType ReturnType;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::CellularDistance> CellularDistanceGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2CellularLookupGenerator : public UFastNoise2CellularGeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetLookupSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetLookupFrequency(float InLookupFrequency);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetLookupFrequency)
	float LookupFrequency = 0.1f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::CellularLookup> CellularLookupGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(Abstract, BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2FractalGeneratorBase : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetGainSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetWeightedStrengthSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetGainValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetWeightedStrengthValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetLacunarityValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetOctaveCount(int32 InOctaveCount);


protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetGainValue)
	float Gain = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetWeightedStrengthValue)
	float WeightedStrength = 0.f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetLacunarityValue)
	float Lacunarity = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetOctaveCount)
	int32 Octaves = 3;

	void InitFractalBase(FastNoise::SmartNode<FastNoise::Fractal<>> InFractalGeneratorInst);

	FastNoise::SmartNode<FastNoise::Fractal<>> FractalGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2FractalFBmGenerator : public UFastNoise2FractalGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::FractalFBm> FractalFBmGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2FractalRidgedGenerator : public UFastNoise2FractalGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::FractalRidged> FractalRidgedGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2FractalPingPongGenerator : public UFastNoise2FractalGeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetPingPongStrengthSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetPingPongStrengthValue(float InPingPongStrength);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetPingPongStrengthValue)
	float PingPongStrength = 0.0f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::FractalPingPong> FractalPingPongGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(Abstract, BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainWarpGeneratorBase : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetWarpAmplitudeSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetWarpAmplitudeValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetWarpFrequencyValue(float InValue);

	const FastNoise::SmartNode<FastNoise::DomainWarp>& GetDomainWarpGenerator() const { return DomainWarpGeneratorInst; }

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetWarpAmplitudeValue)
	float WarpAmplitude = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetWarpFrequencyValue)
	float WarpFrequency = 0.5f;

	void InitDomainWarpBase(FastNoise::SmartNode<FastNoise::DomainWarp> InDomainWarpGeneratorInst);

	FastNoise::SmartNode<FastNoise::DomainWarp> DomainWarpGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainWarpGradientGenerator : public UFastNoise2DomainWarpGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DomainWarpGradient> DomainWarpGradientGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(Abstract, BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2FractalDomainWarpGeneratorBase : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetDomainWarpSource(UFastNoise2DomainWarpGeneratorBase* InSource);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetGainSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintCallable, Category = "Fast Noise 2")
	void SetWeightedStrengthSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetGainValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetWeightedStrengthValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetLacunarityValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetOctaveCount(int32 InOctaveCount);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetGainValue)
	float Gain = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetWeightedStrengthValue)
	float WeightedStrength = 0.f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetLacunarityValue)
	float Lacunarity = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetOctaveCount)
	int32 Octaves = 3;

	void InitFractalDomainWarpBase(FastNoise::SmartNode<FastNoise::Fractal<FastNoise::DomainWarp>> InFractalDomainWarpGeneratorInst);

	FastNoise::SmartNode<FastNoise::Fractal<FastNoise::DomainWarp>> FractalDomainWarpGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainWarpFractalProgressiveGenerator : public UFastNoise2FractalDomainWarpGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DomainWarpFractalProgressive> DomainWarpFractalProgressiveGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainWarpFractalIndependantGenerator : public UFastNoise2FractalDomainWarpGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DomainWarpFractalIndependant> DomainWarpFractalIndependantGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(Abstract, BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2OperatorSourceLHSGeneratorBase : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetLHSSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRHSSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRHSValue(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetRHSValue)
	float RHSValue = 0.0f;

	void InitOperatorSourceLHSGenerator(FastNoise::SmartNode<FastNoise::OperatorSourceLHS> InOperatorSourceLHSGeneratorInst);

	FastNoise::SmartNode<FastNoise::OperatorSourceLHS> OperatorSourceLHSGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(Abstract, BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2OperatorHybridLHSGeneratorBase : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetLHSSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetLHSValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRHSSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRHSValue(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetLHSValue)
	float LHSValue = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetRHSValue)
	float RHSValue = 0.0f;

	void InitOperatorHybridLHSGenerator(FastNoise::SmartNode<FastNoise::OperatorHybridLHS> InOperatorHybridLHSGeneratorInst);

	FastNoise::SmartNode<FastNoise::OperatorHybridLHS> OperatorHybridLHSGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2AddGenerator : public UFastNoise2OperatorSourceLHSGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Add> AddGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2SubtractGenerator : public UFastNoise2OperatorHybridLHSGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Subtract> SubtractGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2MultiplyGenerator : public UFastNoise2OperatorSourceLHSGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Multiply> MultiplyGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DivideGenerator : public UFastNoise2OperatorHybridLHSGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Divide> DivideGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2MinGenerator : public UFastNoise2OperatorSourceLHSGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Min> MinGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2MaxGenerator : public UFastNoise2OperatorSourceLHSGeneratorBase
{
	GENERATED_BODY()

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Max> MaxGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2PowFloatGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetValueSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetValue(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetPowSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetPow(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetValue)
	float Value = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetPow)
	float Pow = 2.0f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::PowFloat> PowFloatGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2PowIntGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetValueSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetPow(int32 InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetPow)
	int32 Pow = 2;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::PowInt> PowIntGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2MinSmoothGenerator : public UFastNoise2OperatorSourceLHSGeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSmoothnessSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSmoothnessValue(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetSmoothnessValue)
	float Smoothness = 0.1f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::MinSmooth> MinSmoothGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2MaxSmoothGenerator : public UFastNoise2OperatorSourceLHSGeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSmoothnessSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSmoothnessValue(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetSmoothnessValue)
	float Smoothness = 0.1f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::MaxSmooth> MaxSmoothGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2FadeGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetASource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetBSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetFadeSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetFadeValue(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetFadeValue)
	float Fade = 0.5f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Fade> FadeGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainScaleGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetScale(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetScale)
	float Scale = 1.0f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DomainScale> DomainScaleGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainOffsetGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetOffsetSources(UFastNoise2GeneratorBase* InSourceX, UFastNoise2GeneratorBase* InSourceY, UFastNoise2GeneratorBase* InSourceZ, UFastNoise2GeneratorBase* InSourceW);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InValue"))
	void SetOffsetValues(const FVector4& InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetOffsetValues)
	FVector4 Offsets;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DomainOffset> DomainOffsetGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainRotateGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InValue"))
	void SetRotation(const FRotator& InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetRotation)
	FRotator Rotation;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DomainRotate> DomainRotateGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2SeedOffsetGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetOffset(int32 InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetOffset)
	int32 Offset = 1;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::SeedOffset> SeedOffsetGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2RemapGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRemapFromLowerBound(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRemapFromUpperBound(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRemapToLowerBound(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetRemapToUpperBound(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetRemapFromLowerBound)
	float FromLowerBound = -1.f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetRemapFromUpperBound)
	float FromUpperBound = 1.f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetRemapToLowerBound)
	float ToLowerBound = 0.f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetRemapToUpperBound)
	float ToUpperBound = 1.f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Remap> RemapGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2ConvertRGBA8Generator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetLowerBound(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetUpperBound(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetLowerBound)
	float LowerBound = -1.f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetUpperBound)
	float UpperBound = 1.f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::ConvertRGBA8> ConvertRGBA8GeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2TerraceGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetMultiplier(float InValue);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSmoothness(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetMultiplier)
	float Multiplier = 1.f;

	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetSmoothness)
	float Smoothness = 0.f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::Terrace> TerraceGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2DomainAxisScaleGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2", meta = (AutoCreateRefTerm = "InValue"))
	void SetScale(const FVector4& InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetScale)
	FVector4 Scale = FVector4(1.f, 1.f, 1.f, 1.f);

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::DomainAxisScale> DomainAxisScaleGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2AddDimensionGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetNewDimensionPositionSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetNewDimensionPositionValue(float InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetNewDimensionPositionValue)
	float NewDimensionPosition = 0.0f;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::AddDimension> AddDimensionGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2RemoveDimensionGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetDimensionToRemove(EFastNoise2Dimension InValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Fast Noise 2", BlueprintSetter = SetDimensionToRemove)
	EFastNoise2Dimension DimensionToRemove = EFastNoise2Dimension::Y;

	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::RemoveDimension> RemoveDimensionGeneratorInst = nullptr;
};

//////////////////////////////////////////////////////////////////////////

UCLASS(BlueprintType)
class UNREALFASTNOISE2_API UFastNoise2GeneratorCacheGenerator : public UFastNoise2GeneratorBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintSetter, Category = "Fast Noise 2")
	void SetSource(UFastNoise2GeneratorBase* InSource);

protected:
	virtual FastNoise::SmartNode<FastNoise::Generator> InitGenerator() override;

	FastNoise::SmartNode<FastNoise::GeneratorCache> GeneratorCacheGeneratorInst = nullptr;
};

