#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>


int main()
{
	// 1.1
	printf("Task 1.1\n");
	printf("res1 = %d\n", 2 + 31);
	printf("res2 = %d\n", 45 * 54 - 11);
	printf("res3 = %d\n", 15 / 4);
	printf("res4 = %f\n", 15.0 / 4);
	printf("res5 = %d\n", 67 % 5);
	printf("res6 = %f\n", (2 * 45.1 + 3.2) / 2);

	printf("\n");

	// 1.2
	printf("Task 1.2\n");
	float fnum1 = 1e-4, fnum2 = 24.33e5, fnum3 = M_PI, fnum4 = M_E, fnum5 = sqrt(5), fnum6 = log(100);
	printf("%.2f\n", fnum1);
	printf("%.2f\n", fnum2);
	printf("%.2f\n", fnum3);
	printf("%.2f\n", fnum4);
	printf("%.2f\n", fnum5);
	printf("%.2f\n", fnum6);
	printf("\n");

	// initialization as double and long double
	/*
	double dnum1 = 1e-4, dnum2 = 24.33e5, dnum3 = M_PI, dnum4 = M_E, dnum5 = sqrt(5), dnum6 = log(100);
	printf("%.2lf\n", dnum1);
	printf("%.2lf\n", dnum2);
	printf("%.2lf\n", dnum3);
	printf("%.2lf\n", dnum4);
	printf("%.2lf\n", dnum5);
	printf("%.2lf\n", dnum6);
	printf("\n");

	long double ldnum1 = 1e-4, ldnum2 = 24.33e5, ldnum3 = M_PI, ldnum4 = M_E, ldnum5 = sqrt(5), ldnum6 = log(100);
	printf("%.2Lf\n", ldnum1);
	printf("%.2Lf\n", ldnum2);
	printf("%.2Lf\n", ldnum3);
	printf("%.2Lf\n", ldnum4);
	printf("%.2Lf\n", ldnum5);
	printf("%.2Lf\n", ldnum6);
	printf("\n");
	*/



	// 1.3
	printf("Task 1.3\n");
	int a;
	printf("Enter a number (from 0 to 9): ");
	scanf_s("%d", &a);
	if (a < 0 || a > 9)
	{
		printf("You have entered the wrong number!");
		return 0;
	}
	printf("-%d-%d-%d\n%d|%d|%d\n-%d-%d-%d\n", a, a, a, a, a, a, a, a, a);

	printf("\n");

	// 1.4
	printf("Task 1.4\n");
	double m1, m2;
	double r;
	double gama = 6.673e-11;
	double F;

	printf("Enter the mass m1: ");
	scanf_s("%lf", &m1);

	printf("Enter the mass m2: ");
	scanf_s("%lf", &m2);

	printf("Enter the distance: ");
	scanf_s("%lf", &r);

	F = gama * m1 * m2 / r / r;
	printf("F = %le", F);
	printf("\n");

	// 1.5
	printf("Task 1.5\n");
	double x;
	double xin2, xin4, xin6, xin8, xin9, xin15, xin28, xin16, xin32, xin64;
	printf("Enter x: ");
	scanf_s("%lf", &x);

	xin2 = x * x;

	xin4 = xin2 * xin2;
	printf("x^4 (2 operations) = %lf\n", xin4);

	xin6 = xin4 * xin2;
	printf("x^6 (3 operations) = %lf\n", xin6);

	xin9 = xin4 * xin4 * x;
	printf("x^9 (4 operations) = %lf\n", xin9);

	xin15 = xin4 * xin4 * xin4 * xin2 * x;
	printf("x^15 (6 operations) = %lf\n", xin15);

	xin8 = xin4 * xin4;

	xin28 = xin8 * xin8 * xin8 * xin4;
	printf("x^28 (6 operations) = %lf\n", xin28);

	xin16 = xin8 * xin8;
	xin32 = xin16 * xin16;

	xin64 = xin32 * xin32;
	printf("x^64 (6 operations) = %lf\n", xin64);

	printf("\n");

	// 1.6
	printf("Task 1.6\n");
	float numDegreeC;
	printf("Degree?\n");
	scanf_s("%f", &numDegreeC);
	float numDegreeF = 9 * numDegreeC / 5 + 32;
	printf("F=%g", numDegreeF);
	printf("\n");

	// 1.7
	printf("Task 1.7\n");
	float y;
	printf("Enter x: ");
	scanf_s("%f", &y);

	int int1Y = (int) y;
	float fract1Y = fabs(y - (float) int1Y);
	printf("(Without using math lib) Integer and fractional parts of %f are %d and %f\n", y, int1Y, fract1Y);

	float int2Y;
	float fract2Y;
	fract2Y = modff(y, &int2Y);
	fract2Y = fabs(fract2Y);
	printf("(With using math lib) Integer and fractional parts of %f are %.0f and %f\n", y, int2Y, fract2Y);

	printf("The largest integer that is less than x and the smallest integer that is greater than x:\n");
	printf("(Without using math lib) %d %d\n", fract1Y > 0.000001 && y > 0 ? int1Y : int1Y - 1, fract1Y > 0.000001 && y < 0 ? int1Y : int1Y + 1);
	printf("(With using math lib) %d %d\n", (int) ceil(y) - 1, (int) floor(y) + 1);
	
	printf("Round of x:\n");
	printf("(Without using math lib) %d\n", (int) (y > 0 ? (y + 0.5) : (y - 0.5)));
	printf("(With using math lib) %d\n", (int) round(y));
	printf("\n");
	
	// 1.8
	printf("Task 1.8\n");
	float y1, y2;
	printf("Enter two float number in different rows\n");
	scanf_s("%f", &y1);
	scanf_s("%f", &y2);
	printf("%f - %f: %g\n", y1, y2, y1 - y2);
	printf("%f * %f: %g\n", y1, y2, y1 * y2);
	printf("\n");



	// 1.9
	printf("Task 1.9\n");
	double x1, x2;
	double averageArithmetic;
	double averageHarmonic;

	printf("Enter two float number with a whitespace:\n");
	scanf_s("%lf %lf", &x1, &x2);

	averageArithmetic = (x1 + x2) / 2;
	averageHarmonic = 2 / (1 / x1 + 1 / x2);

	printf("Average arithmetic and harmonic of %lf and %lf are %lf and %lf\n", x1, x2, averageArithmetic, averageHarmonic);
	printf("Average arithmetic and harmonic of %lf and %lf are %le and %le\n", x1, x2, averageArithmetic, averageHarmonic);
	printf("\n");

	// 1.10
	printf("Task 1.10\n");
	int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5;
	double n6 = 1.0, n7 = 2.1, n8 = 6.3, n9 = 8.10, n10 = 3.2;

	printf("\tx\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n\t-\t|\t--\t|\t--\t|\t--\t|\t--\t|\t--\t|\n\ty\t|\t%.1f\t|\t%.1f\t|\t%.1f\t|\t%.1f\t|\t%.1f\t|\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10);
	printf("\n");

	// 1.21
	printf("Task 1.21\n");
	double numA;
	printf("Enter a: ");
	scanf_s("%lf", &numA);
	if (numA >= 100) return 0;

	printf("\t-\t|\t-\t|\t%g\t|\t-\t|\t-\n\t-\t|\t%g\t|\t%g\t|\t%g\t|\t-\n\t%g\t|\t%g\t|\t%g\t|\t%g\t|\t%g\n", numA, numA, numA, numA, numA, numA, numA, numA, numA);
	printf("\n");
	return 0;
}