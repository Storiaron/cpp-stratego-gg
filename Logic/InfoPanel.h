//
// Created by AsusTuf on 2024. 02. 13..
//

#pragma once


#include "GameLogic.h"

class InfoPanel {
public:
    explicit InfoPanel(std::shared_ptr<GameLogic> gameLogic);
    void setCurrentFigureInfo(const std::shared_ptr<Figure>& figure);
    std::shared_ptr<FigureStats> getCurrentFigureInfo();

protected:
    std::shared_ptr<GameLogic> game;
    FigureStats currentFigureInfo;
};
