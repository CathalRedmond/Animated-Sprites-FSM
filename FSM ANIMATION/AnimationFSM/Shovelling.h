#ifndef SHOVELLING_H
#define SHOVELLING_H

#include <State.h>
class Shovelling : public State
{
public:
	Shovelling() {};
	~Shovelling() {};
	void jumping(Animation* a);
	void idle(Animation* a);
	void hammering(Animation* a);
	void walking(Animation* a);
	void swordmanship(Animation* a);
	void climbing(Animation* a);
};

#endif // !SHOVELLING_H
