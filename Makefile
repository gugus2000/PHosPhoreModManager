CC=gcc
WIN-CC=x86_64-w64-mingw32-gcc
CXX=g++ -Wall
WIN-CXX=x86_64-w64-mingw32-g++ -Wall
RM=rm -rf
CFLAGS=
CXXFLAGS=-std=c++17 --static
CPPFLAGS=-g
LDFLAGS=-g
LDCLIBS=
EXEC=phosphoremodmanager phosphoremodmanager.exe

SRCS=mod.cpp modmanager.cpp func.cpp tinyxml2.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
WIN-OBJS=$(subst .cpp,.wo,$(SRCS))

all: $(EXEC)

phosphoremodmanager: $(OBJS) main.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ main.cpp $(OBJS) $(LDCLIBS)

phosphoremodmanager.exe: $(WIN-OBJS) main.cpp
	$(WIN-CXX) $(LDFLAGS) $(CXXFLAGS) -o $@ main.cpp $(WIN-OBJS) $(LDCLIBS) -lstdc++fs

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.wo: %.cpp
	$(WIN-CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(WIN-OBJS)

mrproper:
	$(RM) $(EXEC)
