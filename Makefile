EXENAME = cs225GradeCalculator
OBJS = main.o graphics.o

CXX = clang++
LD = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

all : $(EXENAME)

$(EXENAME) : $(OBJS)
    $(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp graphics.h
    $(CXX) $(CXXFLAGS) main.cpp

graphics.o : graphics.h graphics.cpp
    $(CXX) $(CXXFLAGS) graphics.cpp