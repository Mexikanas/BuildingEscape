// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(const float DeltaTime);
	void CloseDoor(const float DeltaTime);
	float TotalMassofActors() const;
	void FindAudioComponent();
	void FindPressurePlate() const;

	// tracks if sound has been played
	bool bOpenDoorSound = false;
	bool bCloseDoorSound = true;

private:
	float InitialYaw;
	float CurrentYaw;
	float DoorLastOpened = 0.f;
	
	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY(EditAnywhere)
	float TargetYaw = -90.f;
	UPROPERTY(EditAnywhere)
	float DoorSpeed = 5.f;
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;
	UPROPERTY(EditAnywhere)
	float MassToOpenDoor = 70.f;
};
