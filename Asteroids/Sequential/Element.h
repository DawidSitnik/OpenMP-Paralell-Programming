#ifndef ELEMENT_H
#define ELEMENT_H
#define _USE_MATH_DEFINES
#include "header.h"
#include <math.h>
#include <limits>
class Element
{
public:
	double mass;
	cordXandY pos;
public:
	Element(double x, double y, double mass);
	virtual double getX();
	virtual double getY();
	double distance(Element &element);
	double slope(Element &element);
	double getMass();
	~Element();
};

#endif
