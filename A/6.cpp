#include <iostream>
#include <vector>
using namespace std;

vector<int> adjacency_list[100];
bool visited_nodes[100];

bool depthFirstSearch(int current_node, int parent_node) {
  visited_nodes[current_node] = true;
  for(int adjacent_node: adjacency_list[current_node]) {
    if(adjacent_node == parent_node) continue;
    if(visited_nodes[adjacent_node]) return false;
    if(!depthFirstSearch(adjacent_node, current_node)) return false;
  }
  return true;
}

bool isEdgeConnectedGraph(int num_vertices) {
  fill(visited_nodes, visited_nodes + num_vertices, false);
  return depthFirstSearch(0, -1);
}

int main() {
  int num_vertices, num_edges;
  cin >> num_vertices >> num_edges;

  for(int i = 0; i < num_edges; i++) {
    int vertex_u, vertex_v;
    cin >> vertex_u >> vertex_v;
    adjacency_list[vertex_u].push_back(vertex_v);
    adjacency_list[vertex_v].push_back(vertex_u);
  }

  if(isEdgeConnectedGraph(num_vertices))
    cout << "Lien thong canh";
  else
    cout << "Khong lien thong canh";
}
```
