#pragma once
#include "../Graphics.hpp"
#include "../../header/Entity/EntityConfig.h"
#include "../../ui/GameplayUI/GameplayUIController.h"

namespace Player
{
    enum class PlayerState
    {
        ALIVE,
        FROZEN,
        DEAD,
    };

    class PlayerModel
    {
    private:
        friend class PlayerController;
        friend void UI::GameplayUI::GameplayUIController::updateScoreText();
        friend void UI::GameplayUI::GameplayUIController::updateEnemiesKilledText();
        friend void UI::GameplayUI::GameplayUIController::drawPlayerLives();

        const sf::Vector2f initial_player_position = sf::Vector2f(950.f, 950.f);
        const int max_player_lives = 3;

        sf::Vector2f player_position;
        Entity::EntityType entity_type;
        PlayerState player_state;

        static int player_lives;
        static int player_score;
        static int enemies_killed;
        static int bullets_fired;

        bool b_shield;
        bool b_rapid_fire;
        bool b_tripple_laser;

    public:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 950.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 950.f);
        const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 5.f);
        const sf::Vector2f second_weapon_position_offset = sf::Vector2f(45.f, 0.f);
        const sf::Vector2f third_weapon_position_offset = sf::Vector2f(-45.f, 0.f);

        const float shiled_powerup_duration = 10.f;
        const float rapid_fire_powerup_duration = 10.f;
        const float tripple_laser_powerup_duration = 10.f;

        const float freez_duration = 1.5f;

        const float fire_cooldown_duration = 0.2f;
        const float rapid_fire_cooldown_duration = 0.05f;
        const float tripple_laser_position_offset = 30.f;

        const float player_movement_speed = 350.0f;
        static const int invincible_player_alpha = 170.f;

        PlayerModel();
        ~PlayerModel();

        void initialize();
        void reset();

        sf::Vector2f getPlayerPosition();
        void setPlayerPosition(sf::Vector2f position);

        PlayerState getPlayerState();
        void setPlayerState(PlayerState state);

        Entity::EntityType getEntityType();

        bool isShieldEnabled();
        bool isRapidFireEnabled();
        bool isTrippleLaserEnabled();

        void setShieldState(bool value);
        void setRapidFireState(bool value);
        void setTrippleFireState(bool value);
    };
}