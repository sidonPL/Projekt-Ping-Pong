#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "kulka.h"
#include "paletka1.h"
#include "paletka2.h"
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace sf;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right()
		&& A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisionTest(paletka1& paletka1, kulka& kulka)
{
	if (!isIntersecting(paletka1, kulka)) return false;

	kulka.moveright();
	if (kulka.getPosition().y < paletka1.getPosition().y)
	{
		kulka.moveup();
	}
	else if (kulka.getPosition().y > paletka1.getPosition().y)
	{
		kulka.movedown();
	}
}

bool collisionTest(paletka2& paletka2, kulka& kulka)
{
	if (!isIntersecting(paletka2, kulka)) return false;

	kulka.moveleft();
	if (kulka.getPosition().y < paletka2.getPosition().y)
	{
		kulka.moveup();
	}
	else if (kulka.getPosition().y > paletka2.getPosition().y)
	{
		kulka.movedown();
	}
}


int main()
{
	kulka kulka(400, 300);
	paletka1 paletka1(40, 300);
	paletka2 paletka2(760, 300);
	RenderWindow window{ VideoMode{800,600},"Ping Pong" };
	window.setFramerateLimit(60);
	Event event;
	Music music;

	if (!music.openFromFile("music.ogg"))
	{
		cout << "ERROR" << endl;
	}

	music.play();
	while (true)
	{
		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		
		kulka.update();
		paletka1.update();
		paletka2.update();
		collisionTest(paletka1, kulka);
		collisionTest(paletka2, kulka);
		window.draw(paletka1);
		window.draw(paletka2);
		window.draw(kulka);
		window.display();
	}
	return 69;
}