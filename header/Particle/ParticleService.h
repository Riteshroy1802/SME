#pragma once
#include <vector>
#include "../System/Vector2.hpp"
#include "../../header/Particle/ParticleSystem.h"

namespace Particle
{
	enum class ParticlesType
	{
		EXPLOSION,
	};

	class ParticleService
	{
	private:
		std::vector<ParticleSystem *> particle_system_list;
		std::vector<ParticleSystem *> flagged_particle_system_list;

		ParticleSystemConfig getParticleSystemConfig(ParticlesType particles_type);
		void destroyFlaggedParticleSystem();
		void destroy();

	public:
		ParticleService();
		virtual ~ParticleService();

		void initialize();
		void update();
		void render();

		void reset();

		void spawnParticleSystem(sf::Vector2f position, ParticlesType particles_type);
		void destroyParticleSystem(ParticleSystem *particle_system);
	};
}