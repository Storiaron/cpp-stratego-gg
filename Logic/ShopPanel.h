//
// Created by AsusTuf on 2024. 02. 13..
//

#pragma once


#include "InfoPanel.h"

class ShopPanel : public InfoPanel {
public:
    explicit ShopPanel(std::shared_ptr<GameLogic> gameLogic) : InfoPanel(gameLogic){
        initializeBuyableFigures();
    };
    void buyFigure();

private:
    void initializeBuyableFigures();
    std::shared_ptr<Figure> selectedFigure;
    std::shared_ptr<Figure> buyableFigures{new Figure[13]};

    void addFigureToPlayer(std::shared_ptr<Player> &currentPlayer, const PlayerColor &currentPlayerColor) const;
};
