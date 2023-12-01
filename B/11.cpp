#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> adjacency_list[100];
bool visited[100];

void topologicalSort(int vertex, stack<int>& topoOrder) {
  visited[vertex] = true;
  for(int adjacent_vertex : adjacency_list[vertex]) {
    if(!visited[adjacent_vertex])
      topologicalSort(adjacent_vertex, topoOrder);
  }
  topoOrder.push(vertex);
}

bool hasHamiltonianPath(int num_vertices) {
  stack<int> topo_order;

  for(int i = 0; i < num_vertices; i++)
    if(!visited[i])
      topologicalSort(i, topo_order);

  int source = topo_order.top();

  while(!topo_order.empty()) {
    int u = topo_order.top();
    topo_order.pop();

    if(topo_order.size() > 0) {
      int v = topo_order.top();
      if(find(adjacency_list[u].begin(), adjacency_list[u].end(), v) == adjacency_list[u].end())
         return false;
    }
  }
  return true;
}

int main() {
  int num_vertices, num_edges;
  cin >> num_vertices >> num_edges;

  for(int i = 0; i < num_edges; i++) {
    int vertex_u, vertex_v;
    cin >> vertex_u >> vertex_v;
    adjacency_list[vertex_u].push_back(vertex_v);
  }

  if (hasHamiltonianPath(num_vertices))
    cout << "Co duong di Hamilton";
  else
    cout << "Khong co duong di Hamilton";

  return 0;
}
