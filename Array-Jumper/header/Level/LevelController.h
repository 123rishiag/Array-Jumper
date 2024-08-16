#pragma once
#include "../../header/Level/LevelData.h"

namespace Level
{
	class LevelView;
	class LevelModel;

	class LevelController
	{
	private:
		LevelView* level_view;
		LevelModel* level_model;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		BoxDimensions getBoxDimensions() const;
		BlockType getCurrentBoxValue(int currentPosition) const;
	};
}