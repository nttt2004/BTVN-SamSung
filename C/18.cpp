#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100;

vector<pair<int, int>> edges;
vector<pair<int,int>> spanningTree; 

int parent[MAX_N];

int find(int u) {
  if(parent[u] == u) return u;
  return find(parent[u]);  
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if(rand() & 1)
    swap(u, v);
  
  if(u != v) 
    parent[u] = v;
}

bool isValid() {
  for(int i = 0; i < MAX_N; i++) 
    parent[i] = i;
  
  for(auto ed: spanningTree) 
    merge(ed.first, ed.second); 
  
  for(int i = 1; i < MAX_N; i++)
    if(find(0) != find(i)) 
      return false;
  
  return true;     
}

int reverseDelete() {
  for(auto ed: edges) { 
    spanningTree.push_back(ed);
  }
  
  sort(spanningTree.begin(), spanningTree.end(),
       [](pair<int,int> a, pair<int, int> b) {
         return a.second > b.second;  
       });
  
  for(int i = 0; i < spanningTree.size(); i++) {
    auto last = spanningTree.back();
    spanningTree.pop_back();
    
    if(isValid()) continue;
    else spanningTree.push_back(last); 
  }
  
  int total = 0;
  for(auto ed: spanningTree)
    total += ed.second;
  
  return total;  
}

int main() {

  int V, E;
  cin >> V >> E;

  for(int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }
  
  cout << reverseDelete();

  return 0;  
}

//Do phuc tap: O(ElogE) do sap xep canh.
