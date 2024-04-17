#pragma once
#include "../Graphics.hpp"
#include "../../ui/UIElement/ImageView.h"

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        const float enemy_sprite_width = 60.f;
        const float enemy_sprite_height = 60.f;

        EnemyController *enemy_controller;
        UI::UIElement::ImageView *enemy_image;

        void createUIElements();
        void initializeImage();
        sf::String getEnemyTexturePath();

        void destroy();

    public:
        EnemyView();
        ~EnemyView();

        void initialize(EnemyController *controller);
        void update();
        void render();

        const sf::Sprite &getEnemySprite();
    };
}