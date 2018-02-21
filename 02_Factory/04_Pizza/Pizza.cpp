
#include <iostream>

using namespace std;

class Pizza
{
public:
	int size;
};

class LargePizza : public Pizza
{
public:
	LargePizza()
	{
		cout << "Large Pizza! " << endl;
	}
};

class MediumPizza : public Pizza
{
public:
	MediumPizza()
	{
		cout << "Medium Pizza! " << endl;
	}
};

class SmallPizza : public Pizza
{
public:
	SmallPizza()
	{
		cout << "Small Pizza! " << endl;
	}
};



class PizzaStore
{
private:
	virtual Pizza* createPizza(int size);

};

class NYPizzaStore : public PizzaStore
{
public:
	Pizza* createPizza(int size);
};

class CHIPizzaStore : public PizzaStore
{
public:
	Pizza* createPizza(int size);
};

Pizza* PizzaStore::createPizza(int size)
{
	Pizza *pizza = NULL;
	return pizza;
}

Pizza* NYPizzaStore::createPizza(int size)
{
	Pizza* pizza = NULL;
	if(size == 1){
		pizza = new SmallPizza();
	}
	else if(size == 2){
		pizza = new MediumPizza();
	}
	else if(size == 3){
		pizza = new LargePizza();
	}

	else {


	}
	
	cout << "Create Pizza: " << size << endl;

	return pizza;
}

Pizza* CHIPizzaStore::createPizza(int size)
{
	Pizza* pizza = NULL;
	if(size == 1){
		pizza = new SmallPizza;
	}
	else if(size == 2){
		pizza = new MediumPizza;
	}
	else if(size == 3){
		pizza = new LargePizza;
	}

	else {


	}

	cout << "Create Pizza: " << size << endl;

	return pizza;
}

int main(){

	Pizza *NYPizza;
	Pizza *CHIPizza;

	NYPizzaStore nypS;
	CHIPizzaStore chipS; 
	
	NYPizza = nypS.createPizza(1);
	CHIPizza = chipS.createPizza(3);


	return 0;
}



