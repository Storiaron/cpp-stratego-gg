cmake_minimum_required(VERSION 3.26)
project(cpp_stratego_gg)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

add_executable(cpp_stratego_gg main.cpp
        IO_Handler.h
        IO_Handler.cpp
        Enums/PlayerColor.h
        Figures/Figure.h
        Figures/Figure.cpp
        Figures/Soldiers/Peasant.h
        Figures/Soldiers/Peasant.cpp
        Figures/Soldiers/King.h
        Figures/Soldiers/BabyDragon.h
        Player/Player.h
        Player/Player.cpp
        Logic/Cell.h
        Logic/GameLogic.h
        Logic/GameLogic.cpp
        Logic/Cell.cpp
        Logic/InfoPanel.h
        Logic/InfoPanel.cpp
        Logic/ShopPanel.h
        Logic/ShopPanel.cpp
        UI/TextureCreator.cpp
        UI/TextureCreator.h
        UI/BoardUI.cpp
        UI/BoardUI.h
        UI/CellUI.cpp
        UI/CellUI.h
        UI/SelectedCellUI.cpp
        UI/SelectedCellUI.h
        Figures/Soldiers/Paladin.cpp
        Figures/Soldiers/Vampire.cpp
        Figures/Soldiers/Knight.cpp
        Logic/WinningPlayer.h
        Logic/WinningPlayer.h
        UI/SelectedCellUI.h
        UI/PanelLayerUI.cpp
        UI/PanelLayerUI.h
        UI/ButtonUI.cpp
        UI/ButtonUI.h
        UI/ButtonHoveredUI.cpp
        UI/ButtonHoveredUI.h
        UI/ButtonClickUI.cpp
        UI/ButtonClickUI.h
        UI/CellHoveredUI.cpp
        UI/CellHoveredUI.h
        UI/PanelUI/PanelUI.cpp
        UI/PanelUI/PanelUI.h
        UI/GameText.cpp
        UI/GameText.h
        UI/BluePlayerTexture.cpp
        UI/BluePlayerTexture.h
        UI/RedPlayerTexture.cpp
        UI/RedPlayerTexture.h)

target_link_libraries(cpp_stratego_gg
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
)