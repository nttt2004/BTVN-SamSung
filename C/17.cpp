#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int u, v, w;
};

vector<Edge> spanningTree;
vector<Edge> edges; 

int V, E;

int findRoot(int u) {
  for(Edge e: spanningTree)
    if (e.u == u || e.v == u)
      return e.u == u ? e.v : e.u;

  return -1;    
}

void addEdge(Edge e) {
  int rootU = findRoot(e.u); 
  int rootV = findRoot(e.v);

  if(rootU != rootV) {
    spanningTree.push_back(e);
  } else {
    // Tim canh co trong so lon nhat trong chu trinh   
    int maxW = -1, maxEdge;
    for(Edge ed: spanningTree) {
      if((ed.u == e.u || ed.u == e.v) && 
         (ed.v == e.u || ed.v == e.v)) {
        
        if(ed.w > maxW) {
          maxW = ed.w;
          maxEdge = ed;
        } 
      }
    }  

    // Xoa canh co trong so lon nhat
    spanningTree.erase(
      find(spanningTree.begin(), spanningTree.end(), maxEdge)  
    );

    // Them canh e vao cay
    spanningTree.push_back(e); 
  }
}

int vyssotsky() {
  sort(edges.begin(), edges.end(), 
       [](Edge a, Edge b) { return a.w < b.w; });

  for(Edge e: edges)  
    addEdge(e);

  int total = 0;
  for(Edge e: spanningTree)  
    total += e.w;

  return total;   
}

int main() {
  cin >> V >> E;
  
  for(int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;  
    edges.push_back({u, v, w});
  }
  
  cout << vyssotsky();

  return 0;
}
