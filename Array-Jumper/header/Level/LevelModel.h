#pragma once
#include "../../header/Level/LevelConfiguration.h"

namespace Level
{
	class LevelModel
	{
	private:
		const int number_of_level = LevelConfiguration::NUMBER_OF_LEVELS;
		LevelConfiguration level_configuration;

		int current_level_index;

	public:
		LevelModel();
		~LevelModel();

		bool isLastLevel() const;
		void loadNextLevel();

		int getCurrentLevelNumber() const;

		BlockType getCurrentBoxValue(int currentPosition) const;

		void reset();
	};
}