#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdbool>


int inputArray(double* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=", i);
		int res = scanf_s("%lf", &arr[i]);
		if (res != 1) return i;
	}
	return n;
}

double sum_sqr(double* arr, int n)
{
	double res = 0;
	for (int i = 0; i < n; i++)
	{
		res += arr[i] * arr[i];
	}
	return res;
}

void task9_1()
{
	int n;
	printf("n=");
	scanf_s("%d", &n);

	double* arr = (double*)malloc(n * sizeof(double));
	if (!arr)
	{
		printf("No allocated memory\n");
		return;
	}
	int k = inputArray(arr, n);

	printf("Sum of sqr = %lf", sum_sqr(arr, k));
	free(arr);
}


int inputArray2(int* arr, int n)
{
	int i = 0;
	do
	{
		printf("a[%d]=", i);
		int res = scanf_s("%lf", &arr[i]);
		if (res != 1) return i;
		if (arr[i] == 0) break;
		i++;
	} while (1);
	return i;
}

bool isSqr(int x)
{
	int m = (int)sqrt(x + 0.5);
	return m * m == x;
}

bool isCube(int x)
{
	int m = (int)round(pow(x, 1.0 / 3));
	return m * m * m == x;
}

void ShowSqrCubes(const int* arr, int n)
{
	int cntSqr = 0;
	int cntCubes = 0;
	for (int i = 0; i < n; i++)
	{
		if (isSqr(arr[i])) cntSqr++;
		if (isCube(arr[i])) cntCubes++;
	}

	printf("Number of squares - %d, number of cubes - %d\n", cntSqr, cntCubes);
}

int task9_2()
{
	const int N = 100;
	int* arr = (int*)malloc(N * sizeof(int));

	if (arr == NULL) return -1;


	int n = inputArray2(arr, N);
	ShowSqrCubes(arr, N);
	free(arr);
	return 0;
}


double* inputVect(int n)
{
	double* v = (double*)malloc(n * sizeof(*v));
	for (int i = 0; i < n; i++)
	{
		printf("v[%d] = ", i);
		int res = scanf_s("%lf", &v[i]);
		if (res != 1) return NULL;
	}
	return v;
}

void showVect(const double* v, int n)
{
	printf("(");
	for (int i = 0; i < n; i++)
	{
		printf("%lf, ", v[i]);
	}
	printf("\b\b)\n");
}

double* subVect(const double* v1, const double* v2, int n)
{
	double* v = (double*)calloc(n, sizeof(*v));
	for (int i = 0; i < n; i++)
	{
		v[i] = v1[i] - v2[i];
	}
	return v;
}

void deleteVect(double* v)
{
	free(v);
}

void task9_3()
{
	int n;
	printf("n = ");
	scanf_s("%d", &n);

	double* v1 = inputVect(n);
	showVect(v1, n);
	double* v2 = inputVect(n);
	showVect(v2, n);

	double* v3 = subVect(v1, v2, n);

	showVect(v3, n);

	deleteVect(v1);
	deleteVect(v2);
	deleteVect(v3);
}


double** allocMemory(int n)
{
	double** arr = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double*)calloc(n, sizeof(double));
	}
	return arr;
}

void freeMemory(double** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

double** multMatr(double** arr1, double** arr2, int n)
{
	double** res;
	res = allocMemory(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				res[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	return res;
}

void printMatr(double** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}
}

void inputMatr(double** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d values\n", n);
		for (int j = 0; j < n; j++)
		{
			scanf_s("%lf", &arr[i][j]);
		}
	}
}

int task9_4()
{
	double** arr1;
	double** arr2;
	double** mult;

	int n;

	printf("n = ");
	do
	{
		scanf_s("%d", &n);
	} while (n <= 0);

	arr1 = allocMemory(n);
	arr2 = allocMemory(n);

	if (!arr1 || !arr2)
	{
		printf("Memory fail\n");
		return -1;
	}

	printf("First matrix:\n");
	inputMatr(arr1, n);

	printf("Second matrix:\n");
	inputMatr(arr2, n);

	mult = allocMemory(n);
	if (!mult)
	{
		printf("Memory fail\n");
		return -1;
	}

	mult = multMatr(arr1, arr2, n);

	printf("RESULT:\n");
	printMatr(arr1, n);
	printf("\n\n");
	printMatr(arr2, n);
	printf("\n\nMultiplication:\n");
	printMatr(mult, n);

	freeMemory(arr1, n);
	freeMemory(arr2, n);
	freeMemory(mult, n);

	
	return 0;
}


double** allocMemoryAny(int n, int m)
{
	double** arr = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < m; i++)
	{
		arr[i] = (double*)calloc(m, sizeof(double));
	}
	return arr;
}

void freeMemoryAny(double** arr, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

void printMatrAny(double** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%lf ", arr[i][j]);
		}
		printf("\n");
	}
}

