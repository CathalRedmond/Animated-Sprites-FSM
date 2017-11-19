#ifndef INPUT_H
#define INPUT_H
#include <iostream>
class Input
{
public:
	Input();
	~Input();

	enum Action
	{
		IDLING_7,
		JUMPING_3,
		CLIMBING_1,
		WALKING_2,
		SHOVELLING_4,
		SWORDMANSHIP_5,
		HAMMERING_6
	};

	void setCurrent(Action);
	Action getCurrent();
	std::string outputCurrent();


private:
	Action m_current;

};
#endif