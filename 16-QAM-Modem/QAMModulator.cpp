#include "stdafx.h"
#include "QAMModulator.h"
#include <stdexcept>


QAMModulator::QAMModulator(double A, double w) : _A(A), _w(w)
{
}

std::vector<double> QAMModulator::modulate(const unsigned char * data, size_t size)
{
	std::vector<double> modulatedData;
	if (size % 4 != 0)
	{
		throw std::exception("Incorrect size of binary data");
	}

	/*Every 4 bits get 1 point of signal*/
	const size_t nBits = 4;
	const size_t signalSize = size / nBits;

	modulatedData.resize(signalSize, 0);

	for(size_t idxQuadrature = 0; idxQuadrature < signalSize; idxQuadrature++)
	{

	}

	return modulatedData;
}


QAMModulator::~QAMModulator()
{
}

double QAMModulator::getModulatedValue(const unsigned char * data, size_t size, size_t time)
{
	return 0.0;
}
