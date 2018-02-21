
#pragma once

class Playstation
{
public:
	int SetVersion(int version);
	int GetVersion();

private:
	int version;

};

class Playstation1 : public Playstation {};
class Playstation2 : public Playstation {};
class Playstation3 : public Playstation {};
class Playstation4 : public Playstation {};

