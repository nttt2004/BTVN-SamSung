#include <bits/stdc++.h>
using namespace std;

// Prim lazy version
double primLazy(vector<vector<double>>& graph) {
  double mst_weight = 0;
  
  // code Prim lazy
  
  return mst_weight;
}

// Prim using priority queue 
double primQueue(vector<vector<double>>& graph) {
  double mst_weight = 0;

  // code Prim priority queue
  
  return mst_weight;  
}

// Kruskal using Union Find
double kruskal(vector<vector<double>>& graph) {
  double mst_weight = 0;
  
  // code Kruskal
  
  return mst_weight;
}

int main() {

  vector<vector<double>> graph;
  
  // generate graph
  
  int V = graph.size();

  auto start = chrono::high_resolution_clock::now();  
  double weight = primLazy(graph);
  auto end = chrono::high_resolution_clock::now();

  cout << "Prim lazy time: " 
       << chrono::duration_cast<chrono::microseconds>(end - start).count() << " us" << endl;

  // similarly measure time for other algorithms
  
  return 0;  

