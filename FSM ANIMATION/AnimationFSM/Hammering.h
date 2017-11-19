#ifndef HAMMERING_H
#define HAMMERING_H

#include <State.h>
class Hammering : public State
{
public:
	Hammering() {};
	~Hammering() {};
	void jumping(Animation* a);
	void idle(Animation* a);
	void shovelling(Animation* a);
	void walking(Animation* a);
	void swordmanship(Animation* a);
	void climbing(Animation* a);
};

#endif // !HAMMERING_H
