#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/Level/LevelService.h"
#include "../../header/Player/PlayerService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/UI/UIService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Graphics::GraphicService* graphic_service;
        Event::EventService* event_service;
        Level::LevelService* level_service;
        Player::PlayerService* player_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        ServiceLocator();
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Level::LevelService* getLevelService();
        Player::PlayerService* getPlayerService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
    };
}