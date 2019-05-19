#pragma once
#include <vector>
class QAMDemodulator
{
public:
	QAMDemodulator(double A, double w);
	std::vector<unsigned char> demodulate(const std::vector<double> &data);
	virtual ~QAMDemodulator();
private:
	double _A;
	double _w;
};

