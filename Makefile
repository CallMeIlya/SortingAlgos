CXX=g++
CXXFLAGS= -Wall -g
CPPFLAGS=-I/usr/include
LDFLAGS=

SRCS=sortingalgos.cpp

OBJS=$(SRCS:.cpp=.o)

TARGET=sortingalgos

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
# Rule to compile each .cpp file into a .o file

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

#avltree: avltree.cpp
#	$(CXX) $(CFLAGS) -o avltree avltree.cpp

.PHONY: all clean
