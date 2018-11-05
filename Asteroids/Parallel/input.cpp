#include "input.h"

Input::Input(int argc, char **argv) { //constructor of Input, credit values to Input parrameters (from main() arguments) and checks if they are correct
  if(argc>1) numAsteroids = atoi(argv[1]);
  if(argc>2) numIntertions = atoi(argv[2]);
  if(argc>3) numPlanets = atoi(argv[3]);
  if(argc>4) posRay = atoi(argv[4]);
  if(argc>5) seed = atoi(argv[5]);
  }

bool Input::isRight(){
	if(numAsteroids<0) { //i dont really understand difference between nasteroids - seq and par ,if You know what they mean in the excercise tell me and i will add another expection
    cout<<"nasteroids-seq: Wrong arguments."<<endl<<"Correct use:"<<endl<<"nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed";
    return false;
  }
  if(numIntertions<0) {
    cout<<"num_iterations-seq: Wrong arguments."<<endl<<"Correct use:"<<endl<<"nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed";
    return false;
  }
  if(numPlanets<0) {
    cout<<"num_planets-seq: Wrong arguments."<<endl<<"Correct use:"<<endl<<"nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed";
    return false;
    }
  if(posRay<0 || posRay>200) {
    cout<<"pos_ray-seq: Wrong arguments."<<endl<<"Correct use:"<<endl<<"nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed";
    return false;
    }
  if(seed<0) {
    cout<<"seed-seq: Wrong arguments."<<endl<<"Correct use:"<<endl<<"nasteroids-seq num_asteroids num_iterations num_planets pos_ray seed";
    return false;
    }
	return true;
}
int Input::finishProgram(){ //it is demanded because constructor cant return any value
  return -1;
}

int Input::getNumAsteroids(){
  return this->numAsteroids;
}

int Input::getNumIterations()
{
  return this->numIntertions;
}

int Input::getNumPlanets(){
  return this->numPlanets;
}

double Input::getPosRay(){
  return this->posRay;
}

int Input::getSeed(){
  return this->seed;
}

void Input::display()
{
  cout<<numAsteroids<<numIntertions<<numPlanets<<posRay<<seed;
}

Input::~Input(){}