CC=gcc
CXX=g++
RM=rm -rf
CFLAGS=
CXXFLAGS=
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDCLIBS=$(shell root-config --libs)
EXEC=phosphoremodmanager

SRCS=mod.cpp modmanager.cpp func.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: $(EXEC)

phosphoremodmanager: $(OBJS) main.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ main.cpp $(OBJS) $(LDCLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

mrproper:
	$(RM) $(EXEC)
