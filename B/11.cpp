#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> adj[100];
bool visited[100]; 

void topologicalSort(int v) {
  visited[v] = true;
  for(int u: adj[v]) {
    if(!visited[u])
      topologicalSort(u);
  }
  stack<int> s;
  s.push(v);
}

bool hamiltonianPath(int V) {
  stack<int> topoOrder; 
  
  for(int i = 0; i < V; i++)
    if(!visited[i])
      topologicalSort(i);

  int src = topoOrder.top();  

  while(!topoOrder.empty()) {
    int u = topoOrder.top();
    topoOrder.pop();

    if(topoOrder.size() > 0) {
      int v = topoOrder.top();
      if(find(adj[u].begin(), adj[u].end(), v) == adj[u].end())
         return false; 
    }
  }

  return true;
}

int main() {

  int V, E;
  cin >> V >> E;

  // Nh?p c?nh 
  for(int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); 
  }

  if (hamiltonianPath(V)) 
    cout << "Co duong di Hamilton";
  else
    cout << "Khong co duong di Hamilton";  

  return 0;
}
