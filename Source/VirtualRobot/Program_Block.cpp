// Fill out your copyright notice in the Description page of Project Settings.

#include "Program_Block.h"

Program_Block::Program_Block(int ID, int duration, int mtr1, int mtr2) : m_ID{ ID }, m_duration{ duration }, m_mtr1 { mtr1 }, m_mtr2{ mtr2 } {
}

Program_Block::~Program_Block()
{
}

FString Program_Block::GetStringBlock() {
	
	return FString::FromInt(m_duration) + "," + FString::FromInt(m_mtr1) + "," + FString::FromInt(m_mtr2);
}
