CXX:=LD_LIBRARY_PATH=/usr/local/lib g++

CFLAGS=-Wall -g 
LIB := -lgmp -lgmpxx -LLIBDIR -Wl,-rpath -Wl,LIBDIR
all: main
INC:= -I ./include/  
INCTEST:= -I ./include/ -I ../lib/catch2/ 
	
main: src/dijkstra.cpp  
	$(CXX) $(CFLAGS)  $(INC) src/main_dijkstra.cpp  src/graph_functions.cpp src/dijkstra.cpp   -o main

test: src/main_test.cpp src/dijkstra.cpp
	$(CXX) $(CFLAGS) $(INCTEST) src/main_test.cpp  src/graph_functions.cpp src/dijkstra.cpp   -o test
clean: 
	rm -rf *o main test 
