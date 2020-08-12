# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

.PHONY: all

all: playerDriver teamDriver

playerDriver: playerDriver.o Player.o
	$(CXX) $(CXXFLAGS) -o playerDriver playerDriver.o Player.o

playerDriver.o: playerDriver.cpp Player.h
	$(CXX) $(CXXFLAGS) -c playerDriver.cpp

teamDriver: teamDriver.o Player.o Team.o
	$(CXX) $(CXXFLAGS) -o teamDriver teamDriver.o Player.o Team.o

teamDriver.o: teamDriver.cpp Player.h Team.h
	$(CXX) $(CXXFLAGS) -c teamDriver.cpp

Player.o: Player.h

Team.o: Team.h Player.h
