// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class VIRTUALROBOT_API Program_Block
{
protected:

	int m_ID, m_mtr1, m_mtr2, m_duration, m_row, m_column;
	FString m_blockType;

public:


	Program_Block(int ID, int mtr1, int mtr2, int duration, int row, int column, FString blockType);
	//turn the members to one long string that can be written to the file
	FString GetStringBlock();
	//get column and row for block position on screen
	int GetColumn();
	int GetRow();
	//get the members that appear in the textboxes
	TArray<int> GetInfoForBoxes();
	//get the type of the block
	FString GetBlockType();
	//update the block with new values
	void UpdateBlock(int mtr1, int mtr2, int duration);
	~Program_Block();

};
