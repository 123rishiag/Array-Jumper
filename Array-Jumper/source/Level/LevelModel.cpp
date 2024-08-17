#include "../../header/Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel() {
		reset();
	}
	LevelModel::~LevelModel() {}

	bool LevelModel::isLastLevel() const
	{
		if (current_level_index == LevelConfiguration::NUMBER_OF_LEVELS - 1)
			return true;
		return false;
	}

	void LevelModel::loadNextLevel()
	{
		current_level_index += 1;
	}

	int LevelModel::getCurrentLevelNumber() const
	{
		return current_level_index + 1;
	}

	BlockType LevelModel::getCurrentBoxValue(int currentPosition) const
	{
		return level_configuration.levels[current_level_index].level_boxes[currentPosition];
	}

	void LevelModel::reset()
	{
		current_level_index = 0;
	}
}