CXX:=LD_LIBRARY_PATH=/usr/local/lib g++

CFLAGS=-Wall -g 
LIB := -lgmp -lgmpxx -LLIBDIR -Wl,-rpath -Wl,LIBDIR
all: main
INC:= -I ./include/  
INCTEST:= -I ./include/ -I ../lib/catch2/ 
	
main: src/quicksort_routine.cpp src/quicksort_routine.cpp 
	$(CXX) $(CFLAGS)  src/main_quicksort.cpp  src/quicksort_routine.cpp   -o main

test: src/main_test.cpp src/quicksort_routine.cpp
	$(CXX) $(CFLAGS) $(INCTEST) src/main_test.cpp  src/quicksort_routine.cpp   -o test
clean: 
	rm -rf *o main test 
