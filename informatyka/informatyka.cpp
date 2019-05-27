#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "kulka.h"
#include "paletki.h"
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

bool collisionTest(paletki& paletki, kulka& kulka)
{
	if (!isIntersecting(paletki, kulka)) return false;

	kulka.moveup();
	if (kulka.getPosition().x < paletki.getPosition().x)
	{
		kulka.moveleft();
	}
	else if (kulka.getPosition().x > paletki.getPosition().x)
	{
		kulka.moveright();
	}
}

int main()
{
	kulka kulka(400, 300);
	paletki paletki(400, 550);
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
		paletki.update();
		collisionTest(paletki, kulka);
		window.draw(paletki);
		window.draw(kulka);
		window.display();
	}
	return 69;
}