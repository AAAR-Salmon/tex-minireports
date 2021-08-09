#include <stdio.h>

#define I (27.0/32.0) // true value
#define LOW 1.0
#define HIGH 2.0
#define MAXN 16

// integrand
double f(double x) {
	return 1.0 / (x * x * x) + 2.0 / (x * x * x * x * x);
}

int main(void) {
	double I1, I2, h, y[MAXN + 1];
	for (int n = 2; n <= MAXN; n *= 2) {
		I1 = I2 = 0.0;
		h = (HIGH - LOW) / n;
		for (int i = 0; i <= n; i++) {
			y[i] = f(LOW + h * i);
		}

		// trapezoidal
		I1 += (y[0] + y[n]) / 2.0;
		for (int i = 1; i < n; i++) {
			I1 += y[i];
		}
		I1 *= h;

		// simpson
		double _sum;
		I2 += (y[0] + y[n]);
		_sum = 0.0;
		for (int i = 1; i < n; i += 2) {
			_sum += y[i];
		}
		I2 += _sum * 4;
		_sum = 0.0;
		for (int i = 2; i < n; i += 2) {
			_sum += y[i];
		}
		I2 += _sum * 2;
		I2 *= h / 3.0;

		printf("%2d, %.12f, %.12f, %.12f, %.12f\n", n, I1, I1 - I, I2, I2 - I);
	}

	return 0;
}