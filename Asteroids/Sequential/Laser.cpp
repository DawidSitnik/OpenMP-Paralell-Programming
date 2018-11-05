#include "Laser.h"



Laser::Laser(double posY, double width):y(posY),width(width)
{
}

double Laser::getPos()
{
	return this->y;
}

double Laser::getWidth()
{
	return this->width;
}

Laser::~Laser()
{
}
