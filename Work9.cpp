#include <cstdio>
#include <cstdbool>
#include <cmath>

#define N 3
#define M 3

#define M1 20
#define N1 20

#define M2 25
#define N2 25

#define M3 100
#define N3 100

void task8_1()
{
	int matr[M][N] = { {1, 2, 3},
				   {4, 5, 6},
				   {7, 8, 9} };

	int m, n;
	printf("m, n = ");
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matr[i][j] == m)
			{
				matr[i][j] = n;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
}

void task8_2()
{
	double matr[M][N] = { {1.0, 2, 3},
				   {4, 5, 6},
				   {7, 8, 9} };

	int i, j;
	double a;

	do
	{
		printf("Input i (>= 0): ");
		scanf_s("%d", &i);
	} while (i < 0);

	do
	{
		printf("Input j (>= 0): ");
		scanf_s("%d", &j);
	} while (j < 0);

	printf("Input a: ");
	scanf_s("%lf", &a);

	if (i >= 3 || j >= 3) printf("Incorrect i, j\n");
	else
	{
		matr[i][j] = a;
	}

	for (int i0 = 0; i0 < M; i0++)
	{
		for (int j0 = 0; j0 < N; j0++)
		{
			printf("%lf ", matr[i0][j0]);
		}
		printf("\n");
	}
}

bool inputMatrix1(double matr[][N1], size_t m, size_t n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			printf("a[%zd, %zd] = ", i, j);
			int r = scanf_s("%lf", &matr[i][j]);
			if (r != 1) return false;
		}
	}
	return true;
}

int task8_3()
{
	double matr[M1][N1];

	size_t m, n;
	printf("m, n = ");
	scanf_s("%zd %zd", &m, &n);

	if (n > N1 || m > M1)
	{
		printf("Incorrect sizes %zu % zu!\n", m, n);
		return -1;
	}

	bool r = inputMatrix1(matr, m, n);
	if (!r)
	{
		printf("Input failed\n");
		return -2;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lf ", matr[i][j]);
		}
		printf("\n");
	}
}

bool inputMatrix2(double matr[][N2], size_t m, size_t n)
{
	int r;
	for (size_t i = 0; i < m; i++)
	{
		r = 0;
		printf("Row %zd: ", i);
		for (size_t j = 0; j < n; j++)
		{
			r += scanf_s("%lf", &matr[i][j]);
		}
		if (r != n) return false;
	}
	return true;
}

int task8_4()
{
	double matr[M2][N2];

	size_t m, n;
	printf("m, n = ");
	scanf_s("%zu %zu", &m, &n);

	if (n > N2 || m > M2)
	{
		printf("Incorrect sizes %zu % zu!\n", m, n);
		return -1;
	}

	bool r = inputMatrix2(matr, m, n);
	if (!r)
	{
		printf("Input failed\n");
		return -2;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lf ", matr[i][j]);
		}
		printf("\n");
	}
}

void transposeMatr(double matr[][N2], int n, int m)
{
	double tmp;
	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < n; j++)
		{
			tmp = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = tmp;
		}
	}
}

void task8_5()
{
	printf("Checking for function that transpose a matrix\n");
	double matr1[3][N2] = { {1,2,3},
	                       {4,5,6}, 
		                   {7,8,9} };

	transposeMatr(matr1, 3, 3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%lf ", matr1[i][j]);
		}
		printf("\n");
	}
}

void task8_6()
{
	double A[M3][N3];

	int m, n;

	int k;

	double sum = 0;

	do
	{
		printf("m = ");
		scanf_s("%d", &m);
	} while (m <= 0 || m >= 100);

	do
	{
		printf("n = ");
		scanf_s("%d", &n);
	} while (n <= 0 || n >= 100);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d, %d] = ", i, j);
			scanf_s("%lf", &A[i][j]);
		}
	}

	printf("k = ");
	scanf_s("%d", &k);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i - j == k) sum += A[i][j];
		}
	}

	printf("The sum of the A[i,j] (i - j == k) is %lf\n", sum);

}

