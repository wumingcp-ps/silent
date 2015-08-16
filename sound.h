#ifndef _SOUND_H
#define _SOUND_H
#include<iostream>

class Csound{
public:
	Csound();
	Csound(const float percent);
	~Csound(){};

	void setSound(const float volume);
	void keepSilent();
	float getVolume();
	void restore();

private:
	float _precent;
	float _original;
};

#endif