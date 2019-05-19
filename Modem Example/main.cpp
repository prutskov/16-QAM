#include <cstdlib>
#include <stdio.h>

#include "..\16-QAM-Modem\QAMModulator.h"

int main(int argc, char ** argv)
{
	unsigned char data[] = {0, 1, 0, 1, 1, 1, 0, 0};

	QAMModulator modulator(1, 0.36);
	auto modulatedData = modulator.modulate(data, 8);

	printf("Data: \n");
	for (size_t i = 0; i < 8; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\nModulated data:\n");
	for (size_t i = 0; i < modulatedData.size(); i++)
	{
		printf("%.3f ", modulatedData[i]);
	}
	printf("\n");
	::system("pause");
	return 0;
}