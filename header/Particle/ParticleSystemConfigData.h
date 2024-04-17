#pragma once
#include "ParticleSystemConfig.h"
#include "../../header/Global/Config.h"

namespace Particle
{
	const ParticleSystemConfig explosion_particle_system_config
	(Global::Config::explosion_texture_path, 70.0f, 80.0f, 14.28f, 20.0f, 7, 0.03f);
}