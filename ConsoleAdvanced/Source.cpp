#include <windows.h>
#include <conio.h>

//Usage:
//wasd -- move and fill red
//e -- erase color
//q -= quit

int main()
{
	//Get console handle
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	char c = 0;
	bool eraseFlag = false;

	COORD pos = { 0, 0 };
	
	while (c != 'q')
	{
		if (eraseFlag)
		{
			SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			eraseFlag = false;
		}
		else
			SetConsoleTextAttribute(hStdout, BACKGROUND_RED);

		SetConsoleCursorPosition(hStdout, pos);
		_putch(' ');
		SetConsoleCursorPosition(hStdout, pos);

		//Get character
		c = _getch();
		//Erase character from console
		_putch('\b');

		switch (c)
		{
			case 'w':
				if (pos.Y > 0)
					--pos.Y;
				break;
			case 's':
				if (pos.Y < 20)
					++pos.Y;
				break;
			case 'a':
				if (pos.X > 0)
					--pos.X;
				break;
			case 'd':
				if (pos.X < 40)
				++pos.X;
				break;
			case 'e':
				eraseFlag = true;
				break;
		}
	}

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	return 0;

}