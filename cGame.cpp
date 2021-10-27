#include "cGame.h"

void cGame::gameSettings() {
	system("cls");
	const char *setting[3] = { "Mode", "Sound", "Menu" };
	char * currentSettting[3] = { "HARD", "ON", "" };
	if (constantVar::isHard) {
		currentSettting[0] = "HARD";
	}
	else
	{
		currentSettting[0] = "EASY";
	}
	if (constantVar::isMute) {
		currentSettting[1] = "OFF";
	}
	else {
		currentSettting[1] = "ON ";
	}
	int pos1 = 0;
	const int y = 20;
	const int x = 25;
	int flag = 0;
	int color = rand() % 7 + 9;
	//map.printBorder();
	bool currentKey = true;
	while (1) {
		if (currentKey) {
			//system("cls");
			color = rand() % 7 + 9;
			TextColor(color);
			drawTitle();
			//TextColor(7);
			for (int i = 0; i < 4 - 1; i++) {
				gotoXY(x, y + i);
				if (i == pos1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				cout << setting[i] << " " << currentSettting[i];
			}
			currentKey = false;
		}
		while (1) {
			if (kbhit()) {
				currentKey = true;
				//system("cls");
				
				char key = getch();
				if (key == 'W' || key == 'w') {
					pos1--;
					pos1 = (pos1 + 3) % 3;
					break;
				}
				if (key == 'S' || key == 's') {
					pos1++;
					pos1 %= 3;
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0: {
						//Game mode : easy || hard
						toggleHard();
						if (constantVar::isHard) {
							currentSettting[0] = "HARD";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
							}
						}
						else
						{
							currentSettting[0] = "EASY";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
							}
						}
						break;
					}
					case 1: {
						toggleMute();
						if (constantVar::isMute) {
							currentSettting[1] = "OFF";
							if (constantVar::isMute)PlaySound(NULL("background-music.wav"), NULL, SND_APPLICATION);
						}
						else {
							currentSettting[1] = "ON ";
							PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
							PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
						}
						//flag = 1;
						break;
					}
					case 2: {
						system("cls");
						flag = 1;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						return;
					}
					}
					break;
				}

			}
		}
		
	}
	//if (flag == 1) { //???
	//	//system("cls");
	//	bool isFinish = false;
	//	menu();
	//	//  cGame::drawGame();
	//}
	return;
}

void cGame::menu(bool &isFinish) {
}

