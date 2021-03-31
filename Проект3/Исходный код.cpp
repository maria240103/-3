#include <iostream>
#include <fstream>

using namespace std;

void setText(char*, char*, int);
void getText(char*, char*, int);
bool isDigit(char*);

int main()
{
	setlocale(0, "rus");
	char path[] = "test.txt";
	int length = 100000;
	char* text = new char[length];
	cout << "Ñòðîêà: ";
	cin >> text;
	setText(path, text, length);
	getText(path, text, length);

	char* firstCharDigit = &text[0];
	int maxLen = 0;
	int len = 0;
	for (int i = 0; i < length; i++)
	{
		if (isDigit(&text[i]))
		{
			len++;
		}
		else
		{
			if (maxLen < len)
			{
				maxLen = len;
				firstCharDigit = &text[i] - maxLen;
			}
			len = 0;
		}
	}
	firstCharDigit[maxLen] = '\0';
	
	cout << firstCharDigit << endl;

	system("pause");
	return 0;
}

void setText(char* path, char* text, int len)
{
	ofstream outfile(path, ios::binary | ios::out);
	outfile.write(text, len);
	outfile.close();
}

void getText(char* path, char* var, int len)
{
	ifstream infile(path, ios::binary | ios::in);
	infile.read(var, len);
	infile.close();
}

bool isDigit(char* c)
{
	for (char* digits = "0123456789"; *digits != '\0'; digits++)
	{
		if (*c == *digits)
		{
			return true;
		}
	}

	return false;
}
