//
// Created by AsusTuf on 2024. 02. 13..
//
#pragma once

enum FigureName {
    KING,
    PEASANT,
    MARAUDER,
    WALL,
    ARTIFICER,
    ARCHER,
    SORCERER,
    CAVALIER,
    KNIGHT,
    CLERIC,
    VAMPIRE,
    PALADIN,
    BABY_DRAGON
};

static const char * FigureNameStrings[] = { "King", "Peasant", "Marauder", "Wall", "Artificer", "Archer", "Sorcerer", "Cavalier", "Knight", "Cleric", "Vampire", "Paladin", "Baby Dragon" };

const char * GetFigureNameText( int enumVal )
{
    return FigureNameStrings[enumVal];
}