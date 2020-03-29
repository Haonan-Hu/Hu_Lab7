Lab7: main.o Executive.o Heap.o
	g++ -std=c++11 -g -Wall main.o Executive.o Heap.o -o Lab7

main.o: main.cpp Executive.h Executive.cpp Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Heap.o: Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c Heap.cpp

clean:
	rm *.o Lab7
