#include <iostream>
#include <iomanip>
#include <thread>
#include <cstdlib>
#include <ctime>

#include "cMap.h"
#include "cGame.h"
#include "cTruck.h"
#include "cCar.h"
#include "cBird.h"

bool constantVar::isMute = false;
bool constantVar::isHard = true;


using namespace std;

int main() {
	srand(time(NULL));
	//DisableMouse();
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);
	FixConsoleWindow();
	cGame game;
	//game.getAllFilename("data");
	game.menu();



	//system("pause");
}