
#include <map>
#include <iostream>

using namespace std;

template< typename T >
class Singleton
{

protected:
	Singleton(){};
	virtual ~Singleton(){}
	Singleton(const Singleton& s){}

private:
	static void destroy(){ delete m_pInstance; }

public:
	static T* GetInstance()
	{
		if(m_pInstance == NULL)
		{
			m_pInstance = new T();
			atexit(destroy);
		}

		return m_pInstance;

	}

private:
	static T* m_pInstance;

};

template <typename T> T* Singleton <T>::m_pInstance;


class Item
{
public:
	virtual void operation() =0;

};

class Potion : public Item
{
public:
	void operation() override { cout << "Potion" << endl; }

};

class Axe : public Item
{
public:
	void operation() override { cout<< "Axe" << endl; }

};

class Map : public Item
{
public:
	void operation() override { cout << "Map" << endl; }

};

class ItemFactory : public Singleton<ItemFactory>
{
public:
	~ItemFactory(){}

public:
	template<typename T>
	Item* GetItem(int key)
	{
		if(mList.find(key) == mList.end())
		{
			mList[key] = new T;
		}

		return mList[key];
	}

private:
	map<int, Item*> mList;
};

int main()
{
	Item* potion = ItemFactory::GetInstance()->GetItem<Potion>(1);
	Item* axe = ItemFactory::GetInstance()->GetItem<Axe>(2);
	Item* map = ItemFactory::GetInstance()->GetItem<Map>(3);

	potion->operation();
	axe->operation();
	map->operation();


	return 0;

}










