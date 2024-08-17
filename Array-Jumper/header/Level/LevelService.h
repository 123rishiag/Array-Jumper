#pragma once
#include "../../header/Level/LevelData.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;

		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		bool isLastLevel() const;
		void loadNextLevel();

		int getCurrentLevelNumber() const;

		BoxDimensions getBoxDimensions() const;
		BlockType getCurrentBoxValue(int currentPosition) const;

		void resetLevels();
	};
}