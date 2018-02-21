
#include "Playstation.h"
#include "PlaystationStore.h"

Playstation* PlaystationStore::CreatePlayStation(int version)
{
	Playstation* playstation = nullptr;
	return playstation;
}

Playstation* PlaystationStore::OrderPlayStation(int version)
{
	Playstation* playstation = CreatePlayStation(version)
	return playstation;
}

Playstation* PlaystationStore1::CreatePlayStation(int version)
{
	Playstation* palystation = nullptr;

	if(version == 2) playstation = new Playstation2();
	else if(version == 4) playstation = new Playstation4();

	playstation->SetVersion(version);

	return playstation;
}

Playstation* PlaystationStore2::CreatePlayStation(int version)
{

	Playstation* playstation = nullptr;

	if(version == 1) playstation = new Playstation1();
	else if(version == 3) playstation = new Playstation3();

	playstation->SetVersion(version);

	return playstation;
}
