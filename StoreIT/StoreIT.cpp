#include <iostream>
#include <Windows.h>
#include <string>

// Headers
#include "Help/Help.h"

int main()
{
	Help _help;
	SetConsoleTitleA("Store It");
	while (true) {

		int answer;

		_help.GenerateView();
		std::cin >> answer;
		_help.GetAnswer(answer);

	}

}

