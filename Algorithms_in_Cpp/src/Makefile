CXX:=LD_LIBRARY_PATH=/usr/local/lib g++

CFLAGS=-Wall -g 
LIB := -lgmp -lgmpxx -LLIBDIR -Wl,-rpath -Wl,LIBDIR
all: main
INC: -I ../include/ -I ../lib/gmp/
	
main: main.cpp karatsuba.cpp 
	$(CXX) $(CFLAGS)  main.cpp  karatsuba.cpp $(LIB) $(INC)  -o main

clean: 
	rm -rf *o main 
