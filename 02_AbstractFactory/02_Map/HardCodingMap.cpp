
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

class MapMgr
{
public:
	Map* CreateMap();

};

Map* MapMgr::CreateMap(){

	Map* pMap = new Map;
	Field* f1 = new Field(1);
	Field* f2 = new Field(2);
	Obstacle* pOb = new Obstacle;

	Map->AddField(f1);
	Map->AddField(f2);
	Map->AddOb(pOb);

	return pMap;
}
