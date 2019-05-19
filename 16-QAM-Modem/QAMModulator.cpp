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
	
	/*idxQuadrature = time*/
	for(size_t idxQuadrature = 0; idxQuadrature < signalSize; idxQuadrature++)
	{
		double modulatedVal = getModulatedValue(data + nBits*idxQuadrature, idxQuadrature);
		modulatedData.push_back(modulatedVal);
	}

	return modulatedData;
}


QAMModulator::~QAMModulator()
{
}

double QAMModulator::getModulatedValue(const unsigned char * data, size_t time)
{
	/*Code low and high bits*/
	const unsigned char lowBits = data[0] + data[1] * 2;
	const unsigned char highBits = data[2] + data[3] * 2;

	/*Get modulated amplitude for low and high bits*/
	const double Uk = getValFromDiagram(lowBits);
	const double Un = getValFromDiagram(highBits);

	double modulatedVal = _A*(Uk*cos(_w*time) + Un*sin(_w*time));

	return modulatedVal;
}

inline unsigned char QAMModulator::getValFromDiagram(unsigned char value)
{
	switch (value)
	{
	case 0: return -3;
	case 1: return -1;
	case 2: return  1;
	case 3: return  3;
	default:
		break;
	}
	return 0;
}
