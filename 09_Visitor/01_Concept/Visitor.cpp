
#include <iostream>

using namespace std;

class Element;

class Visitor
{

public:
	virtual void visitElementA(Element* e) = 0;
	virtual void visitElementB(Element* e) = 0;
};

class Element
{

public:
	virtual void accept(Visitor* v) = 0;

};

class ConcreteElementA : public Element
{
public:
	void accept(Visitor* v) override { v->visitElementA(this); }
};

class ConcreteElementB : public Element
{
public:
	void accept(Visitor* v) override { v->visitElementB(this); }
};

class ConcreteVisitor : public Visitor
{

public:
	void visitElementA(Element* e) { cout << "visitElementA" << endl; }
	void visitElementB(Element* e) { cout << "visitElementB" << endl; }

};

int main(){

	ConcreteElementA mConcreteElementA;
	ConcreteElementB mConcreteElementB;

	ConcreteVisitor mConcreteVisitor;

	mConcreteElementA.accept(&mConcreteVisitor);
	mConcreteElementB.accept(&mConcreteVisitor);

	return 0;
}

