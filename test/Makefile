
INC = -I . -I ../inc
CXXFLAGS = -O2 -std=gnu++11 $(INC)

OBJ = timer.o \
      graph_test.o \
      dijkstra_test.o \
      bellman_ford_test.o \
      test.o \

TEST = test

$(TEST): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ ../libgraph.a -o $@

.PHONY: all
all: $(TEST)

.PHONY: run
run: $(TEST)
	./$(TEST)

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@rm -f $(TEST)
