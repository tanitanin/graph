
OBJ = graph.o \
      dijkstra.o \

TEST_OBJ = timer.o \
           graph_test.o \
           dijkstra_test.o \
           test.o \

CXXFLAGS = -O2 -std=gnu++11

all: $(OBJ)

test: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test
	rm -f $(OBJ) $(TEST_OBJ)
	rm -f test

clean:
	rm -f *.o *.out *.exe
