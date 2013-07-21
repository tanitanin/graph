
#include "graph.h"

// ノードコンストラクタ
Node::Node() : edges_() {
}
Node::Node(unsigned int k) : edges_(k) {
}

// ノードデストラクタ
Node::~Node() {
}

// ノードの次数
unsigned int Node::degree() {
  return edges_.size();
}

// ノードへエッジを追加
void Node::add(edge_t &e) {
  edges_.push_back(e);
}

edge_t &Node::edge(unsigned int n) {
  return edges_[n];
}
edge_t &Node::operator[](unsigned int n) {
  return edges_[n];
} 

// グラフコンストラクタ
Graph::Graph(unsigned int n) : nodes_(n) {
}

// グラフデストラクタ
Graph::~Graph() {
}

// グラフへノードを追加
void Graph::add(Node &node) {
  nodes_.push_back(node);
}

// indexのノードを取得
Node &Graph::node(unsigned int index) {
  return nodes_[index];
}
Node &Graph::operator[](const unsigned int n) {
  return nodes_[n];
}

// ノードの数
unsigned int Graph::size() {
  return nodes_.size();
}
