#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:

		PlayerState player_state;
		int current_position;

		const int max_lives = 3;
		int current_lives;

	public:
		PlayerModel();
		~PlayerModel();

		void initialize();

		PlayerState getPlayerState() const;
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition() const;
		void setCurrentPosition(int new_position);

		int getCurrentLives() const;
		void decrementLife();

		void resetPosition();
		void resetPlayer();
	};
}