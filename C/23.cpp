#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int u, v, w;
};

vector<Edge> minEdges;
vector<Edge> spanningTree;

int parent[MAX_N];

int find(int u) {
  if (u == parent[u])
    return u;
  return find(parent[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (rand() & 1)
    swap(u, v);

  if (u != v)
    parent[u] = v;
}

void boruvka(vector<Edge> allEdges) {

  for (int i = 0; i < V; i++)
    parent[i] = i;

  bool changed;

  do {
    changed = false;

    minEdges.assign(V, {0, 0, INT_MAX});

    for (Edge e : allEdges) {
      int u = find(e.u);
      int v = find(e.v);

      if (minEdges[u].w > e.w)
        minEdges[u] = e;

      if (minEdges[v].w > e.w)
        minEdges[v] = e;
    }

    for (int i = 0; i < V; i++) {
      int u = find(minEdges[i].u);
      int v = find(minEdges[i].v);

      if (u != v) {
        merge(u, v);
        spanningTree.push_back(minEdges[i]);
        changed = true;
      }
    }
  }
  while (changed);
}

int main() {

  int V, E;
  cin >> V >> E;

  vector<Edge> edges(E);

  for(int i = 0; i < E; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }

  boruvka(edges);

  return 0;
}
