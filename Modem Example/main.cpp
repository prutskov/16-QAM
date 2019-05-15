#include <cstdlib>
#include <stdio.h>

#include "..\16-QAM-Modem\QAMModulator.h"

int main(int argc, char ** argv)
{
	QAMModulator modulator(12, 23);
	printf("Hello world %.2f\n", *modulator.modulate(NULL, 0));
	::system("pause");
	return 0;
}