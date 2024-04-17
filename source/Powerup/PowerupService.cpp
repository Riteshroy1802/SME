#include "../../header/Powerup/PowerupService.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Collision/ICollider.h"
#include "../../header/Powerup/Controller/OutscalBombController.h"
#include "../../header/Powerup/Controller/RapidFireController.h"
#include "../../header/Powerup/Controller/ShieldController.h"
#include "../../header/Powerup/Controller/TrippleLaserController.h"

namespace Powerup
{
	using namespace Global;
	using namespace Collision;
	using namespace Controller;

	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() { destroy(); }

	void PowerupService::initialize() { }

	void PowerupService::update()
	{
		for (IPowerup* powerup : powerup_list) 
			powerup->update();

		destroyFlaggedPowerup();
	}

	void PowerupService::render()
	{
		for (IPowerup* powerup : powerup_list)
			powerup->render();
	}

	PowerupController* PowerupService::createPowerup(PowerupType powerup_type)
	{
		switch (powerup_type)
		{
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TrippleLaserController(Powerup::PowerupType::TRIPPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType powerup_type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(powerup_type);
		powerup_controller->initialize(position);

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(powerup_controller));
		powerup_list.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::destroyFlaggedPowerup()
	{
		for (IPowerup* powerup : flagged_powerup_list) 
			delete (powerup);

		flagged_powerup_list.clear();
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(powerup_controller));

		flagged_powerup_list.push_back(powerup_controller);
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
	}

	void PowerupService::destroy()
	{
		for (IPowerup* powerup : powerup_list)
			delete (powerup);
	}
}