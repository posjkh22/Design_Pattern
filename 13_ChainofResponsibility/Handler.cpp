
#include <iostream>

using namespace std;

class Handler
{
public:
	Handler(Handler* pHandle): pHandler(pHandle){}
	~Handler(){ if(pHandler) delete pHandler; }

public:
	virtual void handleRequest(int i)
	{
		if(pHandler != NULL)
			pHandler->handleRequest(i);
	}
private:
	Handler* pHandler;

};

class ConcreteHandler1 : public Handler
{
public:
	ConcreteHandler1(Handler* pHandle) : Handler(pHandle){}

public:
	void handleRequest(int i) override
	{
		if( i % 2 == 0 )
			cout << "Even number" << endl;
		else
			Handler::handleRequest(i);
	}

};

class ConcreteHandler2 : public Handler
{
public:
	ConcreteHandler2(Handler* pHandle) : Handler(pHandle){}

public:
	void handleRequest(int i) override
	{
		if(i % 2 != 0)
			cout << "Odd number" << endl;
		else
			Handler::handleRequest(i);
	}
};


int main()
{

	Handler* pHandler = new ConcreteHandler1(new ConcreteHandler2(NULL));

	cout << "value: 25" << endl;
	pHandler->handleRequest(25);
	
	cout << "value: 222" << endl;
	pHandler->handleRequest(222);

	delete pHandler;

	return 0;
}

