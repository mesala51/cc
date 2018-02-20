### Makefile for Unix operating systems.

#CXX = clang++
CXX = g++
#LINK = clang++
BASH_ENV =

DEBUG = #-DASSERTIONS

WARNINGS = -Wall -Werror=return-type

#CXXFLAGS = -fno-rtti -std=c++11 -fno-exceptions $(WARNINGS)  -O3  -march=native

CXXFLAGS = -g -std=c++11

EXECS =

OBJS = main.o piece.o rook.o bishop.o

all: chess

chess: $(OBJS) libprintsome.so
	$(CXX) $(CXXFLAGS)  $(OBJS) -L. -lprintsome -o chess

libprintsome.so: printsome.o
	$(CXX) $(CXXFLAGS)  printsome.o -shared -o libprintsome.so

printsome.o: src/printsome.cpp
	$(CXX) $(CXXFLAGS)  src/printsome.cpp -o printsome.o -c -fpic

### Generic rule for all other .cpp files:
%.o: src/%.cpp
	$(BASH_ENV) $(CXX) $(CXXFLAGS) -o $@ -c $<


clean:
	#rm -f $(EXECS)
	rm -f build/*.o
	rm -f build/*.so
	rm -f build/chess
	rm -f *.o
	rm -f *.so
	rm -f chess
