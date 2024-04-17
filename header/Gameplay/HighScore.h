#pragma once
#include "SFML/Graphics/Text.hpp"

namespace Gameplay
{
    struct HighScoreData
    {
        std::string player_name;
        int score;
    };

    static class HighScore
    {
    public:
        static void saveHighScore(const HighScoreData& highScore);
        static HighScoreData loadHighScore();
    };
}