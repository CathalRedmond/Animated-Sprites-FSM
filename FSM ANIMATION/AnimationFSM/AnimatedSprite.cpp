#include <AnimatedSprite.h>

AnimatedSprite::AnimatedSprite() 
{
	m_current_frame = 0;
}

AnimatedSprite::AnimatedSprite(const sf::Texture& t) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {}

AnimatedSprite::AnimatedSprite(const sf::Texture& t, const sf::IntRect& rect) : Sprite(t), m_current_frame(0), m_time(seconds(0.5f)) {
	m_frames.push_back(rect);
}

AnimatedSprite::~AnimatedSprite() {}



const sf::Clock& AnimatedSprite::getClock() {
	return m_clock;
}

const sf::Time& AnimatedSprite::getTime() {
	return m_time;
}

const vector<IntRect>& AnimatedSprite::getFrames() {
	return m_frames;
}

const IntRect& AnimatedSprite::getFrame(int n) {
	return m_frames[n];
}

void AnimatedSprite::addFrame(IntRect& frame) {
	m_frames.push_back(frame);
}

const int AnimatedSprite::getCurrentFrame() {
	return m_current_frame;
}

void AnimatedSprite::update()
{
	if (m_clock.getElapsedTime() > m_time) {
		if (m_frames.size() > m_current_frame + 1)
		{
			m_current_frame++;
		}
		else 
		{
			m_current_frame = 0;
		}
		m_clock.restart();
	}
}

void AnimatedSprite::update(Input i)
{
	if (finished)
	{
		setStartEndPoints(i);
		finished = false;
	}
	if (m_clock.getElapsedTime() > m_time) 
	{
		if (endpoint > m_current_frame )
		{
			m_current_frame++;
		}
		else 
		{
			m_current_frame = startpoint;
			finished = true;
		}
		m_clock.restart();
	}

}

bool AnimatedSprite::getFinished()
{
	return &finished;
}

void AnimatedSprite::setFinished(bool bollean)
{
	finished = bollean;	
}

void AnimatedSprite::setStartEndPoints(Input i)
{
	switch (i.getCurrent())
	{
	case Input::Action::IDLING_7:
		startpoint = 0;
		endpoint = 5;
		break;
	case Input::Action::HAMMERING_6:
		startpoint = 6;
		endpoint = 11;
		break;
	case Input::Action::CLIMBING_1:
		startpoint = 12;
		endpoint = 17;
		break;
	case Input::Action::WALKING_2:
		startpoint = 18;
		endpoint = 23;
		break;
	case Input::Action::JUMPING_3:
		startpoint = 24;
		endpoint = 29;
		break;
	case Input::Action::SHOVELLING_4:
		startpoint = 30;
		endpoint = 35;
		break;
	case Input::Action::SWORDMANSHIP_5:
		startpoint = 36;
		endpoint = 41;
		break;
	default:
		startpoint = 0;
		endpoint = 5;
		break;
	}
	m_current_frame = startpoint;
}

