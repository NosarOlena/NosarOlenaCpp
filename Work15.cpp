#include <iostream>
#include <fstream>
#include <string>

#define N 100

using namespace std;

//C:\Users\Lena\Documents\Algebraic_exp.txt
int task14_1()
{
	string filename;
	char ch;
	int sign = 1;
	int suma = 0;
	string numstr = "";
	int isprev = 0;

	cout << "Enter the name of file: ";
	cin >> filename;

	ifstream ifs(filename);
	if (ifs.bad())
	{
		cerr << "Can't open the file!";
		return -1;
	}

	while (!ifs.eof())
	{
		ifs >> ch;
		if (ch == '-')
		{
			if (isprev == 1)
			{
				suma+= sign * stoi(numstr);
				numstr.erase();
			}
			sign = -1;
			continue;
		}
		else
		{
			if (ch == '+')
			{
				if (isprev == 1)
				{
					suma += sign * stoi(numstr);
					numstr.erase();
				}
				sign = 1;
				continue;
			}
		}
		if (isdigit(ch) != 0 && !ifs.eof())
		{
			numstr += ch;
			if (isprev == 0) isprev = 1;
		}
	}

	suma += sign * stoi(numstr);
	ifs.close();
	cout << suma << endl;
	return 1;
}

//C:\Users\Lena\Documents\UppercaseFirst.txt
int task14_2()
{
	string filename;
	string text = "";
	char ch;
	int len;
	int pos;
	int i;

	cout << "Enter the name of file: ";
	cin >> filename;

	ifstream ifs(filename);
	if (ifs.bad())
	{
		cerr << "Can't open the file!";
		return -1;
	}
	while (true)
	{
		ifs.get(ch);
		if (ifs.eof()) break;
		text += ch;
	}
	ifs.close();

	len = text.length();

	i = 0;
	pos = text.find("die", i);
	while (pos != -1)
	{
		if (pos + 4 < len)
		{
			text[pos + 4] = toupper(text[pos + 4]);
			i = pos + 4;
		}
		pos = text.find("die", i);
	}
	
	i = 0;
	pos = text.find("der", i);
	while (pos != -1)
	{
		if (pos + 4 < len)
		{
			text[pos + 4] = toupper(text[pos + 4]);
			i = pos + 4;
		}
		pos = text.find("die", i);
	}

	i = 0;
	pos = text.find("das", i);
	while (pos != -1)
	{
		if (pos + 4 < len)
		{
			text[pos + 4] = toupper(text[pos + 4]);
			i = pos + 4;
		}
		pos = text.find("die", i);
	}
	
	ofstream ofs(filename);
	if (ofs.bad())
	{
		cerr << "Can't open the file!";
		return -1;
	}

	ofs << text;
	ofs.close();
	
	return 1;
}

string reverseWord(string word)
{
	string res = "";
	int lenOfWord = word.length();

	for (int i = lenOfWord - 1; i >= 0; i--)
	{
		res += word[i];
	}
	return res;
}

// returns true if ch is ,.!""''?:; and false otherwise
bool isSign(char ch)
{
	return (ch == ',' || ch == '.' || ch == '!' || ch == '\"' || ch == '\'' || ch == '?' || ch == ':' || ch == ';');
}

/*
works correct only for files
FILE
olleH, emoclew    ot  siht  ecalp!eof
*/
//C:\Users\Lena\Documents\Reverse.txt
//C:\Users\Lena\Documents\ReverseRes.txt
int task14_3()
{
	string filein;
	string fileout;
	string text = "";
	char ch;
	int len;
	string sign = "";
	int numOfSpace = 0;
	int isprev = 0;
	string word = "";

	cout << "Enter the name of file 1: ";
	cin >> filein;

	cout << "Enter the name of file 2: ";
	cin >> fileout;

	ifstream ifs(filein);
	if (ifs.bad())
	{
		cerr << "Can't open the file!";
		return -1;
	}
	while (true)
	{
		ifs.get(ch);
		if (ifs.eof()) break;
		text += ch;
	}
	ifs.close();

	len = text.length();
	text.erase(len - 1);
	len--;
	

	ofstream ofs(fileout);
	if (ofs.bad())
	{
		cerr << "Can't open the file!";
		return -1;
	}
	for (int j = 0; j < len; j++)
	{
		if (isSign(text[j]))
		{
			sign = text[j];
			continue;
		}
		if (text[j] == ' ')
		{
			if (isprev == 1)
			{
				ofs << string(" ", numOfSpace) << reverseWord(word) << sign;
				word = "";
				sign = "";
				numOfSpace = 0;
			}
			numOfSpace++;
			continue;
		}
		word += text[j];
		if (isprev == 0) isprev = 1;
	}
	ofs << string(" ", numOfSpace) << reverseWord(word) << sign;

	ofs.close();

	return 1;
}

