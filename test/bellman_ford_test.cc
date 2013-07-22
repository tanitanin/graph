#include <iostream>
#include "bellman_ford_test.h"
#include "timer.h"
#include "graph.h"
#include "bellman_ford.h"

void bellman_ford_test() {
  Timer timer;
  // 負辺のないグラフ
  Graph g1(6);
  edge_t e01= {0,1,2}, e10 = {1,0,2};
  edge_t e02= {0,2,3}, e20 = {2,0,3};
  edge_t e12= {1,2,2}, e21 = {2,1,2};
  edge_t e14= {1,4,4}, e41 = {4,1,4};
  edge_t e23= {2,3,6}, e32 = {3,2,6};
  edge_t e24= {2,4,5}, e42 = {4,2,5};
  edge_t e34= {3,4,2}, e43 = {4,3,2};
  edge_t e35= {3,5,5}, e53 = {5,3,5};
  g1[0].add(e01); g1[1].add(e10);
  g1[0].add(e02); g1[2].add(e20);
  g1[1].add(e12); g1[2].add(e21);
  g1[1].add(e14); g1[4].add(e41);
  g1[2].add(e23); g1[3].add(e32);
  g1[2].add(e24); g1[4].add(e42);
  g1[3].add(e34); g1[4].add(e43);
  g1[3].add(e35); g1[5].add(e53);

  std::cout << "start bellman ford g1" << std::endl;
  timer.start();
  const bool res1 = bellman_ford(g1,0);
  timer.stop();
  std::cout << "g1 result: " << res1 << std::endl;
  std::cout << "g1 utime: " << timer.utime() << std::endl;
  std::cout << "g1 stime: " << timer.stime() << std::endl;
  std::cout << std::endl;

  // 負辺のあるグラフ
  Graph g2(6);
  e01= {0,1,2}, e10 = {1,0,2};
  e02= {0,2,3}, e20 = {2,0,3};
  e12= {1,2,-2};
  e14= {1,4,4}, e41 = {4,1,4};
  e23= {2,3,6}, e32 = {3,2,6};
  e24= {2,4,5}, e42 = {4,2,5};
  e34= {3,4,2}, e43 = {4,3,2};
  e35= {3,5,5}, e53 = {5,3,5};
  g2[0].add(e01); g2[1].add(e10);
  g2[0].add(e02); g2[2].add(e20);
  g2[1].add(e12);
  g2[1].add(e14); g2[4].add(e41);
  g2[2].add(e23); g2[3].add(e32);
  g2[2].add(e24); g2[4].add(e42);
  g2[3].add(e34); g2[4].add(e43);
  g2[3].add(e35); g2[5].add(e53);

  std::cout << "start bellman ford g2" << std::endl;
  timer.start();
  const bool res2 = bellman_ford(g2,0);
  timer.stop();
  std::cout << "g2 result: " << res2 << std::endl;
  std::cout << "g2 utime: " << timer.utime() << std::endl;
  std::cout << "g2 stime: " << timer.stime() << std::endl;
  for(int i=0;i<g2.size();++i) {
    std::cout << "g2[" << i << "] from:" << g2[i].from << " cost:" << g2[i].cost << std::endl;
  }
  std::cout << std::endl;

  // 負閉路のあるグラフ
  Graph g3(6);
  e01= {0,1,2}, e10 = {1,0,2};
  e02= {0,2,3}, e20 = {2,0,3};
  e12= {1,2,-2};
  e41= {4,1,-4};
  e23= {2,3,6}, e32 = {3,2,6};
  e24= {2,4,5}, e42 = {4,2,5};
  e34= {3,4,-2};
  e35= {3,5,5}, e53 = {5,3,5};
  g3[0].add(e01); g3[1].add(e10);
  g3[0].add(e02); g3[2].add(e20);
  g3[1].add(e12);
  g3[4].add(e41);
  g3[2].add(e23); g3[3].add(e32);
  g3[2].add(e24); g3[4].add(e42);
  g3[3].add(e34);
  g3[3].add(e35); g3[5].add(e53);

  std::cout << "start bellman ford g3" << std::endl;
  timer.start();
  const bool res3 = bellman_ford(g3,0);
  timer.stop();
  std::cout << "g3 result: " << res3 << std::endl;
  std::cout << "g3 utime: " << timer.utime() << std::endl;
  std::cout << "g3 stime: " << timer.stime() << std::endl;
  for(int i=0;i<g3.size();++i) {
    std::cout << "g3[" << i << "] from:" << g3[i].from << " cost:" << g3[i].cost << std::endl;
  }
  std::cout << std::endl;

}
