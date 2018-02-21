
#include <iostream>
#include <string>

using namespace std;

class CEngine
{
public:
	CEngine(int mph) : mMPH(mph){}
	int GetMPH() const { return mMPH; }

private:
	int mMPH;

};

class CWheel
{
public:
	CWheel(int size) : mSize(size){}
	int GetSize() const { return mSize; }

private:
	int mSize;

};

class CBody
{
public:
	CBody(string shape) : mShape(shape) {}
	string GetShape() const { return mShape; }

private:
	string mShape;
};

class Car
{
public:
	Car(): mEngine(NULL), mWheel(NULL), mBody(NULL){}
	~Car(){ if(mEngine) delete mEngine; if(mWheel) delete mWheel; if(mBody) delete mBody; }

public:
	void SetEngine(CEngine* engine){ mEngine = engine; }
	void SetWheel(CWheel* wheel){ mWheel = wheel; }
	void SetBody(CBody* body){ mBody = body; }
	void SetManufacturer(string m){ mManufacturer = m; }

	void print() const
	{
		cout << "Manufacturer: " << mManufacturer << endl;
		cout << "Engine MPH: " << mEngine->GetMPH() << endl;
		cout << "Wheel size: " << mWheel->GetSize() << endl;
		cout << "Body type: " << mBody->GetShape() << endl;
	}

private:

	CEngine* mEngine;
	CWheel* mWheel;
	CBody* mBody;
	string mManufacturer;
};


class Builder
{
public:
	virtual CEngine* GetEngine() = 0;
	virtual CWheel* GetWheel() = 0;
	virtual CBody* GetBody() = 0;
	virtual string GetManufacturer() = 0;

};


class JeepBuilder : public Builder
{
public:
	CEngine* GetEngine() override { return new CEngine(120); }
	CWheel* GetWheel() override { return new CWheel(20); }
	CBody* GetBody() override { return new CBody("SUV"); }
	string GetManufacturer() override { return "Jeep"; }
};

class FordBuilder : public Builder
{
public:
	CEngine* GetEngine() override { return new CEngine(150); }
	CWheel* GetWheel() override { return new CWheel(18); }
	CBody* GetBody() override { return new CBody("Hach"); }
	string GetManufacturer() override { return "Ford"; }
};

class Director
{
public:
	Director(Builder* builder) : pBuilder(builder){}
	~Director(){ if(pBuilder) delete pBuilder; }

public:
	Car* construct()
	{
		Car* pCar = new Car;
		pCar->SetBody(pBuilder->GetBody());
		pCar->SetEngine(pBuilder->GetEngine());
		pCar->SetWheel(pBuilder->GetWheel());
		pCar->SetManufacturer(pBuilder->GetManufacturer());

		return pCar;
	}

private:
	Builder* pBuilder;

};

int main(){

	Director* pDirector = new Director(new FordBuilder());
	Car* pCar = pDirector->construct();

	pCar->print();

	delete pCar;
	delete pDirector;

	return 0;
}


