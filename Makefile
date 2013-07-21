
OBJ = graph.o \
      dijkstra.o \

TEST_OBJ = test/timer.o \
           test/graph_test.o \
           test/dijkstra_test.o \
           test/test.o \

CXXFLAGS = -O2 -std=gnu++11 -I .

all: $(OBJ)

test: $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -I . $^ -o test/test
	./test/test
	rm -f $(OBJ) $(TEST_OBJ)
	rm -f test/test

clean:
	rm -f *.o *.out *.exe
