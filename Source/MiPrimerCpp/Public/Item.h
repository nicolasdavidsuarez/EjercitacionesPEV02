// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class UStaticMeshComponent;


UCLASS()
class MIPRIMERCPP_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props")
	int salud;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props")
	int escudo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Props")
	int distancia;
	UPROPERTY(EditAnywhere)
	FString nombre;

	UFUNCTION(BlueprintCallable)
	void mostrarMensaje();

	UFUNCTION(BlueprintPure)
	int getSalud();

	UFUNCTION(BlueprintImplementableEvent)
	void mostrarEscudo();

	UFUNCTION(BlueprintNativeEvent)
	void mostrarDistancia();
	void mostrarDistancia_Implementation();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<USphereComponent> SphereCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> SphereMesh;

	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

};
