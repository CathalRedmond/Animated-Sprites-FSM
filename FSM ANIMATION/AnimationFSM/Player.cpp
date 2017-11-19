#include <iostream>
#include <Player.h>
#include <Idle.h>
#include <Debug.h>

Player::Player()
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}



Player::Player(const AnimatedSprite& s) : m_animated_sprite(s)
{
	m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());
}

Player::~Player() {}

AnimatedSprite& Player::getAnimatedSprite()
{
	int frame = m_animated_sprite.getCurrentFrame();
	m_animated_sprite.setTextureRect(m_animated_sprite.getFrame(frame));
	return m_animated_sprite;
}

void Player::handleInput(Input in)
{
	DEBUG_MSG("Handle Input");

	
		switch (in.getCurrent())
		{
		case Input::Action::IDLING_7:
			//std::cout << "Player Idling" << std::endl;
			m_animation.idle();
			break;
		case Input::Action::JUMPING_3:
			//std::cout << "Player Up" << std::endl;
			m_animation.jumping();
			break;
		case Input::Action::CLIMBING_1:
			//std::cout << "Player Left" << std::endl;
			m_animation.climbing();
			break;
		case Input::Action::WALKING_2:
			//std::cout << "Player Idling" << std::endl;
			m_animation.walking();
			break;
		case Input::Action::SHOVELLING_4:
			m_animation.shovelling();
			break;
		case Input::Action::SWORDMANSHIP_5:
			m_animation.swordmanship();
			break;
		case Input::Action::HAMMERING_6:
			m_animation.hammering();
			break;
		default:
			break;
		}
}

void Player::update()
{
	//std::cout << "Handle Update" << std::endl;
	m_animated_sprite.update();
}

void Player::update(Input i)
{
	m_animated_sprite.update(i);
}
