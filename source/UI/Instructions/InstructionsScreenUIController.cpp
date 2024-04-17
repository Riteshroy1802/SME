#include "../../ui/Instructions/InstructionsScreenUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace UI
{
    namespace Instructions
    {
        using namespace Global;
        using namespace UIElement;
        using namespace Main;
        using namespace Sound;

        InstructionsScreenUIController::InstructionsScreenUIController()
        {
            createButtons();
            createImage();
            createText();
        }

        InstructionsScreenUIController::~InstructionsScreenUIController()
        {
            destroy();
        }

        void InstructionsScreenUIController::initialize()
        {
            initializeTexts();
            initializeBackgroundImage();
            initializeButtons();
            registerButtonCallback();
        }

        void InstructionsScreenUIController::createImage()
        {
            background_image = new ImageView();
        }

        void InstructionsScreenUIController::createButtons()
        {
            menu_button = new ButtonView();
        }

        void InstructionsScreenUIController::createText()
        {
            for (int i = 0; i < number_of_instructions; i++)
            {
                instructions_text_list.push_back(new TextView());
            }
        }

        void InstructionsScreenUIController::initializeBackgroundImage()
        {
            sf::RenderWindow *game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void InstructionsScreenUIController::initializeButtons()
        {
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));
            menu_button->setCentreAlinged();
        }

        void InstructionsScreenUIController::initializeTexts()
        {
            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->initialize(instructions[i], sf::Vector2f(0, top_offset + (text_spacing * i)), FontType::BUBBLE_BOBBLE, font_size, text_color);
                instructions_text_list[i]->setTextCentreAligned();
            }
        }

        void InstructionsScreenUIController::registerButtonCallback()
        {
            menu_button->registerCallbackFuntion(std::bind(&InstructionsScreenUIController::menuButtonCallback, this));
        }

        void InstructionsScreenUIController::menuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void InstructionsScreenUIController::update()
        {
            background_image->update();
            menu_button->update();

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->update();
            }
        }

        void InstructionsScreenUIController::render()
        {
            background_image->render();
            menu_button->render();

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->render();
            }
        }

        void InstructionsScreenUIController::show()
        {
            background_image->show();
            menu_button->show();

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                instructions_text_list[i]->show();
            }
        }

        void InstructionsScreenUIController::destroy()
        {
            delete (background_image);
            delete (menu_button);

            for (int i = 0; i < instructions_text_list.size(); i++)
            {
                delete (instructions_text_list[i]);
            }
        }
    }
}