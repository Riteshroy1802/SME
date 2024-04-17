#include "../../header/Gameplay/HighScore.h"
#include <fstream>

namespace Gameplay
{
	void HighScore::saveHighScore(const HighScoreData& highScore)
	{
		std::ofstream high_score_file("highscore.txt");

		if (high_score_file.is_open())
		{
			high_score_file << highScore.player_name << " " << highScore.score << std::endl;
			high_score_file.close();
		}
		else printf("Failed to open highscore file for writing.");
	}

	HighScoreData HighScore::loadHighScore()
	{
		HighScoreData highScore;
		highScore.player_name = "Outscal";
		highScore.score = 0;

		std::ifstream high_score_file("highscore.txt");

		if (high_score_file.is_open()) 
		{
			high_score_file >> highScore.player_name >> highScore.score;
			high_score_file.close();
		}
		else  printf("Failed to open highscore file for writing.");

		return highScore;
	}
}