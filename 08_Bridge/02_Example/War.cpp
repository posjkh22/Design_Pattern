
#include <iostream>

using namespace std;

class Weapon
{
public:
	virtual void attack() = 0;

};

class FireGun : public Weapon
{
public:
	void attack(){ cout << "FireGun attack!" << endl; }

};

class Gun : public Weapon
{
public:
	void attack(){ cout << "Gun attack!" << endl; }

};

class Unit
{
public:
	virtual void attack() = 0;
};


class Marine : public Unit
{
public:
	Marine(Weapon* i): mWeapon(i){}

public:
	void attack(){ cout << "[Marine]"; mWeapon->attack(); }

private:
	Weapon* mWeapon;
};

class FireBat : public Unit
{
public:
	FireBat(Weapon* i): mWeapon(i){}

public:
	void attack(){ cout << "[FireBat]"; mWeapon->attack(); }

private:
	Weapon* mWeapon;
};


int main(){

	Gun mGun;
	FireGun mFireGun;

	Marine mMarine(&mGun);
	FireBat mFireBat(&mFireGun);

	mMarine.attack();
	mFireBat.attack();

	return 0;
}
