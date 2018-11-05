#include "Engine.h"
#include "output.h"
#include <chrono>

int main(int argc, char **argv) {
	using clk = chrono::high_resolution_clock;
	auto t1 = clk::now();

	Input input(argc, argv);
	if(input.isRight()){
		Engine engine(input.getNumAsteroids(),input.getNumIterations(),input.getNumPlanets(),input.getPosRay(),input.getSeed());
		Output output(PATH_INPUT, PATH_OUTPUT);
		output.saveInitConfToFile(engine.getPlanetVector(), engine.getAsteroidVector(), input.getNumAsteroids(), input.getNumIterations(), input.getNumPlanets(), input.getPosRay(), input.getSeed());
		engine.startCalculations();
		output.saveOutputToFile(engine.getAsteroidVector());
		auto t2 = clk::now();
		cout << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << endl;
		return 0;
	}
	else
		return -1;

}
