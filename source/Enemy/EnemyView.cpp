#include "../../header/Enemy/EnemyView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;

	EnemyView::EnemyView() { createUIElements(); }

	EnemyView::~EnemyView() { destroy(); }

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		initializeImage();
	}

	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->getEnemyPosition());
	}

	void EnemyView::update()
	{
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
		enemy_image->update();
	}

	void EnemyView::render()
	{
		enemy_image->render();
	}

	const sf::Sprite& EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case::Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return Config::thunder_snake_texture_path;

		case::Enemy::EnemyType::SUBZERO:
			return Config::subzero_texture_path;

		case::Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;
		}
	}

	void EnemyView::destroy()
	{
		delete (enemy_image);
	}
}