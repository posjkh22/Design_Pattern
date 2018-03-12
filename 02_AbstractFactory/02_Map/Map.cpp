
class Map
{

public:
	void AddField(Field *);
	void AddOb(Obstacle *);
};

class Field
{

private:
	int Field_No;
public:
	Field(int n) : Field_No(n) {};
};

class Obstacle
{


};


class Factory
{

public:
	virtual Map* MakeMap() const
	{
		return new Map;
	}

	virtual Field* MakeField(int n) const
	{
		return new Field(n);
	}

	virtual Obstacle* MakeOb() const
	{
		return new Obstacle;
	}

};



class MapMgr
{
public:
	Map* CreateMap(Factory& fac);

};

Map* MapMgr::CreateMap(Factory& fac){

	Map* pMap = fac.MakeMap();
	Field* f1 = fac.MakeField(1);
	Field* f2 = fac.MakeField(2);
	Obstacle* pOb = fac.MakeOb;

	Map->AddField(f1);
	Map->AddField(f2);
	Map->AddOb(pOb);

	return pMap;
}




