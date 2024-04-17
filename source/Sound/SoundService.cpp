#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"

namespace Sound
{
	using namespace Global;

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path))
			printf("Error loading background music file");
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
			printf("Error loading background music file");
		if (!buffer_bullet_fire.loadFromFile(Config::bullet_fire_sound_path))
			printf("Error loading background music file");
		if (!buffer_explosion.loadFromFile(Config::explosion_sound_path))
			printf("Error loading background music file");
		if (!buffer_powerup_enabled.loadFromFile(Config::powerup_enabled_sound_path))
			printf("Error loading background music file");
		if (!buffer_powerup_disabled.loadFromFile(Config::powerup_disabled_sound_path))
			printf("Error loading background music file");
	}

	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			sound_effect.play();
			break;

		case SoundType::BULLET_FIRE:
			sound_effect.setBuffer(buffer_bullet_fire);
			sound_effect.play();
			break;

		case SoundType::EXPLOSION:
			explosion_sound_effect.setBuffer(buffer_explosion);
			explosion_sound_effect.play();
			break;

		case SoundType::POWERUP_ENABLED:
			powerup_sound_effect.setBuffer(buffer_powerup_enabled);
			powerup_sound_effect.play();
			break;

		case SoundType::POWERUP_DISABLED:
			powerup_sound_effect.setBuffer(buffer_powerup_disabled);
			powerup_sound_effect.play();
			break;

		default:
			printf("Invalid sound type");
			return;
		}
	}

	void SoundService::playBackgroundMusic()
	{
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}
}