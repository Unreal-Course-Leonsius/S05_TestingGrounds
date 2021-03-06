// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "BallProjectile.h"
#include "Animation/AnimInstance.h"
#include "Gun.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	FP_Gun->SetOnlyOwnerSee(false);			// only the owning player will see this mesh
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	//FP_Gun->SetupAttachment(RootComponent);


	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 0.0f, 10.0f);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

	if (ensure(ProjectileBlueprint == NULL)) { UE_LOG(LogTemp, Warning, TEXT("ProjectileBlueprint is NULL")); return; }


	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::OnFire()
{
	// try and fire a projectile
	if (ProjectileBlueprint != NULL)
	{
		const FRotator SpawnRotation = FP_MuzzleLocation->GetComponentRotation();

		/// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		//const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
		const FVector SpawnLocation = FP_MuzzleLocation->GetComponentLocation();   // + SpawnRotation.RotateVector(GunOffset); // this order little change spawn location

		UWorld * const World = GetWorld();
		if (World != NULL)
		{
			// spawn the projectile at the muzzle
			World->SpawnActor<ABallProjectile>(ProjectileBlueprint, SpawnLocation, SpawnRotation);		
		}	
	}
	
	// try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}
	
	// try and play a firing animation if specified
	// Get the animation object for the arms mesh
	if (FireAnimation != NULL && AnimInstance != NULL)
	{

		AnimInstance->Montage_Play(FireAnimation, 1.f);
		
	}
	
}

