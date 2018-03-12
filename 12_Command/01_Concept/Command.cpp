
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
	virtual void execution() = 0;

};

class FileCreateCommand : public Command 
{
public:
	void registerReceiver(Receiver* r){ pReceiver = r; }
	void execution(){ pReceiver->execution(); }

private:	
	Receiver* pReceiver;
};

class FileSaveCommand : public Command
{
public:
	void registerReceiver(Receiver* r){ pReceiver = r; }
	void execution(){ pReceiver->execution(); }

private:
	Receiver* pReceiver;
};

class FileCloseCommand : public Command
{
public:
	void registerReceiver(Receiver* r){ pReceiver = r; }
	void execution(){ pReceiver->execution(); }

private:
	Receiver* pReceiver;
};

class Processor
{
public:
	void registerCommand(Command* pCmd){ pCommand = pCmd; }
	void executionCommand(){ pCommand->execution(); }

private:
	Command* pCommand;
};



int main()
{
	Processor pProcessor;
	FileCreate pFileNew;
	FileCreateCommand pCommand;
	
	pCommand.registerReceiver(&pFileNew);
	pProcessor.registerCommand(&pCommand);
	pProcessor.executionCommand();
}




