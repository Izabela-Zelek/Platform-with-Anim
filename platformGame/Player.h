#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:

	enum  class PlayerAnimationState { walk, run, jump, idle };

	PlayerAnimationState animationState = PlayerAnimationState::walk;
	Animation animations[4];
	AnimationSheet animSheet;
	sf::Vector2f position;
	sf::Sprite& spriteSheet;

	Player(sf::Sprite& spheet) : spriteSheet(spheet)
	{

	}

	void InitAnimationData()
	{

		animations[int(PlayerAnimationState::walk)] = { 8, 36,10,true };
		animations[int(PlayerAnimationState::run)] = { 3,25,10,true };
		animations[int(PlayerAnimationState::jump)] = { 4,0,15,false };
		animations[int(PlayerAnimationState::idle)] = { 3,21,80,true };
		animationState = PlayerAnimationState::walk;

		animSheet.Init(spriteSheet.getGlobalBounds().width, spriteSheet.getGlobalBounds().height, 5, 9);
	}
	void startAnimaton(PlayerAnimationState _animationState)
	{
		animationState = _animationState;
		animSheet.StartAnimation(animations[int(animationState)]);
	}

	void Draw(sf::RenderWindow& win)
	{
		animSheet.nextFrame();
		spriteSheet.setTextureRect(animSheet.GetFrame());
		win.draw(spriteSheet);
	}

	void Update()
	{
		if (animationState == PlayerAnimationState::walk)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				animationState = PlayerAnimationState::jump;
				startAnimaton(animationState);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				animationState = PlayerAnimationState::run;
				startAnimaton(animationState);
			}

		}
		else if (animationState == PlayerAnimationState::run)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				animationState = PlayerAnimationState::jump;
				startAnimaton(animationState);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				animationState = PlayerAnimationState::walk;
				startAnimaton(animationState);
			}

		}
		else if (animationState == PlayerAnimationState::jump)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				animationState = PlayerAnimationState::walk;
				startAnimaton(animationState);
			}
		}
		else if (animationState == PlayerAnimationState::idle)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				animationState = PlayerAnimationState::walk;
				startAnimaton(animationState);
			}
		}
	}
};