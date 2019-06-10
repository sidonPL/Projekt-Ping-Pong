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

int score1 = 0;
int score2 = 0;

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
void wynik(kulka& kolo)
{
	if (kolo.getPosition().x < 20) 
	{
		score1++;
	}
	if (kolo.getPosition().x > 780)
	{
		score2++;
	}
}

void intro()
{
	RenderWindow window{ VideoMode{800,600},"Ping Pong" };
	window.setFramerateLimit(60);
	Event event;
	Music music;

	Texture BackgroundTexture;
	Sprite background;

	//background.setScale(0.2, 0.2); <--- how?

	if (!BackgroundTexture.loadFromFile("intro.png"))
	{
		return;
	}
	else
	{
		background.setTexture(BackgroundTexture);
	}

	if (!music.openFromFile("intro.ogg"))
	{
		cout << "ERROR" << endl;
	}

	music.play();
	while (true)
	{
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.clear();
		window.draw(background);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
		{
			window.close();
			break;
		}
	}
}

void gra()
{
	kulka kulka(400, 300);
	paletka1 paletka1(40, 300);
	paletka2 paletka2(760, 300);
	RenderWindow window{ VideoMode{800,600},"Ping Pong" };
	window.setFramerateLimit(60);
	Text wynik1;
	Text wynik2;
	Font arial;
	arial.loadFromFile("arial.ttf");
	wynik1.setFont(arial);
	wynik1.setCharacterSize(30);
	wynik1.setFillColor(Color::White);
	wynik1.setPosition(200, 0);
	wynik2.setFont(arial);
	wynik2.setCharacterSize(30);
	wynik2.setFillColor(Color::White);
	wynik2.setPosition(600, 0);
	Event event;
	Music music;

	Texture BackgroundTexture;
	Sprite background;

	//background.setScale(0.2, 0.2); <--- how?

	if (!BackgroundTexture.loadFromFile("tlo.jpg"))
	{
		return;
	}
	else
	{
		background.setTexture(BackgroundTexture);
	}

	if (!music.openFromFile("music.ogg"))
	{
		cout << "ERROR" << endl;
	}

	music.play();
	while (true)
	{
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.clear();
		window.draw(background);
		kulka.update();
		paletka1.update();
		paletka2.update();
		collisionTest(paletka1, kulka);
		collisionTest(paletka2, kulka);
		wynik(kulka);
		window.draw(paletka1);
		window.draw(paletka2);
		window.draw(kulka);
		window.draw(wynik1);
		window.draw(wynik2);
		window.display();
		wynik1.setString(std::to_string(score1));
		wynik2.setString(std::to_string(score2));
	}
}

int main()
{
	intro();
	gra();

}