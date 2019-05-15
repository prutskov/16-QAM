#pragma once
#include <vector>

class QAMModulator
{
public:
	QAMModulator(double A, double w);
	std::vector<double> modulate(const unsigned char *data, size_t size);
	virtual ~QAMModulator();

private:
	double getModulatedValue(const unsigned char *data, size_t size, size_t time);
private:
	double _A;
	double _w;
};

