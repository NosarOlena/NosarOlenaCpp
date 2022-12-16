#include <iostream>
#include <math.h>
#include <io.h>
#include <fstream>
#include <string>

#define MAXNUM 16384

using namespace std;

#pragma warning(disable : 4996) // read() function gave the warnings

bool isSqrt(int x)
{
	int m = (int)sqrt(x + 0.5);
	return m * m == x;
}


void task12_1()
{
	double x, y, z;
	cout << "Enter x: " << endl;
	cin >> x;

	cout << "Enter y: " << endl;
	cin >> y;

	z = pow(x, y);

	cout << "x^y " << z << endl;
	cout << "x^y " << scientific << z << endl;
}

int task12_2()
{
	int n;
	unsigned* array;

	unsigned long long num = 0;
	unsigned long long pow10;
	char digit;

	unsigned long long suma = 0ULL;

	std::cout << "Enter n" << std::endl;
	std::cin >> n;

	array = new unsigned[n];



	for (int i = 0; i < n; i++)
	{
		num = 0;
		pow10 = 10000000000;
		for (int j = 0; j < 10; j++)
		{
			read(0, &digit, 1);
			num += (unsigned long long)((int)(digit - '0') * pow10);
			pow10 /= 10;
		}
		array[i] = num / 10;
	}

	for (int j = 0; j < n; j++)
	{
		suma += array[j];
	}

	std::cout << "Suma: " << suma << std::endl;

	delete[] array;
	return 1;
}

void task12_3()
{
	int n;

	cout << "Enter n (n > 0): ";

	do
	{
		cin >> n;
	} while (n <= 0);

	for (int i = 1; i <= n; i++)
	{
		cout << i << "\t";
	}

	cout << endl;
	cout.precision(3);

	for (int j = 1; j <= n; j++)
	{
		if (isSqrt(j))
		{
			cout << int(sqrt(j)) << "\t";
		}
		else
		{
			cout << sqrt(j) << "\t";
		}
	}
}

//C:\Users\Lena\Documents\Xs.txt
//C:\Users\Lena\Documents\Results.txt
int task12_4()
{
	int n;
	int* arr1;
	double* arr2;
	string filename1;
	string filename2;
	double powx;

	cout << "Enter n (n > 0): ";

	do
	{
		cin >> n;
	} while (n <= 0);

	arr1 = new int[n];
	arr2 = new double[n];

	for (int i = 0; i < n; i++)
	{
		cout << "#" << i << " number ";
		cin >> arr1[i];
	}

	cout << "Enter the name of file of x`s: ";
	cin >> filename1;

	cout << "Enter the name of file for results: ";
	cin >> filename2;


	ifstream ifs(filename1);
	if (ifs.bad())
	{
		cerr << "Can't open the file!";
		delete[] arr1;
		delete[] arr2;
		return -1;
	}
	int cnt = 0;
	while (!ifs.eof())
	{
		ifs >> arr2[cnt];
		cnt++;
		if (cnt == n)
		{
			break;
		}
	}
	ifs.close();

	ofstream ofs(filename2);
	if (ofs.bad())
	{
		ofs << "Writing results in the file is failed" << endl;
		delete[] arr1;
		delete[] arr2;
		return -1;
	}
	for (int i = 0; i < n; i++)
	{
		powx = pow(arr2[i], arr1[i]);
		ofs << powx << endl;
	}

	delete[] arr1;
	delete[] arr2;

	return 1;
}

//C:\Users\Lena\Documents\As.txt
int task12_5()
{
	string filename;
	unsigned long long As[MAXNUM];
	int cnt = 0;
	char sym;

	cout << "Enter the name of file with A`s: ";
	cin >> filename;

	ifstream ifs(filename);
	if (ifs.bad())
	{
		cerr << "Can't open the file!";
		return -1;
	}

	while (ifs >> As[cnt])
	{
		cnt++;
	}

	cout.precision(4);
	for (int i = 0; i < cnt; i++)
	{
		cout << sqrt(As[i]) << endl;
	}

	return 1;
}


struct Date
{
	int day;
	int month;
	int year;
};

//returns true if date1 is earlier than date2 and false otherwise
bool comparison(Date date1, Date date2)
{
	if (date1.year < date2.year) return true;
	if (date2.year < date1.year) return false;

	if (date1.month < date2.month) return true;
	if (date2.month < date1.month) return false;

	if (date1.day < date2.day) return true;
	if (date2.day < date1.day) return false;

	// if date1 == date2
	return false;
}

//C:\Users\Lena\Documents\Dates.txt
//C:\Users\Lena\Documents\TheDates.txt
/* 
works correct only if file contains of dates in the right format, for example
FILE
(d/m/y) (d/m/y) (d/m/y)eof
*/
int task12_21()
{
	string filename1;
	string filename2;

	Date theDateearl;
	Date theDatelast;

	Date date;

	int y, m, d;

	cout << "Enter the name of file with dates: ";
	cin >> filename1;

	cout << "Enter the name of file for results: ";
	cin >> filename2;

	ifstream ifs(filename1);
	if (ifs.bad())
	{
		cerr << "Can't open the file!";
		return -1;
	}
	int cnt = 0;
	while (!ifs.eof())
	{
		if (cnt != 0) ifs.ignore(1); // ignore " " before date
		ifs.ignore(1); // ignore "("
		ifs >> d;
		ifs.ignore(1); // ignore "\"
		ifs >> m;
		ifs.ignore(1); // ignore "\"
		ifs >> y;
		ifs.ignore(1); // ignore ")"
		date = Date{ d, m, y };
		if (cnt == 0)
		{
			theDateearl = date;
			theDatelast = date;
		}
		else
		{
			if (comparison(date, theDateearl)) theDateearl = date;
			else
			{
				if (comparison(theDatelast, date)) theDatelast = date;
			}
		}
		cnt++;	
	}
	ifs.close();

	ofstream ofs(filename2);
	if (ofs.bad())
	{
		ofs << "Writing results in the file is failed" << endl;
		return -1;
	}

	ofs << "(" << theDateearl.day << "\\" << theDateearl.month << "\\" << theDateearl.year << ")" << endl;
	ofs << "(" << theDatelast.day << "\\" << theDatelast.month << "\\" << theDatelast.year << ")" << endl;
	ofs.close();

	return 0;
}



int main()
{
	int n;

	cout << "Input No of the task [1-5, 21]: ";
	cin >> n;

	switch (n)
	{
	case 1:
		task12_1();
		break;
	case 2:
		task12_2();
		break;
	case 3:
		task12_3();
		break;
	case 4:
		task12_4();
		break;
	case 5:
		task12_5();
		break;
	case 21:
		task12_21();
		break;
	}

}