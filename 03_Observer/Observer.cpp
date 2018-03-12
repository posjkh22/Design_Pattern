
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Observer
{
public:
	virtual void Update(int data1, int data2) = 0;

public:
	std::string mName;

};

class Subject
{

public:
	virtual void RegisterObserver(Observer* p) = 0;
	virtual void RemoveObserver(Observer* p) = 0;
	virtual void NotifyObservers() = 0;
};

class WeatherData : public Subject
{

public:
	typedef std::map< std::string, Observer* > STL_MAP_OBSERVERS;
	typedef STL_MAP_OBSERVERS::iterator STL_MAP_OBSERVERS_ITR;
	typedef STL_MAP_OBSERVERS::value_type STL_MAP_OBSERVERS_VT;
	
	virtual void RegisterObserver(Observer* p)
	{
		m_map_Observers.insert(STL_MAP_OBSERVERS_VT(p->mName, p));
	}

	virtual void RemoveObserver(Observer* p)
	{
		m_map_Observers.erase(p->mName);
	}

	virtual void NotifyObservers()
	{
		STL_MAP_OBSERVERS_ITR Itr = m_map_Observers.begin();
		while(Itr != m_map_Observers.end())
		{
			Observer* pObserver = Itr->second;
			pObserver->Update(m_data1, m_data2);
			++Itr;
		}
	}

public:
	int GetData1(){ return m_data1; }
	int GetData2(){ return m_data2; }
	void SetData(int data1, int data2)
	{
		m_data1 = data1;
		m_data2 = data2;
		NotifyObservers(); 
	}
	
private:
	int m_data1;
	int m_data2;


private:
	STL_MAP_OBSERVERS m_map_Observers;

};


class ConditionDisplay : public Observer
{

public:
	ConditionDisplay(Subject* pSubject)
	{
		pSubject->RegisterObserver(this);
		m_pSubject = pSubject;
	}

public:
	virtual void Update(int data1, int data2)
	{
		m_data1 = data1;
		m_data2 = data2;
	}
		
public:
	void Display()
	{
		cout << "Temperature: " << m_data1 << endl;
		cout << "Humidity: " << m_data2 << endl;
	}

private:
	Subject* m_pSubject;
	int m_data1;
	int m_data2;

};

int main()
{
	WeatherData* pWeatherData = new WeatherData;
	ConditionDisplay* pConditionDisplay = new ConditionDisplay(pWeatherData);

	pWeatherData->SetData(13, 22);
	pConditionDisplay->Display();

	return 0;

}



