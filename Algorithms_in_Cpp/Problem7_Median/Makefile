CXX:=LD_LIBRARY_PATH=/usr/local/lib g++

CFLAGS=-Wall -g 
LIB := -lgmp -lgmpxx -LLIBDIR -Wl,-rpath -Wl,LIBDIR
all: main
INC:= -I ./include/  
INCTEST:= -I ./include/ -I ../lib/catch2/ 
	
main: src/main.cpp  
	$(CXX) $(CFLAGS)  $(INC) src/main.cpp  src/main_median.cpp   -o main

test: src/main_test.cpp src/main_median.cpp
	$(CXX) $(CFLAGS) $(INCTEST) src/main_test.cpp   src/main_median.cpp   -o test
clean: 
	rm -rf *o main test 
