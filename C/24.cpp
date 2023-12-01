#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000; 

struct Edge {
  int u, v, w;  
};

vector<Edge> minEdge(MAX_N);
vector<Edge> spanningTree; 

// C?u trúc duy trì các thành ph?n liên thông  
struct DisjointSet {
  int parent[MAX_N];
  int size;
  
  void init() {
    for (int i = 0; i < MAX_N; ++i)
      parent[i] = i;
    size = MAX_N; 
  }
  
  int find(int u) {
    return parent[u] == u ? u : (parent[u] = find(parent[u]));
  }

  void merge(int u, int v) {
    if (size == 1) return; 
    
    u = find(u);
    v = find(v);
    
    if (rand() & 1) 
      swap(u, v);

    if (u != v) {
      parent[u] = v;
      size--;
    }
  }
};

DisjointSet sets; 

void improvedBoruvka(vector<Edge> edges) {

  sets.init();
  
  while (sets.size > 1) {  
    fill(minEdge.begin(), minEdge.end(), {0, 0, INT_MAX});

    for (Edge e : edges) {
      int u = sets.find(e.u);
      int v = sets.find(e.v);

      if (minEdge[u].w > e.w)
        minEdge[u] = e;  

      if (minEdge[v].w > e.w)
        minEdge[v] = e;
    }

    for (int i = 0; i < MAX_N; ++i) 
      if (minEdge[i].w < INT_MAX)
        sets.merge(minEdge[i].u, minEdge[i].v); 
        spanningTree.push_back(minEdge[i]);
  }
}

int main() {

  int V, E;
  cin >> V >> E; 
  
  vector<Edge> edges(E);
  
  for (int i = 0; i < E; ++i) 
    cin >> edges[i].u >> edges[i].v >> edges[i].w;

  improvedBoruvka(edges);

  return 0;
}
