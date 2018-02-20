
#include <iostream>
#include <stdlib.h>

class DynamicSingleton
{
private:

	DynamicSingleton(){};
	DynamicSingleton(const DynamicSingleton& other);
	~DynamicSingleton(){};

	static DynamicSingleton* instance;

	static void Destroy()
	{
		std::cout << "Memory is free!" << std::endl;
		delete instance;
	}

public:
	
	int data;
	static DynamicSingleton* GetInstance()
	{
		if(instance == NULL){
			instance = new DynamicSingleton();
			atexit(Destroy);
		}
		return instance;
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
	

	return 0;

}
