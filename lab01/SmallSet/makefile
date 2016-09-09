smallSet.x: SmallSet.o SmallSet_main_2.o lab01b_printBits_2.o  
	g++ -ggdb SmallSet.o SmallSet_main_2.o lab01b_printBits_2.o  -o smallSet.x

SmallSet.o: SmallSet.cpp  SmallSet.hpp 
	g++ -ggdb -c -o SmallSet.o SmallSet.cpp 

SmallSet_main_2.o: SmallSet_main_2.cpp SmallSet.hpp 
	g++ -ggdb -c -o SmallSet_main_2.o SmallSet_main_2.cpp

lab01b_printBits_2.o: lab01b_printBits_2.hpp lab01b_printBits_2.cpp
	g++ -ggdb -c -o lab01b_printBits_2.o lab01b_printBits_2.cpp
