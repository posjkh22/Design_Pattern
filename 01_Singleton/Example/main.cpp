
#include <iostream>
#include "Speaker.hpp"

int main()
{
	Speaker *sp;

	sp = sp->getInstance();

	Piano pi;
	Violin vi;
	Flute fl;

	sp->tuneMusic(&pi);
	sp->tuneMusic(&vi);
	sp->tuneMusic(&fl);

	return 0;


}
