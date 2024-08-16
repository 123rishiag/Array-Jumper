#pragma once

namespace Event
{
	class EventService;
}

namespace Player
{
	enum class MovementDirection;

	class PlayerView;
	class PlayerModel;

	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		Event::EventService* event_service;

		bool isPositionInBound(int targetPosition) const;
		void move(MovementDirection direction);

		void readInput();

		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition() const;
		void setCurrentPosition(int new_position);
	};
}