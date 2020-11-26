CXX = clang++
CXXFLAGS = -std=c++17

H_FILES = Body.h catch.h collisions.h Colour.h Entity.h TriFan.h Vecs.h
CXX_FILES = Body.cpp collisions.cpp Colour.cpp Entity.cpp TriFan.cpp Vecs.cpp

all: testPairs.exe testBOA.exe

testPairs.exe: testPairs.cpp $(H_FILES) $(CXX_FILES) Makefile
	$(CXX) $(CXXFLAGS) testPairs.cpp $(CXX_FILES) -o testPairs.exe

testBOA.exe: testBOA.cpp $(H_FILES) $(CXX_FILES) Makefile
	$(CXX) $(CXXFLAGS) testBOA.cpp $(CXX_FILES) -o testBOA.exe

.PHONY: clean

clean:
	rm -f testPairs.exe testBOA.exe *.o