void inputMatrAny(double** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d values\n", m);
		for (int j = 0; j < m; j++)
		{
			scanf_s("%lf", &arr[i][j]);
		}
	}
}

void freeMemoryFinal(double*** arr, int k, int** sizes)
{
	for (int i = 0; i < k; i++)
	{
		freeMemoryAny(arr[i], sizes[i][0], sizes[i][1]);
	}
	free(arr);

	for (int j = 0; j < 2; j++)
	{
		free(sizes[j]);
	}
	free(sizes);
}

int task9_6()
{
	double*** arr;
	int k;
	int n, m;

	double** matr;

	int n0, m0;
	bool isSameSizes = 1;

	double** suma;

	int** sizes;

	do
	{
		printf("Input the number of matrixes: ");
		scanf_s("%d", &k);
	} while (k <= 0);

	arr = (double***)malloc(k * sizeof(double**));
	if (!arr)
	{
		printf("Memory fail\n");
		return -1;
	}

	sizes = (int**)malloc(k * sizeof(int*));
	for (int q = 0; q < 2; q++)
	{
		sizes[q] = (int*)calloc(2, sizeof(int));
	}
	if (!sizes)
	{
		printf("Memory fail\n");
		return -1;
	}


	for (int i = 0; i < k; i++)
	{
		do
		{
			printf("Input the number of rows for matrix #%d: ", i);
			scanf_s("%d", &n);
		} while (n <= 0);

		do
		{
			printf("Input the number of columns for matrix #%d: ", i);
			scanf_s("%d", &m);
		} while (m <= 0);

		sizes[i][0] = n;
		sizes[i][1] = m;

		matr = allocMemoryAny(n, m);
		if (!matr)
		{
			printf("Memory fail\n");
			return -1;
		}
		inputMatrAny(matr, n, m);
		arr[i] = matr;

		if (i == 0)
		{
			n0 = n; 
			m0 = m;
		}
		if (i > 0 && isSameSizes == 1)
		{
			if (n0 != n || m0 != m) isSameSizes = 0;
			n0 = n;
			m0 = m;
		}
	}

	if (isSameSizes == 0) printf("Different sizes of matrixes\n");
	else
	{

		suma = allocMemoryAny(n, m);
		if (!suma)
		{
			printf("Memory fail\n");
			return -1;
		}
		for (int p = 0; p < n; p++)
		{
			for (int t = 0; t < m; t++)
			{
				for (int j = 0; j < k; j++)
				{
					suma[p][t] += arr[j][p][t];
				}
			}
		}

		printMatrAny(suma, n, m);

		freeMemoryAny(suma, n, m);
	}
	
	freeMemoryFinal(arr, k, sizes);

	return 0;
}


void deleteRows(double** arr, int n, int m, int* rowsToDelete)
{
	double minEl = fabs(arr[0][0]);
	int cnt = 0;

	double** res;
	int row = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (fabs(arr[i][j]) < minEl) minEl = fabs(arr[i][j]);
		}
	}

	for (int r = 0; r < n; r++)
	{
		for (int t = 0; t < m; t++)
		{
			if (fabs(arr[r][t]) == minEl)
			{
				cnt++;
				rowsToDelete[r] = 1;
				break;
			}
		}
	}

	if (n - cnt == 0)
	{
		printf("Everything is deleted\n");
	}
	else
	{
		res = allocMemoryAny(n - cnt, m);
		for (int w = 0; w < n; w++)
		{
			if (rowsToDelete[w] == 1) continue;
			for (int q = 0; q < m; q++)
			{
				res[w][q] = arr[w][q];
			}
			row++;
		}
		printMatrAny(res, n - cnt, m);
		freeMemoryAny(res, n - cnt, m);
	}
}

void task9_9s()
{
	int n, m;

	do
	{
		printf("Input the number of rows: ");
		scanf_s("%d", &n);
	} while (n <= 0);

	do
	{
		printf("Input the number of columns: ");
		scanf_s("%d", &m);
	} while (m <= 0);

	double** matr;
	matr = allocMemoryAny(n, m);

	inputMatrAny(matr, n, m);

	int* rowsToDelete = (int*)malloc(n * sizeof(int));
	for (int p = 0; p < n; p++)
	{
		rowsToDelete[p] = 0;
	}

	deleteRows(matr, n, m, rowsToDelete);

	freeMemoryAny(matr, n, m);

	free(rowsToDelete);
}



int main()
{
	int n;

	printf("Input No of the task [1-4, 6, 9]: ");
	scanf_s("%d", &n);

	switch (n)
	{
	case 1:
		task9_1();
		break;
	case 2:
		task9_2();
		break;
	case 3:
		task9_3();
		break;
	case 4:
		task9_4();
		break;
	case 6:
		task9_6();
		break;
	case 9:
		task9_9s();
		break;
	}
}