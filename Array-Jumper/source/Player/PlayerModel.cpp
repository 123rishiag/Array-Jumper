#include "../../header/Player/PlayerModel.h"

namespace Player
{
	PlayerModel::PlayerModel() { }

	PlayerModel::~PlayerModel() { }

	void PlayerModel::initialize()
	{
		resetPlayer();
	}

	PlayerState PlayerModel::getPlayerState() const
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState new_player_state)
	{
		player_state = new_player_state;
	}

	int PlayerModel::getCurrentPosition() const
	{
		return current_position;
	}

	void PlayerModel::setCurrentPosition(int new_position)
	{
		current_position = new_position;
	}

	int PlayerModel::getCurrentLives() const
	{
		return current_lives;
	}

	void PlayerModel::decrementLife() 
	{
		resetPosition();
		current_lives--; 
	}

	void PlayerModel::resetPosition()
	{
		current_position = 0;
	}

	void PlayerModel::resetPlayer()
	{
		player_state = PlayerState::ALIVE;
		resetPosition();
		current_lives = max_lives;
	}
}