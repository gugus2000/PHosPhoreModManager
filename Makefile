CC=gcc
WIN-CC=x86_64-w64-mingw32-gcc
CXX=g++
WIN-CXX=x86_64-w64-mingw32-g++
RM=rm -rf
CFLAGS=
CXXFLAGS=-std=c++17
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDCLIBS=$(shell root-config --libs)
EXEC=phosphoremodmanager phosphoremodmanager.exe

SRCS=mod.cpp modmanager.cpp func.cpp tinyxml2.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
WIN-OBJS=$(subst .cpp,.wo,$(SRCS))

all: $(EXEC)

phosphoremodmanager: $(OBJS) main.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ main.cpp $(OBJS) $(LDCLIBS)

phosphoremodmanager.exe: $(WIN-OBJS) main.cpp
	$(WIN-CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ main.cpp $(OBJS) $(LDCLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.wo: %.cpp
	$(WIN-CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

mrproper:
	$(RM) $(EXEC)
