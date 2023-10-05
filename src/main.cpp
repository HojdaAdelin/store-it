#include <iostream>
#include <string>
#include <filesystem>
#include <windows.h>

using namespace std::filesystem;

#include "View/Help.h"

int main() {

    Help help;

    while (true) {

        int answer;
        help.GenerateView();
        std::cin >> answer;
        help.GetAnswer(answer);

    }
    return 0;

}