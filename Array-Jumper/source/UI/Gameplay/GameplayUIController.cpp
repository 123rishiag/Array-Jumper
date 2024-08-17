#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"

#include <sstream>
#include <iomanip>
#include <iostream>

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
		using namespace UIElement;

		GameplayUIController::GameplayUIController()
		{
			createTexts();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::initialize()
		{
			initializeTexts();
		}

		void GameplayUIController::update()
		{
			updateLevelCountText();
			updateLifeCountText();
		}

		void GameplayUIController::render()
		{
			level_count_text->render();
			life_count_text->render();
		}

		void GameplayUIController::createTexts()
		{
			level_count_text = new TextView();
			life_count_text = new TextView();
		}

		void GameplayUIController::initializeTexts()
		{
			initializeLevelCountText();
			initializeLifeCountText();
		}

		void GameplayUIController::initializeLevelCountText()
		{
			float windowWidth = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;
			float x_position = left_offset;
			float y_position = top_offset;

			level_count_text->initialize("0", sf::Vector2f(x_position, y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::White);
		}

		void GameplayUIController::initializeLifeCountText()
		{
			float windowWidth = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x;
			float x_position = (static_cast<float>(windowWidth) - right_offset);
			float y_position = top_offset;

			life_count_text->initialize("0", sf::Vector2f(x_position, y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::White);
		}

		void GameplayUIController::updateLevelCountText()
		{
			int level_count = ServiceLocator::getInstance()->getLevelService()->getCurrentLevelNumber();

			std::string level_count_string = "LEVEL: " + std::to_string(level_count);

			level_count_text->setText(level_count_string);
			level_count_text->update();
		}

		void GameplayUIController::updateLifeCountText()
		{
			int life_count = ServiceLocator::getInstance()->getPlayerService()->getCurrentLives();

			std::string life_count_string = "LIFE: " + std::to_string(life_count);

			life_count_text->setText(life_count_string);
			life_count_text->update();
		}

		void GameplayUIController::destroy()
		{
			delete(level_count_text);
			delete(life_count_text);
		}
	}
}