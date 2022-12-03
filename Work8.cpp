#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
#define N1 5
#define N2 4
#define N3 10
#define N4 5
#define N5 50
#define N6 20 

double sumEuler(double* mas, size_t N);

int maxInMas(int* mas, size_t N);

int inputUintMas(unsigned mas[]);

void cntOddEven(unsigned* mas, size_t N);

int inputDoubleMas(double mas[]);

void printDoubleMas(double* mas, size_t N);

int sumOfMass(double* mas1, size_t N01, double* mas2, size_t N02, double* res);

double scalarProdOfMass(double* mas1, size_t N01, double* mas2, size_t N02);



void task7_1()
{
	int mas[N1] = { 1, 2, 4, 44, 4 };

	double a;
	printf("a=");
	scanf_s("%lf", &a);

	int cnt = 0;
	for (int i = 0; i < N1; i++)
	{
		if (mas[i] < a) cnt++;
	}

	printf("There are %d elements less than a\n", cnt);
}

void task7_2()
{
	int mas[N2] = { 5, 112, 4, 3 };

	for (int i = N2 - 1; i >= 0; i--)
	{
		printf("%d ", mas[i]);
	}

	printf("\n");
}

void task7_3()
{
	double mas[N3];

	for (int i = 0; i < N3; i++)
	{
		printf("mas[%d]=", i);
		scanf_s("%lf", &mas[i]);
	}

	double s = sumEuler(mas, N3);
	printf("s=%lf", s);
}

double sumEuler(double* mas, size_t N)
{
	double res = 0;

	for (size_t i = 0; i < N; i++)
	{
		if (mas[i] > M_E) res += mas[i];
	}

	return res;
}

void task7_4()
{
	int mas[N4];

	for (int i = 0; i < N4; i++)
	{
		printf("mas[%d]=", i);
		scanf_s("%d", &mas[i]);
	}

	int maxEl = maxInMas(mas, N4);
	printf("max=%d", maxEl);
}

int maxInMas(int* mas, size_t N)
{
	int maxEl = mas[0];

	for (int i = 1; i < N; i++)
	{
		if (mas[i] > maxEl) maxEl = mas[i];
	}

	return maxEl;
}

void task7_5()
{
	unsigned mas[N5];

	int n = inputUintMas(mas);

	cntOddEven(mas, n);
}

int inputUintMas(unsigned* mas)
{
	unsigned tmp;
	int i = 0;
	do
	{
		printf("mas[%d]=", i);
		scanf_s("%d", &tmp);
		if (tmp == 0) break;
		mas[i] = tmp;
		i++;
	} while (i < N5 - 1);

	return i;
}

void cntOddEven(unsigned* mas, size_t N)
{
	int cntOdd  = 0;
	int cntEven = 0;

	for (int i = 0; i < N; i++)
	{
		if (mas[i] % 2 == 0) cntEven++;
		else cntOdd++;
	}

	printf("%d odd numbers and %d even numbers\n", cntOdd, cntEven);
}

void task7_6()
{
	double mas1[N6];
	double mas2[N6];

	int size1 = inputDoubleMas(mas1);
	int size2 = inputDoubleMas(mas2);

	printf("Array 1\n");
	printDoubleMas(mas1, size1);

	printf("Array 2\n");
	printDoubleMas(mas2, size2);
	
	printf("Sum of array 1 and array 2\n");
	if (size1 != size2) printf("Vectors have different sizes!\n");
	else
	{
		double sum[sizeof(mas1) / sizeof(mas1[0])];
		sumOfMass(mas1, size1, mas2, size2, sum);
		printDoubleMas(sum, size1);
	}
	
	printf("Scalar product of array 1 and array 2\n");
	if (size1 != size2) printf("Vectors have different sizes!\n");
	else
	{
		printf("res = %lf\n", scalarProdOfMass(mas1, size1, mas2, size2));
	}
}

int inputDoubleMas(double* mas)
{
	int n;

	do
	{
		printf("Input the length of vector (< 20): ");
		scanf_s("%d", &n);
	} while (n <= 0);

	for (int i = 0; i < n; i++)
	{
		printf("mas[%d]=", i);
		scanf_s("%lf", &mas[i]);
	}

	return n;
}

void printDoubleMas(double* mas, size_t N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%lf ", mas[i]);
	}
	printf("\n");
}

int sumOfMass(double* mas1, size_t N01, double* mas2, size_t N02, double* res)
{
	if (N01 != N02)
	{
		printf("Vectors have different sizes!\n");
		return -1;
	}

	for (int i = 0; i < N01; i++)
	{
		res[i] = mas1[i] + mas2[i];
	}
	return 1;
}

double scalarProdOfMass(double* mas1, size_t N01, double* mas2, size_t N02)
{
	if (N01 != N02)
	{
		printf("Vectors have different sizes!\n");
		return -1;
	}

	int res = 0;

	for (int i = 0; i < N01; i++)
	{
		res += mas1[i] * mas2[i];
	}
	return res;
}

void task7_9a()
{
	int n;

	double maxEl;
	double tmp;

	do
	{
		printf("Input the number of an: ");
		scanf_s("%d", &n);
	} while (n <= 0);

	printf("a[0] = ");
	scanf_s("%lf", &tmp);

	maxEl = tmp;

	for (int i = 1; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf_s("%lf", &tmp);
		if (tmp > maxEl) maxEl = tmp;
	}

	printf("a) Max a = %lf\n", maxEl);	
}

void task7_10b()
{
	int n;

	do
	{
		printf("Input the number of an (>= 2): ");
		scanf_s("%d", &n);
	} while (n < 2);

	double inp1, inp0;
	double maxEl;

	printf("a[0] = ");
	scanf_s("%lf", &inp0);

	printf("a[1] = ");
	scanf_s("%lf", &inp1);
	
	maxEl = inp0 + inp1;

	for (int i = 2; i < n; i++)
	{
		printf("a[%d] = ", i);
		inp0 = inp1;
		scanf_s("%lf", &inp1);
		if (inp0 + inp1 > maxEl) maxEl = inp0 + inp1;
	}

	printf("b) Max = %lf\n", maxEl);
}


int main()
{
	int n;

	printf("Input No of task [1-6, 9, 10]: ");
	scanf_s("%d", &n);

	switch (n)
	{
	case 1:
		task7_1();
		break;
	case 2:
		task7_2();
		break;
	case 3:
		task7_3();
		break;
	case 4:
		task7_4();
		break;
	case 5:
		task7_5();
		break;
	case 6:
		task7_6();
		break;
	case 9:
		task7_9a();
		break;
	case 10:
		task7_10b();
		break;
	}
}