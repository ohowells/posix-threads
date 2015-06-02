# Compiler to use 
CXX=g++

# Options to be passed to the compiler
CXXFLAGS=-std=c++11 -lpthread -lrt

p3: cw_code_p3.cpp
	$(CXX) cw_code_p3.cpp $(CXXFLAGS) 

p2: cw_code_p2.cpp
	$(CXX) cw_code_p2.cpp $(CXXFLAGS) 

p1: cw_code_p1.cpp
	$(CXX) cw_code_p1.cpp $(CXXFLAGS) 

clean:
	rm -f *.o p1 p2 p3 a.out