void cGame::menu() {
	const string choice[4] = { "New Game","Load Game","Settings","Quit" };
	int pos = 0;
	int x = 75, y = 25;
	if (!constantVar::isMute)PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
	bool changeInput = true;
	while (true) {
		changeInput = true;
		if (!constantVar::isMute)PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
		while (true) {
			if (changeInput) 
			{
				for (int i = 0; i < 4; i++) 
				{
					gotoXY(x, y + i);
					if (i == pos)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					cout << choice[i] << endl;
				}
				int color = rand() % 7 + 9;
				TextColor(color);
				gotoXY(32, 9); cout << "==================================================================================" << endl;
				gotoXY(33, 10); cout << " OooooooO Oooooooo    OoooooooO    Ooooo    Ooooo   OOOO   OOo    OO   Oooooo"<< endl;
				gotoXY(33, 11); cout << "Oo        OO     O   Oo       oO   Oo       Oo       oo    OO o   OO  Oo"<<endl;
				gotoXY(33, 12); cout << "Oo        OOoooooO   Oo       oO   OoooO    OoooO    oo    OO  o  OO  Oo   oooo"<<endl;
				gotoXY(33, 13); cout << "Oo        OO    OO   Oo       oO       O        O    oo    OO   o OO  Oo    OO"<<endl;
				gotoXY(33, 14); cout << " OooooooO OO      OO  OoooooooO   oooooO   oooooO   OOOO   OO    oOO   OooooO" << endl;
				gotoXY(32, 15); cout <<"==================================================================================" << endl;
				gotoXY(33, 16); cout << "                                   =================================================" << endl;
				gotoXY(33, 17); cout << "                                    Oooooooo     OoooooooO     OoooO     OOooooooO" << endl;
				gotoXY(33, 18); cout << "                                    OO      O   Oo       oO    O   O     OO       oO" << endl;
				gotoXY(33, 19); cout << "                                    OOoooooO    Oo       oO   OoooooO    OO       oO" << endl;
				gotoXY(33, 20); cout << "                                    OO    OO    Oo       oO  Oo     oO   OO       oO" << endl;
				gotoXY(33, 21); cout << "                                    OO      OO   OoooooooO  Oo       oO  OOooooooO" << endl;
				gotoXY(33, 22); cout << "                                   ==================================================" << endl;
				TextColor(7);
			}
			changeInput = false;
			switch (inputKey()) {
				changeInput = true;
				PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
			case 'w':
				changeInput = true;
				pos--;
				pos = (pos + 4) % 4;
				break;
			case 's':
				changeInput = true;
				pos++;
				pos %= 4;
				break;
			case 13:
				switch (pos) {
				case 0:
					while (1) {
						system("cls");
						loading();
	

						if (newGame()) {
							Sleep(1000);
							clrscr();
							map.printBorder();
							if (!constantVar::isMute)PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break;//return; // thang nhung k choi tiep
							Sleep(1000);
						}
						else if (!continueMenu()) {
							if (isLoaded) {
								map.~cMap();
								new(&map) cMap;
							}
							Sleep(1000);
							clrscr();
							//map.printBorder();
							if (!constantVar::isMute)PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break;//return; //thua nhung khong choi tiep
						}
					}
					break;
				case 1: {
					Sleep(1000);
					clrscr();
					system("cls");
					if (loadGameMenu()) 
					{
						while (1) {
							system("cls");
							loading();
							

							if (newGame()) {
								Sleep(1000);
								clrscr();
								map.printBorder();
								if (!constantVar::isMute)PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break;//return; // thang nhung k choi tiep
								Sleep(1000);
							}
							else if (!continueMenu()) {
								Sleep(1000);
								TextColor(7);
								clrscr();
								map.printBorder();
								if (!constantVar::isMute)PlaySound(TEXT("background-music.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break;//return; //thua nhung khong choi tiep
							}
						}
					}
					else {
						changeInput = true;
						map.printBorder();
					}
				}break;
				case 2: {
					Sleep(500);
					gameSettings();
					changeInput = true;
					//map.printBorder();
				}break;
				case 3:
					clrscr();
					return;
				}
				break;
			}
		}
	}
}

bool cGame::continueMenu() {
	clrscr();
	map.printMap();
	map.deleteOldPlayer();
	map.bombEffect();
	gotoXY(15, 5); cout << "OOOOOO    OOOOOOOO       OOOO      OOOOOOO    OO    OO    OOOOOOO    OOOOOOO      TTT   TTT" << endl;
	gotoXY(15, 6); cout << "OO        OO     OO     OO  OO   OO           OO    OO    OO         OO     O     TTT   TTT" << endl;
	gotoXY(15, 7); cout << "OO        OOooooOO     OOooooOO    OOOOOOO    OOOOOOOO    OOOOOOO    OO      O    TTT   TTT" << endl;
	gotoXY(15, 8); cout << "OO        OO   OO     OO      OO         OO   OO    OO    OO         OO     O     TTT   TTT" << endl;
	gotoXY(15, 9); cout << "OOOOOO    OO    OO   OO        OO  OOOOOO     OO    OO    OOOOOOO    OOOOOOO     ##### ##### " << endl;
	gotoXY(58, 24); cout << "Continue ?" << endl;
	const char *choice[2] = { "<YES>", "<NO>" };
	int pos = 0, x = 58, y = 25;
	TextColor(7);

	while (1) {
		TextColor(7);
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
			}
		}

		switch (inputKey()) {
		case 'w':
			pos--;
			pos = abs(pos);
			pos %= 2;
			break;
		case 's':
			pos++;
			pos %= 2;
			break;
		case 13:
			return !pos;
		}
	}

}


