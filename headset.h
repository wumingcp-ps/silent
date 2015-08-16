#ifndef _HEADSET_H
#define _HEADSET_H

class Cheadset{
public:
	Cheadset():ishave(false){};
	~Cheadset(){};

	void setHeadset(const bool value){
		ishave = value;
	}

	bool getHeadset(){
		return ishave;
	}

private:
	bool ishave;
};
#endif