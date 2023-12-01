#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adjacency_list[100];
int in_degree[100];

void eulerTour(int vertex) {
  for (int adjacent_vertex : adjacency_list[vertex]) {
    adjacency_list[vertex].erase(find(adjacency_list[vertex].begin(), adjacency_list[vertex].end(), adjacent_vertex));
    adjacency_list[adjacent_vertex].erase(find(adjacency_list[adjacent_vertex].begin(), adjacency_list[adjacent_vertex].end(), vertex));

    eulerTour(adjacent_vertex);
  }

  cout << vertex << " ";
}

bool hasEulerCircuit(int num_vertices) {
  for (int vertex = 0; vertex < num_vertices; vertex++)
    if (in_degree[vertex] != adjacency_list[vertex].size())
      return false;

  return true;
}

int main() {

  int num_vertices, num_edges;
  cin >> num_vertices >> num_edges;

  for (int i = 0; i < num_edges; i++) {
    int vertex_u, vertex_v;
    cin >> vertex_u >> vertex_v;

    adjacency_list[vertex_u].push_back(vertex_v);
    in_degree[vertex_v]++;
  }

  if (!hasEulerCircuit(num_vertices)) {
    cout << "Khong ton tai Euler circuit";
    return 0;
  }

  eulerTour(0);
  return 0;
}
