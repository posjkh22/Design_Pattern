
#include <iostream>

using namespace std;

class Implementor
{
public:
	virtual void operationImpl() = 0;	
};

class ConcreteImplementorA : public Implementor
{
public:
	void operationImpl(){ cout << "ConcreteImplementator A" << endl; }
};

class ConcreteImplementorB : public Implementor
{
public:
	void operationImpl(){ cout << "ConcreteImplementator B" << endl; }
};

class Abstraction
{
public:
	virtual void operation() = 0;

};

class ConcreteAbstraction : public Abstraction
{
public:
	ConcreteAbstraction(Implementor* i) : impl(i){}

public:
	void operation(){ impl->operationImpl(); }

private:
	Implementor* impl;
};

int main(){

	ConcreteImplementorA pConcreteImplementorA;
	ConcreteImplementorB pConcreteImplementorB;

	ConcreteAbstraction mConcreteAbstractionA(&pConcreteImplementorA);
	ConcreteAbstraction mConcreteAbstractionB(&pConcreteImplementorB);

	mConcreteAbstractionA.operation();
	mConcreteAbstractionB.operation();

	return 0;
}
