#pragma once
#include "../Graphics.hpp"
#include "../../ui/UIElement/ImageView.h"

namespace Powerup
{
    class PowerupController;

    class PowerupView
    {
    private:
        const float powerup_sprite_width = 30.f;
        const float powerup_sprite_height = 30.f;

        PowerupController *powerup_controller;
        UI::UIElement::ImageView *powerup_image;

        void createUIElements();
        void initializeImage();
        sf::String getPowerupTexturePath();

        void destroy();

    public:
        PowerupView();
        ~PowerupView();

        void initialize(PowerupController *controller);
        void update();
        void render();

        const sf::Sprite &getPowerupSprite();
    };
}