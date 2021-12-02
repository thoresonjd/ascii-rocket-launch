/*************************************
* Author:        Justin Thoreson     *
* Project:       ASCII Rocket Launch *
* Creation Date: June 12, 2019       *
* Revision Date: December 1, 2021    *
**************************************/

/*
 █████╗ ███████╗ ██████╗██╗██╗    ██████╗  ██████╗  ██████╗██╗  ██╗███████╗████████╗    ██╗      █████╗ ██╗   ██╗███╗   ██╗ ██████╗██╗  ██╗
██╔══██╗██╔════╝██╔════╝██║██║    ██╔══██╗██╔═══██╗██╔════╝██║ ██╔╝██╔════╝╚══██╔══╝    ██║     ██╔══██╗██║   ██║████╗  ██║██╔════╝██║  ██║
███████║███████╗██║     ██║██║    ██████╔╝██║   ██║██║     █████╔╝ █████╗     ██║       ██║     ███████║██║   ██║██╔██╗ ██║██║     ███████║
██╔══██║╚════██║██║     ██║██║    ██╔══██╗██║   ██║██║     ██╔═██╗ ██╔══╝     ██║       ██║     ██╔══██║██║   ██║██║╚██╗██║██║     ██╔══██║
██║  ██║███████║╚██████╗██║██║    ██║  ██║╚██████╔╝╚██████╗██║  ██╗███████╗   ██║       ███████╗██║  ██║╚██████╔╝██║ ╚████║╚██████╗██║  ██║
╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝╚═╝    ╚═╝  ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝       ╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝╚═╝  ╚═╝
*/

#include <string>
#include <stdio.h>
#include <thread>
#include <chrono>

// ASCII rocket art
const char* rocket = "\
      | \n\
     / \\\n\
    / _ \\\n\
   |.o '.|\n\
   |'._.'|\n\
   |     |\n\
   |     |\n\
 ,'|  |  |`.\n\
/  |  |  |  \\\n\
|,-'--|--'-.|\n\
";

const int HEIGHT = 10; // Height of ASCII rocket (lines)
const int ROWS = 40;   // Height of screen (lines)
const int COLS = 60;   // Width of screen

void initScreen() {
	std::string mode = "mode con cols=" + std::to_string(COLS) + " lines=" + std::to_string(ROWS);
	system(mode.c_str()); // Set num cols and rows for window
	system("color 0a");	  // Set color of window and text
}

void countDown() {
	for (int count = 10; count > 0; count--) {
		system("cls");
		std::printf("%d", count);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void takeoff() {
	for (int i = ROWS; i > HEIGHT; i--) {
		system("cls");
		for (int j = i - HEIGHT; j > 0; j--)
			std::printf("\n");
		std::printf(rocket);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

int main() {
	initScreen();
	system("pause");
	system("cls");
	std::printf("Prepare for takeoff...");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	countDown();
	system("cls");
	std::printf("Liftoff!");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	takeoff();
	system("cls");
	std::printf("We are now in orbit.\n");
	return 0;
}