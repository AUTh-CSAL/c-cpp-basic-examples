CC=g++
CFLAGS=-O3

BINS_DIR=bins
SRC_DIR=src
DIRS=$(BINS_DIR)
$(info $(shell mkdir -p $(DIRS)))

default: all

reverseArray:
	$(CC) $(CFLAGS) -o $(BINS_DIR)/reverseArray.o $(SRC_DIR)/reverseArray.c
treeInorder:
	$(CC) $(CFLAGS) -o $(BINS_DIR)/treeInorder.o $(SRC_DIR)/treeInorder.c
mapReduce:
	$(CC) $(CFLAGS) -o $(BINS_DIR)/mapReduce.o $(SRC_DIR)/mapReduce.cpp

.PHONY: clean

all: reverseArray treeInorder mapReduce

test:
	@printf "\n----------- Running mapReduce: "
	$(BINS_DIR)/mapReduce.o
	@printf "\n\n----------- Running treeInorder: "
	$(BINS_DIR)/treeInorder.o
	@printf "\n\n----------- Running reverseArray: "
	$(BINS_DIR)/reverseArray.o

clean:
	rm -rf $(BINS_DIR)