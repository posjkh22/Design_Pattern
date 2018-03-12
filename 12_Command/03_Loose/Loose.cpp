
#include <iostream>

using namespace std;

class Receiver
{
public:
	virtual void execution() = 0;
};

class FileCreate : public Receiver
{
public:
	virtual void execution() override { cout << "FileCreate" << endl; }

};

class FileSave : public Receiver
{
public:
	virtual void execution() override { cout << "FileSave" << endl; }

};

class FileClose : public Receiver
{
public:
	virtual void execution() override { cout << "FileClose" << endl; }

};

class Command
{
public:
	Command(Receiver* receiver) : pReceiver(receiver){}
	~Command(){ if(pReceiver) delete pReceiver; }

public:
	void execution(){ pReceiver->execution(); }

private:
	Receiver* pReceiver;
};



int main()
{

	Command pCommand1(new FileCreate());
	Command pCommand2(new FileSave());
	Command pCommand3(new FileClose());

	pCommand1.execution();
	pCommand2.execution();
	pCommand3.execution();

	return 0;

}





