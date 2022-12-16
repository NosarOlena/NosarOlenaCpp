#include <iostream>
#include <string>

using namespace std;

void task13_1()
{
	string str1;
	string str2;
	int ind1, ind2;
	int pos = 0;

	cout << "Enter the string: " << endl;
	getline(std::cin, str1);

	ind1 = str1.find(":");
	if (ind1 == -1)
	{
		str2 = str1;
	}
	else
	{

		do
		{
			ind2 = str1.find(",", pos);
			pos = ind2;

		} while (ind2 != -1 && ind2 < ind1);

		if (ind2 == -1)
		{
			str2 = str1.substr(ind1, str1.length() - 1);
		}
		else
		{
			str2 = str1.substr(ind1 + 1, ind2 - ind1 - 1);
		}
	}

	cout << str2;
}

void task13_2()
{
	string str1;
	string str2;

	int ind1, ind2;
	int i = 0;

	cout << "Enter the string: ";
	getline(std::cin, str1);

	ind1 = str1.find('.');
	if (ind1 == -1)
	{
		while (str1[i] == ' ') i++;
		str2 = str1.substr(i, str1.length() - i);
	}
	else
	{
		ind2 = str1.rfind('.');
		if (ind1 == ind2)
		{
			str2 = str1.substr(ind1 + 1, str1.length() - ind1 - 1);
		}
		else
		{
			str2 = str1.substr(ind1 + 1, ind2 - ind1 - 1);
		}
	}
	cout << str2 << endl;
}

void task13_3()
{
	string str1;
	string str2;
	int cnt = 0;
	int len;

	cout << "Enter the string: ";
	getline(std::cin, str1);

	len = str1.length();
	
	str2 = str1;

	for (int i =0; i < len; i++)
	{
		if (i != len - 1 && str1[i] != ' ' && str1[i+1] == ' ')
		{
			str2.erase(i - cnt, 1);
			cnt++;
		}
	}

	cout << str2;
}

double* firstNdouble(string str, string sep)
{
	int n;
	double* arr;
	int len;
	int i = 0, i0 = 0;
	int cnt = 0;
	int sign = 1;


	do
	{
		cout << "Enter n (n > 0): ";
		cin >> n;
	} while (n <= 0);

	arr = new double[n];

	len = str.length();

	while (i < len)
	{
		if (isdigit(str[i]) == 0)
		{
			if (i != len - 1)
			{
				if (str[i] == '-' && isdigit(str[i + 1]) != 0) sign = -1;
				else if (str[i] == '+' && isdigit(str[i + 1]) != 0) sign = 1;
			}
			i++;
			continue;
		}
		i0 = i;
		while (isdigit(str[i]) != 0)
		{
			i++;
			if (str[i] == '.') i++;
		}
		arr[cnt] = sign * stod(str.substr(i0, i - i0 + 1));
		printf("%lf\n", arr[cnt]);
		cnt++;
		sign = 1;
		if (cnt == n) break;
	}

	if (cnt < n)
	{
		cout << "There are less numbers than n!!!" << endl;
	}

	return arr;
}

void task13_4()
{
	string str;
	string sep;

	cout << "Enter the string: ";
	getline(std::cin, str);

	cout << "Enter the string that separates numbers: ";
	getline(std::cin, sep);

	double* arr = firstNdouble(str, sep);

	for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
}

string* splitN(string str, string sep, int n)
{
	string* arr = new string[n];
	int len = str.length();
	int lenSep = sep.length();
	int i = 0;
	int cnt = 0;

	while (i < len)
	{
		if (str.substr(i, lenSep) == sep)
		{
			i += lenSep;
			continue;
		}
		arr[cnt] = str.substr(i, str.find(sep, i) - i);
		i = str.find(sep, i);
		cnt++;
		if (cnt == n) break;
	}

	if (cnt < n)
	{
		cout << "There is less words in str than n!!!" << endl;
	}

	return arr;
}

void task13_5()
{
	string str;
	string sep;
	int n;

	cout << "Enter the string: ";
	getline(std::cin, str);

	cout << "Enter the string that separates numbers: ";
	getline(std::cin, sep);

	do
	{
		cout << "Enter n (n > 0): ";
		cin >> n;
	} while (n <= 0);

	string* arr = splitN(str, sep, n);

	for (int i = 0; i < sizeof(arr) / sizeof(string); i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
}

int split(string str, string* arr)
{
	int len = str.length();
	int i = 0;
	int cnt = 0;

	while (i < len)
	{
		while (str[i] == ' ' && i < len - 1) i++;
		if (str.find(' ', i) != -1)
		{
			arr[cnt] = str.substr(i, str.find(' ', i) - i);
		}
		else
		{
			arr[cnt] = str.substr(i, len - i);
			break;
		}
		i = str.find(' ', i);
		cout << arr[cnt] << endl;
		cnt++;
	}

	return cnt;
}

void task13_6()
{
	string str;
	int cnt;
	int numOfSmallest = 0;
	int smallestLen;
	int theLen;
	int theWord;

	cout << "Enter the string: ";
	getline(std::cin, str);

	string* arr = new string[str.length()];

	cnt = split(str, arr);
	
	smallestLen = arr[0].length();

	for (int i = 1; i < cnt; i++)
	{
		theLen = arr[i].length();
		if (theLen <= smallestLen)
		{
			smallestLen = theLen;
			theWord = i;
		}
	}

	for (int j = 0; j < cnt; j++)
	{
		if (arr[j].length() == smallestLen) numOfSmallest++;
	}

	if (numOfSmallest == 1)
	{
		cout << "The only smallest word is " << arr[theWord] << endl;
	}
	else
	{
		cout << "The last smallest word is " << arr[theWord] << endl;
		for (int k = 0; k < cnt; k++)
		{
			if (arr[k].length() == smallestLen)
			{
				cout << "The first smallest word is " << arr[k] << endl;
				break;
			}
		}
	}

	delete[] arr;
}

void task13_8()
{
	string str1;
	string str2;
	int len;
	int cnt = 0;
	char lastSym;
	int i = 0;
	int i0;
	
	cout << "Enter the string: ";
	getline(std::cin, str1);

	str2 = str1;

	len = str1.length();

	while (i < len)
	{
		if (str1[i] == ' ')
		{
			i++;
			continue;
		}
		i0 = i;
		while (str1[i] != ' ')
		{
			if (i == len - 1)
			{
				if (str1[len - 1] != ' ') i++;
				break;
			}
			i++;
		}
		lastSym = str1[i - 1];
		for (int j = i0; j < i; j++)
		{
			if (str1[j] == lastSym)
			{
				str2.erase(j - cnt, 1);
				cnt++;
			}
		}
	}

	cout << str2 << endl;
}


int main()
{
	int n;

	cout << "Input No of the task [1-6, 8]: ";
	cin >> n;

	switch (n)
	{
	case 1:
		task13_1();
		break;
	case 2:
		task13_2();
		break;
	case 3:
		task13_3();
		break;
	case 4:
		task13_4();
		break;
	case 5:
		task13_5();
		break;
	case 6:
 		task13_6();
		break;
	case 8:
		task13_8();
		break;
	}
}