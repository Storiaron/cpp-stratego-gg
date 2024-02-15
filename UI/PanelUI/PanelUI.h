#pragma once

#include <string>
#include <vector>
#include "../GameText.h"
#include "../../Figures/Figure.h"
#include "../../Logic/InfoPanel.h"

class PanelUI {
public:
    PanelUI(SDL_Renderer* renderer, const std::shared_ptr<InfoPanel>& infoPanel){
        loadStats(renderer, infoPanel);
    }

    void print(SDL_Renderer* renderer);

    bool isAppear{false};

private:
    const std::string fontPath{"../UI/font/BodoniFLF-Bold.ttf"};
    std::vector<std::shared_ptr<GameText>> stats;

    void loadStats(SDL_Renderer* renderer, const std::shared_ptr<InfoPanel>& infoPanel);
};
