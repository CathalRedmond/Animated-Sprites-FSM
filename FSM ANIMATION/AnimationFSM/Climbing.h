#ifndef CLIMBING_H
#define CLIMBING_H

#include <State.h>

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
	void jumping(Animation* a);
	void hammering(Animation* a);
	void shovelling(Animation* a);
	void walking(Animation* a);
	void swordmanship(Animation* a);
};

#endif // !IDLE_H