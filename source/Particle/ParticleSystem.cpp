#include "../../header/Particle/ParticleSystem.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Particle/ParticleService.h"

namespace Particle
{
	using namespace Global;
	using namespace UI::UIElement;

	ParticleSystem::ParticleSystem(ParticleSystemConfig config)
	{
		particle_system_config = config; 
		createUIElements();
	}

	ParticleSystem::~ParticleSystem() 
	{
		delete(particle_image);
	}

	void ParticleSystem::initialize(sf::Vector2f position)
	{
		particles_position = position;
		current_frame = 0;
		frame_time = sf::seconds(particle_system_config.frame_duration);

		initializeImage();
	}

	void ParticleSystem::createUIElements()
	{
		particle_image = new ImageView();
	}

	void ParticleSystem::initializeImage()
	{
		particle_image->initialize(Config::explosion_texture_path, 0, 0, particles_position);
		particle_image->setTextureRect(sf::IntRect(0, 0, particle_system_config.tile_width, particle_system_config.tile_height));

		particle_image->setScale(particle_system_config.particles_sprite_width, 
			particle_system_config.particles_sprite_height, 
			particle_system_config.tile_width,
			particle_system_config.tile_height);
	}

	void ParticleSystem::update()
	{
		if (clock.getElapsedTime() >= frame_time)
		{
			if (current_frame + 1 >= particle_system_config.number_of_animation_frames) 
				destroy();

			current_frame = (current_frame + 1) % particle_system_config.number_of_animation_frames;
			clock.restart();

			particle_image->setTextureRect(sf::IntRect(
				current_frame * particle_system_config.tile_width, 
				0, 
				particle_system_config.tile_width,
				particle_system_config.tile_height));
		}
		particle_image->update();
	}

	void ParticleSystem::render()
	{
		particle_image->render();
	}

	void ParticleSystem::destroy()
	{
		ServiceLocator::getInstance()->getParticleService()->destroyParticleSystem(this);
	}
}