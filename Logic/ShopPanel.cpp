//
// Created by AsusTuf on 2024. 02. 13..
//

#include <iostream>
#include "ShopPanel.h"
#include "../Figures/Soldiers/Archer.h"
#include "../Figures/Soldiers/Artificer.h"
#include "../Figures/Soldiers/BabyDragon.h"
#include "../Figures/Soldiers/Cavalier.h"
#include "../Figures/Soldiers/Cleric.h"
#include "../Figures/Soldiers/King.h"
#include "../Figures/Soldiers/Knight.h"
#include "../Figures/Soldiers/Marauder.h"
#include "../Figures/Soldiers/Paladin.h"
#include "../Figures/Soldiers/Peasant.h"
#include "../Figures/Soldiers/Sorcerer.h"
#include "../Figures/Soldiers/Vampire.h"
#include "../Figures/Soldiers/Wall.h"

void ShopPanel::initializeBuyableFigures() {
    King king(PlayerColor::NO_COLOR);
    buyableFigures.get()[0] = king;
    Peasant peasant(PlayerColor::NO_COLOR);
    buyableFigures.get()[1] = peasant;
    Marauder marauder(PlayerColor::NO_COLOR);
    buyableFigures.get()[2] = marauder;
    Wall wall(PlayerColor::NO_COLOR);
    buyableFigures.get()[3] = wall;
    Artificer artificer(PlayerColor::NO_COLOR);
    buyableFigures.get()[4] = artificer;
    Archer archer(PlayerColor::NO_COLOR);
    buyableFigures.get()[5] = archer;
    Sorcerer sorcerer(PlayerColor::NO_COLOR);
    buyableFigures.get()[6] = sorcerer;
    Cavalier cavalier(PlayerColor::NO_COLOR);
    buyableFigures.get()[7] = cavalier;
    Knight knight(PlayerColor::NO_COLOR);
    buyableFigures.get()[8] = knight;
    Cleric cleric(PlayerColor::NO_COLOR);
    buyableFigures.get()[9] = cleric;
    Vampire vampire(PlayerColor::NO_COLOR);
    buyableFigures.get()[10] = vampire;
    Paladin paladin(PlayerColor::NO_COLOR);
    buyableFigures.get()[11] = paladin;
    BabyDragon babyDragon(PlayerColor::NO_COLOR);
    buyableFigures.get()[12] = babyDragon;
}

void ShopPanel::buyFigure() {
    std::shared_ptr<Player> currentPlayer = this->game->getCurrentPlayer();
    PlayerColor currentPlayerColor = currentPlayer->getColor();
    if (currentPlayer->canGoldBeSpent(selectedFigure->getPrice())
        && game->getSelectedCell()->getFigureOnCell() == nullptr) {
        currentPlayer->spendGold(selectedFigure->getPrice());

        switch (selectedFigure->getName()) {
            case FigureName::KING: {
                King figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::PEASANT: {
                Peasant figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::MARAUDER: {
                Marauder figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::WALL: {
                Wall figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::ARTIFICER: {
                Artificer figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::ARCHER: {
                Archer figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::SORCERER: {
                Sorcerer figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::CAVALIER: {
                Cavalier figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::KNIGHT: {
                Knight figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::CLERIC: {
                Cleric figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::VAMPIRE: {
                Vampire figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::PALADIN: {
                Paladin figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            case FigureName::BABY_DRAGON: {
                BabyDragon figure(currentPlayerColor);
                currentPlayer->addFigure(figure);
                break;
            }
            default: {
                std::cerr << "An error has occurred.";
                break;
            }
        }
    } else {
        std::cerr << "Player doesn't have enough gold or cell is taken!";
    }
}