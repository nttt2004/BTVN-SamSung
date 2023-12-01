#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[100];
vector<int> reverseAdj[100]; 
bool visited[100];

void dfs(int u) {
  visited[u] = true;
  for(int v: adj[u]) {
    if(!visited[v])
      dfs(v); 
  }
  
  stack<int> s;
  s.push(u);
}

bool isHamiltonian() {
  fill(visited, visited+V, false);
  
  for(int i = 0; i < V; i++)
    if(!visited[i]) 
      dfs(i);
      
  for(int i = 0; i < V; i++) {
    for(int j: reverseAdj[i]) {
      if(find(adj[j].begin(), adj[j].end(), i) == adj[j].end())
        return false;
    }
  }  
  
  return true;
}

int main() {
  int V, E;
  cin >> V >> E;

  for(int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    reverseAdj[v].push_back(u); 
  }

  if(isHamiltonian()) 
    cout << "Co thu tu to po duy nhat\n";
  else
    cout << "Khong co thu tu to po duy nhat\n"; 
}
