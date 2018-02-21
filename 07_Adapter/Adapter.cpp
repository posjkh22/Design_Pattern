
#include <iostream>

using namespace std;

class Adaptee
{
public:
	void adaptedOperation(){ cout << "Adpated OPeration()" << endl; }

};

class Adapter
{
public:
	virtual void operation() = 0;
};

class ConcreteAdapterA : public Adapter
{
public:
	void operation() override { pAdaptee.adaptedOperation(); }

private:
	Adaptee pAdaptee;
};

class ConcreteAdapterB : public Adapter, public Adaptee
{
public:
	void operation() override { adaptedOperation(); }
};

int main(){

	ConcreteAdapterA mObjectAdapter;
	mObjectAdapter.operation();

	ConcreteAdapterB mClassAdapter;
	mClassAdapter.operation();

	return 0;


}
