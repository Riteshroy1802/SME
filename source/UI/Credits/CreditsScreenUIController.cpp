#include "../../ui/Credits/CreditsScreenUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Event/EventService.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace UI
{
    namespace Credits
    {
        using namespace Global;
        using namespace UIElement;
        using namespace Main;
        using namespace Sound;

        CreditsScreenUIController::CreditsScreenUIController()
        {
            createText();
            createImage();
            createButtons();
        }

        CreditsScreenUIController::~CreditsScreenUIController()
        {
            destroy();
        }

        void CreditsScreenUIController::initialize()
        {
            initializeText();
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void CreditsScreenUIController::createText()
        {
            title_text = new TextView();
        }

        void CreditsScreenUIController::createImage()
        {
            background_image = new ImageView();
        }

        void CreditsScreenUIController::createButtons()
        {
            menu_button = new ButtonView();
            quit_button = new ButtonView();
        }

        void CreditsScreenUIController::initializeText()
        {
            title_text->initialize(game_title, sf::Vector2f(0, text_top_offset), FontType::BUBBLE_BOBBLE, font_size, text_color);
            title_text->setTextCentreAligned();
        }

        void CreditsScreenUIController::initializeBackgroundImage()
        {
            sf::RenderWindow *game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void CreditsScreenUIController::initializeButtons()
        {
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));
            quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

            menu_button->setCentreAlinged();
            quit_button->setCentreAlinged();
        }

        void CreditsScreenUIController::registerButtonCallback()
        {
            menu_button->registerCallbackFuntion(std::bind(&CreditsScreenUIController::menuButtonCallback, this));
            quit_button->registerCallbackFuntion(std::bind(&CreditsScreenUIController::quitButtonCallback, this));
        }

        void CreditsScreenUIController::menuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void CreditsScreenUIController::quitButtonCallback()
        {
            ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
        }

        void CreditsScreenUIController::update()
        {
            background_image->update();
            menu_button->update();
            quit_button->update();
            title_text->update();
        }

        void CreditsScreenUIController::render()
        {
            background_image->render();
            menu_button->render();
            quit_button->render();
            title_text->render();
        }

        void CreditsScreenUIController::show()
        {
            background_image->show();
            menu_button->show();
            quit_button->show();
            title_text->show();
        }

        void CreditsScreenUIController::destroy()
        {
            delete (title_text);
            delete (menu_button);
            delete (quit_button);
            delete (background_image);
        }
    }
}