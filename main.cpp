#include "window.h"
#include <iostream>
#undef main

int main() {
	window window1("New window", 800, 600);
	//window1.showHeightWidth();
	//int choice = 0;
	//std::cout << "Do you want to move the rectangle? (Yes/No = 1/0)";
	//std::cin >> choice;
	
	while (!window1.is_closed()) {
		window1.pollEvents();
		window1.clear();
	}
}