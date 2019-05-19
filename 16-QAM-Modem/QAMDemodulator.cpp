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
		double valLow = data[i] / _A * cos(_w*i)*2.0;
		double valHigh = data[i] / _A * sin(_w*i)*2.0;
		lowBitsModulated.push_back(valLow);
		highBitsModulated.push_back(valHigh);
	}
	std::vector<cmplx> lowCmplx(signalSize, { 0,0 });
	std::vector<cmplx> highCmplx(signalSize, { 0,0 });

	for (size_t i = 0; i < signalSize; i++)
	{
		lowCmplx[i].real = lowBitsModulated[i];
		highCmplx[i].real = highBitsModulated[i];
	}

	fourierTransform(&lowCmplx, signalSize, -1);
	fourierTransform(&highCmplx, signalSize, -1);

	printf("Fourier low:\n");

	for (size_t i = 0; i < signalSize; i++)
	{
		printf("%.2f ", sqrt(lowCmplx[i].real*lowCmplx[i].real + lowCmplx[i].image*lowCmplx[i].image));
	}	
	printf("\nFourier high:\n");
	for (size_t i = 0; i < signalSize; i++)
	{
		printf("%.2f ", sqrt(highCmplx[i].real*highCmplx[i].real + highCmplx[i].image*highCmplx[i].image));
	}

	for (size_t i = signalSize / 2; i < signalSize; i++)
	{
		lowCmplx[i].real = 0;
		highCmplx[i].real = 0;
		lowCmplx[i].image = 0;
		highCmplx[i].image = 0;
	}

	fourierTransform(&lowCmplx, signalSize, 1);
	fourierTransform(&highCmplx, signalSize, 1);

	printf("\nLow:\n");

	for (size_t i = 0; i < signalSize; i++)
	{
		printf("%.2f ", lowCmplx[i].real);
	}
	printf("\nHigh:\n");
	for (size_t i = 0; i < signalSize; i++)
	{
		printf("%.2f ", highCmplx[i].real);
	}

	printf("\ndata:\n");
	for (size_t i = 0; i < signalSize; i++)
	{
		printf("%.2f %.2f ", lowCmplx[i].real, highCmplx[i].real);
	}
	printf("\n");
	return std::vector<unsigned char>();
}


QAMDemodulator::~QAMDemodulator()
{
}

void QAMDemodulator::fourierTransform(std::vector<cmplx>* data, int n, int is)
{
	int i, j, istep;
	int m, mmax;
	float r, r1, theta, w_r, w_i, temp_r, temp_i;
	float pi = 3.1415926f;

	r = pi * is;
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (i < j)
		{
			temp_r = (*data)[j].real;
			temp_i = (*data)[j].image;
			(*data)[j].real = (*data)[i].real;
			(*data)[j].image = (*data)[i].image;
			(*data)[i].real = temp_r;
			(*data)[i].image = temp_i;
		}
		m = n >> 1;
		while (j >= m) { j -= m; m = (m + 1) / 2; }
		j += m;
	}
	mmax = 1;
	while (mmax < n)
	{
		istep = mmax << 1;
		r1 = r / (float)mmax;
		for (m = 0; m < mmax; m++)
		{
			theta = r1 * m;
			w_r = (float)cos((double)theta);
			w_i = (float)sin((double)theta);
			for (i = m; i < n; i += istep)
			{
				j = i + mmax;
				temp_r = w_r * (*data)[j].real - w_i * (*data)[j].image;
				temp_i = w_r * (*data)[j].image + w_i * (*data)[j].real;
				(*data)[j].real = (*data)[i].real - temp_r;
				(*data)[j].image = (*data)[i].image - temp_i;
				(*data)[i].real += temp_r;
				(*data)[i].image += temp_i;
			}
		}
		mmax = istep;
	}
	if (is > 0)
		for (i = 0; i < n; i++)
		{
			(*data)[i].real /= (float)n;
			(*data)[i].image /= (float)n;
		}

}

