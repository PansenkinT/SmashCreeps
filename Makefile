CXXFLAGS= -lSDL -lSDL_image -lglut -Wall

SRCS=$(wildcard client/model/*.cpp)
SRCS+=$(wildcard client/view/*.cpp)
SRCS+=$(wildcard client/controller/*.cpp)
SRCS+=$(wildcard client/com/*.cpp)
SRCS+=$(wildcard /common/model/*.cpp)
SRCS+=$(wildcard /common/controller/*.cpp)

OBJECTS=$(subst .cpp,.o,$(SRCS))

CLIENTC=client/client.cpp
CLIENTO=client/client.o

.PHONY: clean

all: client

client: $(OBJECTS)
		g++ $(CXXFLAGS) $(OBJECTS) -o $(CLIENTO) $(CLIENTC)
		
Blueprint.o: geometrical_objects.o
Drawer.o: geometrical_objects.o

clean:
		-rm -f $(CLIENTO) $(OBJECTS)
