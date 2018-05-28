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
		void File_Write(FString& dir, FString& fileName, FString& txt);
		void File_Write_arr(FString& dir, FString& fileName, TArray<FString> txt);
	/** Read array from file. */
		void File_Read();

		bool VerifyOrCreateDirectory(const FString& TestDir) const;

protected:
	IPlatformFile* PlatformFile;
};
