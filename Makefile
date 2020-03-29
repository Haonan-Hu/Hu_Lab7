Lab7: main.o Executive.o MinHeap.o MaxHeap.o
	g++ -std=c++11 -g -Wall main.o Executive.o MinHeap.o MaxHeap.o -o Lab7

main.o: main.cpp Executive.h Executive.cpp MinHeap.h MinHeap.cpp Doctor.h MaxHeap.h MaxHeap.cpp Patient.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp MinHeap.h MinHeap.cpp Doctor.h MaxHeap.h MaxHeap.cpp Patient.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

MinHeap.o: MinHeap.h MinHeap.cpp Doctor.h
	g++ -std=c++11 -g -Wall -c MinHeap.cpp

MaxHeap.o: MaxHeap.h MaxHeap.cpp Patient.h
	g++ -std=c++11 -g -Wall -c MaxHeap.cpp

clean:
	rm *.o Lab7
