#include "../../header/Elements/Bunker/BunkerController.h"
#include "../../header/Elements/Bunker/BunkerView.h"
#include "../../../header/Entity/EntityConfig.h"
#include "../../header/Global/ServiceLocator.h"

namespace Element
{
	namespace Bunker
	{
		using namespace Entity;
		using namespace Global;

		BunkerController::BunkerController() { bunker_view = new BunkerView(); }

		BunkerController::~BunkerController() { delete(bunker_view); }

		void BunkerController::initialize(BunkerData data)
		{
			bunker_data = data;
			bunker_view->initialize(this); 
		}

		void BunkerController::update() { bunker_view->update(); }

		void BunkerController::render() { bunker_view->render(); }

		const sf::Sprite& BunkerController::getColliderSprite() { return bunker_view->getBunkerSprite(); }

		void BunkerController::onCollision(ICollider* other_collider) { }

		sf::Vector2f BunkerController::getBunkerPosition() { return bunker_data.position; }
	}
}