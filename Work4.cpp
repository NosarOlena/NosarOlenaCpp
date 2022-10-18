#include <cstdio>
#include <cmath>
#include <cfloat>

void task4_1()
{
	unsigned i, n;
	float x, y;
	printf("x=");
	scanf_s("%f", &x);
	printf("n=");
	scanf_s("%u", &n);

	y = x;
	for (i = 0; i < n;i++)
	{
		y = sin(y);
	}
	printf("y=%g",y);
}

void task4_2()
{
	unsigned n, i1, i2;
	
	printf("Enter n ");
	scanf_s("%u", &n);

	printf("1)\n");
	printf("n! = ");
	for (i1 = 1; i1 <= n; i1++)
	{
		if (i1 != n) printf("%u*", i1);
		else printf("%u", i1);
	}
	printf("\n");
	printf("2)\n");
	printf("n! = ");
	for (i2 = n; i2 != 0; i2--)
	{
		if (i2 != 1) printf("%u*", n - i2 + 1);
		else printf("%u", n - i2 + 1);
	}
	printf("\n");
}

void task4_3a()
{
	unsigned i, n;
	float x, y, power;

	printf("x=");
	scanf_s("%f", &x);

	printf("n=");
	scanf_s("%u", &n);

	y = 1;
	power = 1;

	for (i = 1; i <= n; i++)
	{
		power *= x;
		y += power;
	}

	printf("y=%g\n", y);
}

void task4_3b()
{
	unsigned i, n;
	float x, y, z, power_x, power_y;

	printf("x=");
	scanf_s("%f", &x);

	printf("y=");
	scanf_s("%f", &y);

	printf("n=");
	scanf_s("%u", &n);

	z = 1;
	power_x = x * x;
	power_y = y;

	for (i = 1; i <= n; i++)
	{
		z += power_x * power_y;
		power_x *= power_x;
		power_y *= y;
	}

	printf("z=%g\n", z);

}

void task4_4()
{
	unsigned i, n;
	float x, y, power;

	printf("x=");
	scanf_s("%f", &x);
	printf("n=");
	scanf_s("%u", &n);

	y = 0;
	power = 1;
	for (i = 1; i <= n; i++)
	{
		power *= x;
		y += i * power;
	}
	printf("y=%g\n", y);
}

void task4_5()
{
	unsigned n, i;
	long long unsigned res = 1;

	printf("n=");
	scanf_s("%u", &n);

	i = n;
	while (i > 1)
	{
		res *= i;
		i -= 2;
	}

	printf("Result: %llu", res);

}

void task4_6a()
{
	unsigned i, n;
	double y = sqrt(2);

	printf("n=");
	scanf_s("%u", &n);

	for (i = 1; i < n;i++)
	{
		y = sqrt(2 + y);
	}

	printf("y=%f", y);

}

void task4_6b()
{
	unsigned i, n, koef;
	double y;

	printf("n=");
	scanf_s("%u", &n);

	koef = 3 * n;
	y = sqrt(koef);

	for (i = 1; i < n;i++)
	{
		koef -= 3;
		y = sqrt(y + koef);
	}

	printf("y=%f", y);
}

void task4_7()
{
	unsigned i, n, fact = 1;
	double x, y = 1, power = 1;

	printf("n=");
	scanf_s("%u", &n);

	while (1)
	{
		printf("Enter x, |x| < 1 ");
		scanf_s("%lf", &x);
		if (fabs(x) - 1 < 0) break;
		printf("Incorrect input\n");
	}

	for (i = 1; i <= n; i++)
	{
		fact *= i;
		power *= x;
		y += power / fact;
	}

	printf("y=%lf", y);
}

void task4_8()
{
	unsigned m, k;
	unsigned power4ink;

	while (1)
	{
		printf("Enter m, m >= 1 ");
		scanf_s("%u", &m);
		if (m >= 1) break;
		printf("Incorrect input\n");
	}

	k = 0;
	power4ink = 1;

	while (power4ink <= m)
	{
		k++;
		power4ink *= 4;
	}
	k--;

	printf("The greatest k such that 4^k <= %u is %u\n", m, k);
}

void task4_9()
{
	unsigned n, r;
	unsigned power2inr;

	while (1)
	{
		printf("Enter n, n >= 1 ");
		scanf_s("%u", &n);
		if (n >= 1) break;
		printf("Incorrect input\n");
	}
	
	r = 1; // n >= 1 -> 2^0 = 1 <= n -> min r = 1
	power2inr = 2;

	while (power2inr <= n)
	{
		r++;
		power2inr *= 2;
	}

	printf("The smallest r such that 2^r > %u is %u\n", n, r);
}

double seq4_18(double x, unsigned k)
{
	unsigned power = 2 * k;
	double xinpower = x, tmp = x;
	unsigned fact = 1;

	for (int i = 2 * k + 1; i > 1; i--)
	{
		fact *= i;
	}

	while (power >= 1)
	{
		if (power % 2 == 1)
		{
			xinpower *= tmp;
		}
		if (power == 1) break;
		tmp *= tmp;
		power /= 2;
	}

	return xinpower / fact;
}

int main()
{
	// 4.1
	printf("Task 4.1\n");
	task4_1();
	printf("\n");

	// 4.2
	printf("Task 4.2\n");
	task4_2();
	printf("\n");

	// 4.3
	printf("Task 4.3 a)\n");
	task4_3a();
	printf("Task 4.3 b)\n");
	task4_3b();
	printf("\n");

	// 4.4
	printf("Task 4.4\n");
	task4_4();
	printf("\n");

	// 4.5
	printf("Task 4.5\n");
	task4_5();
	printf("\n");

	// 4.6
	printf("Task 4.6 a)\n");
	task4_6a();
	printf("Task 4.6 b)\n");
	task4_6b();
	printf("\n");
	
	// 4.7
	printf("Task 4.7\n");
	task4_7();
	printf("\n");
	
	// 4.8
	printf("Task 4.8\n");
	task4_8();
	printf("\n");
	

	// 4.9
	printf("Task 4.9\n");
	task4_9();
	printf("\n");

	// 4.10
	printf("Task 4.9\n");
	
	float a = 1;
	while (1 + a != 1)
	{
		a /= 2;
	}
	a *= 2;

	printf("Float computer 0 is %.25f (with 25 digits after comma) without using lib\n", a);
	printf("Float computer 0 is %.25f (with 25 digits after comma) using lib\n", FLT_EPSILON);
	printf("\n");

	// 4.18 4)
	printf("Task 4.18 4)\n");

	unsigned k1;
	double x1;

	printf("k (k >= 0) = ");
	scanf_s("%u", &k1);
	printf("x = ");
	scanf_s("%lf", &x1);

	printf("Result: %lf\n", seq4_18(x1, k1));
	printf("\n"); 

	// 4.27 4)
	printf("Task 4.27 4)\n");

	double eps = 0.000001;

	double resPi = 0;
	double dodanok = 3.5;
	unsigned k2 = 0;
	int sign = 1;
	long long unsigned power4 = 1;

	while (dodanok >= eps)
	{
		if (sign == 1) resPi += dodanok;
		else resPi -= dodanok;
		k2++;
		sign *= -1;
		power4 *= 4;
		dodanok = (double)(20 * k2 + 12) / ((8 * k2 * k2 + 6 * k2 + 1) * power4);
	}

	printf("Result: %lf", resPi);
	printf("\n");
}