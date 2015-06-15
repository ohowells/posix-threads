# Compiler to use
CXX=g++

# Options to be passed to the compiler
#
# CXXFLAGS_D for default
CXXFLAGS_D=-std=c++11 -lpthread -lrt -o

CXXFLAGS=-std=c++11 -lrt -o

OBJECTS=pthread.o

default:
	$(CXX) cw_code_p3.cpp $(CXXFLAGS_D) $(OBJECTS)

p2:
	$(CXX) $(CXXFLAGS) $(OBJECTS) cw_code_p2.cpp

p1:
	$(CXX) $(CXXFLAGS) $(OBJECTS) cw_code_p1.cpp

clean:
	rm -f $(OBJECTS) *.out
