#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100];
int indeg[100]; 

void eulerTour(int u) {
  for(int v: adj[u]) {
    adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
    adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
    
    eulerTour(v);
  }
  
  cout << u << " "; 
}

bool hasEulerCircuit() {
  for(int u = 0; u < V; u++) 
    if(indeg[u] != adj[u].size())
      return false;

  return true;  
}

int main() {

  int V, E; 
  cin >> V >> E;

  for(int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v); 
    indeg[v]++; 
  }

  if (!hasEulerCircuit()) {
    cout << "Khong ton tai Euler circuit";
    return 0;
  }

  eulerTour(0);
  return 0;
}
