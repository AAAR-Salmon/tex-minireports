#include <stdio.h>

#define I_TRUE (27.0/32.0) // true value
#define LOW 1.0
#define HIGH 2.0
#define LOG_MAXN 4

// integrand
double f(double x) {
	return 1.0 / (x * x * x) + 2.0 / (x * x * x * x * x);
}

int main(void) {
	double I[5][5], y[1 << LOG_MAXN + 1];
	for (int i = 0; i <= LOG_MAXN; i++) {
		int n = 1 << i;
		double _I0 = 0.0;
		double h = (HIGH - LOW) / n;
		for (int i = 0; i <= n; i++) {
			y[i] = f(LOW + h * i);
		}

		// trapezoidal
		_I0 += (y[0] + y[n]) / 2.0;
		for (int i = 1; i < n; i++) {
			_I0 += y[i];
		}
		_I0 *= h;

		I[0][i] = _I0;
		printf("0, %2d, %.12f, %.12f\n", n, _I0, _I0 - I_TRUE);
	}

	double pow4 = 4;
	for (int k = 1; k <= LOG_MAXN; k++) {
		for (int log_n = k; log_n <= LOG_MAXN; log_n++) {
			I[k][log_n] = (pow4 * I[k - 1][log_n] - I[k - 1][log_n - 1]) / (pow4 - 1);
			printf("%1d, %2d, %.12f, %.12f\n", k, 1 << log_n, I[k][log_n], I[k][log_n] - I_TRUE);
		}
		pow4 *= 4;
	}


	return 0;
}