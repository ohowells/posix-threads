# Compiler to use 
CXX=g++

# Options to be passed to the compiler
CXXFLAGS=-std=c++11 -Wall -lpthread -lrt

p3: cw_code_p3.cpp
	$(CXX) $(CXXFLAGS) cw_code_p3.cpp

p2: cw_code_p2.cpp
	$(CXX) $(CXXFLAGS) cw_code_p2.cpp

p1: cw_code_p1.cpp
	$(CXX) $(CXXFLAGS) cw_code_p1.cpp

clean:
	rm -f *.o p1 p2 p3  
