#include "../../header/Event/EventService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include <iostream>

namespace Event
{
    using namespace Global;
    using namespace Graphics;

    EventService::EventService() { game_window = nullptr; }

    EventService::~EventService() = default;

    void EventService::initialize()
    {
        game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
    }

    void EventService::update()
    {
        updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
        updateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
        updateKeyboardButtonsState(left_arrow_button_state, sf::Keyboard::Left);
        updateKeyboardButtonsState(right_arrow_button_state, sf::Keyboard::Right);
        updateKeyboardButtonsState(A_button_state, sf::Keyboard::A);
        updateKeyboardButtonsState(D_button_state, sf::Keyboard::D);
    }

    void EventService::processEvents()
    {
        if (isGameWindowOpen())
        {
            // Iterate over all events in the queue.
            while (game_window->pollEvent(game_event))
            {
                if (gameWindowWasClosed() || hasQuitGame())
                    game_window->close();
            }
        }
    }

    void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
    {
        if (sf::Mouse::isButtonPressed(mouse_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }

    void EventService::updateKeyboardButtonsState(ButtonState& current_button_state, sf::Keyboard::Key keyboard_button)
    {
        if (sf::Keyboard::isKeyPressed(keyboard_button))
        {
            switch (current_button_state)
            {
            case ButtonState::RELEASED:
                current_button_state = ButtonState::PRESSED;
                break;
            case ButtonState::PRESSED:
                current_button_state = ButtonState::HELD;
                break;
            }
        }
        else
        {
            current_button_state = ButtonState::RELEASED;
        }
    }

    bool EventService::isGameWindowOpen() { return game_window != nullptr; }

    bool EventService::gameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

    bool EventService::hasQuitGame() { return (isKeyboardEvent() && pressedEscapeKey()); }

    bool EventService::isKeyboardEvent() { return game_event.type == sf::Event::KeyPressed; }

    bool EventService::pressedEscapeKey() { return game_event.key.code == sf::Keyboard::Escape; }

    bool EventService::pressedLeftArrowKey() { return left_arrow_button_state == ButtonState::HELD; }

    bool EventService::pressedRightArrowKey() { return right_arrow_button_state == ButtonState::HELD; }

    bool EventService::pressedAKey() { return A_button_state == ButtonState::HELD; }

    bool EventService::pressedDKey() { return D_button_state == ButtonState::HELD; }

    bool EventService::pressedLeftMouseButton() { return left_mouse_button_state == ButtonState::PRESSED; }

    bool EventService::pressedRightMouseButton() { return right_mouse_button_state == ButtonState::PRESSED; }
}