#pragma once
class QAMModulator
{
public:
	QAMModulator(double A, double w);
	double * modulate(unsigned char *data, size_t size);
	virtual ~QAMModulator();

private:
	double _A;
	double _w;
};

