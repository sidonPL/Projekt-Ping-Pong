#include "paletka1.h"

paletka1::paletka1(float t_X, float t_Y)
{
	prostokat.setPosition(t_X, t_Y);
	prostokat.setSize({ this->paddleWidth, this->paddleHeight });
	prostokat.setFillColor(Color::Red);
	prostokat.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
}
void paletka1::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->prostokat, state);
}
void paletka1::update()
{
	this->prostokat.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::W) && this->top() > 0)
	{
	velocity.y = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) && this->bottom() < 600)
	{
	velocity.y = paddleVelocity;
	}
	else
	{
		velocity.y = 0;
		velocity.x = 0;
	}
}
float paletka1::left()
{
	return this->prostokat.getPosition().x - prostokat.getSize().x /2.f;
}
float paletka1::right()
{
	return this->prostokat.getPosition().x + prostokat.getSize().x / 2.f;
}
float paletka1::top()
{
	return this->prostokat.getPosition().y - prostokat.getSize().y / 2.f;
}
float paletka1::bottom()
{
	return this->prostokat.getPosition().y + prostokat.getSize().y / 2.f;
}
Vector2f paletka1::getPosition()
{
	return prostokat.getPosition();
}