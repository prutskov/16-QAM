#include "stdafx.h"
#include "QAMDemodulator.h"


QAMDemodulator::QAMDemodulator(double A, double w) : _A(A), _w(w)
{
}

std::vector<unsigned char> QAMDemodulator::demodulate(const std::vector<double>& data)
{
	std::vector<double> lowBitsModulated;
	std::vector<double> highBitsModulated;

	/*4 bits get from 1 point of signal*/
	const size_t nBits = 4;
	const size_t signalSize = data.size();

	/*Quadrature conversion*/
	for (size_t i = 0; i < signalSize; i++)
	{
		double valLow  = data[i] / _A * cos(_w*i)*2.0;
		double valHigh = data[i] / _A * sin(_w*i)*2.0;
		lowBitsModulated.push_back(valLow);
		highBitsModulated.push_back(valHigh);
	}
	printf("data:\n");
	for (size_t i = 0; i < signalSize; i++)
	{
		printf("%.2f %.2f ", lowBitsModulated[i], highBitsModulated[i]);
	}
	printf("\n");
	return std::vector<unsigned char>();
}


QAMDemodulator::~QAMDemodulator()
{
}
