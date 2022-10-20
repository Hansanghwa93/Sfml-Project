#pragma once
#include "Object.h"
#include "../Framework/Utils.h"

class TextObj : public Object
{
protected:
	Text text;
public:
	TextObj();
	virtual ~TextObj();

	virtual void Init() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void SetText(Font& font, string tex, int size , Color color);
	void SetPosition(Vector2f pos);
	void SetOrigin(Origins origin);
};