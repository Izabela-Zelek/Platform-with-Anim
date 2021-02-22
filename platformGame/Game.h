// platform game.....
// Author :Noel O' Hara
// Extra Code: Izabela Zelek & Mati Kutt
// Robot Animation: Stephen Hurley
//Link: https://instituteoftechnol663-my.sharepoint.com/:v:/g/personal/c00247865_itcarlow_ie/ETTFY8tC4AhBvVlpaJAAtgEBsAP_AF4om9dFaxYXrbspDg?e=wI9KHc
#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Player.h"

class Game
{
public:
	//create Window
	sf::RenderWindow window;
	sf::View view;
	float randomNum;
	float timeChange = 0;

	//sf::RectangleShape playerShape;
	int pixelsPerMeter = 80;

	sf::Vector2f velocity{ 0,0 };
	sf::Vector2f gravity{ 0,12 };
	sf::Vector2f jumpPushOff{ 0,6 * pixelsPerMeter };

	Player player;
	sf::Texture playerTextureSheet;
	sf::Sprite playerSpriteSheet;


	bool textureInit = false;


	static const int numRows = 45;
	static const int numCols = 20;
	int levelData[numRows][numCols] =
	{
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,2 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,2,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,3,0,0,1,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0 },
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0 },
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

	sf::RectangleShape level[numRows][numCols];

	Game() : player(playerSpriteSheet)
	{
		window.create(sf::VideoMode(800, 600), "Endless Runner Game");
	}

	void jumpBlock()
	{
		velocity.y += (-jumpPushOff.y * 2) * timeChange;
	}

	void init()
	{
		view = window.getDefaultView();
		//playerShape.setSize(sf::Vector2f(20, 20));
		//playerShape.setPosition(160, 500);

		if (textureInit == false)
		{
			if (!playerTextureSheet.loadFromFile("character_robot_sheet.png"))
			{
				// error...
			}

			textureInit = true;
			playerSpriteSheet.setTexture(playerTextureSheet);
			player.InitAnimationData();
		}

		player.startAnimaton(Player::PlayerAnimationState::walk);

		for (int row = 0; row < numRows; row++)
		{
			for (int col = 0; col < numCols; col++)
			{

				if (levelData[row][col] == 1)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);
					level[row][col].setFillColor(sf::Color::Red);
				}
				if (levelData[row][col] == 0)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);
					level[row][col].setFillColor(sf::Color::Black);
				}
				if (levelData[row][col] == 2)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);
					level[row][col].setFillColor(sf::Color::Blue);
				}
				if (levelData[row][col] == 3)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);
					level[row][col].setFillColor(sf::Color::Green);
				}
				if (levelData[row][col] == 4)
				{
					level[row][col].setSize(sf::Vector2f(70, 30));
					level[row][col].setPosition(row * 70, col * 30);
					level[row][col].setFillColor(sf::Color::Magenta);

				}
			}

		}

	}
	void run()
	{
		sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

		sf::Time timeSinceLastUpdate = sf::Time::Zero;

		sf::Clock clock;

		clock.restart();

		while (window.isOpen())
		{

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}


			timeSinceLastUpdate += clock.restart();


			if (timeSinceLastUpdate > timePerFrame)
			{
				timeChange = (float)timeSinceLastUpdate.asSeconds();
				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						level[row][col].move(-3.7, 0);
					}

				}


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && velocity.y == 0)
				{
					velocity.y += -jumpPushOff.y * timeChange;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false)
				{
					velocity.y = velocity.y + gravity.y * timeChange;
				}

				gravity = sf::Vector2f(0, 12);

				velocity.y = velocity.y + gravity.y * timeChange;

				playerSpriteSheet.move(0, velocity.y);

				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						if (velocity.y >= 0)
						{
							if (levelData[row][col] == 1)
							{

								if (playerSpriteSheet.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
								{
									if (player.animationState == Player::PlayerAnimationState::jump)
									{
										player.animationState = Player::PlayerAnimationState::walk;
										player.startAnimaton(player.animationState);
									}

									if (playerSpriteSheet.getPosition().y < level[row][col].getPosition().y)
									{
										gravity.y = 0;
										velocity.y = 0;
										playerSpriteSheet.setPosition(playerSpriteSheet.getPosition().x, level[row][col].getPosition().y);
										playerSpriteSheet.move(0, -playerSpriteSheet.getGlobalBounds().height);
										break;
									}
									else {
										init();
									}
								}


							}

						}
						if (velocity.y < 0)
						{

							if (levelData[row][col] == 1)
							{
								if (playerSpriteSheet.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
								{
									init();
								}

							}

						}
						if (levelData[row][col] == 2)
						{
							if (playerSpriteSheet.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
							{
								init();
							}
						}
						if (levelData[row][col] == 3)
						{
							if (playerSpriteSheet.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
							{
								jumpBlock();
							}
						}
						if (levelData[row][col] == 4)
						{
							if (playerSpriteSheet.getGlobalBounds().intersects(level[row][col].getGlobalBounds()))
							{
								window.close();
							}
						}
					}
				}

				if (playerSpriteSheet.getPosition().y > 600)
				{
					init();
				}

				player.Update();

				window.clear();

				for (int row = 0; row < numRows; row++)
				{
					for (int col = 0; col < numCols; col++)
					{
						window.draw(level[row][col]);

					}
				}

				//window.draw(playerShape);

				player.Draw(window);

				window.display();

				timeSinceLastUpdate = sf::Time::Zero;
			}
		}
	}
};
