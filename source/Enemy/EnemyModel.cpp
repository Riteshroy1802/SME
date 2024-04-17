#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type) 
	{
		enemy_type = type;
		entity_type = Entity::EntityType::ENEMY;
	}

	EnemyModel::~EnemyModel() { }

	void EnemyModel::initialize()
	{
		enemy_state = EnemyState::PATROLLING;
		movement_direction = MovementDirection::RIGHT;
		enemy_position = reference_position;
	}

	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}

	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}

	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}

	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}

	void EnemyModel::setEnemyType(EnemyType type)
	{
		enemy_type = type;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	Entity::EntityType EnemyModel::getEntityType()
	{
		return entity_type;
	}
}