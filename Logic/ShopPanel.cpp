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
    if (selectedFigure != nullptr
    && currentPlayer->canGoldBeSpent(selectedFigure->getPrice())
    && game->getSelectedCell()->getFigureOnCell() == nullptr) {
        currentPlayer->spendGold(selectedFigure->getPrice());

        createFigureForPlayer(currentPlayer, currentPlayerColor);
    } else {
        std::cerr << "Player doesn't have enough gold or cell is taken!";
    }
}

void ShopPanel::createFigureForPlayer(std::shared_ptr<Player> &currentPlayer, const PlayerColor &currentPlayerColor) {
    switch (selectedFigure->getName()) {
        case KING: {
            King figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case PEASANT: {
            Peasant figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case MARAUDER: {
            Marauder figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case WALL: {
            Wall figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case ARTIFICER: {
            Artificer figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case ARCHER: {
            Archer figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case SORCERER: {
            Sorcerer figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case CAVALIER: {
            Cavalier figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case KNIGHT: {
            Knight figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case CLERIC: {
            Cleric figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case VAMPIRE: {
            Vampire figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case PALADIN: {
            Paladin figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        case BABY_DRAGON: {
            BabyDragon figure(currentPlayerColor);
            AddFigureToPlayerInventoryAndPlaceOnCell(currentPlayer, figure);
            break;
        }
        default: {
            std::cerr << "An error has occurred.";
            break;
        }
    }
}

void ShopPanel::AddFigureToPlayerInventoryAndPlaceOnCell(std::shared_ptr<Player> &currentPlayer, const Figure &figure) {
    currentPlayer->addFigure(figure);
    game->getSelectedCell()->addFigureToCell(std::make_shared<Figure>(figure));
}

std::shared_ptr<Figure> ShopPanel::getSelectedFigure() {
    return selectedFigure;
}

void ShopPanel::setSelectedFigure(std::shared_ptr<Figure> figure) {
    selectedFigure = std::move(figure);
}

