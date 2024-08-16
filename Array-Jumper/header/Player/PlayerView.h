#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelData.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:

		PlayerController* player_controller;

		sf::RenderWindow* game_window;
		UI::UIElement::ImageView* player_image;

		Level::BoxDimensions current_box_dimensions;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calulcatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}