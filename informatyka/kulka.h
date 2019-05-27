#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class kulka : public Drawable
{
public:
	kulka(float t_X, float t_Y);
	kulka() = delete;
	~kulka() = default;

	void update();
	
	void moveup();
	void movedown();
	void moveright();
	void moveleft();
	
	Vector2f getPosition();

	float left();
	float right();
	float top();
	float bottom();
private:
	CircleShape kolo;
	const float ballRadius{ 10.0f };
	const float ballVelocity{ 5.0f };
	Vector2f velocity{ ballVelocity, ballRadius };
	void draw(RenderTarget& target, RenderStates state) const override;
};

