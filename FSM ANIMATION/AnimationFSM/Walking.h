#ifndef WALKING_H
#define WALKING_H

#include <State.h>
class Walking : public State
{
public:
	Walking() {};
	~Walking() {};
	void jumping(Animation* a);
	void idle(Animation* a);
	void shovelling(Animation* a);
	void hammering(Animation* a);
	void swordmanship(Animation* a);
	void climbing(Animation* a);
};

#endif // !WALKING_H
