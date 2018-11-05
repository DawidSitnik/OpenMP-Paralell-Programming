#ifndef ASTEROID_H
#define ASTEROID_H
#include "Element.h"
#include "header.h"
#include <omp.h>
#include <math.h>
#include "AtomicLock.h"
using namespace std;

class Asteroid :
	public Element
{
public: 
	AtomicLock *lockForceX, *lockForceY;
	cordXandY force = {0.0, 0.0};
	cordXandY vel = { 0.0, 0.0 };
	cordXandY acc = { 0.0, 0.0 };
public:
	Asteroid(double x, double y, double mass);
	double getVelX();
	double getVelY();
	double getX();
	double getY();
	void setForceX(double &force);
	void setForceY(double &force);
	void setAndCalculateForce(double & force, double & angle);
	double getForceX();
	double getForceY();
	void calculate();
	void resetForce();
	//calculate accelaration, velocity, position of asteroid
	void calculateAcceleration();
	void calculateVelocity();
	void calculatePosition();
	void checkAndChangePosition();		//check if the position is in space litation and if yes changing the position
	bool isOnLaser(double posRay, double width);		//return if the asteroid is in laser area
	Asteroid & operator+=(cordXandY force);		//sum the forces
	~Asteroid();
};

#endif