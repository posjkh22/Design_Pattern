
#include <iostream>


class Singleton
{
private:

	Singleton(){};
	Singleton(const Singleton& other);

	static Singleton instance;


public:
	
	int data;
	static Singleton* GetInstance()
	{
		return &instance;
	}

};

Singleton Singleton::instance;


int main(){

	Singleton* sp1, *sp2;

	sp1 = Singleton::GetInstance();
	sp1->data = 1;
	std::cout << "sp1->data: " << sp1->data << std::endl;
	
	sp2 = Singleton::GetInstance();
	sp2->data = 2;
	std::cout << "sp2->data: " << sp2->data << std::endl;

	std::cout << "sp1->data: " << sp1->data << std::endl;
	

	return 0;

}
