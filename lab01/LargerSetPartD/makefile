LargerSetPartD.x: LargerSetPartD.o LargerSetPartD_main.o
	g++ -ggdb LargerSetPartD.o LargerSetPartD_main.o InvertedList.o  -o largerSetPartD.x

LargerSetPartD.o: LargerSetPartD.cpp  LargerSetPartD.hpp 
	g++ -ggdb -c -o LargerSetPartD.o LargerSetPartD.cpp 
	
LargerSetPartD_main.o: LargerSetPartD_main.cpp LargerSetPartD.hpp InvertedList.o
	g++ -ggdb -c -o LargerSetPartD_main.o LargerSetPartD_main.cpp

