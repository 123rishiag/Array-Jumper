#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Sound;
	using namespace Level;
	using namespace Main;

	GameplayController::GameplayController() { }

	GameplayController::~GameplayController() { }

	void GameplayController::initialize() { }

	void GameplayController::update() { }

	void GameplayController::render() { }

	bool GameplayController::isEndBlock(Level::BlockType value) const
	{
		if (value == BlockType::TARGET)
			return true;
		return false;
	}

	void GameplayController::processEndBlock()
	{
		ServiceLocator::getInstance()->getPlayerService()->levelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::LEVEL_COMPLETE);

		if (isLastLevel())
		{
			gameWon();
			return;
		}

		loadNextLevel();
	}

	bool GameplayController::isObstacle(Level::BlockType value) const
	{
		if (value == BlockType::OBSTACLE_ONE || value == BlockType::OBSTACLE_TWO)
			return true;
		return false;
	}

	void GameplayController::processObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}

	void GameplayController::onPositionChanged(int position)
	{
		BlockType value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
			processObstacle();

		if (isEndBlock(value))
			processEndBlock();
	}

	void GameplayController::gameOver()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		ServiceLocator::getInstance()->getLevelService()->resetLevels();
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}

	void GameplayController::gameWon()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::GAME_WON);
		ServiceLocator::getInstance()->getLevelService()->resetLevels();
	}

	bool GameplayController::isLastLevel() const
	{
		return ServiceLocator::getInstance()->getLevelService()->isLastLevel();
	}

	void GameplayController::loadNextLevel()
	{
		ServiceLocator::getInstance()->getLevelService()->loadNextLevel();
	}
}