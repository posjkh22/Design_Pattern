
#include <iostream>

using namespace std;

class Music
{
public:
	~Music(){};
	
public:
	void virtual Sound() = 0;

};

class Piano : public Music
{
public:
	void Sound() override;		

};

class Violin : public Music
{
public:
	void Sound() override;		

};

class Flute : public Music
{
public:
	void Sound() override;		

};

