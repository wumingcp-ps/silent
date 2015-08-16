#include <afxwin.h>
#include "sound.h"


Csound::Csound()
	: _original(0.f), _precent(0.f){
}

Csound::Csound(const float precent)
	: _original(0.f), _precent(precent){
}

inline void Csound::setSound(const float volume){
	_original = _precent;
	_precent = volume;
}

inline void Csound::keepSilent(){
	_original = _precent;
	_precent = 0;
}

inline float Csound::getVolume(){
	return _precent;
}

inline void Csound::restore(){
	_precent = _original;
}