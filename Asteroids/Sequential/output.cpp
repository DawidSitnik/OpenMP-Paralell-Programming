#include "output.h"

Output::Output(const char *pathInitConf, const char *pathOutput) :pathInitConf(pathInitConf), pathOutput(pathOutput)
{
}
void Output::saveInitConfToFile(vector<Planet> planets, vector <Asteroid> asteroids, int numAsteroids, int numInterations, int numPlanets, double posRay, int seed) {
	ofstream initConfFile;
	initConfFile << fixed << showpoint << setprecision(3);
	initConfFile.open(pathInitConf);
	initConfFile << numAsteroids << " " << numInterations << " " << numPlanets << " " << posRay << " " << seed << endl;
	for (auto it = asteroids.begin(); it != asteroids.end(); ++it) {
		initConfFile << it->getX() << " " << it->getY() << " " << it->getMass() << endl;
	}
	for (auto it = planets.begin(); it != planets.end(); it++) {
		initConfFile << it->getX() << " " << it->getY() << " " << it->getMass() << endl;
	}
	initConfFile.close();
}
void Output::saveOutputToFile(vector <Asteroid> asteroids) {
	ofstream outputFile;
	outputFile << fixed << showpoint << setprecision(3);
	outputFile.open(pathOutput);
	for (auto it = asteroids.begin(); it != asteroids.end(); ++it) {
		outputFile << it->getX() << " " << it->getY() << " " << it->getVelX() << " " << it->getVelY() << " " << it->getMass() << endl;
	}
	outputFile.close();
}

Output::~Output() {}