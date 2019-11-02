#
# File to control how I compile and link files in this folder
# Assume a well structured project with an include folder, a source folder and test foder
#

CC := g++
SRC_DIR := ./src
INCLUDE_DIR := ./include
BUILD_DIR := ./build

CFLAGS = -I $(INCLUDE_DIR) -Wall
_DEPS = $(INCLUDE_DIR)/karatsuba.h
ODIR=obj


$(ODIR)/%.o: $(SRC_DIR)/%.cpp $(_DEPS)
	@echo "$(CC) -c -o $@ $< $(CFLAGS)"
	$(CC) -c -o $@ $< $(CFLAGS)


main: $(ODIR)/main.o $(ODIR)/karatsuba.o
	@echo "$(CC) -o $@ $^ $(CFLAGS)"
	$(CC) -o $@ $^ $(CFLAGS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 
