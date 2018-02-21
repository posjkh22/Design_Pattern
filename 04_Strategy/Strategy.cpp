#include <iostream>

using namespace std;

class Strategy
{
public:
	virtual int AlgorithmInterface(int a, int b) = 0;

};

class Adder : public Strategy
{
public:
	int AlgorithmInterface(int a, int b) override
	{
		return a + b;
	}
};

class Subtracter : public Strategy
{
public:
	int AlgorithmInterface(int a, int b) override
	{
		return a - b;
	}
};


class Multiplyer : public Strategy
{
public:
	int AlgorithmInterface(int a, int b) override
	{
		return a * b;
	}
};

class Context
{
public:
	Context(int x, int y) : m_pStrategy(0), a(x), b(y){}
	~Context(){ if(m_pStrategy) delete m_pStrategy; }


public:
	void ChangeStrategy(Strategy* pStrategy)
	{
		if(m_pStrategy) delete m_pStrategy;
		m_pStrategy = pStrategy;
	}

	int ContextInterface(){ m_pStrategy->AlgorithmInterface(a, b); }

private:
	Strategy* m_pStrategy;
	int a;
	int b;
};

int main(){
	
	int result;

	Context* pContext = new Context(5, 3);
	pContext->ChangeStrategy(new Adder());
	result = pContext->ContextInterface();
	std::cout << "Adder:" << result << std::endl;

	pContext = new Context(5, 3);
	pContext->ChangeStrategy(new Subtracter());
	result = pContext->ContextInterface();
	std::cout << "Adder:" << result << std::endl;

	pContext = new Context(5, 3);
	pContext->ChangeStrategy(new Multiplyer());
	result = pContext->ContextInterface();
	std::cout << "Adder:" << result << std::endl;

	return 0;
}


