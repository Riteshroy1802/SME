#pragma once
#include "../Graphics.hpp"
#include "../../ui/UIElement/ImageView.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
    class PlayerView
    {
    private:
        const sf::String player_texture_path = "assets/textures/player_ship.png";

        const float player_sprite_width = 60.f;
        const float player_sprite_height = 60.f;

        PlayerController *player_controller;
        UI::UIElement::ImageView *player_image;

        void createUIElements();
        void initializeImage();

        void destroy();

    public:
        PlayerView();
        ~PlayerView();

        void initialize(PlayerController *controller);
        void update();
        void render();

        void setPlayerHighlight(bool b_highlight);
        const sf::Sprite &getPlayerSprite();
    };
}