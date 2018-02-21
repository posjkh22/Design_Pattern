
#include <iostream>


class LocalStaticSingleton
{
private:

	LocalStaticSingleton(){};
	LocalStaticSingleton(const LocalStaticSingleton& other);
	~LocalStaticSingleton(){};


public:
	
	int data;
	static LocalStaticSingleton& GetInstance()
	{
		static LocalStaticSingleton ins;
		return ins;
	}

};



int main(){

	LocalStaticSingleton* sp1, *sp2;

	sp1 = &LocalStaticSingleton::GetInstance();
	sp1->data = 1;
	std::cout << "sp1->data: " << sp1->data << std::endl;
	
	sp2 = &LocalStaticSingleton::GetInstance();
	sp2->data = 2;
	std::cout << "sp2->data: " << sp2->data << std::endl;

	std::cout << "sp1->data: " << sp1->data << std::endl;
	

	return 0;

}
