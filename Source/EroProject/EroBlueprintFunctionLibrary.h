// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EroBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EROPROJECT_API UEroBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Cargar fichero", Keywords = "Abrir Script Juego"), Category = Game)
		static TArray<FString> AbrirFichero(FString ruta);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Guardar preferencias", Keywords = "Guardar Preferencias Juego"), Category = Game)
		static void GuardarPreferencias(TArray<int32> parametros);
	
	
};
