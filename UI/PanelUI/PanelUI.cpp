
#include "PanelUI.h"

void PanelUI::loadStats(SDL_Renderer *renderer, const std::shared_ptr<InfoPanel>& infoPanel) {
    int nameSize = 40;
    int size = 25;
    SDL_Color color = {0,0,0,255};
    if (infoPanel->getCurrentFigureInfo() != nullptr) {
        std::string figureName = infoPanel->getCurrentFigureInfo()->name;
        std::shared_ptr<GameText> name = std::make_shared<GameText>(renderer, fontPath, nameSize, figureName, color, 10,
                                                                    10);
        std::string figureHp = infoPanel->getCurrentFigureInfo()->currentHp;
        std::shared_ptr<GameText> hp = std::make_shared<GameText>(renderer, fontPath, size, "Current Hp: " + figureHp, color, 10,
                                                                  60);
        std::string figurePlayer = infoPanel->getCurrentFigureInfo()->color;
        std::shared_ptr<GameText> player = std::make_shared<GameText>(renderer, fontPath, size, "Player: " + figurePlayer, color, 10,
                                                                  85);

        stats.push_back(name);
        stats.push_back(hp);
        stats.push_back(player);
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
