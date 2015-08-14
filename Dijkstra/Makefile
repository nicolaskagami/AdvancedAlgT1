
CC=g++

dijkstra: dijkstra.o FSgraph.o NHeap.o
	$(CC) dijkstra.o FSgraph.o NHeap.o -o dijkstra
dijkstra.o: dijkstra.cpp
	$(CC) -c dijkstra.cpp
FSgraph.o: FSgraph.cpp
	$(CC) -c FSgraph.cpp
NHeap.o: NHeap.cpp
	$(CC) -c NHeap.cpp

clean:
	rm -rf *.o
