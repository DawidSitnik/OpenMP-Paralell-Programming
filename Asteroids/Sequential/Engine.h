#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "header.h"
#include <vector>
#include <iterator>
#include "Asteroid.h"
#include "Planet.h"
#include "Laser.h"
#include <random>
#include <math.h>

#include <mutex>
using namespace std;

class Engine {
public:
	int numIterations;
	vector<Asteroid> asteroids;
	vector<Planet> planets;
	Laser *laser = nullptr;
	unsigned int seed;
public:
	Engine(int numAsteroids, int numInterations, int numPlanets, double posRay, unsigned int seed);
	vector<Asteroid> getAsteroidVector();
	vector<Planet> getPlanetVector();
	void generateAsteroids(int numAsteroids);
	void generatePlanets(int numPlanets);
	void generateLaser(double posRay);
	void startCalculations();												//main function calculate everything
	void calculateToAllPlanet(vector<Asteroid>::iterator &asteroid);		//calculate forces according to all planets and set them to asteroid
	void calculateToAllAsteroids(vector<Asteroid>::iterator &asteroid);		//calculate forces according to all asteroids and set them to both asteroids

																			// Random distributions
	default_random_engine re;
	uniform_real_distribution<double> xdist{ 0.0, std::nextafter(MAX_WIDTH,
		std::numeric_limits<double>::max()) };
	uniform_real_distribution<double> ydist{ 0.0, std::nextafter(MAX_HEIGHT,
		std::numeric_limits<double>::max()) };
	normal_distribution<double> mdist{ M, SDM };

	~Engine();
};


#endif
