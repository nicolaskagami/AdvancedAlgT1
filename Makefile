
CC=g++ -std=c++0x

dijkstra: dijkstra.o FSgraph.o NHeap.o
	$(CC) dijkstra.o FSgraph.o NHeap.o -o dijkstra
dijkstra.o: Dijkstra/dijkstra.cpp
	$(CC) -c Dijkstra/dijkstra.cpp 
FSgraph.o: FSgraph/FSgraph.cpp
	$(CC) -c FSgraph/FSgraph.cpp
NHeap.o: NHeap/NHeap.cpp
	$(CC) -c NHeap/NHeap.cpp

clean:
	rm -f *.o
