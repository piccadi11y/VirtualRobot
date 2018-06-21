// Fill out your copyright notice in the Description page of Project Settings.

#include "FileInterface.h"

TArray<FString> FileInterface::File_Read(const FString& dir, const FString& fileName) const {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
	FString abs = dir + "/" + fileName;
	TArray<FString> res;

	/* If dir and file exists, read data into array. */
	if (PF.DirectoryExists(*dir) && PF.FileExists(*abs)) {
		FFileHelper::LoadFileToStringArray(res, *abs);
		/* Return the file's contents. */
		return res;
	}
	/* If no dir/file exists, return a single empty FString.  */
	return {FString("")};
}

TArray<FString> FileInterface::File_Read_Robot(const FString &FileName) const {
	FString dir = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_ROBOTS);
	FString fn = FileName + FString(ROBOT_EXTENSION);
	return File_Read(dir, fn);
}

TArray<FString> FileInterface::File_Read_Program(const FString &FileName) const {
	FString dir = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_PROGRAMS);
	FString fn = FileName + FString(PROGRAM_EXTENSION);
	return File_Read(dir, fn);
}

void FileInterface::File_Write_Robot(const FString &FileName, TArray<FString> ContentToWrite) {
	FString dir = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_ROBOTS);
	FString fn = FileName + FString(ROBOT_EXTENSION);
	File_Write(dir, fn, ContentToWrite);
}

void FileInterface::File_Write_Program(const FString &FileName, TArray<FString> ContentToWrite) {
	FString dir = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_PROGRAMS);
	FString fn = FileName + FString(PROGRAM_EXTENSION);
	File_Write(dir, fn, ContentToWrite);
}

void FileInterface::File_Write(FString& dir, FString& fileName, TArray<FString> txt/*, bool Overwrite*/) {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
	FString abs = dir + "/" + fileName;

	bool exists = PF.DirectoryExists(*dir);
	/* If directory exists, write data to file. Either overwriting current or creating new. */
	if (exists/* && Overwrite*/) {
		FFileHelper::SaveStringArrayToFile(txt, *abs);
	}/* else if (!exists) FFileHelper::SaveStringArrayToFile(txt, *abs);*/
}

bool FileInterface::VerifyOrCreateDirectory(const FString& TestDir) const {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();

	/* If the file doesn't exist, try to create it. */
	if (!PF.DirectoryExists(*TestDir)) {
		PF.CreateDirectory(*TestDir);
		/* If creation failed, return false. Indicating failure. */
		if (!PF.DirectoryExists(*TestDir)) return false;
	}
	/* If file exists, return true. */
	return true;
}

TArray<FString> FileInterface::LoadFileList_Robot() {
	FFileManagerGeneric FM;
	TArray<FString> FileNames;
	FString absDir = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_ROBOTS);
	/* Find all robot files in directory. */
	FM.FindFiles(FileNames, *absDir, *FString(ROBOT_EXTENSION));
	/* Returns list of all robot files in directory. */
	return FileNames;
}

TArray<FString> FileInterface::LoadFileList_Program() {
	FFileManagerGeneric FM;
	TArray<FString> FileNames;
	FString absDir = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_PROGRAMS);
	/* Find all program files in directory. */
	FM.FindFiles(FileNames, *absDir, *FString(PROGRAM_EXTENSION));
	/* Returns list of all program files in directory. */
	return FileNames;
}

bool FileInterface::VerifyOrCreateDefaultDirectories() const {
	FString absRbt = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_ROBOTS);
	FString abePrgm = FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_PROGRAMS);

	if (!VerifyOrCreateDirectory(FString(BASE_PATH))) return false;
	else {
		/* Verify/Create robot default directory. */
		if (!VerifyOrCreateDirectory(FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_ROBOTS))) return false;
		/* Verify/Create program default directory. */
		if (!VerifyOrCreateDirectory(FString(BASE_PATH) + "/" + FString(RELATIVE_PATH_PROGRAMS))) return false;
	} 
	
	return true;
}

bool FileInterface::CheckFileExists(const FString& Path) const {
	FFileManagerGeneric FM;

	/* Check for and return the existence of the file. */
	return FM.FileExists(*Path);
}