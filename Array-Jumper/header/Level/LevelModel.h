#pragma once
#include "../../header/Level/LevelData.h"

namespace Level
{
	class LevelModel
	{
	private:
		LevelData current_level_data;

	public:
		LevelModel();
		~LevelModel();

		BlockType getCurrentBoxValue(int currentPosition);
	};
}