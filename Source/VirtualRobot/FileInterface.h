// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "FileHelper.h"
#include "PlatformFile.h"
#include "FileManagerGeneric.h"
#include "MacroDefinitions.h"



/**
 * 
 */
class VIRTUALROBOT_API FileInterface
{
public:

		/** Write array to file. */
		void File_Write(FString& dir, FString& fileName, TArray<FString> txt/*, bool Overwrite*/);
		/** Checks for existing dir, if doesn't exist, create it. */
		bool VerifyOrCreateDirectory(const FString& TestDir) const;
		/** Checks for existing default dir, if doesn't exist, create it. */
		bool VerifyOrCreateDefaultDirectories() const;
		/** Checks to see if a file exists. */
		bool CheckFileExists(const FString& Path) const;

		/** Read array from .rbt file. */
		TArray<FString> File_Read_Robot(const FString &FileName) const;
		/** Read array from .prgm file. */
		TArray<FString> File_Read_Program(const FString &FileName) const;
		/** Write array to .rbt file. */
		void File_Write_Robot(const FString &FileName, TArray<FString> ContentToWrite);
		/** Write array to .prgm file. */
		void File_Write_Program(const FString &FileName, TArray<FString> ContentToWrite);


		/** Loads robot files, returns the file names in an array of FStrings. */
		TArray<FString> LoadFileList_Robot();
		/** Loads list of program files, returns the file names in an array of FStrings. */
		TArray<FString> LoadFileList_Program();
protected:
	
		/** Read array from file. */
		TArray<FString> File_Read(const FString& dir, const FString& fileName) const;
};
