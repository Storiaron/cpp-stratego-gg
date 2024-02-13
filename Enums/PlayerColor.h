//
// Created by AsusTuf on 2024. 02. 12..
//
#pragma once


enum PlayerColor {
    BLUE,
    RED
};

static const char * PlayerColorStrings[] = { "Blue", "Red" };

const char * GetPlayerColorText( int enumVal )
{
    return PlayerColorStrings[enumVal];
}