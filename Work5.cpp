#include <cstdio>
#include <cmath>

// function for 5.2 1)
unsigned long long Fib(unsigned n)
{
	unsigned long long F0 = 0;
	unsigned long long F1 = 1UL;
	unsigned long long F  = 1UL;

	if (n == 0) return 0;
	if (n == 1) return 1;

	for (unsigned i = 2; i <= n; i++)
	{
		F = F0 + F1;
		F0 = F1;
		F1 = F;
	}
	return F;
}

// function for 5.2 2)
unsigned NFibLessOrEqual(double a)
{
	unsigned long long F0 = 0;
	unsigned long long F1 = 1UL;
	unsigned long long F = 1UL;

	if (a <= 0) return -1; // a <= 0 means that every Fibbonacci number is not smaller then a
	if (a <= 1) return 2;

	unsigned n = 1;
	while (F <= a)
	{
		n++;
		F = F0 + F1;
		F0 = F1;
		F1 = F;
	}
	return n - 1;
}

// function for 5.2 3)
unsigned NFibGreater(double a)
{
	unsigned long long F0 = 0;
	unsigned long long F1 = 1UL;
	unsigned long long F = 1UL;

	if (a < 0) return 0;
	if (a < 1) return 1;

	unsigned n = 1;
	while (F <= a)
	{
		n++;
		F = F0 + F1;
		F0 = F1;
		F1 = F;
	}
	return n;
}

// function for 5.3
int collatz(int k, int n)
{
	int a0 = n;
	if (k == 0) return a0;

	for (int i = 1; i <= k; i++)
	{
		if (a0 % 2 == 0)
		{
			a0 = a0 / 2;
		}
		else
		{
			a0 = 3 * a0 + 1;
		}
	}
	return a0;
}

// function for 5.4 1)
double dobutok4a(int n)
{
	double P = 1;
	double invFact = 1;

	for (int i = 1; i <= n; i++)
	{
		invFact /= i;
		P *= (1 + invFact);
	}
	return P;
}

// function for 5.4 2)
double dobutok4b(int n)
{
	// 1 + (-1)^(i + 1) * i^2 / 2^(i + 1)
	double P = 1;
	double dodanok =  1.0 / 4;

	for (int i = 2; i <= n; i++)
	{
		P *= (1 + dodanok);
		dodanok *= -1 * i * i / 2 / (i - 1)/ (i - 1);
		
	}
	return P * (1 + dodanok);
}

// function for 5.5
void task5()
{
	int x1 = -99, x2 = -99, x3 = -99;
	int x = x3;
	int i = 3;
	while (x <= 0)
	{
		i++;
		x = x3 + x1 + 100;
		x1 = x2;
		x2 = x3;
		x3 = x;
	}
	printf("x(%d) = %d\n", i, x);
}

void task6a(int b, unsigned n)
{
	// version 1
	double res = b;

	for (unsigned i = 1; i <= n; i++)
	{
		res = b + 1.0 / res;
	}

	printf("v. 1: b(%u) = %lf\n", n, res);

	// version 2
	int znam = b;
	int chisl = b * b + 1;
	int extra;

	for (unsigned i = 2; i <= n; i++)
	{
		extra = znam;
		znam = chisl;
		chisl = b * chisl + extra;
	}

	printf("v. 2: b(%u) = %lf\n", n, (double)chisl / znam);
}

void task6b(unsigned n)
{
	double res = 4 * n + 2;

	for (unsigned i = 2; i <= n; i++)
	{
		res = 1.0 / res + 4 * (n - i) + 2;
	}

	printf("l(%u) = %lf\n", n, res);
}

void task6c(unsigned n)
{
	double res = 1.0 / 2;

	for (unsigned i = 1; i <= n; i++)
	{
		if (i % 2 == 1) res = 1 + 1.0 / res;
		else res = 2 + 1.0 / res;
	}

	printf("x(2*%u) = %lf\n", n, res);
}

void task7(unsigned n)
{
	double b1 = 1.0, b2 = 0.0;
	double a1 = 0.0, a2 = 1.0;

	double bn, an;
	unsigned power2 = 1;

	double suma = 0;

	for (unsigned i = 1; i <= n; i++)
	{
		if (i == 1) 
		{
			bn = b1;
			an = a1;
		}
		else
		{
			if (i == 2)
			{
				bn = b2;
				an = a2;
				a2 = a1;
			}
			else
			{
				bn = bn + an;
				a1 = a2;
				a2 = an;
				an = a2 / i + a1 * bn;
			}
		}
		power2 *= 2;
		suma += (double)power2 / (an + bn);
	}

	printf("S(%u) = %lf\n", n, suma);
}

