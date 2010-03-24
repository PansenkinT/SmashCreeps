CXXFLAGS= -lSDL -lSDL_image -lglut
SRCS=$(wildcard *.cc)
OBJECTS=$(subst .cc,.o,$(SRCS))

.PHONY: clean

all: main
		 

main: $(OBJECTS)
		g++ $(CXXFLAGS) -o $@ main.cpp

clean:
		-rm -f main $(OBJECTS)
