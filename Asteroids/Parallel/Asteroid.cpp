#include "Asteroid.h"



Asteroid::Asteroid(double x, double y, double mass):Element(x,y,mass)
{
	lockForceX = new AtomicLock();
	lockForceY = new AtomicLock();
}

double Asteroid::getVelX(){
	double velx = this->vel.x;
	return velx;
}

double Asteroid::getVelY(){
	double vely = this->vel.y;
	return vely;
}

double Asteroid::getX()
{
	double posX = this->pos.x;
	return posX;
}

double Asteroid::getY()
{
	double posY = this->pos.y;
	return posY;
}

void Asteroid::setForceX(double &force)
{
	lockForceX->lock();
	this->force.x = force;
	lockForceX->unlock();
}

void Asteroid::setForceY(double &force)
{
	lockForceY->lock();
	this->force.y = force;
	lockForceY->unlock();
}

void Asteroid::setAndCalculateForce(double &force, double &angle)
{
	//if (force > 200.0) force = 200.0;
	lockForceX->lock();
	this->force.x += force*cos(angle); 
	lockForceX->unlock();
	lockForceY->lock();
	this->force.y += force*sin(angle);
	lockForceY->unlock();
}

double Asteroid::getForceX()
{
	double forcex = this->force.x;
	return forcex;
}

double Asteroid::getForceY()
{
	double forcey = this->force.y;
	return forcey;
}

void Asteroid::calculate()
{
	calculateAcceleration();
	calculateVelocity();
	calculatePosition();
	resetForce();
}

void Asteroid::resetForce()
{
	lockForceX->lock();
	this->force.x = 0.0;
	lockForceX->unlock();
	lockForceY->lock();
	this->force.y = 0.0;
	lockForceY->unlock();
}
void Asteroid::calculateAcceleration()
{
	acc.x = force.x / mass;
	acc.y = force.y / mass;
}

void Asteroid::calculateVelocity()
{
	vel.x += acc.x*TIME_INTERVAL;
	vel.y += acc.y*TIME_INTERVAL;
}

void Asteroid::calculatePosition()
{
	pos.x += vel.x*TIME_INTERVAL;
	pos.y += vel.y*TIME_INTERVAL;
}

void Asteroid::checkAndChangePosition()
{
	//checking X axis
	if (pos.x <= 0.0) {
		pos.x = CONFLICT_POSITION;
		vel.x *= -1.0;
	}
	if (pos.x >= MAX_WIDTH) {
		pos.x = MAX_WIDTH - CONFLICT_POSITION;
		vel.x *= -1.0;
	}
	//checking Y axis
	if (pos.y <= 0) {
		pos.y = CONFLICT_POSITION;
		vel.y *= -1.0;
	}
	if (pos.y >= MAX_HEIGHT) {
		pos.y = MAX_HEIGHT - CONFLICT_POSITION;
		vel.y *= -1.0;
	}
}

bool Asteroid::isOnLaser(double posRay, double width)
{
	double bufforLeft = posRay - (width / 2.0);
	double bufforRight = posRay + (width / 2.0);
	if (bufforLeft <= pos.y && pos.y <= bufforRight)
		return true;
	else
		return false;
}

Asteroid& Asteroid::operator +=(cordXandY force) {
	//force X
	lockForceX->lock();
	this->force.x += force.x;
	lockForceX->unlock();
	//force Y
	lockForceY->lock();
	this->force.y += force.y;
	lockForceY->unlock();
	return *this;
}

Asteroid::~Asteroid()
{
}
