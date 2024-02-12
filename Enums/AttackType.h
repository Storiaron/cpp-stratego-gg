//
// Created by AsusTuf on 2024. 02. 12..
//
#pragma once

enum AttackType {
    MELEE,
    RANGE,
    HEAL,
    LIFESTEAL,
    NONE
};

static const char * AttackTypeStrings[] = { "Melee", "Range", "Heal", "Lifesteal", "None" };

const char * GetAttackTypeText( int enumVal )
{
    return AttackTypeStrings[enumVal];
}