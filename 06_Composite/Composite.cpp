
#include <list>
#include <iostream>

using namespace std;


class Component
{

public:

	virtual void operation() = 0;
	virtual void add(Component* c){}
	virtual void remove(Component* c){}
	virtual Component* getChild(int i){ return 0; }

};

class Leaf : public Component
{
public:

	void operation() override { cout << "Leaf operation" << endl; }
};

class Composite : public Component
{
public:
	void operation() override
	{
		for(auto it = mList.begin(); it != mList.end(); it++)
		{
			(*it)->operation();

		}
	}

	void add(Component* c) override { mList.push_back(c); }
	void remove(Component* c) override { mList.remove(c); }
	Component* getChild(int i) override
	{
		int ii = 0;
		for(auto it = mList.begin(); it != mList.end(); it++, ii++)
		{
			if(i == ii)
				return *it;
		}

		return NULL;
	}

private:
	list<Component* > mList;
};


int main(){

	Leaf LeafA;
	Leaf LeafB;

	Composite mComposite;

	mComposite.add(&LeafA);
	mComposite.add(&LeafB);

	mComposite.operation();

	return 0;

}











