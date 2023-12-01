#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> adjacency_list[100];
vector<int> reverse_adjacency_list[100];
bool visited[100];

void dfs(int vertex, stack<int>& s) {
  visited[vertex] = true;
  for(int adjacent_vertex : adjacency_list[vertex]) {
    if(!visited[adjacent_vertex])
      dfs(adjacent_vertex, s);
  }
  s.push(vertex);
}

bool hasUniqueTopoOrder(int num_vertices) {
  fill(visited, visited + num_vertices, false);
  stack<int> topo_order;

  for(int i = 0; i < num_vertices; i++)
    if(!visited[i])
      dfs(i, topo_order);

  for(int i = 0; i < num_vertices; i++) {
    for(int j : reverse_adjacency_list[i]) {
      if(find(adjacency_list[j].begin(), adjacency_list[j].end(), i) == adjacency_list[j].end())
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
    reverse_adjacency_list[vertex_v].push_back(vertex_u);
  }

  if(hasUniqueTopoOrder(num_vertices))
    cout << "Co thu tu to po duy nhat\n";
  else
    cout << "Khong co thu tu to po duy nhat\n";
}
