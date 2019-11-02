CXX:=LD_LIBRARY_PATH=/usr/local/lib g++

CFLAGS=-Wall -g 
LIB := -lgmp -lgmpxx -LLIBDIR -Wl,-rpath -Wl,LIBDIR
all: main
INC:= -I ./include/  
INCTEST:= -I ./include/ -I ../lib/catch2/ 
	
main: src/scc.cpp  
	$(CXX) $(CFLAGS)  $(INC) src/main_scc.cpp  src/scc.cpp   -o main

test: src/main_test.cpp src/scc.cpp
	$(CXX) $(CFLAGS) $(INCTEST) src/main_test.cpp  src/scc.cpp   -o test
clean: 
	rm -rf *o main test 
