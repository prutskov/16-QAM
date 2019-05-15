#include "stdafx.h"
#include "QAMModulator.h"


QAMModulator::QAMModulator(double A, double w) : _A(A), _w(w)
{
}

double * QAMModulator::modulate(unsigned char * data, size_t size)
{
	double a = 44;
	return &a;
}


QAMModulator::~QAMModulator()
{
}
