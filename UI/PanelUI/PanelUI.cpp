
#include "PanelUI.h"

void PanelUI::loadStats(SDL_Renderer *renderer, const std::shared_ptr<InfoPanel>& infoPanel) {
    int size = 40;
    SDL_Color color = {0,0,0,255};
    if (infoPanel->getCurrentFigureInfo() != nullptr) {
        std::string figureName = infoPanel->getCurrentFigureInfo()->name;
        std::shared_ptr<GameText> name = std::make_shared<GameText>(renderer, fontPath, size, figureName, color, 10,
                                                                    10);
        stats.push_back(name);
    } else {
        stats.clear();
    }
}

void PanelUI::print(SDL_Renderer *renderer) {

    if(!stats.empty()) {
        for(const std::shared_ptr<GameText>& stat : stats){
            stat->display(renderer);
        }
    }

}
