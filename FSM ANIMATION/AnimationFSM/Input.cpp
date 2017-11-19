#include <Input.h>

Input::Input() 
{
	m_current = IDLING_7;
}
Input::~Input() {}

void Input::setCurrent(Action a) 
{
	m_current = a;
}

Input::Action Input::getCurrent() 
{
	return m_current;
}

std::string Input::outputCurrent()
{
	switch (getCurrent())
	{
	case HAMMERING_6:
		return std::string("Hammering");
		break;
	case WALKING_2:
		return std::string("Walking");
		break;
	case JUMPING_3:
		return std::string("Jumping");
		break;
	case CLIMBING_1 :
		return std::string("Climbing");
		break;
	case SWORDMANSHIP_5:
		return std::string("Swording");
		break;
	case IDLING_7:
		return std::string("Idling");
		break;
	case SHOVELLING_4:
		return std::string("Shovelling");
		break;
	}
}


