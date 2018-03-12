
#include <iostream>

using namespace std;

class StateInterface
{

public:
	virtual void process() = 0;

};

class Move : public StateInterface
{	
public:
	void process() override { cout << "Move" << endl; }

};

class Attack : public StateInterface
{
public:
	void process() override { cout << "Attack" << endl; }

};

class Get : public StateInterface
{
public:
	void process() override { cout << "Get" << endl; }
};

class Monster
{
public:
	Monster(StateInterface* state) : pState(state) {}
	~Monster(){ if(pState) delete pState; }
	
public:
	void ChangeState(StateInterface* state){ if(pState) delete pState; pState = state; }
	void process(){ pState->process(); }

private:
	StateInterface* pState;
};

int main()
{
	Monster* pMonster = new Monster(new Move());
	pMonster->process();

	pMonster->ChangeState(new Attack());
	pMonster->process();

	pMonster->ChangeState(new Get());
	pMonster->process();

	delete pMonster;

	return 0;

}
