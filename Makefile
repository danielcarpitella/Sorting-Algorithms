
CC = g++
CFLAGS = -std=c++17 -g -Wall

HEADERS=sortingalgorithms.hpp
	
SOURCES=main.cpp
TARGET=sorting

.PHONY : all clean

all : $(SOURCES) $(HEADERS) 
	  $(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)
	  ./$(TARGET)
	


clean :
	@rm -rf $(TARGET)