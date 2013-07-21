#include <iostream>
#include "timer.h"
#include "graph_test.h"

void graph_test() {
  Timer timer;

  std::cout << "Graph g1(6)" << std::endl;
  timer.start();
  //
  Graph g1(6);
  edge_t e01 = {0,1,2}, e10 = {1,0,2};
  edge_t e02 = {0,2,5}, e20 = {2,0,5};
  edge_t e12 = {1,2,4}, e21 = {2,1,4};
  edge_t e14 = {1,4,5}, e41 = {4,1,5};
  edge_t e23 = {2,3,6}, e32 = {3,2,6};
  edge_t e24 = {2,4,3}, e42 = {4,2,3};
  edge_t e34 = {3,4,2}, e43 = {4,3,2};
  edge_t e35 = {3,5,7}, e53 = {5,3,7};
  g1[0].add(e01); g1[0].add(e21);
  g1[0].add(e02); g1[2].add(e20);
  g1[1].add(e12); g1[2].add(e21);
  g1[1].add(e14); g1[4].add(e41);
  g1[2].add(e23); g1[3].add(e32);
  g1[2].add(e24); g1[4].add(e42);
  g1[3].add(e34); g1[4].add(e43);
  g1[3].add(e35); g1[5].add(e53);
  timer.stop();
  std::cout << "user:" << timer.utime() << std::endl;
  std::cout << "sys:" << timer.stime() << std::endl;


  std::cout << "Graph g2(64*64) Complete Graph" << std::endl;
  timer.start();
  // 
  Graph g2(64*64);
  for(unsigned int i=0;i<g2.size();++i) {
    for(unsigned int j=0;j<g2.size();++j) {
      if(i==j) continue;
      edge_t e = {i,j,1};
      g2[i].add(e);
    }
  }
  timer.stop();
  std::cout << "user:" << timer.utime() << std::endl;
  std::cout << "sys:" << timer.stime() << std::endl;

}
