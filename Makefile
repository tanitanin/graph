
INC = -I . -I inc \

OBJ = src/graph.o \
      src/dijkstra.o \
      src/bellman_ford.o \

LIB_NAME = libgraph.a

CXXFLAGS = -O2 -std=gnu++11 $(INC)
ARFLAGS = rv

$(LIB_NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all
all: $(LIB_NAME)

.PHONY: test
test: $(LIB_NAME)
	$(MAKE) -C test
	$(MAKE) -C test run
	$(MAKE) -C test clean

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@rm -f $(LIB_NAME)
