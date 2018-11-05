#ifndef HEADER_H
#define HEADER_H

struct cordXandY {
	double x;
	double y;
public:
	cordXandY& operator *(int multiplier) {
		this->x *= multiplier;
		this->y *= multiplier;
		return *this;
	}
};
constexpr double CONFLICT_POSITION = 2.0;
constexpr double GRAVITY = 6.674e-5;
constexpr double TIME_INTERVAL = 0.1;
constexpr double DMIN = 2.0;
constexpr double MAX_WIDTH = 200;
constexpr double MAX_HEIGHT = 200;
constexpr double RAY_WIDTH = 4.0;
constexpr unsigned int M = 1000;
constexpr unsigned int SDM = 50;
constexpr unsigned int PLANET_MASS_MULTIPLIER = 10;
constexpr double MIN_DISTANCE = 2.0;
const char PATH_OUTPUT[] = "out.txt";
const char PATH_INPUT[] = "init_conf.txt";
#endif