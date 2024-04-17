#pragma once
#include <vector>
#include "../../sfml/include/SFML/System/Vector2.hpp"

namespace Powerup
{
	class IPowerup;
	class PowerupController;
	enum class PowerupType;
	enum class MovementDirection;

	class PowerupService
	{
	private:
		std::vector<IPowerup*> flagged_powerup_list;
		std::vector<IPowerup*> powerup_list;

		PowerupController* createPowerup(PowerupType powerup_type);
		void destroyFlaggedPowerup();
		void destroy();

	public:
		PowerupService();
		virtual ~PowerupService();

		void initialize();
		void update();
		void render();

		PowerupController* spawnPowerup(PowerupType powerup_type, sf::Vector2f position);
		void destroyPowerup(PowerupController* powerup_controller);
	};
}