#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/MovementDirection.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Event/EventService.h"
#include "../../header/Gameplay/GameplayService.h"

namespace Player
{
	using namespace Global;
	using namespace Sound;
	using namespace Level;
	using namespace Event;
	using namespace Gameplay;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
		event_service = nullptr;
	}

	PlayerController::~PlayerController() { destroy(); }

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize();

		event_service = ServiceLocator::getInstance()->getEventService();
	}

	void PlayerController::update()
	{
		player_view->update();
		readInput();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	bool PlayerController::isPositionInBound(int targetPosition) const
	{
		if (targetPosition >= 0 && targetPosition < LevelData::NUMBER_OF_BOXES)
			return true;
		return false;
	}

	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->getCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->setCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);

		ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);
	}

	void PlayerController::jump(MovementDirection direction)
	{
		int current_position = player_model->getCurrentPosition();
		int box_value = static_cast<int>(ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(current_position));
		int steps, targetPosition;

		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = box_value;
			break;
		case MovementDirection::BACKWARD:
			steps = -box_value;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = current_position + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->setCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::JUMP);

		ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::FORWARD);
			else
				move(MovementDirection::FORWARD);
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::BACKWARD);
			else
				move(MovementDirection::BACKWARD);
		}
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::setPlayerState(PlayerState new_player_state)
	{
		player_model->setPlayerState(new_player_state);
	}

	int PlayerController::getCurrentPosition() const
	{
		return player_model->getCurrentPosition();
	}

	void PlayerController::setCurrentPosition(int new_position)
	{
		player_model->setCurrentPosition(new_position);
	}

	void PlayerController::takeDamage()
	{
		player_model->resetPlayer();
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}
}