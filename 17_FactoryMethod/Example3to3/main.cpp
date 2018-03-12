

#include "DocumentCreator.hpp"
#include "Code.hpp"

int main()
{
	CDocumentCreator cdc;
	CXXDocumentCreator cxxdc;
	JavaDocumentCreator javadc;


	Code* c_ptr = cdc.Creator(); 
	c_ptr->ViewCode();

	c_ptr  = cxxdc.Creator();
	c_ptr->ViewCode();

	c_ptr  = javadc.Creator();
	c_ptr->ViewCode();

	return 0;
}
