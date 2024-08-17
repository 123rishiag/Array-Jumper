#include "../../header/Level/LevelService.h"
#include "../../header/Level/LevelController.h"

namespace Level
{
	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}

	LevelService::~LevelService() { destroy(); }

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	bool LevelService::isLastLevel() const
	{
		return level_controller->isLastLevel();
	}

	void LevelService::loadNextLevel()
	{
		level_controller->loadNextLevel();
	}

	int LevelService::getCurrentLevelNumber() const
	{
		return level_controller->getCurrentLevelNumber();
	}

	BoxDimensions LevelService::getBoxDimensions() const
	{
		return level_controller->getBoxDimensions();
	}

	BlockType LevelService::getCurrentBoxValue(int currentPosition) const
	{
		return level_controller->getCurrentBoxValue(currentPosition);
	}

	void LevelService::resetLevels()
	{
		level_controller->resetLevels();
	}

	void LevelService::destroy()
	{
		delete(level_controller);
	}
}