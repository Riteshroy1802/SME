#include "../../ui/UIService.h"
#include "../../header/Main/GameService.h"
#include "../../ui/UIElement/TextView.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace SplashScreen;
	using namespace GameplayUI;
	using namespace Instructions;
	using namespace Credits;
	using namespace UIElement;
	using namespace Interface;

	UIService::UIService()
	{
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		instructions_ui_controller = nullptr;
		credits_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		main_menu_controller = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
		instructions_ui_controller = new InstructionsScreenUIController();
		credits_ui_controller = new CreditsScreenUIController();
		splash_screen_ui_controller = new SplashScreenUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::update()
	{
		IUIController *ui_controller = getCurrentUIController();
		if (ui_controller)
			ui_controller->update();
	}

	void UIService::render()
	{
		IUIController *ui_controller = getCurrentUIController();
		if (ui_controller)
			ui_controller->render();
	}

	void UIService::showScreen()
	{
		IUIController *ui_controller = getCurrentUIController();
		if (ui_controller)
			ui_controller->show();
	}

	void UIService::initializeControllers()
	{
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
		instructions_ui_controller->initialize();
		credits_ui_controller->initialize();
		splash_screen_ui_controller->initialize();
	}

	IUIController *UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_ui_controller;

		case GameState::MAIN_MENU:
			return main_menu_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		case GameState::INSTRUCTIONS:
			return instructions_ui_controller;

		case GameState::CREDITS:
			return credits_ui_controller;

		default:
			return nullptr;
		}
	}

	void UIService::destroy()
	{
		delete (main_menu_controller);
		delete (gameplay_ui_controller);
		delete (instructions_ui_controller);
		delete (credits_ui_controller);
		delete (splash_screen_ui_controller);
	}
}