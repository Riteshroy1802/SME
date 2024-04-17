#pragma once
#include "../Graphics.hpp"

namespace Powerup
{
    enum class PowerupType;

    class PowerupModel
    {
    private:
        float movement_speed = 300.f;

        sf::Vector2f powerup_position;
        PowerupType powerup_type;

    public:
        PowerupModel(PowerupType type);
        ~PowerupModel();

        void initialize(sf::Vector2f position);

        sf::Vector2f getPowerupPosition();
        void setPowerupPosition(sf::Vector2f position);

        PowerupType getPowerupType();
        void setPowerupType(PowerupType type);

        float getMovementSpeed();
        void setMovementSpeed(float speed);
    };
}