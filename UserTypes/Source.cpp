#include <iostream>

enum class DayOfWeek {
					Monday = 0,
					Tuesday,
					Wednesday,
					Thursday,
					Friday,
					Saturday,
					Sunday
				};

const char* weekDaysStr[] = {
		"Monay",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
};

void printDayOfWeek(DayOfWeek day)
{
	std::cout << weekDaysStr[(int)day] << std::endl;
}

struct Point
{
	double x;
	double y;
};

struct Line
{
	Point p1;
	Point p2;
};

#pragma pack(push,1)
struct Nuance
{
	short x;
	int y;
};
#pragma pack(pop)

struct NuanceOfNuance
{
	double x;
	Nuance n;
};

enum ParameterType {Double, Int, Char};

union ParameterValue
{
	double x;
	int y;
	char z;
};

struct Parameter {
	ParameterType type;
	ParameterValue value;
};

union IntAsArray
{
	int x;
	char bytes[4];
};

struct bitStruct
{
	char b12 : 2;
	char b34 : 2;
	//char b58 : 4;
	char b;
};

int main()
{
	printDayOfWeek(DayOfWeek::Tuesday);
	Point p;
	p.x = 1;
	p.y = 2;

	union{
		int var1;
		double var2;
	};

	var1 = 2;

	//struct test1
	//{
	//	int testVar;
	//};
	//testVar = 1;

	IntAsArray iaa;
	iaa.x = 258;
	std::cout << (int)iaa.bytes[0] << " " << (int)iaa.bytes[1] << std::endl;
	std::cout << sizeof(NuanceOfNuance) << std::endl;

	bitStruct t1;
	t1.b34 = 0;
	t1.b12 = 0b1111;
	std::cout << (int)t1.b34 << std::endl;

	system("pause");
	return 0;
}