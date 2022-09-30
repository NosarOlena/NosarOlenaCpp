#include <cfloat>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>

double hypotenuse(double a, double b)
{
	return sqrt(a * a + b * b);
}

double heron(double a, double b, double c)
{
	return sqrt((a + b + c) * (a + c - b) * (a + b - c) * (b + c - a)) / 4;
}

double task4a(double x)
{
	double xplus1 = x * x + 1;
	return xplus1 * xplus1;
}

double task4b(double x)
{
	double xin2 = x * x;
	return xin2 * xin2 + xin2 * x + xin2 + x + 1;
}

double task4c(double x)
{
	double xplus1 = x + 1;
	double xplus1in2 = xplus1 * xplus1;
	return xplus1in2 * xplus1in2 * xplus1;
}

double task4d(double x)
{
	double xin3 = x * x * x;
	return xin3 * xin3 * xin3 + xin3 + 1;
}

double task4e(double x)
{
	double xmult2 = x * 2;
	double xmult2in2 = xmult2 * xmult2;
	return xmult2in2 * xmult2in2 + xmult2in2 * xmult2 + xmult2in2 + xmult2 + 1;
}

double task4f(double x)
{
	double xin2 = x * x;
	return x * (xin2 * xin2 + xin2 + 1);
}

double Rosenbrock2d(double x, double y)
{
	double z = x * x - y;
	return 100 * z * z + (x - 1) * (x - 1);
}

double length(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double arctg(double x)
{
	return atan(x);
}

double derivativeArctg(double x)
{
	return 1 / (1 + x * x);
}



int main()
{
	// 2.1
	printf("Task 2.1\n");
	float x;
	printf("x=");
	scanf_s("%f", &x);

	float y = cos(x);
	printf("cos(%f)=%f\n", x, y);
	printf("\n");

	// 2.2
	printf("Task 2.2\n");
	double side1, side2;
	printf("Enter a, b\n");
	scanf_s("%lf %lf", &side1, &side2);
	double side3 = hypotenuse(side1, side2);
	printf("Hypotenuse is %lf\n", side3);
	printf("\n");

	// 2.3
	printf("Task 2.3\n");
	double a, b, c;
	printf("Enter a, b, c\n");
	scanf_s("%lf %lf %lf", &a, &b, &c);
	double S = heron(a, b, c);
	printf("S=%lf\n",S);
	printf("\n"); 

	// 2.4
	printf("Task 2.4\n");
	double iks;
	printf("Enter x\n");
	scanf_s("%lf", &iks);
	printf("result a): %lf\n", task4a(iks));
	printf("result b): %lf\n", task4b(iks));
	printf("result c): %lf\n", task4c(iks));
	printf("result d): %lf\n", task4d(iks));
	printf("result e): %lf\n", task4e(iks));
	printf("result f): %lf\n", task4f(iks));
	printf("\n");

	// 2.5
	printf("Task 2.5\n");
	double epsilon = 2 * DBL_EPSILON;
	double x1 = 3.1, y1 = 5;
	if (fabs(Rosenbrock2d(x1, y1) - 2129.62) < 0.00001)
		printf("Rosenbrock2d for the numbers %f and %f is correct\n", x1, y1);
	double x2 = 1, y2 = 1;
	if (fabs(Rosenbrock2d(x2, y2)) < epsilon)
		printf("Rosenbrock2d for the numbers %f and %f is correct\n", x2, y2);
	double x3 = 1, y3 = 2;
	if (fabs(Rosenbrock2d(x3, y3) - 100) < epsilon)
		printf("Rosenbrock2d for the numbers %f and %f is correct\n", x3, y3);
	printf("\n");

	// 2.6
	printf("Task 2.6\n");
	double iks1, igrek1, iks2, igrek2, iks3, igrek3;
	double s1, s2, s3;
	double square;

	printf("Enter the parameters\n");
	scanf_s("%lf %lf", &iks1, &igrek1);
	scanf_s("%lf %lf", &iks2, &igrek2);
	scanf_s("%lf %lf", &iks3, &igrek3);

	s1 = length(iks1, igrek1, iks2, igrek2);
	s2 = length(iks1, igrek1, iks3, igrek3);
	s3 = length(iks3, igrek3, iks2, igrek2);

	square = heron(s1, s2, s3);
	printf("S = %lf\n", square);
	printf("\n");

	// 2.10
	printf("Task 2.10\n");
	double a1, a2, a3;
	printf("Enter 3 sides of the triangle\n");
	scanf_s("%lf %lf %lf", &a1, &a2, &a3);

	double angle1rad, angle2rad, angle3rad;
	angle1rad = acos((a1 * a1 + a2 * a2 - a3 * a3) / 2 / a1 / a2);
	angle2rad = acos((a1 * a1 + a3 * a3 - a2 * a2) / 2 / a1 / a3);
	angle3rad = acos((a3 * a3 + a2 * a2 - a1 * a1) / 2 / a3 / a2);

	printf("Angles in rad: %lf, %lf, %lf\n", angle1rad, angle2rad, angle3rad);

	double angle1degree, angle2degree, angle3degree;
	angle1degree = angle1rad * 180 / M_PI;
	angle2degree = angle2rad * 180 / M_PI;
	angle3degree = angle3rad * 180 / M_PI;

	printf("Angles in degrees: %lf, %lf, %lf\n", angle1degree, angle2degree, angle3degree);
	printf("\n");

	// 2.17 d)
	printf("Task 2.17 d)\n");
	double arg;
	printf("Enter x: ");
	scanf_s("%lf", &arg);

	printf("arctg(%lf) = %lf\n", arg, arctg(arg));
	printf("(derivative of arctg)(%lf) = %lf\n", arg, derivativeArctg(arg));
	printf("\n");

	return 0;
}