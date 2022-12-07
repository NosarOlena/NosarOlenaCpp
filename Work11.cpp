#include <cstdio>
#include <cstdbool>
#include <ctype.h>
#include <cstring>
#include <cmath>

#define MAXNAME 16
#define N 3


struct Date
{
	int day;
	int month;
	int year;
};

bool isLeap(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0 && y % 400 != 0) return false;
		return true;
	}
	else return false;
}

bool isCorrectDate(int d, int m, int y)
{
	if (y < 0) return false;
	switch (m)
	{
	case  1: 
		if (d <= 0 || d > 31) return false;
		break;
	case  2:
		if (isLeap(y))
		{
			if (d <= 0 || d > 29) return false;
			break;
		}
		else
		{
			if (d <= 0 || d > 28) return false;
			break;
		}		
	case  3:
		if (d <= 0 || d > 31) return false;
		break;
	case  4:
		if (d <= 0 || d > 30) return false;
		break;
	case  5:
		if (d <= 0 || d > 31) return false;
		break;
	case  6:
		if (d <= 0 || d > 30) return false;
		break;
	case  7:
		if (d <= 0 || d > 31) return false;
		break;
	case  8:
		if (d <= 0 || d > 31) return false;
		break;
	case  9:
		if (d <= 0 || d > 30) return false;
		break;
	case 10:
		if (d <= 0 || d > 31) return false;
		break;
	case 11:
		if (d <= 0 || d > 30) return false;
		break;
	case 12:
		if (d <= 0 || d > 31) return false;
		break;
	default:
		return false;
	}
	return true;
}

Date inputDate()
{
	int d, m, y;
	while (1)
	{
		printf("Input day: ");
		scanf_s("%d", &d);
		printf("Input month: ");
		scanf_s("%d", &m);
		printf("Input  year: ");
		scanf_s("%d", &y);
		if (isCorrectDate(d, m, y)) break;
		else printf("Incorrect input\n");
	}
	Date res = Date{ d, m, y };
	return res;
}

void outputDate(Date theDate)
{
	printf("%d.%d.%d\n", theDate.day, theDate.month, theDate.year);
}


struct Field
{
	char col;
	unsigned row;
};

bool isCorrectField(Field theField)
{
	if (!isalpha(theField.col)) return false;

	if (theField.col < 'a' || theField.col > 'h') return false;

	if (theField.row == 0 || theField.row > 8) return false;

	return true;

}

Field inputField()
{
	char col;
	unsigned row;

	Field res;

	while (1)
	{
		printf("Input col [a - h]: ");
		scanf_s(" %c", &col);
		printf("Input row [1 - 8]: ");
		scanf_s(" %u", &row);
		res = Field{ col, row };
		if (isCorrectField(res)) break;
		else printf("Incorrect input\n");
	}
	return res;
}

void output(Field theField)
{
	printf("%c%u\n", theField.col, theField.row);
}


struct Vertex
{
	double x;
	double y;
};

Vertex inputVertex()
{
	Vertex res;

	double x, y;

	printf("Input x: ");
	scanf_s("%lf", &x);
	printf("Input y: ");
	scanf_s("%lf", &y);

	res = Vertex{ x,y };

	return res;

}

void output(Vertex theVertex)
{
	printf("(%lf, %lf)\n", theVertex.x, theVertex.y);
}

struct Rectangle
{
	Vertex v1;
	Vertex v2;
};

bool isCorrectRectangle(Rectangle theRectangle)
{
	if (fabs(theRectangle.v1.x - theRectangle.v2.x) < 0.000001) return false;

	if (fabs(theRectangle.v1.y - theRectangle.v2.y) < 0.000001) return false;

	return true;
}

Rectangle inputRectangle()
{
	Rectangle res;

	while (1)
	{
		printf("Input Vertex 1:\n");
		Vertex v1 = inputVertex();
		printf("Input Vertex 2:\n");
		Vertex v2 = inputVertex();
		res = Rectangle{ v1, v2 };
		if (isCorrectRectangle(res)) break;
		printf("Incorrect input\n");
	}

	return res;
}

void outputRectangle(Rectangle theRectangle)
{
	printf("v1: ");
	output(theRectangle.v1);
	printf("v2: ");
	output(theRectangle.v2);
	printf("\n");
}


struct Polynom
{
	double* koefs;
	int* powers;
};

Polynom inputPolynom()
{
	Polynom res;

	double* koefs;
	int* powers;

	int n;
	do
	{
		printf("Input the number of monomials: ");
		scanf_s("%d", &n);
	} while (n <= 0);

	koefs = (double*)malloc(n * sizeof(double));
	powers = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("Input the koefficient: ");
		scanf_s("%lf", &koefs[i]);
		do
		{
			printf("Input the power: ");
			scanf_s("%d", &powers[i]);
		} while (powers[i] < 0);
		printf("\n");
	}

	res = Polynom{ koefs, powers };
	return res;
}

