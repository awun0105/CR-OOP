#ifndef cRow_h
#define cRow_h

#include <vector>
#include "cOneRow.h"

using namespace std;

class cRows
{
private:
	vector <cOneRow*> subRows;
public:
	cRows();
	~cRows() = default;
	bool pushEnemy(int row, cEnemy* enemy); //  push a new enemy to a row
	void pushRow(cOneRow*);
	vector <cEnemy*> listEnemy(); // return all enemies from all rowsgit ad
	vector <cOneRow*> listRow();
	int moveToNextState(int t);
	void redrawState();

};

#endif // cRows