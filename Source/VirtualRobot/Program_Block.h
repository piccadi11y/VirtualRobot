// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class VIRTUALROBOT_API Program_Block
{
protected:

	int m_ID, m_Type, m_mtr1, m_mtr2;

public:

	int AddContents();

	Program_Block(int ID, int Type, int mtr1, int mtr2);
	~Program_Block();
};
