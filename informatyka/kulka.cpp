#include "kulka.h"

kulka::kulka(float t_X, float t_Y)
{
	kolo.setPosition(t_X, t_Y);
	kolo.setRadius(this->ballRadius);
	kolo.setFillColor(Color::Yellow);
	kolo.setOrigin(this->ballRadius, this->ballRadius);
}

void kulka::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->kolo, state);
}
void kulka::update()
{
	kolo.move(this->velocity);
	if (this->left() < 0)
	{
		velocity.x = ballVelocity;
	}
	else if (this->right() > 800)
	{
		velocity.x = -ballVelocity;
	}
	
	if (this->top() < 0)
	{
		velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600)
	{
		velocity.y = -ballVelocity;
	}

}
float kulka::left()
{
	return this->kolo.getPosition().x - kolo.getRadius();
}
float kulka::right()
{
	return this->kolo.getPosition().x + kolo.getRadius();
}
float kulka::top()
{
	return this->kolo.getPosition().y - kolo.getRadius();
}
float kulka::bottom()
{
	return this->kolo.getPosition().y + kolo.getRadius();
}

void kulka::movedown()
{
	this-> velocity.y = ballVelocity;
}
void kulka::moveup()
{
	this-> velocity.y = -ballVelocity;
}
void kulka::moveright()
{
	this-> velocity.x = ballVelocity;
}
void kulka::moveleft()
{
	this -> velocity.x = -ballVelocity;
}
Vector2f kulka::getPosition()
{
	return kolo.getPosition();
}