#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;  

vector<pair<int, int>> adj[MAX_N];  
bool visited[MAX_N];
int dist[MAX_N];

int prim(int V) {
  int total = 0;
  
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  for(int u = 0; u < V; u++) {
    dist[u] = INF;
  }
  
  dist[0] = 0;
  pq.push({0, 0});

  while(!pq.empty()) {
    int u = pq.top().second; 
    pq.pop();
    
    if(visited[u]) continue;
    
    visited[u] = true;
    total += dist[u];
    
    for(auto ed: adj[u]) {
      int v = ed.first, w = ed.second;
      
      if(!visited[v] && w < dist[v]) {
        dist[v] = w;
        pq.push({dist[v], v});  
      }
    }
  }
  
  return total; 
}
