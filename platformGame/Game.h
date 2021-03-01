// platform game
// Author :Noel O' Hara
// Extra Code: Izabela Zelek 
// Robot Animation: Stephen Hurley
// Coins Animations: Rauls Bergs
//Link: https://instituteoftechnol663-my.sharepoint.com/:v:/g/personal/c00247865_itcarlow_ie/ETTFY8tC4AhBvVlpaJAAtgEBsAP_AF4om9dFaxYXrbspDg?e=wI9KHc
#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Player.h"
#include "Coin.h"
#include <string>

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

	bool gameOver = false;

	Player player;
	sf::Texture playerTextureSheet;
	sf::Sprite playerSpriteSheet;


	Coin m_coin;
	sf::Texture m_coinTexture;
	sf::Sprite m_coinSprite;
	sf::Vector2i m_coinPositions[6];
	int coinIndex = 0;

	sf::Text Score;
	int scoreValue = 0;
	sf::Font arial;

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
	{ 0,0,0,0,0,0,5,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0 },
	{ 0,0,5,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,5,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,5,1,0,0,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,5,1,1,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0 },
	{ 0,0,5,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

	sf::RectangleShape level[numRows][numCols];

	Game() : player(playerSpriteSheet), m_coin(m_coinSprite)
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

		if (!m_coinTexture.loadFromFile("MonedaR.png"));
		{
			m_coinSprite.setTexture(m_coinTexture);
			m_coinSprite.setScale(3, 3);
			m_coin.InitAnimationData();
		}

		if (!arial.loadFromFile("arial.ttf"))
		{
		}

		player.startAnimaton(Player::PlayerAnimationState::walk);
		m_coin.startAnimaton(Coin::CoinAnimationState::rotate);

		Score.setFont(arial);
		Score.setFillColor(sf::Color::White);
		Score.setOutlineColor(sf::Color::Yellow);
		Score.setCharacterSize(16U);
		Score.setLetterSpacing(1.6);
		Score.setString("Score : ");
		Score.setPosition(sf::Vector2f(20.0f, 20.0f));

		scoreValue = 0;

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
				if (levelData[row][col] == 5)
				{
					m_coinPositions[coinIndex] = { (row * 70) + 10, (col * 30) - 20 };
					coinIndex++;

					if (coinIndex > 5)
					{
						coinIndex = 0;
					}
				}
			}

		}

	}
	void run()
	{
		sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

		sf::Time timeSinceLastUpdate = sf::Time::Zero;

		sf::Clock clock;

		int coinsAliveCounter = 0;

		Score.setFillColor(sf::Color::White);
		Score.setOutlineColor(sf::Color::Yellow);
		Score.setCharacterSize(16U);
		Score.setLetterSpacing(1.6);
		Score.setString("Score : ");
		Score.setPosition(sf::Vector2f(20.0f, 20.0f));

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
						level[row][col].move(-3, 0);
						if (levelData[row][col] == 5)
						{
							m_coinPositions[coinIndex] = { m_coinPositions[coinIndex].x - 3,
														   m_coinPositions[coinIndex].y };
							coinIndex++;
							if (coinIndex > 5)
							{
								coinIndex = 0;
							}
						}
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
									else
									{
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
						if (levelData[row][col] == 5)
						{
							if (playerSpriteSheet.getGlobalBounds().contains(sf::Vector2f{ m_coinPositions[coinsAliveCounter] }))
							{
								scoreValue++;
								m_coinPositions[coinsAliveCounter] = { 9000 , 9000 };
								coinsAliveCounter++;
							}
						}
					}
				}

				if (playerSpriteSheet.getPosition().y > 600)
				{
					init();
				}

				if (gameOver == false)
				{
					player.Update();

					m_coin.Update();

					window.clear();

					for (int row = 0; row < numRows; row++)
					{
						for (int col = 0; col < numCols; col++)
						{
							window.draw(level[row][col]);
						}
					}

					for (int i = 0; i < 6; i++)
					{
						m_coinSprite.setPosition(sf::Vector2f{ m_coinPositions[i] });
						m_coin.Draw(window);
					}

					player.Draw(window);
					if (scoreValue < 6)
					{
						Score.setString("Score:  " + std::to_string(scoreValue));
					}
					else if (scoreValue == 6) {

						Score.setString("You collected all the coins!!!");
					}

					window.draw(Score);

					window.display();

					timeSinceLastUpdate = sf::Time::Zero;
				}
			}
		}
	}
};
