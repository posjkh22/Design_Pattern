
#include <iostream>

using namespace std;

class Subject
{
public:
	virtual void request() = 0;

};

class RealSubject : public Subject
{
public:
	void request(){ cout << "Request by RealSubject" << endl; }

};

class Proxy : public Subject
{
public:
	Proxy() : mReal(NULL){}
	~Proxy(){ if(mReal) delete mReal; }

public:
	void request()
	{
		if(!mReal)
			mReal = new RealSubject;
	
		mReal->request();
	}

private:
	RealSubject* mReal;
};

int main()
{
	Subject* pProxy = new Proxy();
	pProxy->request();
	delete pProxy;

	return 0;
}