bool cGame::newGame() { // start a new game, initialize cMap map

	char key;
	if (!isLoaded) {
		map.~cMap();
		new(&map) cMap();
	}
	isPausing = false;
	map.printMap();
	if (!isLoaded) map.initializeNewState();
	isLoaded = false;

	const string choice[3] = { "Save Game","Load Game","Quit" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}

		int x = 125, y = 22;
		if (isPausing) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			gotoXY(125, 19); cout << "PAUSE MENU - press P to continue game" << endl;
			for (int i = 0; i < 3; i++) {
				gotoXY(x, y + i);
				if (i == pos)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				cout << choice[i] << endl;
			}
		}

		if (kbhit())
		{
			key = getch();
			if (key == 'l')
			{
				//Save
				// call saveGame of cGame to get name of file
				saveGameMenu();
			}
			if (key == 't')
			{
				togglePauseGame();
				loadGameMenu();
				loading();
				clrscr();
				map.redrawMap();
				togglePauseGame();
				isLoaded = false;
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0; // reset pause menu selection
				if (!isPausing) { // map.redrawMap();
					gotoXY(125, 19); cout << "                  " << endl;
					for (int i = 0; i < 3; i++) {
						gotoXY(x, y + i);
						cout << "                 " << endl;
					}
				}
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if (!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					loading();
					clrscr();
					map.redrawMap();
					togglePauseGame();
					isLoaded = false;
					break;
				case 2:
					system("cls");
					menu();
					//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return true;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}

bool cGame::continueGame()
{
	char key;
	isPausing = false;
	map.printMap();
	map.initializeNewState();
	/*
	gotoXY(125, 5); cout << "CONTROL MANUAL" << endl;
	gotoXY(125, 6); cout << "[ W ]: UP" << endl;
	gotoXY(125, 7); cout << "[ S ]: DOWN" << endl;
	gotoXY(125, 8); cout << "[ A ]: LEFT" << endl;
	gotoXY(125, 9); cout << "[ D ]: RIGHT" << endl;
	gotoXY(125, 11); cout << "COMMANDS" << endl;
	gotoXY(125, 12); cout << "[ L ]: Save game" << endl;
	gotoXY(125, 13); cout << "[ T ]: Load game" << endl;
	gotoXY(125, 14); cout << "[ P ]: Pause game/Menu" << endl;
	*/
	const string choice[3] = { "Save Game","Load Game","Quit" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoXY(125, 19); cout << "PAUSE MENU" << endl;
		gotoXY(125, 20); cout << "PRESS P TO CONTINUE GAME" << endl;
		int x = 125, y = 22;
		for (int i = 0; i < 3; i++) {
			gotoXY(x, y + i);
			if (isPausing && i == pos)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << choice[i] << endl;
		}

		if (kbhit())
		{
			key = getch();
			if (key == 'l')
			{
				//Save
				// call saveGame of cGame to get name of file
				togglePauseGame();
				saveGameMenu();
				togglePauseGame();
			}
			if (key == 't')
			{
				togglePauseGame();
				loadGameMenu();
				togglePauseGame();
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0; // reset pause menu selection
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if (!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					break;
				case 2:
					system("cls");
					menu();
					//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return true;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}


void cGame::loading()
{
	system("cls");
	
	if (!constantVar::isMute)PlaySound(TEXT("Loading4.wav"), NULL, SND_ASYNC); //RaceStart
	map.printMap();
	map.deleteOldPlayer();
	drawTitle();
	gotoXY(50, 25);
	
	cout << "LOADING...";
	gotoXY(29, 26);
	cout << "[";
	gotoXY(81, 26);
	cout << "]";
	for (int i = 0; i <= 50; i++)
	{
		Sleep(35);
		gotoXY(30 + i, 26);
		cout << "|";
		gotoXY(60, 25);
		cout << i * 2 << "%";
	}

}

vector<string> cGame::getAllFilename(const string& name)
{
		vector<string> v;
		string pattern(name);
		pattern.append("\\*");
		std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
		LPCWSTR sw = stemp.c_str();
		WIN32_FIND_DATA data;					
		HANDLE hFind;
		if ((hFind = FindFirstFile(sw, &data)) != INVALID_HANDLE_VALUE) {
			do {
				wchar_t* txt = data.cFileName;
				wstring ws(txt);
				// your new String
				string str(ws.begin(), ws.end());
				if (str[0] == '.') continue;
				// Show String
				v.push_back(str);
				//Just test !
				//cout << str << endl;
			} while (FindNextFile(hFind, &data) != 0);
			FindClose(hFind);
		}
		return v;
}

bool cGame::loadGameMenu() { // get file of cMap map
	string filename;
	clrscr();
	vector <string> files = getAllFilename("data");
	if (files.size() == 0) {
		gotoXY(30, 15);
		cout << "No saved file to load !!!";
		Sleep(1000);
		return false;
	}
	int curPos = 0;
	clrscr();
	map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoXY(43, 8); cout << "=========================================== " << endl;
	gotoXY(44, 9); cout <<  "00       0000000      0000     0000000" << endl;
	gotoXY(44, 10); cout << "00      00     00    00  00    00     0" << endl;
	gotoXY(44, 11); cout << "00      00     00   00    00   00      0 " << endl;
	gotoXY(44, 12); cout << "00      00     00  0000000000  00     0 " << endl;
	gotoXY(44, 13); cout << "0000000  0000000  00        00 0000000  " << endl;
	gotoXY(43, 14); cout << "=========================================== " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(50, 17); cout << "<Press ESC to escape...>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoXY(50, 18);
	cout << "Choose Filename to load: ";

	for (int i = 0; i < (int)files.size(); ++i) {
		if (i == curPos) {
			gotoXY(47, 19 + i);
			cout << ">> ";
		}
		gotoXY(53, 19 + i);
		cout << files[i] << endl;
	}
	while (true) {
		if (kbhit())
		{
			char key=getch();
			if (key == 'w')
			{
				gotoXY(47, 19 + curPos);
				cout << "    " << files[curPos];
				curPos--;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(49, 19 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 's')
			{
				gotoXY(47, 19 + curPos);
				cout << "    " << files[curPos];
				curPos++;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(49, 19 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 13)
			{
				isLoaded = true;
				map.loadGame(files[curPos]);
				clrscr();
				//map.redrawMap();
				return true;
			}
			if (key == 27)
			{
				clrscr();
				//map.redrawMap();
				return false;
			}
		}
		Sleep(200);
	}
}

void cGame::saveGameMenu() { // get file of cMap ma
	string filename;
	clrscr();
	map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoXY(34, 8); cout << "==========================================" << endl;
	gotoXY(35, 9); cout << " OOOOOOO     OOOO    OO       OO  OOOOOOO" << endl;
	gotoXY(35, 10); cout << "  OO       OO  OO    OO     OO   OO" << endl;
	gotoXY(35, 11); cout << "    OO    OOooooOO    OO   OO    OOOOOOO" << endl;
	gotoXY(35, 12); cout << "    OO   OO      OO    OO OO     OO" << endl;
	gotoXY(35, 13); cout << "OOOOO   OO        OO    OO       OOOOOOO" << endl;
	gotoXY(34, 14); cout << "==========================================" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(50, 17);
	cout << "<Press ESC to escape>";
	map.deleteOldPlayer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(50, 18);
	cout << "Input file name to save: ";
	//getline(cin, filename);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	char key;
	while ((key = getch()) != 27 ) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				filename.pop_back();
				gotoXY(50, 19);
				cout << "                                                 ";
				gotoXY(50, 19);
				cout << filename;
			}
			break;
		case 13:
			map.saveGame(filename);
			break;
		default:
			filename.push_back(key);
			gotoXY(50, 19);
			cout << filename;
		}
		if (key == 13) break;
	}
	clrscr();
	map.redrawMap();
	//isPausing = false;
	//file = file + ".txt";
	//map.saveGame(filename);
}

void cGame::togglePauseGame() { // toggle status of isPausing
	
	isPausing = !isPausing;
};

void cGame::gameOver() {
	cout << "Game over" << endl;
};

void cGame::toggleMute() {
	constantVar::isMute = !constantVar::isMute;
}


void cGame::toggleHard()
{
	constantVar::isHard = !constantVar::isHard;
}