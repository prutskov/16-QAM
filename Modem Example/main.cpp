#include <cstdlib>
#include <stdio.h>

#include "..\16-QAM-Modem\QAMModulator.h"
#include "..\16-QAM-Modem\QAMDemodulator.h"

int main(int argc, char ** argv)
{
	unsigned char data[] = { 0, 0, 1, 1,
							0, 0, 1, 1 ,
							1, 1, 0, 0,
							0, 1, 1, 0};

	QAMModulator modulator(1, 1.5);
	auto modulatedData = modulator.modulate(data, 16);

	printf("Data: \n");
	for (size_t i = 0; i < 16; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\nModulated data:\n");
	for (size_t i = 0; i < modulatedData.size(); i++)
	{
		printf("%.3f ", modulatedData[i]);
	}
	printf("\n");

	QAMDemodulator demodulator(1, 1.5);
	demodulator.demodulate(modulatedData);
	::system("pause");
	return 0;
}