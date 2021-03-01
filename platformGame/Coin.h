#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Coin
{
public:

	enum  class CoinAnimationState { rotate };

	CoinAnimationState animationState = CoinAnimationState::rotate;
	Animation animations[1];
	AnimationSheet animationSheet;
	sf::Vector2f position;
	sf::Sprite& spriteSheet;
	bool alive;

	Coin(sf::Sprite& spheet) : spriteSheet(spheet)
	{

	}

	void InitAnimationData()
	{
		animations[int(CoinAnimationState::rotate)] = { 5, 0,20, true };
		animationState = CoinAnimationState::rotate;

		animationSheet.Init(80, 16, 1, 5);

		alive = true;
	}
	void startAnimaton(CoinAnimationState _animationState)
	{
		animationState = _animationState;
		animationSheet.StartAnimation(animations[int(animationState)]);
	}

	void Draw(sf::RenderWindow& win)
	{
		animationSheet.nextFrame();
		spriteSheet.setTextureRect(animationSheet.GetFrame());
		win.draw(spriteSheet);
	}

	void Update()
	{
		if (animationState == CoinAnimationState::rotate)
		{
			coinMove();
		}
	}

	void coinMove() {
		spriteSheet.setPosition(spriteSheet.getPosition().x - 3.7, spriteSheet.getPosition().y);
	}
};