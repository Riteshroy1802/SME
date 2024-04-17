#pragma once
#include "../../ui/Interface/IUIController.h"
#include "../../ui/UIElement/ImageView.h"
#include "../../ui/UIElement/ButtonView.h"
#include "../../ui/UIElement/TextView.h"

namespace UI
{
	namespace Instructions
	{
		class InstructionsScreenUIController : public Interface::IUIController
		{
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float menu_button_y_position = 700.f;
			const float background_alpha = 85.f;

			static const int number_of_instructions = 4;
			const float top_offset = 200.f;
			const float text_spacing = 95.f;
			const int font_size = 50;

			const sf::Color text_color = sf::Color::White;

			sf::String instructions[number_of_instructions] = {"Use the arrow keys to 'Move' your 'Spaceship'",
															   "Press the 'Left Mouse Button' to fire lasers and destroy the 'Alien' invaders",
															   "Collect 'Power-ups' for improved 'Firepower' and 'Shields'",
															   "Compete for the 'High Score'"};

			UIElement::ImageView *background_image;
			UIElement::ButtonView *menu_button;

			std::vector<UIElement::TextView *> instructions_text_list;

			void createImage();
			void createButtons();
			void createText();
			void initializeBackgroundImage();
			void initializeButtons();
			void initializeTexts();
			void registerButtonCallback();

			void menuButtonCallback();

			void destroy();

		public:
			InstructionsScreenUIController();
			~InstructionsScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}