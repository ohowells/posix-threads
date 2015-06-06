# Compiler to use
CXX=g++

# Options to be passed to the compiler
CXXFLAGS=-std=c++11 -lpthread -lrt

default:
	$(CXX) cw_code_p3.cpp $(CXXFLAGS)

p2:
	$(CXX) cw_code_p2.cpp $(CXXFLAGS)

p1:
	$(CXX) cw_code_p1.cpp $(CXXFLAGS)

clean:
	rm -f *.o default p2 p3 a.out
