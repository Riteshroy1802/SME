#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Graphics/GraphicService.h"

namespace Gameplay
{
	using namespace UI::UIElement;
	using namespace Global;

	GameplayView::GameplayView() { background_image = new ImageView(); }

	GameplayView::~GameplayView() { delete (background_image); }

	void GameplayView::initialize() { initializeBackgroundImage(); }

	void GameplayView::initializeBackgroundImage()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		background_image->initialize(Config::background_texture_path,
			game_window->getSize().x,
			game_window->getSize().y,
			sf::Vector2f(0, 0));

		background_image->setImageAlpha(background_alpha);
	}

	void GameplayView::update() { background_image->update(); }

	void GameplayView::render() { background_image->render(); }
}