#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\System\Clock.hpp>
#include <vector>
#include <Debug.h>
#include <Input.h>

using namespace std;
using namespace sf;

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(const Texture&);
	AnimatedSprite(const Texture&, const IntRect&);
	~AnimatedSprite();


	const Clock& getClock();
	const Time& getTime();
	const vector<IntRect>& getFrames();
	const IntRect& getFrame(int);
	void addFrame(IntRect&);
	const int getCurrentFrame();
	void update();
	void update(Input);
	bool getFinished();
	void setFinished(bool);
	
private:
	Clock m_clock;
	Time m_time;
	vector<IntRect> m_frames;
	int m_current_frame;
	int startpoint = 0;
	int endpoint = 0;
	void setStartEndPoints(Input);
	// bool if sprites animation is completed
	bool finished{false};
};

#endif // !ANIMATED_SPRITE_H
