
#include "DocumentCreator.hpp"



Code* CDocumentCreator::Creator()
{
	Code* new_code = new CCode;
	return new_code;
}

Code* CXXDocumentCreator::Creator()
{
	Code* new_code = new CXXCode;
	return new_code;
}

Code* JavaDocumentCreator::Creator()
{
	Code* new_code = new JavaCode;
	return new_code;
}
