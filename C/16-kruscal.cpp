#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100; // assuming the maximum number of vertices

struct Edge {
  int u, v, w;
  bool operator<(Edge const& other) {
    return w < other.w;
  }
};

int parent[MAX_N];

int find(int u) {
  if(u == parent[u]) return u;
  return find(parent[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if(u != v) parent[u] = v;
}

int kruskal(vector<Edge>& edges, int V) {
  sort(edges.begin(), edges.end());

  for(int u = 0; u < V; u++)
    parent[u] = u;

  int total = 0;

  for(Edge& e : edges) {
    if(find(e.u) != find(e.v)) {
      merge(e.u, e.v);
      total += e.w;
    }
  }

  return total;
}
