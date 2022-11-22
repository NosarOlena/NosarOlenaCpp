#include <cstdio>
#include <cmath>

double exponent(double x, double eps)
{
	double res = 1;
	int i = 0;

	double dodanok = x;

	while (fabs(dodanok) >= eps)
	{
		i++;
		dodanok *= x / i;
		res += dodanok;
	}

	return res;
}

double expIntegral(double x, double eps)
{
	double res = x;
	int i = 1;

	double dodanok = x;
	double factorial = 1;

	while (fabs(dodanok) >= eps)
	{
		i += 2;
		dodanok *= x * x / i / factorial;
		factorial *= (i - 1) * i;
		res += dodanok;
	}

	return res;
}

void task5_19()
{
	double eps;

	double a = 0.001;
	double b = 1.5;

	double c;

	do
	{
		printf("Input positive eps: ");
		scanf_s("%lf", &eps);
	} while (eps <= 0);

	double tg_a;
	double tg_c;

	tg_a = tan(a) - a;

	do
	{
		c = (a + b) / 2;

		tg_c = tan(c) - c;

		if (tg_a * tg_c <= 0) a = c;
		else b = c;
	} while (b - a >= eps);


	printf("Root is %lf\n", c);
	printf("Checking: tg(%lf) is %lf\n", c, tan(c));
}

void task5_22()
{
	int k;

	int cnt = 0;

	do
	{
		printf("Input positive k: ");
		scanf_s("%d", &k);
	} while (k <= 0);

	double a0 = 1;
	double b0 = sqrt(2) / 2;
	double t0 = 0.25;
	double p0 = 1;

	double ak = a0;
	double bk = b0;
	double tk = t0;
	double pk = p0;

	while (cnt <= k)
	{
		cnt++;
		a0 = ak;
		b0 = bk;

		ak = (a0 + b0) / 2;
		bk = sqrt(a0 * b0);

		p0 = pk;
		pk = p0 * 2;

		t0 = tk;
		tk = t0 - p0 * (a0 - ak) * (a0 - ak);
	}

	double res = (ak + bk) * (ak + bk) / 4 / tk;
	printf("pi = %lf\n", res);
}

void task4_30()
{
	unsigned n;
	unsigned ncopy;

	unsigned d = 2;
	unsigned chislOfRes = 1;
	unsigned znamOfRes = 1;


	do
	{
		printf("Input positive n: ");
		scanf_s("%d", &n);
	} while (n <= 0);

	ncopy = n;

	while (ncopy > 1)
	{
		if (ncopy % d == 0)
		{
			chislOfRes *= (d - 1);
			znamOfRes *= d;
		}

		while (ncopy % d == 0)
		{

			ncopy /= d;
		}
		d++;
	}

	printf("Euler`s function of %u is %u\n", n, n * chislOfRes / znamOfRes);
}

int main()
{
	// 5.6 and 5.7 in the previous pull request
	
	printf("Task 5.8\n");
	// 5.8 a)
	double x5_8a, eps5_8a;

	printf("Input x for a): ");
	scanf_s("%lf", &x5_8a);

	do 
	{
		printf("Input positive eps for a): ");
		scanf_s("%lf", &eps5_8a);
	} while (eps5_8a <= 0);
	
	printf("exp(%lf) = %lf\n", x5_8a, exponent(x5_8a, eps5_8a));
	// 5.8 b)
	double x5_8b, eps5_8b;

	printf("Input x for b): ");
	scanf_s("%lf", &x5_8b);

	do
	{
		printf("Input positive eps for b): ");
		scanf_s("%lf", &eps5_8b);
	} while (eps5_8b <= 0);

	printf("F(%lf) = %lf\n", x5_8b, expIntegral(x5_8b, eps5_8b));
	printf("\n");

    // 5.19
	printf("Task 5.19\n");
	task5_19();
	printf("\n");
	
	// 5.22
	printf("Task 5.22\n");
	task5_22();
	printf("\n");

	// 4.30
	printf("Task 4.30\n");
	task4_30();
}
