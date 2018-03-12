

#include "DocumentCreator.hpp"
#include "Code.hpp"

int main()
{
	DocumentCreator dc;
	Code c;

	Code* c_ptr = dc.Creator(); 
	c_ptr->ViewCode();
}
