#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <cmath>

void print_digits(unsigned n)
{
	unsigned a = n % 10;
	unsigned b = (n /10) % 10;
	unsigned c = n / 100;
	printf("%u %u %u\n", a, b, c);

}

unsigned sum_digits(unsigned n)
{
	return n % 10 + (n / 10) % 10 + n / 100;
}

unsigned inverse(unsigned n)
{
	unsigned a = n % 10;
	unsigned b = (n / 10) % 10;
	unsigned c = n / 100;
	return a * 100 + b * 10 + c;
}

void task3_2(unsigned n)
{
	unsigned a = n % 10;
	unsigned b = (n / 10) % 10;
	unsigned c = n / 100;
	if (a != b && b != c && a != c)
	{
		printf("%u\n", a * 100 + b * 10 + c);
		printf("%u\n", a * 100 + c * 10 + b);
		printf("%u\n", b * 100 + a * 10 + c);
		printf("%u\n", b * 100 + c * 10 + a);
		printf("%u\n", c * 100 + a * 10 + b);
		printf("%u\n", n);
	}
	else printf("The number has digits that are the same\n");
}

void task3_7a(double a, double b, double c)
{
	if (fabs(a) < 0.00001) // if a == 0
	{
		if (fabs(b) < 0.00001) // if a == 0 && b == 0
		{
			if (fabs(c) < 0.00001) // if a == 0 && b == 0 && c == 0
			{
				printf("Infinite number of x's from R\n");
			}
			else
			{
				printf("No solves\n");
			}
		}
		else
		{
			double x = -c / b;
			printf("The only solve is %lf\n", x);
		}
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (fabs(D) < 0.00001) // D == 0
		{
			double x = -b / 2 / a;
			printf("The only solve is %lf\n", x);
		}
		else
		{ 
			if (D > 0)
			{
				double x1, x2;
				x1 = (-b + sqrt(D)) / 2 / a;
				x2 = (-b - sqrt(D)) / 2 / a;
				printf("Two solves: %g, %g", x1, x2);
			}
			else
			{
				printf("No solves\n");
			}
		}
	}
}

void task3_7b(double a, double b, double c)
{
	if (fabs(a) < 0.00001) // if a == 0
	{
		if (fabs(b) < 0.00001) // if a == 0 && b == 0
		{
			if (fabs(c) < 0.00001) // if a == 0 && b == 0 && c == 0
			{
				printf("Infinite number of x's from R\n");
			}
			else
			{
				printf("No solves\n");
			}
		}
		else
		{
			double x = -c / b;
			if (x > 0)
			{
				x = sqrt(x);
				printf("The solves are %lf, %lf\n", x, -x);
			}
			else
			{
				if (fabs(x) < 0.00001)
				{
					printf("The only solve is %lf\n", x);
				}
				else
				{
					printf("No solves\n");
				}
			}
		}
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (fabs(D) < 0.00001) // D == 0
		{
			double x = -b / 2 / a;
			if (x > 0)
			{
				x = sqrt(x);
				printf("The solves are %lf, %lf\n", x, -x);
			}
			else
			{
				if (fabs(x) < 0.00001)
				{
					printf("The only solve is %lf\n", x);
				}
				else
				{
					printf("No solves\n");
				}
			}
		}
		else
		{
			if (D > 0)
			{
				double x1, x2;
				x1 = (-b + sqrt(D)) / 2 / a;
				x2 = (-b - sqrt(D)) / 2 / a;
				unsigned num1_of_solves = 0;
				unsigned num2_of_solves = 0;
				if (x1 > 0)
				{
					x1 = sqrt(x1);
					num1_of_solves = 2;
				}
				else
				{
					if (fabs(x1) < 0.00001)
					{
						num1_of_solves = 1;
					}
				}
				if (x2 > 0)
				{
					x2 = sqrt(x2);
					num2_of_solves = 2;
				}
				else
				{
					if (fabs(x2) < 0.00001)
					{
						num2_of_solves = 1;
					}
				}
				if (num1_of_solves + num2_of_solves == 0) printf("No solves\n");
				else
				{
					printf("%u solves:\n", num1_of_solves + num2_of_solves);
					if (num1_of_solves == 1) printf("%lf ", x1);
					else if (num1_of_solves == 2) printf("%lf %lf", x1, -x1);
					if (num2_of_solves == 1) printf("%lf ", x2);
					else if (num2_of_solves == 2) printf("%lf %lf", x2, -x2);
				}

			}
			else printf("No solves\n");
		}
	}
}

void task3_13b(double a, double b, double c)
{
	// |x+y| = 1 -> x+y = or x+y = -1

	double x1, y1;
	double x2, y2;

	// x+y = 1
	int num1_of_solves = 0;
	if (fabs(a - b) < 0.00001)
	{
		if (fabs(b + c) < 0.00001) num1_of_solves = -1; // infinite number of solves
	}
	else
	{
		x1 = -(b + c) / (a - b);
		y1 = -x1 + 1;
		num1_of_solves = 1;
	}

	// x+y = -1
	int num2_of_solves = 0;
	if (fabs(a - b) < 0.00001)
	{
		if (fabs(-b + c) < 0.00001) num2_of_solves = -1; // infinite number of solves
	}
	else
	{
		x2 = -(-b + c) / (a - b);
		y2 = -x2 - 1;
		num2_of_solves = 1;
	}

	if (num1_of_solves == -1 || num2_of_solves == -1) printf("Infinite number of x's and y's\n");
	else
	{
		if (num1_of_solves == 0 && num2_of_solves == 0) printf("No solves\n");
		else
		{
			printf("Solves: ");
			if (num1_of_solves == 1) printf("(%lg,%lg) ", x1, y1);
			if (num2_of_solves == 1) printf("(%lg,%lg) ", x2, y2);
		}
	}
}

