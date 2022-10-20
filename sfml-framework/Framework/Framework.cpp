#include "Framework.h"
#include "InputMgr.h"
#include "../Scenes/SceneMgr.h"
#include "ResourceMgr.h"
#include "../DataTable/DataTableMGR.h"
#include "SoundMgr.h"

Framework::Framework(int width, int height)
	:windowSize(width, height), timeScale(1.f)
{
	window.create(VideoMode(windowSize.x, windowSize.y), "Game");
}

Framework::~Framework()
{
}

float Framework::GetDT() const
{
    return deltaTime.asSeconds() * timeScale;
}

float Framework::GetRealDT() const
{
    return deltaTime.asSeconds();
}

bool Framework::Init()
{
    SOUND_MGR->Init();
    RESOURCE_MGR->LoadAll();
    SCENE_MGR->Init();
    InputMgr::Init();
    return true;
}

bool Framework::Do()
{
    while (window.isOpen())
    {
        deltaTime = clock.restart();
        float dt = GetDT();
        InputMgr::ClearInput();
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed)
            {
                window.close();
            }
            InputMgr::UpdateInput(ev);
            if (InputMgr::GetKeyDown(Keyboard::Escape))
                exit(-1);
        }
        SCENE_MGR->Update(dt);
        SOUND_MGR->Update();
        window.clear();
        SCENE_MGR->Draw(window);
        window.display();
    }
	return true;
}
