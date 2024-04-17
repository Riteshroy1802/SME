#include "../../header/Enemy/Controller/UFOController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Powerup/PowerupService.h"
#include "../../header/Entity/EntityConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Entity;

	namespace Controller
	{
		UFOController::UFOController(EnemyType type) : EnemyController(type) { }

		UFOController::~UFOController() { }

		void UFOController::initialize()
		{
			EnemyController::initialize();
			reward = ufo_reward;
		}

		void UFOController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;
			}
		}

		void UFOController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void UFOController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		Powerup::PowerupType UFOController::getRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}

		void UFOController::onCollision(ICollider* other_collider)
		{
			EnemyController::onCollision(other_collider);
		}

		void UFOController::processScore()
		{
			ServiceLocator::getInstance()->getPlayerService()->increaseScore(ufo_reward);
			EnemyController::processScore();
		}
	}
}
