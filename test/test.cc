//#include <gtest/gtest.h>

#include "graph_test.h"
#include "dijkstra_test.h"
#include "bellman_ford_test.h"

int main(int argc, char **argv) {
  //::testing::InitGoogleTest(&argc, argv);
  //return RUN_ALL_TESTS();
  
  graph_test();
  dijkstra_test();
  bellman_ford_test();

  return 0;
}

