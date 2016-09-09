smallSet.x: LargerSet.o LargerSet_main.o
	g++ -ggdb LargerSet.o LargerSet_main.o  -o largerSet.x

SmallSet.o: LargerSet.cpp  LargerSet.hpp 
	g++ -ggdb -c -o LargerSet.o LargerSet.cpp 

LargerSet_main.o: LargerSet_main.cpp LargerSet.hpp 
	g++ -ggdb -c -o LargerSet_main.o LargerSet_main.cpp