#pragma once
#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	class GameplayController
	{
	private:
		bool isObstacle(Level::BlockType value);
		void processObstacle();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void onPositionChanged(int position);
	};
}