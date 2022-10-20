#include "SceneDev1.h"
#include "SceneMgr.h"
#include "../Framework/InputMgr.h"
#include "../Framework/ResourceMgr.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"
#include "../Framework/SoundMgr.h"

SceneDev1::SceneDev1()
	:Scene(Scenes::Dev1)
{
	SpriteObj* obj = new SpriteObj();
	obj->SetTexture(*RESOURCE_MGR->GetTexture("graphics/player3.png"));
	objList.push_back(obj);

	TextObj* tex = new TextObj();
	tex->SetText(*RESOURCE_MGR->GetFont("fonts/NotoSansKR-Bold.otf"), ("Dev1"), 75, (Color::Magenta));
	uiObjList.push_back(tex);
	tex->SetOrigin(Origins::TR);
	tex->SetPosition(Vector2f{ 1280,0 });
}

SceneDev1::~SceneDev1()
{
}

void SceneDev1::Enter()
{
	SOUND_MGR->Play("sound/Hennesis.wav", true);
}

void SceneDev1::Exit()
{
	SOUND_MGR->StopAll();
}

void SceneDev1::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev2);
	}
	if (InputMgr::GetKeyDown(Keyboard::Return))
	{
		SOUND_MGR->Play("sound/Hennesis.wav");
	}	
	Scene::Update(dt);
}

void SceneDev1::Draw(RenderWindow& window)
{
	Scene::Draw(window);
}
