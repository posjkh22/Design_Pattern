
#include <iostream>

using namespace std;

class ICoffeeComponent
{
public:
	virtual int GetCost() = 0;
	virtual string GetIngredients() = 0;
};

class Coffee : public ICoffeeComponent
{
public:
	int GetCost(){ return 1000; }
	string GetIngredients(){ return string("coffee"); }

};

class CoffeeDecorator : public ICoffeeComponent 
{
public:
	CoffeeDecorator(ICoffeeComponent* c) : pComponent(c){}
	~CoffeeDecorator(){ if(pComponent) delete pComponent; }

public:
	int GetCost(){ if(pComponent) return pComponent->GetCost(); else return 0; }
	string GetIngredients(){ if(pComponent) return pComponent->GetIngredients(); else return string(""); }

private:
	ICoffeeComponent* pComponent;
};

class MilkDecorator : public CoffeeDecorator
{
public:
	MilkDecorator(ICoffeeComponent* d) : CoffeeDecorator(d){}

public:
	int GetCost(){ return CoffeeDecorator::GetCost() + 200; }
	string GetIngredients(){ return string("Milk ") + CoffeeDecorator::GetIngredients(); } 
};

class WhipCreamDecorator : public CoffeeDecorator
{
public:
	WhipCreamDecorator(ICoffeeComponent* d) : CoffeeDecorator(d){}

public:	
	int GetCost(){ return CoffeeDecorator::GetCost() + 500; }
	string GetIngredients(){ return string("WhipCream ") + CoffeeDecorator::GetIngredients(); }

};

int main()
{

	ICoffeeComponent* pComponent = new MilkDecorator(new WhipCreamDecorator(new CoffeeDecorator(new Coffee())));
	cout << "Cost: " << pComponent->GetCost() << endl;
	cout << "Ingredients: " << pComponent->GetIngredients() << endl;

	delete pComponent;

	return 0;
}






