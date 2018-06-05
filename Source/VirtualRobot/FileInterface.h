// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FileHelper.h"
#include "PlatformFile.h"
#include "FileManagerGeneric.h"

#define BASE_PATH "C:/VirtualRobot"
#define RELATIVE_PATH_ROBOTS "Robots"
#define RELATIVE_PATH_PROGRAMS "Programs"
#define ROBOT_EXTENSION ".rbt"
#define PROGRAM_EXTENSION ".prgm"

/**
 * 
 */
class VIRTUALROBOT_API FileInterface
{
public:

		/** Write array to file. */
		void File_Write(FString& dir, FString& fileName, TArray<FString> txt/*, bool Overwrite*/);
		/** Read array from file. */
		TArray<FString> File_Read(FString& dir, FString& fileName);
		/** Checks for existing dir, if doesn't exist, create it. */
		bool VerifyOrCreateDirectory(const FString& TestDir) const;
		/** Checks for existing default dir, if doesn't exist, create it. */
		bool VerifyOrCreateDefaultDirectories() const;
		/** Checks to see if a file exists. */
		bool CheckFileExists(const FString& Path) const;


		/** Loads robot files, returns the file names in an array of FStrings. */
		TArray<FString> LoadFileList_Robot();
		/** Loads list of program files, returns the file names in an array of FStrings. */
		TArray<FString> LoadFileList_Program();
protected:
	
};