double determinant(double matr[][N3], size_t n)
{
	if (n == 1) return matr[0][0];
	else if (n == 2) return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];

	double res = 0;
	int   sign = 1;

	double matrForEl[N3][N3];
	int cntRows = 0;
	int cntCols = 0;

	for (int i = 0; i < n; i++)
	{
		for (int i0 = 1; i0 < n; i0++)
		{
			for (int j0 = 0; j0 < n; j0++)
			{
				if (j0 == i) continue;
				matrForEl[cntRows][cntCols] = matr[i0][j0];
				cntCols++;
			}
			cntCols = 0;
			cntRows++;
		}

		cntRows = 0;
		cntCols = 0;

		res += sign * matr[0][i] * determinant(matrForEl, n - 1);
		sign *= -1;
	}

	return res;
}

void task8_7()
{
	double matr[N3][N3] = { {2,0,0,8},{0,1,0,8},{0,0,1,6}, {9,1,2,3} };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%lf ", matr[i][j]);
		}
		printf("\n");
	}

	printf("det = %lf\n", determinant(matr, 4));
}

void formMinor(double matr[][N3], double minor[][N3], size_t n, int i, int j)
{
	int cntRows = 0;
	int cntCols = 0;

	for (int k = 0; k < n; k++)
	{
		if (k == i) continue;
		for (int l = 0; l < n; l++)
		{
			if (l == j) continue;
			minor[cntRows][cntCols] = matr[k][l];
			cntCols++;
		}
		cntRows++;
		cntCols = 0;
	}
}

int task8_9()
{
	double matr1[N3][N3];
	int n;

	double matr2[N3][N3];
	double minor[N3][N3];
	int sign = 1;
	double det;
	double tmp;

	do
	{
		printf("n (< 100) = ");
		scanf_s("%d", &n);
	} while (n <= 0 || n >= 100);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d,%d] = ", i, j);
			scanf_s("%lf", &matr1[i][j]);
		}
	}

	det = determinant(matr1, n);

	if (fabs(det) < 0.00001)
	{
		printf("Det of matrix == 0\n");
		return -1;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j) % 2 == 0) sign = 1;
			else sign = -1;

			formMinor(matr1, minor, n, i, j);
			matr2[i][j] = sign * determinant(minor, n - 1) / det;
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			tmp = matr2[i][j];
			matr2[i][j] = matr2[j][i];
			matr2[j][i] = tmp;
		}
	}

	for (int p = 0; p < n; p++)
	{
		for (int t = 0; t < n; t++)
		{
			printf("%lf ", matr2[p][t]);
		}
		printf("\n");
	}

	return 0;
}

void task8_20()
{
	int n, m;
	double matr[M3][N3];

	int k;

	double tmp;

	do
	{
		printf("n (< 100) = ");
		scanf_s("%d", &n);
	} while (n <= 0 || n >= 100);

	do
	{
		printf("m (< 100) = ");
		scanf_s("%d", &m);
	} while (m <= 0 || m >= 100);

	do
	{
		printf("k (>= 0) = ");
		scanf_s("%d", &k);
	} while (k < 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0l; j < m; j++)
		{
			printf("a[%d, %d] = ", i, j);
			scanf_s("%lf", &matr[i][j]);
		}
	}

	for (int i0 = 0; i0 < n; i0++)
	{
		for (int j0 = 0; j0 < m; j0++)
		{
			printf("%lf ", matr[i0][j0]);
		}
		printf("\n");
	}

	if (k == 0) printf("Nothing to do\n");
	else
	{
		for (int p = m - k; p < m; p++)
		{
			for (int l = 0; l < n; l++)
			{
				tmp = matr[l][p];
				matr[l][p] = matr[l][p - (m - k)];
				matr[l][p - (m - k)] = tmp;
			}
		}
		printf("RESULT:\n");
		for (int i1 = 0; i1 < n; i1++)
		{
			for (int j1 = 0; j1 < m; j1++)
			{
				printf("%lf ", matr[i1][j1]);
			}
			printf("\n");
		}
	}	
}

int main()
{
	int n;

	printf("Input No of task [1-7, 9, 20]: ");
	scanf_s("%d", &n);

	switch (n)
	{
	case 1:
		task8_1();
		break;
	case 2:
		task8_2();
		break;
	case 3:
		task8_3();
		break;
	case 4:
		task8_4();
		break;
	case 5:
		task8_5();
		break;
	case 6:
		task8_6();
		break;
	case 7:
		task8_7();
		break;
	case 9:
		task8_9();
		break;
	case 20:
		task8_20();
		break;
	}
}