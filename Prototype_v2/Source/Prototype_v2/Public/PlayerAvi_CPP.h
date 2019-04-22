// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AvatarAimingComponent.h"
#include "GameFramework/Character.h"
#include "PlayerAvi_CPP.generated.h"

UCLASS()
class PROTOTYPE_V2_API APlayerAvi_CPP : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UAvatarAimingComponent* AvatarAimingComponent = nullptr;

public:	
	// Sets default values for this character's properties
	APlayerAvi_CPP();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetSwordReference(USkeletalMeshComponent* SwordToSet);

	UPROPERTY(EditAnywhere, Category = Attributes)
	float DamagePerHit = 10;
	
};
