
#include <stack>
#include <iostream>

using namespace std;

class Memento
{
public:
	Memento(string _state){ state = _state; }
	
public:
	string getState() const { return state; }

private:
	string state;
};

class Originator
{	
public:
	void setState(string _state)
	{
		state = _state;
		cout << "Originator: Setting state to " << state << endl;
	}

public:
	void setMemento(Memento *m)
	{
		if(m)
		{
			state = m->getState();
			delete m;
			cout << "Originator: State after restoring from Memento: " << state << endl;
		}

	}

	Memento* createMemento()
	{
		cout << "Originator: Create to Memento: " << state << endl;
		return new Memento(state);
	}

private:
	string state;

};


class CareTaker
{
public:
	void pushMemento(Memento* m){ mStack.push(m); }
	Memento* popMemento(){ Memento* m = mStack.top(); mStack.pop(); return m; }

private:
	stack<Memento* > mStack;

};


int main()
{

	CareTaker mCareTaker;
	Originator* originator = new Originator();

	originator->setState("State1");
	mCareTaker.pushMemento(originator->createMemento());


	originator->setState("State2");
	mCareTaker.pushMemento(originator->createMemento());

	originator->setMemento(mCareTaker.popMemento());
	originator->setMemento(mCareTaker.popMemento());

	delete originator;

	return 0;

}
