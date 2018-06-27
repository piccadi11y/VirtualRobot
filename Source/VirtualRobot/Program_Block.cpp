// Fill out your copyright notice in the Description page of Project Settings.

#include "Program_Block.h"

Program_Block::Program_Block(int ID, int duration, int mtr1, int mtr2, int row, int column) : m_ID{ ID }, m_duration{ duration }, m_mtr1{ mtr1 }, m_mtr2{ mtr2 }, m_row{ row }, m_column{ column } {
}

Program_Block::~Program_Block()
{
}

FString Program_Block::GetStringBlock() {
	
	return FString::FromInt(m_duration) + "," + FString::FromInt(m_mtr1) + "," + FString::FromInt(m_mtr2);
}

TArray<int> Program_Block::GetInfoForBoxes() {
	return { m_mtr1, m_mtr2, m_duration };
}