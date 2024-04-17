#pragma once
#include "../System/Vector2.hpp"

namespace Powerup
{
	class IPowerup
	{
	public:
		virtual void initialize(sf::Vector2f position) = 0;
		virtual void update() = 0;
		virtual void render() = 0;

		virtual ~IPowerup(){};
	};
}