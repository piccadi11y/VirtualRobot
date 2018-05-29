// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FileHelper.h"
#include "PlatformFile.h"
#include "PlatformFilemanager.h"

/**
 * 
 */
class VIRTUALROBOT_API FileInterface
{
public:
	FileInterface();
	~FileInterface();

	/** Write array to file. */
		void File_Write(FString& dir, FString& fileName, TArray<FString> txt);
	/** Read array from file. */
		TArray<FString> File_Read(FString& dir, FString& fileName);

		bool VerifyOrCreateDirectory(const FString& TestDir) const;

protected:
	
};
