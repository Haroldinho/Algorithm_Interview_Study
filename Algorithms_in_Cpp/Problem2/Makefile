CXX:=LD_LIBRARY_PATH=/usr/local/lib g++

CFLAGS=-Wall -g 
LIB := -lgmp -lgmpxx -LLIBDIR -Wl,-rpath -Wl,LIBDIR
all: main
INC:= -I ./include/  
INCTEST:= -I ./include/ -I ../lib/catch2/ 
	
main: src/main_count_inversion.cpp src/count_inversion.cpp 
	$(CXX) $(CFLAGS)  src/main_count_inversion.cpp  src/count_inversion.cpp   -o main

test: src/main_test.cpp src/count_inversion.cpp
	$(CXX) $(CFLAGS) $(INCTEST) src/main_test.cpp  src/count_inversion.cpp   -o test
clean: 
	rm -rf *o main test 
