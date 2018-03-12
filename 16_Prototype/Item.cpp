
#include <iostream>

using namespace std;

class ItemInterface
{
public:
	virtual ItemInterface* clone() = 0;
};

class Shield : public ItemInterface
{
public:
	Shield(){}
	Shield(const Shield& c){}
	ItemInterface* clone() override { return new Shield(*this); }

};

class Sword : public ItemInterface
{
	Sword(){}
	Sword(const Sword* c){}
	ItemInterface* clone() override { return new Sword(*this); }

};


int main()
{
	ItemInterface* pShield = new Shield();
	ItemInterface* pClone = pShield->clone();

	delete pClone;
	delete pShield;

	return 0;

}
