#pragma once
#include <vector>

namespace Collision
{
	class ICollider;

	class CollisionService
	{
	private:
		std::vector<ICollider*> collider_list;

		void processCollision();
		void doCollision(int index_i, int index_j);
		bool hasCollisionOccurred(int index_i, int index_j);
		bool areActiveColliders(int index_i, int index_j);

	public:
		CollisionService();
		~CollisionService();

		void initialize();
		void update();

		void addCollider(ICollider* collider);
		void removeCollider(ICollider* collider);
	};
}