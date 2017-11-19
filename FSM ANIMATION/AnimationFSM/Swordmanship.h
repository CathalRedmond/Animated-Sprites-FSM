#ifndef SWORDMANSHIP_H
#define SWORDMANSHIP_H

#include <State.h>
class Swordmanship : public State
{
public:
	Swordmanship() {};
	~Swordmanship() {};
	void jumping(Animation* a);
	void idle(Animation* a);
	void shovelling(Animation* a);
	void walking(Animation* a);
	void hammering(Animation* a);
	void climbing(Animation* a);
};

#endif // !SWORDMANSHIP_H
