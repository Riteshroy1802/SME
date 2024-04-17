#pragma once

namespace Particle
{
    struct ParticleSystemConfig 
    {
        sf::String particles_texture_path;

        float particles_sprite_width;
        float particles_sprite_height;

        float tile_width;
        float tile_height;

        int number_of_animation_frames;
        float frame_duration;

        ParticleSystemConfig() {};

        ParticleSystemConfig(sf::String texture_path, float sprite_width, float sprite_height, float tile_width, float tile_height, int frames, float duration) :
            particles_texture_path(texture_path),
            particles_sprite_width(sprite_width),
            particles_sprite_height(sprite_height),
            tile_width(tile_width),
            tile_height(tile_height),
            number_of_animation_frames(frames),
            frame_duration(duration) {}  
    };
}