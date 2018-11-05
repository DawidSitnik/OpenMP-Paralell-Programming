CXXFLAGS= -g -c -pedantic-errors -O3 -O0 -pedantic -static -std=c++14 -Wall -DDEBUG -o obj/
DIR=obj/

a.out: $(DIR)Source.o $(DIR)Asteroid.o $(DIR)Element.o $(DIR)Engine.o $(DIR)Laser.o $(DIR)Planet.o $(DIR)input.o $(DIR)output.o $(DIR)AtomicLock.o
	g++ -g -DDEBUG $(DIR)Source.o $(DIR)Asteroid.o $(DIR)Element.o $(DIR)Engine.o $(DIR)Laser.o $(DIR)Planet.o $(DIR)input.o $(DIR)output.o
$(DIR)Source.o: Source.cpp
	g++ $(CXXFLAGS)Source.o Source.cpp
$(DIR)Asteroid.o: Asteroid.cpp
	g++ $(CXXFLAGS)Asteroid.o Asteroid.cpp
$(DIR)Element.o: Element.cpp
	g++ $(CXXFLAGS)Element.o Element.cpp
$(DIR)Engine.o: Engine.cpp
	g++ $(CXXFLAGS)Engine.o Engine.cpp
$(DIR)Laser.o: Laser.cpp
	g++ $(CXXFLAGS)Laser.o Laser.cpp
$(DIR)Planet.o: Planet.cpp
	g++ $(CXXFLAGS)Planet.o Planet.cpp
$(DIR)input.o: input.cpp
	g++ $(CXXFLAGS)input.o input.cpp
$(DIR)output.o: output.cpp
	g++ $(CXXFLAGS)output.o output.cpp
