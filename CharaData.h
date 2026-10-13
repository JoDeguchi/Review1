#pragma once
#include "Element.h"

/// <summary>
/// キャラのデータ（名前、状態など）
/// </summary>
struct CharaData
{
	int ID;					// 敵のID
	const char* NAME;		// 敵の名前
	int HP;					// 敵の体力
	int ATK;				// 敵の攻撃力
	int DEF;				// 敵の防御力	
	ElementType ELEMENT;	// 敵の属性
};