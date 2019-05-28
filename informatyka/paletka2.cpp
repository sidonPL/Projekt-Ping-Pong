#include "paletka2.h"

paletka2::paletka2(float t_X, float t_Y)
{
	prostokat.setPosition(t_X, t_Y);
	prostokat.setSize({ this->paddleWidth, this->paddleHeight });
	prostokat.setFillColor(Color::Blue);
	prostokat.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
}
void paletka2::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->prostokat, state);
}
void paletka2::update()
{
	this->prostokat.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0)
	{
		velocity.y = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < 600)
	{
		velocity.y = paddleVelocity;
	}
	else
	{
		velocity.y = 0;
		velocity.x = 0;
	}
}
float paletka2::left()
{
	return this->prostokat.getPosition().x - prostokat.getSize().x / 2.f;
}
float paletka2::right()
{
	return this->prostokat.getPosition().x + prostokat.getSize().x / 2.f;
}
float paletka2::top()
{
	return this->prostokat.getPosition().y - prostokat.getSize().y / 2.f;
}
float paletka2::bottom()
{
	return this->prostokat.getPosition().y + prostokat.getSize().y / 2.f;
}
Vector2f paletka2::getPosition()
{
	return prostokat.getPosition();
}