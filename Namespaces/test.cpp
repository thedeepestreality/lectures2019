#include "namespaces.h"

namespace hopelessTrials
{
	int x = 3;
	int y = 7;

	int test()
	{
		return x;
	}

	namespace existencialHorror
	{
		int x = 2;
	}
}

using namespace hopelessTrials::existencialHorror;
using hopelessTrials::y;

void test()
{
	y = x + 1 + hopelessTrials::test();
	hopelessTrials::existencialHorror::x += 666;
}