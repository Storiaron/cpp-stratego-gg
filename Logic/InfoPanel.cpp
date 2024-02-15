//
// Created by AsusTuf on 2024. 02. 13..
//

#include "InfoPanel.h"

InfoPanel::InfoPanel(std::shared_ptr<GameLogic> gameLogic) {
    this->game = gameLogic;
}

void InfoPanel::setCurrentFigureInfo(const std::shared_ptr<Figure>& figure) {
    if (figure != nullptr) {
        this->currentFigureInfo = figure->getStats();
    }
}

std::shared_ptr<FigureStats> InfoPanel::getCurrentFigureInfo() {
    return std::make_shared<FigureStats>(currentFigureInfo);
}
