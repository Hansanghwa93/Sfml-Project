#include "SceneDev2.h"
#include "SceneMgr.h"
#include "../Framework/InputMgr.h"
#include "../Framework/ResourceMgr.h"
#include "../GameObject/SpriteObj.h"
#include "../GameObject/TextObj.h"
#include "../Framework/SoundMgr.h"

SceneDev2::SceneDev2()
	:Scene(Scenes::Dev2)
{
	SpriteObj* obj = new SpriteObj();
	obj->SetTexture(*RESOURCE_MGR->GetTexture("graphics/player5.png"));
	objList.push_back(obj);

	TextObj* tex = new TextObj();
	tex->SetText(*RESOURCE_MGR->GetFont("fonts/NotoSansKR-Bold.otf"), ("Dev2"), 75, (Color::Magenta));
	uiObjList.push_back(tex);
	tex->SetOrigin(Origins::TR);
	tex->SetPosition(Vector2f{ 1280,0 });
}

SceneDev2::~SceneDev2()
{
}

void SceneDev2::Enter()
{
	SOUND_MGR->Play("sound/Cunningcity.wav", true);
}

void SceneDev2::Exit()
{

	SOUND_MGR->StopAll();
}

void SceneDev2::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Space))
	{
		SCENE_MGR->ChangeScene(Scenes::Dev1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Return))
	{
		SOUND_MGR->Play("sound/Cunningcity.wav");
	}
	Scene::Update(dt);
}

void SceneDev2::Draw(RenderWindow& window)
{
	Scene::Draw(window);
}
