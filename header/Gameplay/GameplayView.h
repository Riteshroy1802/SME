#pragma once
#include "../Graphics.hpp"
#include "../../ui/UIElement/ImageView.h"

namespace Gameplay
{
    class GameplayController;

    class GameplayView
    {
    private:
        sf::RenderWindow *game_window;
        sf::Texture background_texture;
        sf::Sprite background_sprite;
        const float background_alpha = 150.f;

        GameplayController *gameplay_controller;
        UI::UIElement::ImageView *background_image;

        void initializeBackgroundImage();

    public:
        GameplayView();
        ~GameplayView();

        void initialize();
        void update();
        void render();
    };
}