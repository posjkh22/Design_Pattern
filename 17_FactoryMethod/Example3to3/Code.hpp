
#ifndef CODE
#define CODE

#include <iostream>


class Code
{

public:
	void virtual ViewCode() = 0;

};


class CCode : public Code
{

public:
	void ViewCode() override;

};

class CXXCode : public Code
{

public:
	void ViewCode() override;

};

class JavaCode : public Code
{

public:
	void ViewCode() override;

};


#endif
