// Fill out your copyright notice in the Description page of Project Settings.

#include "EroBlueprintFunctionLibrary.h"
#include "FileManager.h"
#include "PlatformFilemanager.h"
#include "Paths.h"
#include "FileHelper.h"
#include "EroProject.h"


TArray<FString> UEroBlueprintFunctionLibrary::CargarFichero(FString f)
{
	TArray<FString> texto[1000];
	FString ContentPath = FPaths::GameContentDir();
	FString path = ContentPath + FString("Files/") + f;
	const TCHAR* ruta = *path;
	IFileManager* FileManager = &IFileManager::Get();
	// Read and parse the file, adding the pawns and their sounds to the list
	FArchive* TextFile = FileManager->CreateFileReader(ruta, 0);
	if (TextFile != NULL)
	{
		// get the size of the file
		int32 Size = TextFile->TotalSize();
		// read the file
		TArray<uint8> Buffer;
		Buffer.Empty(Size);
		Buffer.AddUninitialized(Size);
		TextFile->Serialize(Buffer.GetData(), Size);
		// zero terminate it
		Buffer.Add(0);
		// Release the file
		delete TextFile;

		// Now read it
		// init traveling pointer
		UTF8CHAR* Ptr = (UTF8CHAR*)Buffer.GetData();

		// iterate over the lines until complete
		bool bIsDone = false;
		while (!bIsDone)
		{
			// Store the location of the first character of this line
			UTF8CHAR* Start = Ptr;

			// Advance the char pointer until we hit a newline character
			while (*Ptr && *Ptr != '\r' && *Ptr != '\n')
			{
				Ptr++;
			}

			// If this is the end of the file, we're done
			if (*Ptr == 0)
			{
				bIsDone = 1;
			}
			// Handle different line endings. If \r\n then NULL and advance 2, otherwise NULL and advance 1
			// This handles \r, \n, or \r\n
			else if (*Ptr == '\r' && *(Ptr + 1) == '\n')
			{
				// This was \r\n. Terminate the current line, and advance the pointer forward 2 characters in the stream
				*Ptr++ = 0;
				*Ptr++ = 0;
			}
			else
			{
				// Terminate the current line, and advance the pointer to the next character in the stream
				*Ptr++ = 0;
			}

			FString CurrLine = UTF8_TO_TCHAR(Start);
			texto->Add(CurrLine);
		}
	}
	return *texto;
}

void UEroBlueprintFunctionLibrary::GuardarPreferencias(TArray<FString> parametros)
{
	FString ContentPath = FPaths::GameContentDir();
	FString SaveDirectory = ContentPath + FString("Files");
	FString FileName = FString("preferences");
	bool AllowOverwriting = true;

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// CreateDirectoryTree returns true if the destination
	// directory existed prior to call or has been created
	// during the call.
	if (PlatformFile.CreateDirectoryTree(*SaveDirectory))
	{
		// Get absolute file path
		FString AbsoluteFilePath = SaveDirectory + "/" + FileName;

		// Allow overwriting or file doesn't already exist
		if (AllowOverwriting || !PlatformFile.FileExists(*AbsoluteFilePath))
		{
			FString s = "";
			for (int i = 0; i < parametros.Num(); i++) {
				s += parametros[i];
				if (parametros.Num() - i > 1)
					s += "\n";
			}
			FFileHelper::SaveStringToFile(s, *AbsoluteFilePath);
			//FFileHelper::SaveArrayToFile(parametros, *AbsoluteFilePath);
		}
	}
}
