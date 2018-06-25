// Fill out your copyright notice in the Description page of Project Settings.

#include "Program_Block.h"

Program_Block::Program_Block(int ID, int Type, int mtr1, int mtr2) : m_ID{ ID }, m_Type{ Type }, m_mtr1{ mtr1 }, m_mtr2{ mtr2 } {
}

Program_Block::~Program_Block()
{
}

int Program_Block::AddContents() {
	return m_Type + m_ID;
}

FString Program_Block::GetStringBlock() {
	return FString::FromInt(m_mtr1);
}
