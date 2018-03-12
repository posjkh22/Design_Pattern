

#ifndef SPEAKER
#define SPEAKER

#include "Music.hpp"

class Speaker
{

public:
	Speaker* getInstance();
	
protected:
	Speaker(){};

private:
	static Speaker* m_speaker;


public:
	void tuneMusic(Music*);

};


#endif
