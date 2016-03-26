simulator.out : main.o vector.o city.o
	g++ -ansi -Wall -g -o simulator.out main.o vector.o city.o

main.o : main.cpp vector.h
	g++ -ansi -Wall -g -c main.cpp 

vector.o : vector.cpp vector.h city.h
	g++ -ansi -Wall -g -c vector.cpp

city.o : city.cpp vector.h city.h 
	g++ -ansi -Wall -g -c city.cpp

clean :
	rm -f simulator.out main.o vector.o city.o