//C:\Users\Lena\Documents\Tds.txt
bool task14_4()
{
	string opentg;
	string closetg;
	int lenOpen;
	int lenClose;

	string filename;

	char ch;
	string text;
	int len;
	int i = 0;


	cout << "Enter the open <td>: ";
	cin >> opentg;

	lenOpen = opentg.length();

	cout << "Enter the close <td>: ";
	cin >> closetg;

	lenClose = closetg.length();

	cout << "Enter the name of file: ";
	cin >> filename;

	ifstream ifs(filename);
	if (ifs.bad())
	{
		cerr << "Can't open the file!";
		exit(1);
	}

	while (true)
	{
		ifs.get(ch);
		if (ifs.eof()) break;
		text += ch;
	}
	ifs.close();

	len = text.length();

	int res = 0;
	bool isCorrect = true;
	bool firstOpen = false;

	while (i < len)
	{
		if (i + lenOpen <= len)
		{
			if (text.substr(i, lenOpen) == opentg)
			{
				if (!firstOpen) firstOpen = true;
				res++;
				i += lenOpen;
				continue;
			}
			else
			{
				if (i + lenClose <= len)
				{
					if (text.substr(i, lenClose) == closetg)
					{
						if (!firstOpen) return false;
						res--;
						if (res < 0) return false;
						i += lenClose;
						continue;
					}
				}
			}
		}
		i++;
	}

	return (res == 0);
}

typedef struct {
	string name;
	int course;
	int group;
	int marksCount;
	int marks[N];
} Student;

void writeStudentsToFile(string filename, Student* students, int n) {
	ofstream ofs(filename);
	if (ofs.bad()) exit(1);
	int j;

	for (int i = 0; i < n; i++)
	{
		ofs << students[i].name << "; ";
		ofs<< "course: " << students[i].course << "; ";
		ofs << "group: " << students[i].group << "; ";
		ofs << "points: ";
		
		for (j = 0; j < students[i].marksCount - 1; j++)
		{
			ofs << students[i].marks[j] << ", ";
		}

		ofs << students[i].marks[j] << endl;
	}

	ofs.close();
}

int readStudentsFromFile(string filename, Student* students) {
	ifstream ifs(filename);
	if (ifs.bad()) exit(1);

	int n = 0;
	int x;
	string str;

	while (ifs.good())
	{
		
		ifs >> str;
		if (ifs.fail()) break;
		str.pop_back();
		students[n].name = str;

		ifs >> str >> x;
		students[n].course = x;

		ifs.ignore(256, ';');
		ifs >> str >> x;
		students[n].group = x;

		ifs.ignore(256, ';');
		ifs >> str;
		students[n].marksCount = 0;

		do
		{
			ifs >> x;
			students[n].marks[students[n].marksCount] = x;
			students[n].marksCount++;
		} while (ifs.get() == ',');
		n++;
	}

	ifs.close();

	return n;
}

int sumaArr(int* arr, int n)
{
	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += arr[i];
	}

	return suma;
}

//C:\Users\Lena\Documents\Students.txt
void task14_5()
{
	string filename;

	cout << "Enter the name of file: ";
	cin >> filename;

	int n;

	Student students0[N] = {
		{"Sergiy", 2, 2, 4, {100, 99, 97, 98}},
		{"Vlad", 2, 1, 4, {90, 95, 88, 83}},
		{"Maria", 2, 1, 3, {80, 70, 100}}
	};

	Student students1[N];

	writeStudentsToFile(filename, students0, 3);
	n = readStudentsFromFile(filename, students1);

	int minPoints = (double)sumaArr(students1[0].marks, students1[0].marksCount) / students1[0].marksCount;
	int theStudent = 0;
	int points;

	for (int i = 1; i < n; i++)
	{
		points = (double)sumaArr(students1[i].marks, students1[i].marksCount) / students1[i].marksCount;

		if (points < minPoints)
		{
			minPoints = points;
			theStudent = i;
		}
	}

	cout << "The student with min points is " << students1[theStudent].name << endl;	
}

bool isEmpty(string line)
{
	int len = line.length();

	for (int i = 0; i < len; i++)
	{
		if (line[i] != '\n' || line[i] != '\t' || line[i] != '\b' || line[i] != ' ') return false;
	}

	return true;
}

int numOfEmptyRows(string filename)
{
	int res = 0;
	string line;

	ifstream ifs(filename);
	if (ifs.bad()) exit(1);

	while (true)
	{
		if (ifs.eof()) break;
		getline(ifs, line);
		if (isEmpty(line)) res++;
	}

	ifs.close();

	return res;
}

int maxLenOfLine(string filename)
{
	int res;
	int len;
	string line;

	ifstream ifs(filename);
	if (ifs.bad()) exit(1);

	getline(ifs, line);
	res = line.length();
	while (true)
	{
		if (ifs.eof()) break;
		getline(ifs, line);
		if (!isEmpty(line))
		{
			len = line.length();
			if (len > res) res = len;
		}
	}

	ifs.close();

	return res;
}

//C:\\Users\\Lena\\Documents\\EmptyRows.txt
void task14_23()
{
	string filename;

	cout << "Enter the name of file: ";
	cin >> filename;

	cout << "The number of empty rows is " << numOfEmptyRows(filename) << endl;
	cout << "Max length of row is " << maxLenOfLine(filename) << endl;
}

int main()
{
	int n;

	cout << "Input No of the task [1-5, 23]: ";
	cin >> n;

	switch (n)
	{
	case 1:
		task14_1();
		break;
	case 2:
		task14_2();
		break;
	case 3:
		task14_3();
		break;
	case 4:
		cout << task14_4() << endl;
		break;
	case 5:
		task14_5();
		break;
	case 23:
		task14_23();
		break;
	}
}