#pragma once
#include "../../sfml/include/sfml/Graphics/RenderWindow.hpp"
#include "../../sfml/include/sfml/Window/Event.hpp"

namespace Event
{
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};

	class EventService
	{
	private:
		sf::Event game_event;
		sf::RenderWindow *game_window;

		ButtonState left_mouse_button_state;
		ButtonState right_mouse_button_state;
		ButtonState left_arrow_button_state;
		ButtonState right_arrow_button_state;
		ButtonState A_button_state;
		ButtonState D_button_state;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();
		bool isKeyboardEvent();
		void updateMouseButtonsState(ButtonState &current_button_state, sf::Mouse::Button mouse_button);
		void updateKeyboardButtonsState(ButtonState &current_button_state, sf::Keyboard::Key keyboard_button);

	public:
		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents();

		bool pressedEscapeKey();
		bool pressedLeftArrowKey();
		bool pressedRightArrowKey();
		bool pressedAKey();
		bool pressedDKey();
		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();
	};
}