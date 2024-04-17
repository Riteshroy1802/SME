#include "../../header/Enemy/Controller/ZapperController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;

	namespace Controller
	{
		ZapperController::ZapperController(EnemyType type) : EnemyController(type) { }

		ZapperController::~ZapperController() { }

		void ZapperController::initialize()
		{
			EnemyController::initialize();
		}

		void ZapperController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				moveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				moveRight();
				break;

			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void ZapperController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x) enemy_model->setMovementDirection(MovementDirection::RIGHT);
				else enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::processScore()
		{
			ServiceLocator::getInstance()->getPlayerService()->increaseScore(reward);
			EnemyController::processScore();
		}
	}
}
