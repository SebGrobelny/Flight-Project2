//Authors: Sebastian Grobelny Nicki Padar
#ifndef VECTOR_H
 #define VECTOR_H
#include "city.h"
class Vector
{ 
	City *cityArray;
  int size;
  int count;
  void resize();

public:
Vector(); 
~Vector(); 

int findAirport(char const *temp)const;
void readCities();
void readAirports();
void cleanCities();
void calcDistance(const int index1, const int index2)const;
void calcAirportTraffic(const int index);
};

#endif