double isReLu(double a, double x)
{
	if (x < 0) 
	{
		return x / sqrt(1 + a * x * x);
	}
	else
	{
		return x;
	}
}

double isReLuDer(double a, double x)
{
	if (x < 0)
	{
		return 1 / (1 + a * x * x) / sqrt(1 + a * x * x);
	}
	else
	{
		return 1;
	}
}

int main()
{
	// 3.1
	printf("Task 3.1\n");
	unsigned n1;
	printf("n=");
	scanf_s("%u", &n1);

	if (n1>=1000 || n1<100) 
	{
		printf("n is not 3-digit!");
		return 0;
	}
	print_digits(n1);
	printf("sum of digits %u\n", sum_digits(n1));
	printf("inverse number %u\n",inverse(n1));
	printf("\n");

	// 3.2
	printf("Task 3.2\n");
	unsigned n2;
	printf("n=");
	scanf_s("%u", &n2);

	if (n2 >= 1000 || n2 < 100)
	{
		printf("n is not 3-digit!");
		return 0;
	}
	task3_2(n2);
	printf("\n");

	// 3.3 a) and b) 
	printf("Task 3.3\n");
	int num1, num2, num3;
	unsigned long long res; // for a) int can be used

	printf("Enter 3 numbers with commas\n");
	int is_correct = scanf_s("%d, %d, %d", &num1, &num2, &num3);
	if (is_correct != 3)
	{
		printf("Incorrect input\n");
		return -1;
	}
	res = (unsigned long long) num1 * num2 * num3;
	printf("Result: %llu\n", res);
	printf("\n");

	// 3.4
	printf("Task 3.4\n");
	uint8_t arg1, arg2;
	uint16_t prod;

	printf("Enter two 8-bit numbers\n");
	scanf_s("%" SCNu8, &arg1);
	scanf_s("%" SCNu8, &arg2);
	prod = (uint16_t)arg1 * arg2;
	printf("Result: %" PRIu16, prod);
	printf("\n");

	// 3.5
	printf("Task 3.5\n");
	float a, b;
	printf("Enter 2 numbers\n");
	scanf_s("%f %f", &a, &b);
	if (a > b) printf("%g > %g\n", a, b);
	else if (a < b) printf("%g > %g\n", b, a);
		 else printf("%g == %g\n", a, b);
	printf("\n");

	// 3.6
	printf("Task 3.6\n");
	float a1, a2, a3;
	float largest, smallest;

	printf("Enter 3 numbers\n");
	scanf_s("%f %f %f", &a1, &a2, &a3);

	if (fabs(a1) > fabs(a2)) largest = a1;
	else largest = a2;
	if (fabs(a3) > largest) largest = a3;

	if (fabs(a1) < fabs(a2)) smallest = a1;
	else smallest = a2;
	if (fabs(a3) < smallest) smallest = a3;

	printf("The largest: %g\n", largest);
	printf("The smallest: %g\n", smallest);
	printf("\n");

	// 3.7 a)
	printf("Task 3.7 a)\n");
	double a3_7a, b3_7a, c3_7a;

	printf("Enter a, b, c with whitespaces\n");
	scanf_s("%lf %lf %lf", &a3_7a, &b3_7a, &c3_7a);

	task3_7a(a3_7a, b3_7a, c3_7a);
	printf("\n");

	// 3.7 b)
	printf("Task 3.7 b)\n");
	double a3_7b, b3_7b, c3_7b;

	printf("Enter a, b, c with whitespaces\n");
	scanf_s("%lf %lf %lf", &a3_7b, &b3_7b, &c3_7b);

	task3_7b(a3_7b, b3_7b, c3_7b);
	printf("\n");

	// 3.13 b)
	printf("Task 3.13 b)\n");
	double a3_13b, b3_13b, c3_13b;

	printf("Enter a, b, c with whitespaces\n");
	scanf_s("%lf %lf %lf", &a3_13b, &b3_13b, &c3_13b);

	task3_13b(a3_13b, b3_13b, c3_13b);
	printf("\n");

	// 3.23 e)
    printf("Task 3.23 e)\n");
	double a3_23, x3_23;

	printf("Enter a and x with a whitespace\n");
	scanf_s("%lf %lf", &a3_23, &x3_23);

	if (x3_23 < 0 && fabs(1 + a3_23 * x3_23 * x3_23) < 0.00001)
	{
		printf("The function can't be defined\n");
		return -1;
	}
	printf("Function: %lg\n", isReLu(a3_23, x3_23));
	printf("Derivative: %lg\n", isReLuDer(a3_23, x3_23));

	return 0;
}