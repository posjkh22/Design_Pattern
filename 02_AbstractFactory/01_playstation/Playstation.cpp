
#include <iostream>
#include "Playstation.h"

using namespace std;

int Playstation::GetVersion()
{
	return this->version;
}

int Playstation::SetVersion(int version)
{
	this->version = version;
}
