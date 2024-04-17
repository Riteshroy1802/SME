#pragma once
#include "../../../sfml/include/sfml/System/Vector2.hpp"

namespace Element
{
	namespace Bunker
	{
		struct BunkerData
		{
			sf::Vector2f position;

			BunkerData();
			BunkerData(sf::Vector2f position);
		};
	}
}