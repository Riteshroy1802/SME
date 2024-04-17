#include "../../ui/GameplayUI/GameplayUIController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Sound;
        using namespace Global;
        using namespace Player;
        using namespace UI::UIElement;

        GameplayUIController::GameplayUIController() { createUIElements(); }

        GameplayUIController::~GameplayUIController() { destroy(); }

        void GameplayUIController::initialize()
        {
            initializeImage();
            initializeText();
        }

        void GameplayUIController::createUIElements()
        {
            player_image = new ImageView();
            score_text = new TextView();
            enemies_killed_text = new TextView();
        }

        void GameplayUIController::initializeImage()
        {
            player_image->initialize(Config::player_texture_path, player_sprite_width, player_sprite_height, sf::Vector2f(0, 0));
        }

        void GameplayUIController::initializeText()
        {
            sf::String score_string = "Score  :  0";
            sf::String enemies_killed_string = "Enemies Killed  :  0";

            score_text->initialize(score_string, sf::Vector2f(score_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);
            enemies_killed_text->initialize(enemies_killed_string, sf::Vector2f(enemies_killed_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);
        }

        void GameplayUIController::update()
        {
            updateScoreText();
            updateEnemiesKilledText();
        }

        void GameplayUIController::render()
        {
            score_text->render();
            enemies_killed_text->render();
            drawPlayerLives();
        }

        void GameplayUIController::show() {}

        void GameplayUIController::updateScoreText()
        {
            sf::String score_string = "Score  :  " + std::to_string(PlayerModel::player_score);
            score_text->setText(score_string);
        }

        void GameplayUIController::updateEnemiesKilledText()
        {
            sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemies_killed);
            enemies_killed_text->setText(enemies_killed_string);
        }

        void GameplayUIController::drawPlayerLives()
        {
            sf::RenderWindow *game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            for (int i = 0; i < PlayerModel::player_lives; i++)
            {
                player_image->setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
                player_image->render();
            }
        }

        void GameplayUIController::destroy()
        {
            delete (player_image);
            delete (score_text);
            delete (enemies_killed_text);
        }
    }
}