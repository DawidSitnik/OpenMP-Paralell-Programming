#ifndef PLANET_H
#define PLANET_H
#include "Element.h"
class Planet :
	public Element
{
public:
	Planet(double x, double y, double mass);
	double getX();
	double getY();
	~Planet();
};

#endif