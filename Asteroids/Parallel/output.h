#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include "Engine.h"
#include "input.h"
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Output{
private:
	string pathInitConf;
	string pathOutput;
public:
	Output(const char * pathInitConf, const char * pathOutput);
	void saveInitConfToFile(vector<Planet> planets, vector<Asteroid> asteroids, int numAsteroids, int numInterations, int numPlanets, double posRay, int seed);
	void saveOutputToFile(vector<Asteroid> asteroids);
	~Output();
};
#endif