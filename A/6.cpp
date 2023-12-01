#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100]; 
bool visited[100];

bool dfs(int u, int parent) {
  visited[u] = true;
  for(int v: adj[u]) {
    if(v == parent) continue;
    if(visited[v]) return false; 
    if(!dfs(v, u)) return false; 
  }
  return true;
}

bool isEdgeConnected(int V) {
  fill(visited, visited+V, false);
  return dfs(0, -1); 
}

int main() {
  int V, E;
  cin >> V >> E;

  for(int i = 0; i<E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  
  if(isEdgeConnected(V)) 
    cout << "Lien thong canh";
  else
    cout << "Khong lien thong canh";
}
