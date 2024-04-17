#include "../../header/Collision/ICollider.h"

namespace Collision
{
	ICollider::ICollider() { collision_state = CollisionState::ENABLED; }

	ICollider::~ICollider() { }

	void ICollider::enableCollision() { collision_state = CollisionState::ENABLED; }

	void ICollider::disableCollision() { collision_state = CollisionState::DISABLED; }

	CollisionState ICollider::getCollisionState() { return collision_state; }
}

