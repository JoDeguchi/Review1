#pragma once
#include "CharaData.h"

//  ダメージ与える用
class Attack
{
private:
  
public:
   
    int damage = 0;
    void Execute(CharaData& attack, CharaData& defens)
    {
        //	ATKーDEFがダメージ量
        damage = std::max(1, attack.ATK - defens.DEF);
        //  対象のHPを求めたダメージ量で引く
        defens.HP -= damage;

        if (defens.HP < 0)
        {
            defens.HP = 0;
        }
    }

    void Reset()
    {
        damage = 0;
    }


};