void Sort(Polynom thePolynom)
{
	int size = sizeof(thePolynom.powers) / sizeof(int);

	int tmp1;
	double tmp2;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (thePolynom.powers[i] < thePolynom.powers[j])
			{
				tmp1 = thePolynom.powers[j];
				thePolynom.powers[j] = thePolynom.powers[i];
				thePolynom.powers[i] = tmp1;

				tmp2 = thePolynom.koefs[j];
				thePolynom.koefs[j] = thePolynom.koefs[i];
				thePolynom.koefs[i] = tmp2;
			}
		}
	}
}

void outputPolynom(Polynom thePolynom)
{
	Sort(thePolynom);

	for (int i = 0; i < sizeof(thePolynom.powers) / sizeof(int); i++)
	{
		if (fabs(thePolynom.koefs[i]) < 0.0001) continue;
		if (i > 0 && thePolynom.koefs[i] < 0)
		{
			printf("\b\b");
		}
		printf("%lf*x ^ %d + ", thePolynom.koefs[i], thePolynom.powers[i]);
	}
	printf("\b\b");
}

void deletePolynom(Polynom thePolynom)
{
	free(thePolynom.koefs);
	free(thePolynom.powers);
}

bool turnQueen(Field f1, Field f2)
{
	if (f1.col == f2.col) return true;
	if (f1.row == f2.row) return true;

	if ((int)fabs((int)f1.row - (int)f2.row) == (int)fabs(f1.col - f2.col)) return true;
	return false;
}


Date nextDay(Date theDate)
{
	Date res;
	int d, m, y;

	y = theDate.year;

	if (theDate.month != 12)
	{
		if (theDate.month == 1 || theDate.month == 3 || theDate.month == 5 || theDate.month == 7 || theDate.month == 8 || theDate.month == 10)
		{
			if (theDate.day == 31)
			{
				m = theDate.month + 1;
				d = 1;
			}
			else
			{
				m = theDate.month;
				d = theDate.day + 1;
			}
		}
		else
		{
			if (theDate.month == 4 || theDate.month == 6 || theDate.month == 9 || theDate.month == 11)
			{
				if (theDate.day == 30)
				{
					m = theDate.month + 1;
					d = 1;
				}
				else
				{
					m = theDate.month;
					d = theDate.day + 1;
				}
			}
			else
			{
				if (theDate.day == 28)
				{
					if (isLeap(theDate.year))
					{
						m = theDate.month;
						d = theDate.day + 1;
					}
					else
					{
						m = theDate.month + 1;
						d = 1;
					}
				}
			}
		}
	}
	else
	{
		if (theDate.day == 31)
		{
			y++;
			m = 1;
			d = 1;
		}
		else
		{
			m = theDate.month;
			d = theDate.day + 1;
		}
	}
	
	res = Date{ d, m, y };
	return res;
}

void dayOfWeek2022(Date theDate)
{
	int cnt = 0;
	switch (theDate.month)
	{
	case 12:
		cnt += 30;
	case 11:
		cnt += 31;
	case 10:
		cnt += 30;
	case 9:
		cnt += 31;
	case 8:
		cnt += 31;
	case 7:
		cnt += 30;
	case 6:
		cnt += 31;
	case 5:
		cnt += 30;
	case 4:
		cnt += 31;
	case 3:
		cnt += 28;
	case 2:
		cnt += 31;
	case 1:
		cnt += 0;
	}

	cnt += theDate.day;

	switch (cnt % 7)
	{
	case 0:
		printf("Friday\n");
		break;
	case 1:
		printf("Saturday\n");
		break;
	case 2:
		printf("Sunday\n");
		break;
	case 3:
		printf("Monday\n");
		break;
	case 4:
		printf("Tuesday\n");
		break;
	case 5:
		printf("Wednesday\n");
		break;
	case 6:
		printf("Thursday\n");
		break;
	}
}


struct Mountain
{
	char* name;// [MAXNAME] ;
	double height;
};

Mountain inputMountain()
{
	Mountain res;

	char name[MAXNAME];
	double height;

	printf("Input the name [15 symbols]:\n");
	scanf_s(" %s ", name); //sometimes doesn`t work correct

	do
	{
		printf("Input the height: ");
		scanf_s("%lf", &height);
	} while (height <= 0);

	res = Mountain{ name, height };
	return res;
}

void outputMountain(Mountain m)
{
	printf(" %s - %lf\n", m.name, m.height);
}

