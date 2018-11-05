#include "Engine.h"


Engine::Engine(int numAsteroids, int numIterations, int numPlanets, double posRay, unsigned int seed) :numIterations(numIterations), seed(seed)
{
	re.seed(seed);
	generateAsteroids(numAsteroids);
	generatePlanets(numPlanets);
	generateLaser(posRay);
}

vector<Asteroid> Engine::getAsteroidVector()
{
	return this->asteroids;
}

vector<Planet> Engine::getPlanetVector()
{
	return this->planets;
}

void Engine::generateAsteroids(int numAsteroids)
{
	double x, y, m;
	for (int i = 0; i < numAsteroids; ++i) {
		x = xdist(re);
		y = ydist(re);
		m = mdist(re);
		asteroids.push_back(Asteroid(x, y, m));
	}
}

void Engine::generatePlanets(int numPlanets)
{
	double x, y, m;
	while (numPlanets) {
		numPlanets--;
		y = ydist(re);
		m = mdist(re);
		planets.push_back(Planet(0, y, m*PLANET_MASS_MULTIPLIER));
		if (numPlanets) {
			numPlanets--;
			x = xdist(re);
			m = mdist(re);
			planets.push_back(Planet(x, 0, m*PLANET_MASS_MULTIPLIER));
		}
		if (numPlanets) {
			numPlanets--;
			y = ydist(re);
			m = mdist(re);
			planets.push_back(Planet(MAX_WIDTH, y, m*PLANET_MASS_MULTIPLIER));
		}
		if (numPlanets) {
			numPlanets--;
			x = xdist(re);
			m = mdist(re);
			planets.push_back(Planet(x, MAX_HEIGHT, m*PLANET_MASS_MULTIPLIER));
		}
	}
}

void Engine::generateLaser(double posRay)
{
	laser = new Laser(posRay, RAY_WIDTH);
}

void Engine::startCalculations()
{
	//loop going to number of Iterations
	for (int i = 0; i < numIterations; i++) {

//#pragma omp for schedule(static,1) ordered
//#pragma omp for schedule(dynamic) ordered
		for (auto asteroid = asteroids.begin(); asteroid < asteroids.end(); asteroid++) {
//#pragma omp ordered
			calculateToAllAsteroids(asteroid);
		}
#pragma omp parallel
		{
#pragma omp for schedule(dynamic)
		for (auto asteroid = asteroids.begin(); asteroid < asteroids.end(); asteroid++) {
			calculateToAllPlanet(asteroid);
		}
#pragma omp for schedule(dynamic)
		for (auto asteroid = asteroids.begin(); asteroid < asteroids.end(); asteroid++) {
			(*asteroid).calculate();
			(*asteroid).checkAndChangePosition();
		}
#pragma omp single
	{
			for (vector<Asteroid>::iterator asteroid = asteroids.begin(); asteroid != asteroids.end();)
				if ((*asteroid).isOnLaser(laser->getPos(), laser->getWidth()))
					asteroid = asteroids.erase(asteroid);
				else
					asteroid++;
		}
	}
}
}
void Engine::calculateToAllPlanet(vector<Asteroid>::iterator &asteroid) {
	double dist, forceBuffor, angle;
	double gravity = GRAVITY;
	double minDist = MIN_DISTANCE;
	cordXandY force = { 0.,0. };
	//loop going through all planets
	for (auto planet = planets.begin(); planet != planets.end(); ++planet) {
		dist = asteroid->distance(*planet);
		if (dist > minDist) {
			angle = asteroid->slope(*planet);
			forceBuffor = gravity*asteroid->getMass();
			forceBuffor *= planet->getMass();
			forceBuffor /= pow(dist, 2);
			if (forceBuffor > 200.) forceBuffor = 200.;
			force.x += forceBuffor*cos(angle);
			force.y += forceBuffor*sin(angle);
		}
	}
	*asteroid += force;
}
void Engine::calculateToAllAsteroids(vector<Asteroid>::iterator &asteroid)
{
	double dist, forceBuffor, angle, forceX = 0.0, forceY = 0.0;
	cordXandY force = {0.,0.};
#pragma omp parallel for schedule(static,1) private(dist, forceBuffor, angle) shared(forceX, forceY) ordered
	for (auto ast = asteroid + 1; ast < asteroids.end(); ++ast) {
		dist = asteroid->distance(*ast);
		if (dist > MIN_DISTANCE) {
			angle = asteroid->slope(*ast);
			forceBuffor = GRAVITY*(*asteroid).getMass();
			forceBuffor *= (*ast).getMass();
			forceBuffor /= pow(dist, 2.0);
			if (forceBuffor > 200.) forceBuffor = 200.;
#pragma omp ordered
			{
			forceX += forceBuffor*cos(angle);
			forceY += forceBuffor*sin(angle);
			forceBuffor *= -1.;
			ast->setAndCalculateForce(forceBuffor, angle);
			}
		}
	}
	force.x = forceX;
	force.y = forceY;
	*asteroid += force;
}

Engine::~Engine()
{
	this->asteroids.clear();
	this->planets.clear();
	delete(laser);
}
