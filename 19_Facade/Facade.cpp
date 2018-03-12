
#include <iostream>

using namespace std;

class BIOS
{
public:
	void operation(){ cout << "BIOS Loading.." << endl; }
};

class CPU
{
public:
	void operation(){ cout << "CPU Loading.." << endl; }
};

class Memory
{
public:
	void operation(){ cout << "Memory Loading.." << endl; }
};

class HDD
{
public:
	void operation(){ cout << "HDD Loading.. " << endl; }
};

class Computer
{
public:
	Computer(BIOS* a, CPU* b, Memory* c, HDD* d): mBios(a), mCpu(b), mMemory(c), mHdd(d) {}

public:
	void Booting()
	{
		cout << "Computer Booting Start!" << endl;
		mBios->operation();
		mCpu->operation();
		mMemory->operation();
		mHdd->operation();

		cout << "Computer Booting Complete!" << endl;
	}


private:
	BIOS* mBios;
	CPU* mCpu;
	Memory* mMemory;
	HDD* mHdd;
};

int main()
{
	BIOS bios;
	CPU cpu;
	Memory memory;
	HDD hdd;

	Computer mComputer(&bios, &cpu, &memory, &hdd);
	mComputer.Booting();

	return 0;


}



