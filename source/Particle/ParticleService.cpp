#include "../../header/Particle/ParticleService.h"
#include "../../header/Particle/ParticleSystemConfigData.h"

namespace Particle
{
	ParticleService::ParticleService() { }

	ParticleService::~ParticleService() { destroy(); }

	void ParticleService::initialize() { }

	void ParticleService::update()
	{
		for (ParticleSystem* particle_system : particle_system_list) 
			particle_system->update();

		destroyFlaggedParticleSystem();
	}

	void ParticleService::render()
	{
		for (ParticleSystem* particle_system : particle_system_list)
			particle_system->render();
	}

	void ParticleService::spawnParticleSystem(sf::Vector2f position, ParticlesType particles_type)
	{
		ParticleSystem* particle_system = new ParticleSystem(getParticleSystemConfig(particles_type));
		particle_system->initialize(position);
		particle_system_list.push_back(particle_system);
	}

	void ParticleService::destroyParticleSystem(ParticleSystem* particle_system)
	{
		flagged_particle_system_list.push_back(particle_system);
		particle_system_list.erase(std::remove(particle_system_list.begin(), particle_system_list.end(), particle_system), particle_system_list.end());
	}

	ParticleSystemConfig ParticleService::getParticleSystemConfig(ParticlesType particles_type)
	{
		switch (particles_type)
		{
			case Particle::ParticlesType::EXPLOSION:
				return explosion_particle_system_config;
		}
	}

	void ParticleService::destroyFlaggedParticleSystem()
	{
		for (ParticleSystem* particle_system : flagged_particle_system_list)
			delete (particle_system);

		flagged_particle_system_list.clear();
	}

	void ParticleService::reset() { destroy(); }

	void ParticleService::destroy()
	{
		for (ParticleSystem* particle_system : particle_system_list)
			delete (particle_system);
	}
}