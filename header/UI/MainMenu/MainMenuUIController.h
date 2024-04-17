#pragma once
#include "../../../sfml/include/sfml/Graphics.hpp"
#include "../Interface/IUIController.h"
#include "../UIElement/ImageView.h"
#include "../UIElement/ButtonView.h"
#include "../UIElement/TextView.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			const sf::Color text_color = sf::Color::White;
			const float background_alpha = 85.f;

			const float play_button_top_offset = 400.f;
			const float instructions_button_top_offset = 600.f;
			const float quit_button_top_offset = 800.f;

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float text_top_offset = 150.f;
			const int font_size = 80;

			UIElement::ImageView *background_image;
			UIElement::TextView *high_score_text;

			UIElement::ButtonView *play_button;
			UIElement::ButtonView *instructions_button;
			UIElement::ButtonView *quit_button;

			void createImage();
			void createText();
			void createButtons();

			void initializeBackgroundImage();
			void initializeTexts();
			void initializeButtons();

			void registerButtonCallback();
			void playButtonCallback();
			void instructionsButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}