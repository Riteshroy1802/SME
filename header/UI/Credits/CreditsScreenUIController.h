#pragma once
#include "../../ui/Interface/IUIController.h"
#include "../../ui/UIElement/ImageView.h"
#include "../../ui/UIElement/ButtonView.h"
#include "../../ui/UIElement/TextView.h"

namespace UI
{
	namespace Credits
	{
		class CreditsScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const sf::String game_title = "Outscal Presents - Space Invaders";

			const float text_top_offset = 260.f;
			const int font_size = 110;

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float menu_button_y_position = 600.f;
			const float quit_button_y_position = 800.f;

			const float background_alpha = 85.f;

			const sf::Color text_color = sf::Color::White;

			UIElement::ImageView *background_image;
			UIElement::TextView *title_text;

			UIElement::ButtonView *menu_button;
			UIElement::ButtonView *quit_button;

			void createText();
			void createImage();
			void createButtons();

			void initializeText();
			void initializeBackgroundImage();
			void initializeButtons();

			void registerButtonCallback();

			void menuButtonCallback();
			void quitButtonCallback();

			void destroy();

		public:
			CreditsScreenUIController();
			~CreditsScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}