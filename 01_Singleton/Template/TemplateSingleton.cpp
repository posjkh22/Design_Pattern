
#include <iostream>

template < typename T >
class TemplateSingleton
{

protected:
	TemplateSingleton()
	{

	}

	virtual ~TemplateSingleton()
	{

	}

public:

	static T * GetInstance()
	{
		if(m_pInstance == NULL) m_pInstance = new T;
		return m_pInstance;
	};

	static void DestroyInstance()
	{

		if(m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	};

private:
	static T * m_pInstance;

};

template < typename T > T * TemplateSingleton <T>::m_pInstance = 0;

class CObject : public TemplateSingleton<CObject>
{
public:
	CObject(){};
	~CObject(){};

	int data;
};

int main(){


	CObject *ptr1;
	CObject *ptr2;

	ptr1 = CObject::GetInstance();
	ptr1->data = 1;
	std::cout << "ptr1->data: " << ptr1->data << std::endl;

	ptr2 = CObject::GetInstance();
	ptr2->data = 2;
	std::cout << "ptr2->data: " << ptr2->data << std::endl;
	
	std::cout << "ptr1->data: " << ptr1->data << std::endl;


	return 0;
}



