g1_main.o: g1_main.cpp g1_main.h
	g++ -pedantic-errors -std=c++11 -c g1_main.cpp
g2_main.o: g2_main.cpp g2_main.h
	g++ -pedantic-errors -std=c++11 -c g2_main.cpp
main.o: main.cpp g1_main.h g2_main.h
	g++ -pedantic-errors -std=c++11 -c main.cpp
adventure: main.o g1_main.o g2_main.o
	g++ -pedantic-errors -std=c++11 main.o g1_main.o g2_main.o -o adventure

clean:
	rm -f g1_main.o g2_main.o main.o adventure
.PHONY: clean
