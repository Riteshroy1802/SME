#pragma once

namespace Enemy
{
	enum class EnemyType
	{
		ZAPPER,
		THUNDER_SNAKE,
		SUBZERO,
		UFO,
	};

    enum class EnemyState
    {
        PATROLLING,
        ATTACK,
        DEAD,
    };

    enum class MovementDirection
    {
        LEFT,
        RIGHT,
        DOWN,
        LEFT_DOWN,
        RIGHT_DOWN,
    };
}