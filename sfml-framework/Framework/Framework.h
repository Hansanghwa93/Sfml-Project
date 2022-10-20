#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Framework
{
protected:
	RenderWindow window;
	Vector2i windowSize;

	Clock clock;
	Time deltaTime;
	float timeScale;
public:
	Framework(int width, int height);
	virtual ~Framework();

	float GetDT() const;
	float GetRealDT() const;

	bool Init();
	bool Do();
};

