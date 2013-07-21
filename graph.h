#pragma once

#include <vector>

// エッジ
typedef struct {
  unsigned int from;
  unsigned int to;
  int weight;
} edge_t;

// ノード
typedef struct {
  std::vector<edge_t> edges;
  bool done = false;
  int cost = -1;
  unsigned int from;
} node_t;

class Node {
  private:
    std::vector<edge_t> edges_;
  public:
    Node();
    Node(unsigned int k);
    ~Node();
    
    unsigned int degree();
    void add(edge_t &e);
    edge_t &edge(unsigned int n);
    edge_t &operator[](unsigned int n);

  // ダイクストラ用
  public:
    bool done = false;
    int from = -1;
    int cost = -1;
};

// グラフ
class Graph {
  private:
    std::vector<Node> nodes_;
  public:
    Graph(unsigned int n);
    ~Graph();
    void add(Node &node);
    Node &node(unsigned int index);
    Node &operator[](const unsigned int n);
    unsigned int size();
};

