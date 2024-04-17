#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Event/EventService.h"
#include "../../header/Entity/EntityConfig.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Gameplay/HighScore.h"

namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Time;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;
	using namespace Sound;
	using namespace Main;
	using namespace Gameplay;

	PlayerController::PlayerController()
	{
		player_view = new PlayerView();
		player_model = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete (player_view);
		delete (player_model);
	}

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize(this);
	}

	void PlayerController::update()
	{
		switch (player_model->getPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			processPlayerInput();
			break;

		case::Player::PlayerState::FROZEN:
			updateFreezDuration();
			break;
		}

		updatePowerupDuration();
		player_view->update();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}

	sf::Vector2f PlayerController::getPlayerPosition()
	{
		return player_model->getPlayerPosition();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	const sf::Sprite& PlayerController::getColliderSprite()
	{
		return player_view->getPlayerSprite();
	}

	void PlayerController::onCollision(ICollider* other_collider)
	{
		if(processPowerupCollision(other_collider)) 
			return;

		processEnemyCollision(other_collider);
	}

	bool PlayerController::processEnemyCollision(ICollider* other_collider)
	{
		if (player_model->isShieldEnabled()) 
			return false;

		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(other_collider);

		if (enemy_controller)
		{
			decreasePlayerLive();
			return true;
		}
		return false;
	}

	bool PlayerController::processPowerupCollision(ICollider* other_collider)
	{
		PowerupController* powerup_controller = dynamic_cast<PowerupController*>(other_collider);
		if (powerup_controller)
		{
			return true;
		}
		return false;
	}

	void PlayerController::updatePowerupDuration()
	{
		if (elapsed_shield_duration > 0)
		{
			elapsed_shield_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
			if (elapsed_shield_duration <= 0) 
				disableShield();
		}

		if (elapsed_rapid_fire_duration > 0)
		{
			elapsed_rapid_fire_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
			if (elapsed_rapid_fire_duration <= 0) 
				disableRapidFire();
		}

		if (elapsed_tripple_laser_duration > 0)
		{
			elapsed_tripple_laser_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			
			if (elapsed_tripple_laser_duration <= 0) 
				disableTrippleLaser();
		}
	}

	void PlayerController::freezPlayer()
	{
		player_model->setPlayerState(PlayerState::FROZEN);
		elapsed_freez_duration = player_model->freez_duration;
		player_view->setPlayerHighlight(true);
	}

	void PlayerController::enableShield()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_ENABLED);
		elapsed_shield_duration = player_model->shiled_powerup_duration;
		player_model->setShieldState(true);
		player_view->setPlayerHighlight(true);
	}

	void PlayerController::disableShield()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_DISABLED);
		player_model->setShieldState(false);
		player_view->setPlayerHighlight(false);
	}

	void PlayerController::enableRapidFire()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_ENABLED);
		elapsed_rapid_fire_duration = player_model->rapid_fire_powerup_duration;
		player_model->setRapidFireState(true);
	}

	void PlayerController::disableRapidFire()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_DISABLED);
		player_model->setRapidFireState(false);
	}

	void PlayerController::enableTrippleLaser()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_ENABLED);
		elapsed_tripple_laser_duration = player_model->tripple_laser_powerup_duration;
		player_model->setTrippleFireState(true);
	}

	void PlayerController::disableTrippleLaser()
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::POWERUP_DISABLED);
		player_model->setTrippleFireState(false);
	}

	void PlayerController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey()) 
			moveLeft();	

		if (event_service->pressedRightArrowKey() || event_service->pressedDKey()) 
			moveRight();

		//if (event_service->pressedLeftMouseButton()) 
		//	processBulletFire();
	}

	void PlayerController::moveLeft()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x -= player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::max(currentPosition.x, player_model->left_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::moveRight()
	{
		sf::Vector2f currentPosition = player_model->getPlayerPosition();
		currentPosition.x += player_model->player_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		currentPosition.x = std::min(currentPosition.x, player_model->right_most_position.x);
		player_model->setPlayerPosition(currentPosition);
	}

	void PlayerController::updateFreezDuration()
	{
		if (elapsed_freez_duration >= 0)
		{
			elapsed_freez_duration -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (elapsed_freez_duration <= 0)
			{
				player_model->setPlayerState(PlayerState::ALIVE);
				player_view->setPlayerHighlight(false);
			}
		}
	}

	void PlayerController::decreasePlayerLive()
	{
		PlayerModel::player_lives -= 1;
		if (PlayerModel::player_lives <= 0)
		{
			saveHighScore();
			GameService::setGameState(GameState::CREDITS);
		}
	}

	void PlayerController::saveHighScore()
	{
		HighScoreData current_high_score = HighScore::loadHighScore();

		if (PlayerModel::player_score > current_high_score.score)
		{
			current_high_score.player_name = "Outscal";
			current_high_score.score = PlayerModel::player_score;
			HighScore::saveHighScore(current_high_score);
		}
	}
}