void maxHeight(Mountain* list)
{
	double max = list[0].height;
	int ind = 0;
	for (int i = 1; i < N; i++)
	{
		if (list[i].height > max)
		{
			max = list[i].height;
			ind = i;
		}
	}

	printf("Mountain with max height: %s\n", list[ind].name);
}

void printName(Mountain* list)
{
	char find[MAXNAME];

	printf("Input the name [15 symbols]: ");
	scanf_s(" %s", find); //sometimes doesn`t work correct

	for (int i = 0; i < N; i++)
	{
		if (strcmp(list[i].name, find) == 0)
		{
			printf("The height: %lf\n", list[i].height);
			break;
		}
	}

}

void task10_5()
{
	struct Mountain list[N];

	for (int i = 0; i < N; i++)
	{
		list[i] = inputMountain();
		outputMountain(list[i]);
	}

	maxHeight(list);
	printName(list);
}


struct Matrix
{
	int n;
	int m;
	double** matr;
};

double** allocMemory(int n, int m)
{
	double** arr = (double**)malloc(n * sizeof(double*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double*)calloc(m, sizeof(double));
	}
	return arr;
}

Matrix inputMatrix()
{
	int n, m;
	double** matrix;

	Matrix res;

	do
	{
		printf("n = ");
		scanf_s("%d", &n);
	} while (n <= 0);

	do
	{
		printf("m = ");
		scanf_s("%d", &m);
	} while (m <= 0);

	matrix = allocMemory(n, m);

	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("m[%d, %d] = ", i, j);
			scanf_s("%lf", &matrix[i][j]);
		}
	}

	res = Matrix{ n, m, matrix };
	return res;
}

void outputMatrix(Matrix theMatr)
{
	for (int i = 0; i < theMatr.n; i++)
	{
		for (int j = 0; j < theMatr.m; j++)
		{
			printf("%lf ", theMatr.matr[i][j]);
		}
		printf("\n");
	}
}

void freeMemory(Matrix theMatr)
{
	for (int i = 0; i < theMatr.n; i++)
	{
		free(theMatr.matr[i]);
	}
	free(theMatr.matr);
}


struct Country
{
	char name[MAXNAME];
	int numOfResidents; // in millions
	double square;
};

Country inputCountry()
{
	Country res;

	char name[MAXNAME];
	int numOfResidents;
	double square;

	printf("Input the name [15 symbols]:\n");
	scanf_s(" %s ", name); //sometimes doesn`t work correct

	do
	{
		printf("Input the number of residents: ");
		scanf_s("%d", &numOfResidents);
	} while (numOfResidents <= 0);

	do
	{
		printf("Input the square: ");
		scanf_s("%lf", &square);
	} while (square <= 0);

	res = Country{ name, numOfResidents, square };
	return res;
}

void outputCountry(Country theCountry)
{
	printf("%s: residents - %d, square - %lf\n", theCountry.name, theCountry.numOfResidents, theCountry.square);
}

void minResOnSq(struct Country list[N])
{
	double minEl = (double)list[0].numOfResidents * 1000000 / list[0].square;

	int ind = 0;
	double tmp;

	for (int i = 1; i < N; i++)
	{
		tmp = (double)list[i].numOfResidents * 1000000 / list[0].square;
		if (tmp < minEl)
		{
			minEl = tmp;
			ind = i;
		}
	}

	printf("Country with min number residents on square is %s\n", list[ind].name);
}

void task10_10()
{
	struct Country list[N];

	for (int i = 0; i < N; i++)
	{
		list[i] = inputCountry();
		outputCountry(list[i]);
	}

	minResOnSq(list);
}



int main()
{
	int n;

	printf("Input No of the task [1-3, 5, 6, 10]: ");
	scanf_s("%d", &n);

	switch (n)
	{
	case 1:
		Date theDate1 = inputDate();
		outputDate(theDate1);

		Field theField = inputField();
		output(theField);

		Rectangle theRectangle = inputRectangle();
		outputRectangle(theRectangle);

		Polynom thePolynom = inputPolynom();
		outputPolynom(thePolynom);
		deletePolynom(thePolynom);
		break;
	case 2:
		Field f1 = inputField();
		Field f2 = inputField();
		printf("There is a queen\`s turn from f1 to f2 - %d\n", turnQueen(f1, f2));
		break;
	case 3:
		Date theDate2 = inputDate();
		outputDate(theDate2);
		dayOfWeek2022(theDate2);
		Date theNext = nextDay(theDate2);
		outputDate(theNext);
		dayOfWeek2022(theNext);
		break;
	case 5:
		task10_5();
		break;
	case 6:
		Matrix matr = inputMatrix();
		outputMatrix(matr);
		freeMemory(matr);
		break;
	case 10:
		task10_10();
		break;
	}
}