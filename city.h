//Authors: Sebastian Grobelny Nicki Padar
#ifndef CITY_H
 #define CITY_H

using namespace std;
class City
{
 double longitude;
 double latitude;
 char *name;
 char *state;
 char airport[4];
 int population;

public:
City();
~City();
City& operator = (const City &rhs);
void readCity(char *temp);
void readAirport(char *temp);
bool isEqual(const City *cityarray)const;
void copyLocation(City *city_local);
bool hasAirport();
void deallocate();
void setAirport(const char *temp);
void calcDistance(const City *cityarray2)const;
void calcTraffic(const City *cityarray, int &total);
};

#endif
