CXX := g++
source := example/example.cpp
#LIBS := -lstdc++fs
INC := -Iinclude/

all:
	mkdir -p bin
	$(CXX) $(INC) $(source) -o bin/example $(LIBS)
	
clean:
	rm -r bin
