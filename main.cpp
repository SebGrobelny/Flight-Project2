//Authors: Sebastian Grobelny Nicki Padar
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include "vector.h"
using namespace std;

void run(Vector *cities);
void getChoice(Vector *cities);

int main()
{
  Vector cities;
  cities.readCities();
  cities.readAirports();
  cities.cleanCities();
  getChoice(&cities);
  return 0;
}//main()


void getChoice(Vector *cities)
{
  int input, index = 0;
  char air[100];
  const char *air1;
  cout << "\n";
  cout << "Flight Simulator Menu\n";
  cout << "0. Done.\n";
  cout << "1. Determine distance and passengers between two airports.\n";
  cout << "2. Determine all traffic from one airport.\n";
  cout << "\n";
  cout << "Your choice (0 - 2): ";
  cin >> input;
  cin.ignore();
 
  while(input!=0)
  {
    if(input == 1)
    {
      run(cities);
    }
    else if(input == 2)
    {
      cout << "\n";
      cout << "Please enter an airport abbreviation (XXX): ";
      cin.getline(air, 100);
      air[strlen(air) + 1] = '\n';
      air1 = strtok(air, "\n");
      if(cities->findAirport(air1) != -1)
      {
        index = cities->findAirport(air1);
        cities->calcAirportTraffic(index);
      }
      else
      {
        cout<< air1 << " is not a valid airport.\n";
      } //else
    } //else if
    else
    {
      cout << "Your choice must be between 0 and 2. Please try again.\n";
    } //else
    
    cout << "\n";
    cout << "Flight Simulator Menu\n";
    cout << "0. Done.\n";
    cout << "1. Determine distance and passengers between two airports.\n";
    cout << "2. Determine all traffic from one airport.\n";
    cout << "\n";
    cout << "Your choice (0 - 2): ";
    cin >> input;
    cin.ignore();
  } //while

  if(input == 0)
    return ;
} //getChoice

void run(Vector *cities)
{
  char input[79];
  const char *ptr1, *ptr2;
  int index1, index2;
  cout << "\n";
  cout << "Please enter two airport abbreviations (XXX XXX): ";
  cin.getline(input, 79);
  input[strlen(input) + 1] = '\n';
  ptr1 = strtok(input, " ");
  ptr2 = strtok(NULL, "\n");
   
  index1 = cities->findAirport(ptr1);
  index2 = cities->findAirport(ptr2);

  if ((index1 != -1) && ( index2 != -1))
  {
   cities->calcDistance(index1, index2);
  }//if calcDistance()

  if (index1 == -1)
  {
   cout << ptr1 << " is not a valid airport.";
   cout << "\n";
  }//if cout 

  if (index2 == -1)
  {
   cout << ptr2 << " is not a valid airport.";
   cout << "\n";
  }//if cout
  	
}//run()
  

