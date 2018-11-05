#ifndef LASER_H
#define LAER_H
class Laser
{
private:
	double y;
	double width;
public:
	Laser(double posY, double width);
	double getPos();
	double getWidth();
	~Laser();
};

#endif