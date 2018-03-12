
#include <iostream>

using namespace std;


class DocumentInterface
{
public:
	virtual void print() = 0;
};

class DocumentHangul : public DocumentInterface
{
public:
	void print() override { cout << "Hangul type document" << endl; }

};

class DocumentExcel : public DocumentInterface
{
public:
	void print() override { cout << "Excel type document" << endl; }

};

class ProgramInterface
{
public:
	DocumentInterface* create(){ return DocumentCreate(); }

protected:
	virtual DocumentInterface* DocumentCreate() = 0;
};

class ProgramHangul : public ProgramInterface
{
private:
	DocumentInterface* DocumentCreate(){ return new DocumentHangul; }

};

class ProgramExcel : public ProgramInterface
{
private:
	DocumentInterface* DocumentCreate(){ return new DocumentExcel; }

};


int main()
{

	ProgramHangul pHwpCreator;
	ProgramExcel pXlsCreator;

	DocumentInterface* pDocument = pHwpCreator.create();
	pDocument->print();

	pDocument = pXlsCreator.create();
	pDocument->print();

	return 0;

}
