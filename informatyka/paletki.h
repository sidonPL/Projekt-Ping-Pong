#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class paletka1 : public Drawable 
{
public:
	paletka1(float t_X, float t_Y);
	paletka1() = delete;
	~paletka1() = default;
	void update();
	float left();
	float right();
	float top();
	float bottom();
	Vector2f getPosition();
private:
	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape prostokat;
	const float paddleWidth{ 20.0f };
	const float paddleHeight{ 80.0f };
	const float paddleVelocity{ 6.0f };
	Vector2f velocity{ paddleVelocity, 0.f };

};

