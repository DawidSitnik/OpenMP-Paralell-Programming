#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include <iostream>
using namespace std;

class Input{
private:
	int numAsteroids=-1, numIntertions=-1, numPlanets =-1;
	double posRay=-1.0;
	int seed=-1;

	int finishProgram();

public:
	Input(int argc, char **argv);
	
	bool isRight();
	int getSeed();
	int getNumAsteroids();
	int getNumIterations();
	int getNumPlanets();
	double getPosRay();

	void display();
	~Input();
};
#endif