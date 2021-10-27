#ifndef cEnemy_h
#define cEnemy_h
#include <Windows.h>
#include <iostream>
#include "cConsole.h"
#include <mmsystem.h>
#include "cPosition.h"

using namespace std;

class cEnemy

{

private:
	cPosition point;

	bool outMap;

public:

	cPosition getPos();

	int getX();

	int getY();

	cEnemy();

	cEnemy(cPosition st); // create new enemy with starting position

	virtual ~cEnemy() = default;

	//  virtual void draw() =0;

	virtual char ** shape() = 0; // return the shape of enemy to draw

	virtual void sound() = 0;

	virtual int getType() = 0;

	void updatePosition(int dx, int dy);

	bool isOutOfMap();

	void goOutMap();

	virtual int getWidth();

	int getHeight();
};



#endif // cEnemy
