#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Player;
	using namespace Sound;
	using namespace UI;
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		player_service = new PlayerService();
		sound_service = new SoundService();
		ui_service = new UIService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		player_service->initialize();
		sound_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			player_service->update();
		}
		// No sound service to update
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		// No event service to render
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			player_service->render();
		}
		// No sound service to render
		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(player_service);
		delete(sound_service);
		delete(ui_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	EventService* ServiceLocator::getEventService() { return event_service; }

	PlayerService* ServiceLocator::getPlayerService() { return player_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }
}