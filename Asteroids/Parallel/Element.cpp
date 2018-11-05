#include "Element.h"

Element::Element(double x, double y, double mass) :mass(mass)
{
	pos.x = x;
	pos.y = y;
}

double Element::getX()
{
	return this->pos.x;
}

double Element::getY()
{
	return this->pos.y;
}

double Element::distance(Element & element)
{
	double bufforX = this->pos.x - element.pos.x;
	bufforX = pow(bufforX, 2);
	double bufforY = this->pos.y - element.pos.y;
	bufforY = pow(bufforY, 2);
	bufforX += bufforY;
	return sqrt(bufforX);
}

double Element::slope(Element & element)
{
	double dev0 = (this->pos.x - element.pos.x);
	double slope = (this->pos.y - element.pos.y);
	if (dev0 == 0.0) {
		if (slope > 0)
			return atan(std::numeric_limits<double>::infinity());
		else
			return atan(-std::numeric_limits<double>::infinity());
	}
	slope /= dev0;
	if (fabs(slope) > 1) slope -= trunc(slope);
	return atan(slope);
}

double Element::getMass()
{
	return this->mass;
}

Element::~Element()
{
}
