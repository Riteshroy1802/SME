#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            const float thunder_snake_horizontal_movement_speed = 190.f;
            const int thunder_snake_reward = 3;

            void move() override;
            void moveLeft();
            void moveRight();
            void moveDiagonalLeft();
            void moveDiagonalRight();
            void processScore() override;

            MovementDirection getInitialMovementDirection();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
        };
    }
}