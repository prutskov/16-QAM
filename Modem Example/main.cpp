#include <cstdlib>
#include <stdio.h>

#include "..\16-QAM-Modem\QAMModulator.h"

int main(int argc, char ** argv)
{
	QAMModulator modulator(12, 23);
	modulator.modulate(NULL, 3);
	printf("Hello world %.2f\n", 34.3);
	::system("pause");
	return 0;
}