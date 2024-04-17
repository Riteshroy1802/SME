#include "../../header/Elements/Bunker/BunkerData.h"

namespace Element
{
	namespace Bunker
	{
		BunkerData::BunkerData() { }

		BunkerData::BunkerData(sf::Vector2f position)
		{
			this->position = position;
		}
	}
}