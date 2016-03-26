//Authors: Sebastian Grobelny Nicki Padar
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "city.h"
#include "vector.h"
using namespace std;

City::City() : longitude(0), latitude(0), name(NULL), state(NULL), population(0)
{ 
  airport[0] = '\0'; 
}//City

City::~City()
{
}//~City()

City& City::operator = (const City &rhs)
{
  if(&rhs != this)
  {
    this->population = rhs.population;
    this->name = rhs.name;
    this->state = rhs.state;
    this->latitude = rhs.latitude;
    this->longitude = rhs.longitude;
    strcpy(this->airport, rhs.airport);
  }
  return *this;
}//operator

void City::readCity(char *temp)
{
  char  *ptr1, *ptr2, *ptr3;
  int pop;

  ptr1 = strtok(temp, ",");
  name = new char[strlen(ptr1) + 1];
  strcpy(name, ptr1);
  ptr2 = strtok(NULL, ",");
  state = new char[strlen(ptr2) + 1];
  strcpy(state, ptr2);
  ptr3 = strtok(NULL, "\n");
  pop = atoi(ptr3);
  population = pop;
}//readCity()

void City::readAirport(char *newline)
 {  
  char *ptr1, *ptr2, *ptr3, *ptr4, *ptr5;
  double lat, lon;
  
  if(isalpha(newline[0]))
  {
    ptr5 = strtok(newline,"\n");
    state = new char[strlen(ptr5) + 1];
    strcpy(state, ptr5);
  }
  

  if(newline[0] == '[')
  {
  ptr1 = strtok(newline, " ");
  strncpy(airport, ptr1 + 1, 3);
  ptr2 = strtok(NULL, " ");
  lat = atof(ptr2);
  latitude = lat;
  ptr3 = strtok(NULL, " ");
  lon = atof(ptr3);
  longitude = lon;
  ptr4 = strtok(NULL, ",");
  name = new char[strlen(ptr4) + 1];
  strncpy(name, ptr4 + 1, strlen(ptr4));
  }
 }//readAirport()

bool City::isEqual(const City *cityarray)const
 {	
  if (( cityarray->name && name ) && ( cityarray->state && state))
   {
   return (strcmp(name, cityarray->name) == 0)&&(strcmp(state,cityarray->state)==0);
   }//if
   else if(airport[0] && cityarray-> airport[0])
   {
    return (strcmp(airport, cityarray->airport)==0);
   }
  else //not the same
   {
    return 0;
   }//else
 }//isEqual()

 
void City::copyLocation(City *city_local)
 {
  strcpy(city_local->airport, airport);
  city_local->latitude = latitude;
  city_local->longitude = longitude;
 }//copyLocation()


bool City::hasAirport()
 {          
  if (airport[0] == '\0')
   {
    return 0;
   }//if
  else //not the same
   {
    return 1;
   }//else
 }//hasAirport() 


void City::deallocate()
 {
  delete [] name;
  delete [] state;
 }//deallocate()

void City::setAirport(const char *arguments)
 {
  //name = new char[20];
  strcpy(airport, arguments);
 }//setAirport() 


void City::calcDistance(const City *cityarray2)const
 {
  double R = 3963, pop1, pop2, lat1, lon1, lat2, lon2, sines, cosines;
  int passengers, distance;
  pop1 = population;
  pop2 = cityarray2->population;
  lat1 = (M_PI / 180)*(latitude);
  lon1 = (M_PI / 180)*(longitude);
  lat2 = (M_PI / 180)*(cityarray2->latitude);
  lon2 = (M_PI / 180)*(cityarray2->longitude);
  passengers = (int)((pop1 * pop2) / (2500000000));
  sines = sin(lat1)*sin(lat2); 
  cosines = cos(lat1)*cos(lat2)*cos(lon1-lon2); 
  distance = (int)(acos(sines + cosines)*R);
   
  if (distance < 100)
   {
   passengers = 0;
   }//if
  cout << passengers << " passengers fly the " << distance << " miles from\n";
  cout << name << ", " << state << " to ";
  cout << cityarray2 -> name << ", " << cityarray2 -> state << ".\n";
} //calcDistance()

void City::calcTraffic(const City *cityarray, int &total)
{
  double R = 3963, pop1, pop2, lat1, lon1, lat2, lon2, sines, cosines;
  int passengers, distance;

  pop1 = population;
  pop2 = cityarray->population;
  lat1 = (M_PI / 180)*(latitude);
  lon1 = (M_PI / 180)*(longitude);
  lat2 = (M_PI / 180)*(cityarray->latitude);
  lon2 = (M_PI / 180)*(cityarray->longitude);
  passengers = (int)((pop1 * pop2) / (2500000000));
  sines = sin(lat1)*sin(lat2); 
  cosines = cos(lat1)*cos(lat2)*cos(lon1-lon2); 
  distance = (int)(acos(sines + cosines)*R);

  if (distance < 100)
  {
    passengers = 0;
  }

  cout<< cityarray->name << ", " << cityarray->state << ": " << passengers << "\n";
  total = passengers + total;
}

