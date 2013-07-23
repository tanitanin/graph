#include <limits>
#include "bellman_ford.h"


bool bellman_ford(Graph &g, unsigned int s) {
  static const int INF = std::numeric_limits<int>::max() / 2;
  const int N = g.size();

  // 初期化
  for(int i=0;i<N;++i) {
    g[i].cost = INF + INF;
    g[i].from = -2;
  }
  g[s].cost = 0;

  // コストを更新
  bool negative_cycle = false;
  for(int k=0;k<N;++k) {
    for(int v=0;v<N;++v) {
      const int E = g[v].degree();
      for(int e=0;e<E;++e) {
        const int cost = g[v].cost + g[v][e].weight;
        if(g[g[v][e].to].cost > cost) {
          g[g[v][e].to].cost = cost;
          g[g[v][e].to].from = v;
          if (k == N-1) {
            g[g[v][e].to].cost = -INF;
            negative_cycle = true;
          }
        }
      }
    }
  }
  return !negative_cycle;
}
