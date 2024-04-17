#pragma once
#include <vector>
#include "../../sfml/include/sfml/System/Vector2.hpp"
#include "../../header/Elements/Bunker/BunkerController.h"
#include "../../header/Elements/Bunker/BunkerData.h"

namespace Element
{
	class BunkerController;

	class ElementService
	{
	private:
		const std::vector<Bunker::BunkerData> bunker_data_list = {Bunker::BunkerData(sf::Vector2f(130.f, 800.f)),
																  Bunker::BunkerData(sf::Vector2f(430.0f, 800.f)),
																  Bunker::BunkerData(sf::Vector2f(730.0f, 800.f)),
																  Bunker::BunkerData(sf::Vector2f(1130.0f, 800.f)),
																  Bunker::BunkerData(sf::Vector2f(1430.0f, 800.f)),
																  Bunker::BunkerData(sf::Vector2f(1730.0f, 800.f))};

		std::vector<Bunker::BunkerController *> bunker_list;
		std::vector<Bunker::BunkerController *> flagged_bunker_list;

		void spawnBunkers();
		void destroyFlaggedBunkers();
		void destroy();

	public:
		ElementService();
		virtual ~ElementService();

		void initialize();
		void update();
		void render();

		void reset();

		void destroyBunker(Bunker::BunkerController *bunker_controller);
	};
}