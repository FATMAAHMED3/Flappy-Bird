#include<iostream>
#include <SFML/Graphics.hpp> 
#include<SFML\Audio.hpp>
using namespace std;
using namespace sf;
int main()
{
	int x = 0;
	Texture ground;
	Sprite Ground;
	ground.loadFromFile("ground.JPG");
	Ground.setTexture(ground);
	Ground.setTextureRect(IntRect(0, 0, 850, 478));
	Ground.setScale(2,2.7);
	Texture menu;
	menu.loadFromFile("menu.JPG");
	Sprite Menu;
	Menu.setTexture(menu);
	RenderWindow window(VideoMode(1050,1280), "flappy bird");
	Texture flappy;
	flappy.loadFromFile("flappy.PNG");
	Sprite bird;
	bird.setTexture(flappy);
	bird.setTextureRect(IntRect(x*150, x*104, 150, 104));  //setTextureRect(IntRect(index x,index y,width ,height) 
	bird.setPosition(350,590);
	bird.scale(0.5, 0.5);
	int cnt = 0;
	Texture CONT;
	CONT.loadFromFile("continue.jpg");
	Sprite conti;
	conti.setTexture(CONT);
	conti.setPosition(230,400);
	Texture toppipetexture, bottompipetexture;
	toppipetexture.loadFromFile("toppipetexture.jpg");
	Sprite toppipe;
	bottompipetexture.loadFromFile(" bottompipetexture.jpg");
	Sprite downpipe;
	int miniheight = 100;
	int maxheight = 398;
	int pipheight = (100 + rand() % 399);
	downpipe.setPosition(0, toppipe.getPosition().y + 250);
	toppipe.setTextureRect(IntRect(0, 0, 102, 398));
	Texture s;
	Sprite stop;
	s.loadFromFile("stop.JPG");
	stop.setTexture(s);
	//game loop
	while (window.isOpen())
	{	
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)

				window.close();
		}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousePos = Mouse::getPosition(window);
				if (mousePos.x > 384 && mousePos.x < 761 && mousePos.y > 507 && mousePos.y < 722)
				{
					cnt = 1;
				}
				else if (mousePos.x > 384 && mousePos.x < 761 && mousePos.y > 507 && mousePos.y < 722)
					
				window.close();
			}
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i mousePos = Mouse::getPosition(window);
					if (mousePos.x < 115 && mousePos.x>0 && mousePos.y > 0 && mousePos.y < 69)
					{
						cnt=2;
					}
					
				}
				if (Keyboard::isKeyPressed(Keyboard::Enter))
				{

					cnt = 1;
				}

		if ((Keyboard::isKeyPressed(Keyboard::Space)|| Mouse::isButtonPressed(Mouse::Left) )&&  bird.getPosition().y>-9)
		{
			bird.move(0, -0.4);
			x++;
			x %= 3; //update x x=1 ,2 only  1%2=1
			bird.setTextureRect(IntRect(x * 150, 0 * 104, 150,104));
		}
		if (Ground.getPosition().y > 0)
		{
			Ground.setTextureRect(IntRect(x * 850, 0, 850, 478));
				x++;
				x %= 3;
		}
		window.clear();
		if (cnt == 0)
			window.draw(Menu);
		else if (cnt == 1)
		{
			window.draw(Ground);
			window.draw(bird);
			window.draw(toppipe);
			window.draw(downpipe);
			window.draw(stop);
		}
		else if (cnt == 2)
		{
			
			window.draw(Ground);
			window.draw(bird);
			window.draw(toppipe);
			window.draw(downpipe);
			window.draw(conti);
		}
		window.display(); 
	}
	return 0;
}