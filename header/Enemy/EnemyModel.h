#pragma once
#include "../Graphics.hpp"
#include "../../header/Entity/EntityConfig.h"

namespace Enemy
{
    enum class EnemyType;
    enum class EnemyState;
    enum class MovementDirection;

    class EnemyModel
    {
    private:
        sf::Vector2f reference_position = sf::Vector2f(50.f, 100.f);
        sf::Vector2f enemy_position;

        Entity::EntityType entity_type;
        EnemyType enemy_type;
        EnemyState enemy_state;
        MovementDirection movement_direction;

    public:
        const sf::Vector2f left_most_position = sf::Vector2f(50.f, 100.f);
        const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 100.f);
        const sf::Vector2f barrel_position_offset = sf::Vector2f(20.f, 50.f);

        EnemyModel(EnemyType type);
        ~EnemyModel();

        void initialize();

        sf::Vector2f getEnemyPosition();
        void setEnemyPosition(sf::Vector2f position);

        sf::Vector2f getReferencePosition();
        void setReferencePosition(sf::Vector2f position);

        EnemyState getEnemyState();
        void setEnemyState(EnemyState state);

        EnemyType getEnemyType();
        void setEnemyType(EnemyType type);

        MovementDirection getMovementDirection();
        void setMovementDirection(MovementDirection direction);

        Entity::EntityType getEntityType();
    };
}