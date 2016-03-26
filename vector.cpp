//Authors: Sebastian Grobelny Nicki Padar
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include "vector.h"
using namespace std;


Vector::Vector() : size(10), count(0)
{
  cityArray = new City[size];
} //Vector()

Vector::~Vector()
{
} //~Vector()

void Vector::readCities()
{
  ifstream infile;
  infile.open("citypopulations.csv");
  char temp[100];
 
  while(infile.getline(temp, 100))
   {
    temp[strlen(temp) + 1] = '\n';    
    if(count == size)
     {
      resize();
     } //if resize()

    cityArray[count].readCity(temp); 
    count = count + 1;
   } //while getline()
	 
  infile.close();
 } //readCities()


void Vector::resize()
{
  City *temp_city;
  int count;
  size = size * 2;
  temp_city = new City[size];

  for (count = 0; count  < size / 2; count++)
    {  
    temp_city[count] = cityArray[count];  
    } //for copyTemp()
	
  delete[] cityArray;  
  cityArray = new City[size];
  cityArray = temp_city;
 } //resize()

void Vector::readAirports()
 {  
  ifstream infile;    
  infile.open("airportLL.txt");
  char temp[100], a;
  int b = 0;
  City *city_local;	

  while(infile.getline(temp, 100))
    {
      temp[strlen(temp) + 1] = '\n';
      
        if(isalpha(temp[0]))
        {
          city_local = new City[10];
          city_local->readAirport(temp);
        }
           if (temp[0] == '[')
               {
                //city_local = new City[10];
                city_local->readAirport(temp);

                for (int i = 0; i < count; i++)
                  {
                   b = city_local->isEqual(&cityArray[i]);

                   if (b == 1)
                   {		       
                    city_local->copyLocation(&cityArray[i]);
                   }//if copyLocation()
                  }  
                }
            //}           
          //}    
        //}//for isEqual()
      }//readAirport()
    	
    infile.close(); 
    city_local->deallocate();
 }//readAirports()

void Vector::cleanCities()
 {
  int i=0;

  while(i < count)
  {
    if(!(cityArray[i].hasAirport()))
    {
      cityArray[i]= cityArray[--count];
    }//for hasAirport() 
    else
    {
      i++;
    }//else
  } //while()
} //cleanCities()

int Vector::findAirport(const char *arguments)const
 {
  int i, b;
  City *new_local;
  new_local = new City[1];
  new_local->setAirport(arguments);
 // cout<<"IN find Airport ";
  for ( i = 0; i < (count) ; i++)
  {
    b = new_local->isEqual(&cityArray[i]);

    if (b == 1)
    {
      return i;
    }//if
  }//for isEqual

  return -1;	
 }//findAirport

void Vector::calcDistance(const int index1, const int index2)const
 {
  cityArray[index1].calcDistance(&cityArray[index2]);
 }//calcDistance

void Vector::calcAirportTraffic(const int index)
{ 
  int total = 0; 

  for( int i =0; (i < count); i++)
  {
    if(i!=index)
      cityArray[index].calcTraffic(&cityArray[i], total);
  }//for

  cout << "Total passengers: " << total;
  cout << "\n";
} //calcAirportTraffic
