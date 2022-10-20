#include "TextObj.h"


TextObj::TextObj()
{
}

TextObj::~TextObj()
{
}

void TextObj::Init()
{
}

void TextObj::Update(float dt)
{
}

void TextObj::Draw(RenderWindow& window)
{
	window.draw(text);
}

void TextObj::SetText(Font& font, string tex, int size, Color color)
{
	text.setString(tex);
	text.setFont(font);
	text.setFillColor(color);
	text.setCharacterSize(size);
}

void TextObj::SetPosition(Vector2f pos)
{
	text.setPosition(pos);
}

void TextObj::SetOrigin(Origins origin)
{
	Utils::SetOrigin(text,origin);
}
