
#include <queue>
#include "dijkstra.h"

// ダイクストラ法
void dijkstra(Graph &g, unsigned int s) {

  // init
  for(int i=0;i<g.size();++i) {
    g[i].done = false;
    g[i].cost = -1;
  }
  // 始点のコストをゼロにする
  g[s].cost = 0;

  // loop
  while(true) {
    // 確定していないノードを探す
    int done_node = -1;
    for(int i=0;i<g.size();++i) {
      if(g[i].done || g[i].cost < 0) {
        continue;
      }
      if(done_node < 0 || g[i].cost < g[done_node].cost) {
        done_node = i;
      }
    }
    // すべてのノードが確定したら終了
    if(done_node < 0) break;

    // 隣接する頂点のコストを更新
    g[done_node].done = true;
    for(int i=0;i<g[done_node].degree();++i) {
      const int next = g[done_node][i].to;
      const int weight = g[done_node][i].weight;
      const int cost  = g[done_node].cost + weight;
      if(g[next].cost < 0 || cost < g[next].cost) {
        g[next].cost = cost;
        g[next].from = i;
      }
    }
  }
}

