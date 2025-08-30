// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"



// Sets default values
AItem::AItem() 
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	nombre = TEXT("Nombre del actor, por ejemplo... carlos");
	distancia = 1800;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(SphereCollision);
	

} 

void AItem::mostrarMensaje()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1,// la key
			5.f, //el tiempo
			FColor::Red,//el color
			FString::FromInt(salud));//el mensaje
	}
}

int AItem::getSalud()
{
	return salud;
}



void AItem::mostrarDistancia_Implementation()
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1,// la key
			5.f, //el tiempo
			FColor::Red,//el color
			FString::FromInt(distancia));//el mensaje
	}
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	mostrarDistancia();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	 
}

