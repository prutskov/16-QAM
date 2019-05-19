#pragma once
#include <vector>
class QAMDemodulator
{
	struct cmplx { float real; float image; };
public:
	QAMDemodulator(double A, double w);
	std::vector<unsigned char> demodulate(const std::vector<double> &data);
	virtual ~QAMDemodulator();
private:
	void fourierTransform(std::vector<cmplx> *data, int n, int is);
private:
	double _A;
	double _w;
};

