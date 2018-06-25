// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class VIRTUALROBOT_API Program_Block
{
protected:

	int m_ID, m_mtr1, m_mtr2, m_duration;

public:


	Program_Block(int ID,int duration, int mtr1, int mtr2);

	FString GetStringBlock();

	~Program_Block();

};
