CXXFLAGS= -lSDL -lSDL_image -lglut
SRCS=$(wildcard *.cpp)
OBJECTS=$(subst .cpp,.o,$(SRCS))

.PHONY: clean

all: main
		 

main: $(OBJECTS)
		g++ $(CXXFLAGS) -o $@ main.cpp

clean:
		-rm -f main $(OBJECTS)
