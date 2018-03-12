
#ifndef DOCUMENTCREATOR
#define DOCUMENTCREATOR

#include "Code.hpp"



class DocumentCreator
{

public:
	virtual Code* Creator() = 0;


};


class CDocumentCreator : public DocumentCreator
{

public:
	Code* Creator() override;

};

class CXXDocumentCreator : public DocumentCreator
{

public:
	Code* Creator() override;

};


class JavaDocumentCreator : public DocumentCreator
{

public:
	Code* Creator() override;

};

#endif
