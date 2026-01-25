// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeDMIMod.generated.h"

class UNiagaraSystem;

UCLASS(Blueprintable)
class FIRSTPERSON415_API ACubeDMIMod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeDMIMod();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
		UBoxComponent* boxComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta=(AllowPrivateAccess = "true"))
		UStaticMeshComponent* cubeMesh;
	
	UPROPERTY(EditAnywhere)
		UMaterialInterface* baseMat;

	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;

	UPROPERTY(EditAnywhere)
		UNiagaraSystem* colorP;


	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
