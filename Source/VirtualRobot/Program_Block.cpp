// Fill out your copyright notice in the Description page of Project Settings.

#include "Program_Block.h"

Program_Block::Program_Block(int ID, int mtr1, int mtr2, int duration, int row, int column, FString blockType) : m_ID{ ID }, m_mtr1{ mtr1 }, m_mtr2{ mtr2 }, m_duration{ duration }, m_row{ row }, m_column{ column }, m_blockType{blockType} {
}

Program_Block::~Program_Block()
{
}

FString Program_Block::GetStringBlock() {

	return FString::FromInt(m_mtr1) + "," + FString::FromInt(m_mtr2) + "," + FString::FromInt(m_duration);
}

TArray<int> Program_Block::GetInfoForBoxes() {
	return { m_mtr1, m_mtr2, m_duration };
}

void Program_Block::UpdateBlock(int mtr1, int mtr2, int duration)  {
	m_mtr1 = mtr1;
	m_mtr2 = mtr2;
	m_duration = duration;
}

FString Program_Block::GetBlockType() {
	return { m_blockType };
}

int Program_Block::GetColumn() {
	return m_column;
}

int Program_Block::GetRow() {
	return m_row;
}