.PHONY: deploy test clean
CC = g++ 

INC_DIR = ../include
SRC_DIR = ../src
TEST_DIR = ./
CPP_FLAGS = -std=c++11 -Wall -Werror
TEST_SRC= test_karatsuba.cpp
SRC_EXT = cpp

INCLUDES=\
	 -I $(INC_DIR)\
	 -I $(TEST_DIR)

SOURCES := $(shell find $(SRC DIR) -name *.$(SRC_EXT))
SRCS=\
     $(SRC_DIR)/karatsuba.cpp

OBJS=$(SRCS:.cpp=.o)


test: $(OBJS)
	@echo "@$(CC) $(CPP_FLAGS) $(INCLUDES) -o run_test $(OBJS) $(TEST_SRC)"
	@$(CC) $(CPP_FLAGS) $(INCLUDES) -o run_test $(OBJS) $(TEST_SRC)
	@./run_test

%.o : %.cpp
	$(CC) $(CPP_FLAGS) $(INCLUDES) -c $< -o $@

clean: 
	rm $(OBJS)
