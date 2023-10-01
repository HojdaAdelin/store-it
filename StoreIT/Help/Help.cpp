#include <iostream>
#include <string>
#include <Windows.h>

#include "Help.h"
#include "../Basics/StoreFunctions.h"

HANDLE h_color = GetStdHandle(STD_OUTPUT_HANDLE);

void Help::bracksColor(int _nr) {

	SetConsoleTextAttribute(h_color, 3);
	std::cout << "[";
	SetConsoleTextAttribute(h_color, 14);
	std::cout << _nr;
	SetConsoleTextAttribute(h_color, 3);
	std::cout << "] ";
	SetConsoleTextAttribute(h_color, 15);

}

void Help::GenerateView() {

	SetConsoleTextAttribute(h_color, 3);
	std::cout << "Welcome to Store It!" << "\n\n";
	SetConsoleTextAttribute(h_color, 15);

	bracksColor(1);
	std::cout << "Auto store" << "\n";
	bracksColor(2);
	std::cout << "Custom store" << "\n";
	bracksColor(3);
	std::cout << "Set default store" << "\n";
	bracksColor(4);
	std::cout << "Use default store" << "\n\n";

}

void Help::GetAnswer(int _answer) {

	if (_answer == 1) {


	}
	else if (_answer == 2) {



	}
	else if (_answer == 3) {



	}
	else if (_answer == 4) {

			

	}
	else {

		std::cout << "Wrong argument!\n\n";

	}

}