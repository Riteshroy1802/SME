#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:
            const int ufo_reward = 0;
            
            void move() override;
            void moveLeft();
            void moveRight();
            void processScore() override;
            Powerup::PowerupType getRandomPowerupType();

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void initialize() override;
            void onCollision(ICollider* other_collider) override;
        };
    }
}