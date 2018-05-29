// Fill out your copyright notice in the Description page of Project Settings.

#include "FileInterface.h"

FileInterface::FileInterface() {
}

FileInterface::~FileInterface() {
}

TArray<FString> FileInterface::File_Read(FString& dir, FString& fileName) {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
	FString abs = dir + "/" + fileName;
	TArray<FString> res;

	if (PF.DirectoryExists(*dir) && PF.FileExists(*abs)) {
		FFileHelper::LoadFileToStringArray(res, *abs);
		return res;
	}
	return {FString("null")};
}

void FileInterface::File_Write(FString& dir, FString& fileName, TArray<FString> txt) {
	IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
	FString abs = dir + "/" + fileName;
	bool x{ false };
	if (PF.DirectoryExists(*dir)) {
		FFileHelper::SaveStringArrayToFile(txt, *abs);
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