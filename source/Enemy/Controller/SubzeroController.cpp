#include "../../header/Enemy/Controller/SubzeroController.h"
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
		SubzeroController::SubzeroController(EnemyType type) : EnemyController(type) { }

		SubzeroController::~SubzeroController() { }

		void SubzeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			reward = subzero_reward;
			rate_of_fire = subzero_rate_of_fire;
			vertical_movement_speed = subzero_vertical_movement_speed;
		}

		void SubzeroController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				moveDown();
				break;
			}
		}

		void SubzeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}

		void SubzeroController::processScore()
		{
			ServiceLocator::getInstance()->getPlayerService()->increaseScore(reward);
			EnemyController::processScore();
		}
	}
}
