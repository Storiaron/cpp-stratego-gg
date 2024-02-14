//
// Created by AsusTuf on 2024. 02. 12..
//
#pragma once


enum PlayerColor {
    BLUE,
    RED,
    NO_COLOR
};

static const char * PlayerColorStrings[] = { "Blue", "Red", "No Color" };

static const char * GetPlayerColorText( int enumVal )
{
    return PlayerColorStrings[enumVal];
}