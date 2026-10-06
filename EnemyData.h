#pragma once
#include "Element.h"

/// <summary>
/// “G‚Ìƒf[ƒ^i–¼‘OAó‘Ô‚È‚Çj
/// </summary>
struct EnemyData
{
	int ID;					// “G‚ÌID
	const char* NAME;		// “G‚Ì–¼‘O
	int HP;					// “G‚Ì‘Ì—Í
	int ATK;				// “G‚ÌUŒ‚—Í
	int DEF;				// “G‚Ì–hŒä—Í	
	ElementType ELEMENT;	// “G‚Ì‘®«
};