
#include <iostream>

using namespace std;

class AbstractProductA;
class AbstractProductB;
class ConcretProductA1;
class ConcretProductB1;
class ConcretProductA2;
class ConcretProductB2;

class AbstractFactory;
class ConcreteFactory1;
class ConcreteFactory2;


class AbstractProductA
{
public:
	virtual void print() = 0;
};

class AbstractProductB
{
public:
	virtual void print() = 0;
};

class ConcreteProductA1 : public AbstractProductA
{
public:
	void print() override { cout << "ConcretProduct A1" << endl; }

};

class ConcreteProductA2 : public AbstractProductA
{
public:
	void print() override { cout << "ConcretProduct A2" << endl; }
};


class ConcreteProductB1 : public AbstractProductB
{
public:
	void print() override { cout << "ConcretProduct B1" << endl; }

};

class ConcreteProductB2 : public AbstractProductB
{
public:
	void print() override { cout << "ConcretProduct B2" << endl; }
};


class AbstractFactory
{
public:
	virtual AbstractProductA* createProductA() = 0;
	virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
	AbstractProductA* createProductA() override { return new ConcreteProductA1; }
	AbstractProductB* createProductB() override { return new ConcreteProductB1; }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
	AbstractProductA* createProductA() override { return new ConcreteProductA2; }
	AbstractProductB* createProductB() override { return new ConcreteProductB2; }
};

int main(){

	ConcreteFactory1 pFactory1;
	ConcreteFactory2 pFactory2;

	AbstractProductA* pA1 = pFactory1.createProductA();
	pA1->print();


	AbstractProductB* pB1 = pFactory1.createProductB();
	pB1->print();
	
	AbstractProductA* pA2 = pFactory2.createProductA();
	pA1->print();

	AbstractProductB* pB2 = pFactory2.createProductB();
	pB2->print();

	delete pA1;
	delete pB1;
	delete pA2;
	delete pB2;

	return 0;

}






