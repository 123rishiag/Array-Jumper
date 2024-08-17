#pragma once
#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	class GameplayController
	{
	private:
		bool isEndBlock(Level::BlockType value) const;
		void processEndBlock();
		bool isObstacle(Level::BlockType value) const;
		void processObstacle();

		void gameOver();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void onPositionChanged(int position);
		void onDeath();
		void gameWon();

		bool isLastLevel() const;

		void loadNextLevel();
	};
}