void task11(unsigned n)
{
	double a0, a1, an;

	unsigned power2 = 2;
	double invFact = 1;

	double suma = 0;

	a0 = 1;
	a1 = a0 + invFact;
	suma += power2 * invFact * a1;
	for (unsigned i = 2; i <= n; i++)
	{
		an = i * a1 + 1.0 / i;
		a0 = a1;
		a1 = an;
		invFact /= i;
		power2 *= 2;
		suma += power2 * invFact * an;
	}
	printf("S(%u) = %lf\n", n, suma);
}

void task16(double eps, double x)
{
	double    suma = 0;
	double dodanok = x;
	int        cnt = 0;

	while (fabs(dodanok) >= eps)
	{
		cnt++;
		dodanok *= x * x * (2 * cnt - 1) / (2 * cnt);
		suma += dodanok;
	}

	printf("arcsin(%lf) = %lf\n", x, suma);
}

int main()
{
	// 5.1
	printf("Task 5.1\n");

	double a1;
	printf("Enter a: ");
	scanf_s("%lf", &a1);

	double s = 0;
	int i = 1;
	while (s <= a1)
	{
		s += 1.0 / i;
		i++;
	}
	i--;
	printf("S(%d) = %lf > %lf\n", i, s, a1);
	printf("The smallest n > 0 that %lf > S is %d\n", a1, i);
	printf("\n");
	
	// 5.2
	printf("Task 5.2\n");

	unsigned n;
	printf("Enter a for the task 5.2 a): ");
	scanf_s("%u", &n);
	printf("F(%u) = %llu\n", n, Fib(n));

	double a2;
	printf("Enter a for the task 5.2 b): ");
	scanf_s("%lf", &a2);
	printf("The largest n such that F(n) <= %lf is %u\n", a2, NFibLessOrEqual(a2));

	double a3;
	printf("Enter a for the task 5.2 c): ");
	scanf_s("%lf", &a3);
	printf("The smallest n such that F(n) > %lf is %u\n", a3, NFibGreater(a3));

	unsigned long suma = 0;

	unsigned long F0 = 0;
	unsigned long F1 = 1UL;
	unsigned long F  = 1UL;

	while (F <= 1000)
	{
		suma += F;
		F = F0 + F1;
		F0 = F1;
		F1 = F;
	} 
	printf("Sum of the Fibonacci numbers that are not greater than 1000 is %lu\n", suma);
	printf("\n");
	
	
	// 5.3
	printf("Task 5.3\n");
	int MaxJ = 0;
	int TheN;
	for (int num = 1; num <= 1000; num++)
	{
		int a = num;
		int j = 0;
		while (a != 1)
		{
			j++;
			a = collatz(j, num);
			if (j > 1000000)
			{
				printf("We break the conjecture!");
				break;
			}
		}
		if (j > MaxJ)
		{
			MaxJ = j;
			TheN = num;
		}
	}
	printf("The number which requires the largest number of steps (= %d) is %d\n", MaxJ, TheN);
	printf("\n");
	
	// 5.4
	printf("Task 5.4\n");

	int n1;
	printf("Enter n for the task 5.4 a): ");
	scanf_s("%d", &n1);
	printf("The result is %lf\n", dobutok4a(n1));

	int n2;
	printf("Enter n for the task 5.4 b): ");
	scanf_s("%d", &n2);
	printf("The result is %lf\n", dobutok4b(n2));
	printf("\n");

	// 5.5
	printf("Task 5.5\n");
	task5();
	printf("\n");
	
	// 5.6
	printf("Task 5.6\n");
	unsigned k1;
	double b;

	printf("Enter n for the task 5.6 a): ");
	scanf_s("%u", &k1);
	printf("Enter b for the task 5.6 a): ");
	scanf_s("%lf", &b);

	task6a(b, k1);

	unsigned k2;

	printf("Enter n for the task 5.6 b): ");
	scanf_s("%u", &k2);

	task6b(k2);

	unsigned k3;

	printf("Enter n for the task 5.6 c): ");
	scanf_s("%u", &k3);

	task6c(k3);
	printf("\n");
	
	// 5.7
	printf("Task 5.7\n");
	unsigned n7; 

	printf("Enter n for the task 5.7: ");
	scanf_s("%u", &n7);

	task7(n7);
	printf("\n");
	
	// 5.11 6)
	printf("Task 5.11 6)\n");
    unsigned n11;

    printf("Enter n for the task 5.11: ");
    scanf_s("%u", &n11);

    task11(n11);
	printf("\n");
	
    // 5.16 14)
	printf("Task 5.16 14)\n");
    double eps;
	double x;

	printf("Enter epsilon: ");
	scanf_s("%lf", &eps);

	printf("Enter x, |x| < 1: ");
	scanf_s("%lf", &x);
	while (fabs(x) >= 1)
	{
		printf("Incorrect input\n");
		printf("Enter x, |x| < 1: ");
		scanf_s("%lf", &x);
	}

	task16(eps, x);
	printf("\n");
}