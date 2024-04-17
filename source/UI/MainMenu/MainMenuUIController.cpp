#include "../../ui/MainMenu/MainMenuUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Global/Config.h"
#include "../../header/Gameplay/HighScore.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Event/EventService.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Gameplay;
        using namespace Graphics;
        using namespace Event;
        using namespace UIElement;
        using namespace Sound;

        MainMenuUIController::MainMenuUIController()
        {
            createImage();
            createText();
            createButtons();
        }

        MainMenuUIController::~MainMenuUIController()
        {
            destroy();
        }

        void MainMenuUIController::initialize()
        {
            initializeBackgroundImage();
            initializeTexts();
            initializeButtons();
            registerButtonCallback();
        }

        void MainMenuUIController::createImage()
        {
            background_image = new ImageView();
        }

        void MainMenuUIController::createText()
        {
            high_score_text = new TextView();
        }

        void MainMenuUIController::createButtons()
        {
            play_button = new ButtonView();
            instructions_button = new ButtonView();
            quit_button = new ButtonView();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            sf::RenderWindow *game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void MainMenuUIController::initializeTexts()
        {
            sf::String text_value = "HighScore : " + std::to_string(HighScore::loadHighScore().score);

            high_score_text->initialize(text_value, sf::Vector2f(0, text_top_offset), FontType::BUBBLE_BOBBLE, font_size, text_color);
            high_score_text->setTextCentreAligned();
        }

        void MainMenuUIController::initializeButtons()
        {
            play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_top_offset));
            instructions_button->initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(0, instructions_button_top_offset));
            quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_top_offset));

            play_button->setCentreAlinged();
            instructions_button->setCentreAlinged();
            quit_button->setCentreAlinged();
        }

        void MainMenuUIController::registerButtonCallback()
        {
            play_button->registerCallbackFuntion(std::bind(&MainMenuUIController::playButtonCallback, this));
            instructions_button->registerCallbackFuntion(std::bind(&MainMenuUIController::instructionsButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&MainMenuUIController::quitButtonCallback, this));
        }

        void MainMenuUIController::playButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void MainMenuUIController::instructionsButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::INSTRUCTIONS);
        }

        void MainMenuUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void MainMenuUIController::update()
        {
            background_image->update();
            play_button->update();
            instructions_button->update();
            quit_button->update();
            high_score_text->update();
        }

        void MainMenuUIController::render()
        {
            background_image->render();
            play_button->render();
            instructions_button->render();
            quit_button->render();
            high_score_text->render();
        }

        void MainMenuUIController::show()
        {
            background_image->show();
            play_button->show();
            instructions_button->show();
            quit_button->show();
            high_score_text->show();
        }

        void MainMenuUIController::destroy()
        {
            delete (play_button);
            delete (instructions_button);
            delete (quit_button);
            delete (background_image);
            delete (high_score_text);
        }
    }
}