#include "Planet.h"



Planet::Planet(double x, double y, double mass):Element(x,y,mass)
{
}
double Planet::getX()
{
	return this->pos.x;
}

double Planet::getY()
{
	return this->pos.y;
}
Planet::~Planet()
{
}
