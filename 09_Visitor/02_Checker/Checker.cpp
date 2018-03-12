
#include <iostream>
#include <list>

using namespace std;

class Checker;

class Element
{
public:
	virtual void accept(Checker* v) = 0;	

};

class Wheel : public Element
{
public:
	void accept(Checker* v) override;

};




class Engine : public Element
{
public:
	void accept(Checker* v) override;

};


class Body : public Element
{
public:
	void accept(Checker* v) override;

};

class Car : public Element
{

public:
	void append(Element* e){ mList.push_back(e); }
	void accept(Checker* e) override;

private:
	list<Element* > mList;
};


class Checker
{
public:
	virtual void checker(Wheel* e) = 0;
	virtual void checker(Engine* e) = 0;
	virtual void checker(Body* e) = 0;
	virtual void checker(Car* e) = 0;
};

class CarPrintChecker : public Checker
{

public:
	void checker(Wheel* e) override { cout << "Wheel is checked!" << endl; } 
	void checker(Engine* e) override { cout << "Engine is checked!" << endl; } 
	void checker(Body* e) override { cout << "Body is checked!" << endl; } 
	void checker(Car* e) override { cout << "Car is checked!" << endl; } 

};


void Wheel::accept(Checker* v){ v->checker(this); }
void Engine::accept(Checker* v){ v->checker(this); }
void Body::accept(Checker* v){ v->checker(this); }
void Car::accept(Checker* v)
{ 	
	for(auto i = mList.begin(); i != mList.end(); ++i){
	
		(*i)->accept(v);
		//v->checker(this);
	}
}


int main(){

	Wheel mWheel;
	Engine mEngine;
	Body mBody;
	Car mCar;
	
	mCar.append(&mWheel);
	mCar.append(&mEngine);
	mCar.append(&mBody);

	CarPrintChecker mCarPrintChecker;
	mCar.accept(&mCarPrintChecker);

	return 0;
}






