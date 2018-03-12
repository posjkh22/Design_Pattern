
#include <iostream>
#include <list>
#include <typeinfo>

using namespace std;

class Colleague;
class Mediator
{

public:
	virtual void AppendUser(Colleague* colleague) = 0;
	virtual void RemoveUser(Colleague* colleague) = 0;
	virtual void sendMessage(const char* messeage, Colleague* sender) = 0;
};

class Colleague
{
public:
	Colleague(Mediator* m, const char* name): pMediator(m), mName(name) {}

public:
	virtual void SendMessages(const char* str) = 0;
	virtual void ReceiveMessages(const char* str) = 0;

protected:
	Mediator* pMediator;
	string mName;

};

class User : public Colleague
{

public:
	User(Mediator* m, const char* name) : Colleague(m, name){}

public:
	void SendMessages(const char* str) override
	{
		cout << mName << " send: " << str << endl;
		pMediator->sendMessage(str, this);
	}

	void ReceiveMessages(const char* str) override
	{
		cout << mName << " receive: " << str << endl;
	}
};

class ChatMediator : public Mediator
{

public:
	void AppendUser(Colleague* colleague) override
	{	
		mList.push_back(colleague);
	}

	void RemoveUser(Colleague* colleague) override
	{
		mList.remove(colleague);

	}

	void sendMessage(const char* message, Colleague* sender)
	{
		for(Colleague* object : mList)
		{
			if(object != sender)
				object->ReceiveMessages(message);

		}


	}

private:
	list<Colleague* > mList;

};

int main(){

	ChatMediator mChatMediator;
	
	User mUser1(&mChatMediator, "BOB");
	User mUser2(&mChatMediator, "SUZI");
	User mUser3(&mChatMediator, "MINA");

	mChatMediator.AppendUser(&mUser1);
	mChatMediator.AppendUser(&mUser2);
	mChatMediator.AppendUser(&mUser3);

	mUser1.SendMessages("Hello! Nice to meet you!");

	return 0;
}

