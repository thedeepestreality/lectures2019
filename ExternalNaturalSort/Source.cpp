#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

const int SIZE = 1e3;

void generateFile(char* filename, int size)
{
	ofstream out;
	out.open(filename);
	if (!out.is_open())
	{
		throw "File opening error";
	}

	for (int i = 0; i < size; ++i)
		out << rand() - 2 * rand() << " ";

	out.close();
}

void openStream(fstream& stream, char* filename, bool read = true)
{
	if (read)
		stream.open(filename, ios::in);
	else
		stream.open(filename, ios::out);

	if (!stream.is_open())
	{
		throw "File opening error";
	}
}

void sortFile(char* filename, int size)
{
	fstream source;
	fstream f1;
	fstream f2;

	char f1name[] = "f1.txt";
	char f2name[] = "f2.txt";

	int currNumber;
	int prevNumber;

	//For switching between files
	bool fileFlag = true;
	//Current sequence length
	int count = 0;
	int f1Number;
	int f2Number;
	//Maximal sequence length
	//(for output)
	int maxCount = 0;

	while (true)
	{
		//SPLIT STEP
		openStream(source, filename);
		openStream(f1, f1name, false);
		openStream(f2, f2name, false);

		source >> currNumber;
		prevNumber = currNumber;
		while (!source.eof())
		{
			if (currNumber < prevNumber)
			{
				fileFlag = !fileFlag;
				count = 0;
				if (count > maxCount)
					maxCount = count;
			}

			(fileFlag ? f1 : f2) << currNumber << " ";

			prevNumber = currNumber;
			source >> currNumber;

			if (++count == size)
			{
				cout << "sorted!" << endl;
				source.close();
				f1.close();
				f2.close();
				return;
			}
		}

		if (count > maxCount)
			maxCount = count;

		source.close();
		f1.close();
		f2.close();

		openStream(source, filename, false);
		openStream(f1, f1name);
		openStream(f2, f2name);

		//MERGE STEP
		f1 >> f1Number;
		f2 >> f2Number;
		while (!f1.eof() && !f2.eof())
		{
			if (f1Number < f2Number)
			{
				source << f1Number << " ";
				f1 >> f1Number;
			}
			else
			{
				source << f2Number << " ";
				f2 >> f2Number;
			}
		}
		while (!f1.eof())
		{
			source << f1Number << " ";
			f1 >> f1Number;
		}

		while (!f2.eof())
		{
			source << f2Number << " ";
			f2 >> f2Number;
		}

		source.close();
		f1.close();
		f2.close();

		//cout << "Current max count: " << maxCount << endl;
		count = 0;
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	if (argc < 3)
	{
		cout << "Not enough arguments" << endl;
		system("pause");
		return 0;
	}

	char* mode = argv[1];

	switch (mode[0])
	{
	case 'g':
	{
		try
		{
			generateFile(argv[2], SIZE);
		}
		catch (char* message)
		{
			cout << message << endl;
			system("pause");
			return -1;
		}
		break;
	}
	case 's':
	{
		try
		{
			sortFile(argv[2], SIZE);
		}
		catch (char* message)
		{
			cout << message << endl;
			system("pause");
			return -1;
		}
		break;
	}
	default:
	{
		cout << "Wrong arguments" << endl;
		system("pause");
		return -1;
	}
	}

	system("pause");
	return 0;
}