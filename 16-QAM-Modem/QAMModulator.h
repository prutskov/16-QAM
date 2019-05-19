#pragma once
#include <vector>

class QAMModulator
{
public:
	QAMModulator(double A, double w);
	std::vector<double> modulate(const unsigned char *data, size_t size);
	virtual ~QAMModulator();

private:
	double getModulatedValue(const unsigned char *data, size_t time);
	inline unsigned char getValFromDiagram(unsigned char value);
private:
	double _A;
	double _w;
};

