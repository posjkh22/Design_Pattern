
#include <iostream>
#include <stdlib.h>

class DestroyerClass;

class DynamicSingleton
{
private:

	DynamicSingleton(){};
	DynamicSingleton(const DynamicSingleton& other);
	~DynamicSingleton(){};

	static DynamicSingleton* instance;

	friend DestroyerClass;

public:
	
	int data;
	static DynamicSingleton* GetInstance()
	{
		if(instance == NULL) instance = new DynamicSingleton();
		return instance;
	}

};

class DestroyerClass
{

public:

	~DestroyerClass()
	{
		std::cout << "Delete! "<< std::endl;
		delete DynamicSingleton::GetInstance();
	}

};


DynamicSingleton* DynamicSingleton::instance = nullptr;


int main(){

	DynamicSingleton* sp1, *sp2;

	sp1 = DynamicSingleton::GetInstance();
	sp1->data = 1;
	std::cout << "sp1->data: " << sp1->data << std::endl;
	
	sp2 = DynamicSingleton::GetInstance();
	sp2->data = 2;
	std::cout << "sp2->data: " << sp2->data << std::endl;

	std::cout << "sp1->data: " << sp1->data << std::endl;

	DestroyerClass freeMemory;

	return 0;

}
