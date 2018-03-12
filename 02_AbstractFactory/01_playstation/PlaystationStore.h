
#pragma once

class PlaystationStore
{

private:
	virtual Playstation* CreatePlayStation(int version);
public:
	Playstation* OrderPlayStation(int version);

};

class PlaystationStore1 : public PlaystationStore
{
private:
	Playstation* CreatePlayStation(int version);
};

class PlaystationStore2 : public PlaystationStore
{
private:
	Playstation* CreatePlayStation(int version);
};


