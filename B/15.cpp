#include <iostream> 
#include <queue>

using namespace std;

const int N = 100;

vector<int> adj[N]; 
int indeg[N];  

void topologicalSort(int V) {
  queue<int> q;
  
  for(int u = 0; u < V; u++) {
    if(indeg[u] == 0) {
      q.push(u); 
    }
  }
  
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << " ";
    
    for(int v: adj[u]) {
      indeg[v]--;
      if(indeg[v] == 0) {
        q.push(v);  
      }
    }
  }
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
  
  topologicalSort(V);
  
  return 0;
}
