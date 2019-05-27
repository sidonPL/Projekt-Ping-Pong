#include "paletki.h"

paletki::paletki(float t_X, float t_Y)
{
	prostokat.setPosition(t_X, t_Y);
	prostokat.setSize({ this->paddleWidth, this->paddleHeight });
	prostokat.setFillColor(Color::Red);
	prostokat.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
}
void paletki::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->prostokat, state);
}
void paletki::update()
{
	this->prostokat.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::W) && this->top() < 0)
	{
	velocity.y = -paddleVelocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::S) && this->bottom() > 600)
	{
	velocity.y = paddleVelocity;
	}
	else
	{
		velocity.x = 0;
	}
}
float paletki::left()
{
	return this->prostokat.getPosition().x - prostokat.getSize().x /2.f;
}
float paletki::right()
{
	return this->prostokat.getPosition().x + prostokat.getSize().x / 2.f;
}
float paletki::top()
{
	return this->prostokat.getPosition().y - prostokat.getSize().x / 2.f;
}
float paletki::bottom()
{
	return this->prostokat.getPosition().y + prostokat.getSize().x / 2.f;
}
Vector2f paletki::getPosition()
{
	return prostokat.getPosition();
}