// Fill out your copyright notice in the Description page of Project Settings.

#include "FileInterface.h"

FileInterface::FileInterface() {
	PlatformFile = &FPlatformFileManager::Get().GetPlatformFile();
}

FileInterface::~FileInterface() {
}

void FileInterface::File_Read() {

}

void FileInterface::File_Write(FString& dir, FString& fileName, FString& txt) {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
	FString abs = dir + "/" + fileName;
	bool x{ false };
	if (PF.DirectoryExists(*dir)) {
		FFileHelper::SaveStringToFile(txt, *abs);
		/*if (x || !PF.FileExists(*abs)) {
		FFileHelper::SaveStringToFile(txt, *abs);
		}*/
	}

}

void FileInterface::File_Write_arr(FString& dir, FString& fileName, TArray<FString> txt) {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
	FString abs = dir + "/" + fileName;
	bool x{ false };
	if (PF.DirectoryExists(*dir)) {
		FFileHelper::SaveStringArrayToFile(txt, *abs);
		/*if (x || !PF.FileExists(*abs)) {
		FFileHelper::SaveStringArrayToFile(txt, *abs);
		}*/
	}

}

bool FileInterface::VerifyOrCreateDirectory(const FString& TestDir) const {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();

	if (!PF.DirectoryExists(*TestDir)) {
		PF.CreateDirectory(*TestDir);
		if (!PF.DirectoryExists(*TestDir)) return false;
	}
	return true;
}