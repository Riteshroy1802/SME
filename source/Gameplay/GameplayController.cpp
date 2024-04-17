#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/GameplayView.h"

namespace Gameplay
{
	GameplayController::GameplayController() { gameplay_view = new GameplayView(); }

	GameplayController::~GameplayController() { delete (gameplay_view); }

	void GameplayController::initialize() { gameplay_view->initialize(); }

	void GameplayController::update() { gameplay_view->update(); }

	void GameplayController::render() { gameplay_view->render(); }
}