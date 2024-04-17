#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupView.h"
#include "../../header/Powerup/PowerupModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Player/PlayerController.h"

namespace Powerup
{
	using namespace Global;
	using namespace Player;

	PowerupController::PowerupController(PowerupType type)
	{
		powerup_view = new PowerupView();
		powerup_model = new PowerupModel(type);
	}

	PowerupController::~PowerupController()
	{
		delete (powerup_view);
		delete (powerup_model);
	}

	void PowerupController::initialize(sf::Vector2f position)
	{
		powerup_model->initialize(position);
		powerup_view->initialize(this);
	}

	void PowerupController::update()
	{
		updatePowerupPosition();
		powerup_view->update();
	}

	void PowerupController::render()
	{
		powerup_view->render();
	}

	void PowerupController::updatePowerupPosition()
	{
		sf::Vector2f currentPosition = powerup_model->getPowerupPosition();
		currentPosition.y += powerup_model->getMovementSpeed() * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		powerup_model->setPowerupPosition(currentPosition);
	}

	void PowerupController::handleOutOfBounds()
	{
		sf::Vector2f powerupPosition = getPowerupPosition();
		sf::Vector2u windowSize = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (powerupPosition.x < 0 || powerupPosition.x > windowSize.x ||
			powerupPosition.y < 0 || powerupPosition.y > windowSize.y)
		{
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}

	sf::Vector2f PowerupController::getPowerupPosition()
	{
		return powerup_model->getPowerupPosition();
	}

	PowerupType PowerupController::getPowerupType()
	{
		return powerup_model->getPowerupType();
	}

	const sf::Sprite& PowerupController::getColliderSprite()
	{
		return powerup_view->getPowerupSprite();
	}

	void PowerupController::onCollision(ICollider* other_collider)
	{
		PlayerController* player_controller = dynamic_cast<PlayerController*>(other_collider);

		if (player_controller)
		{
			applyPowerup();
			ServiceLocator::getInstance()->getPowerupService()->destroyPowerup(this);
		}
	}
}