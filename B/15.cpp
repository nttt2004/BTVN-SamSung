#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_N = 100;

vector<int> adjacency_list[MAX_N];
int in_degree[MAX_N];

void topologicalSort(int num_vertices) {
  queue<int> q;

  for(int vertex = 0; vertex < num_vertices; vertex++) {
    if(in_degree[vertex] == 0) {
      q.push(vertex);
    }
  }

  while(!q.empty()) {
    int vertex = q.front();
    q.pop();
    cout << vertex << " ";

    for(int adjacent_vertex : adjacency_list[vertex]) {
      in_degree[adjacent_vertex]--;
      if(in_degree[adjacent_vertex] == 0) {
        q.push(adjacent_vertex);
      }
    }
  }
}

int main() {

  int num_vertices, num_edges;
  cin >> num_vertices >> num_edges;

  for(int i = 0; i < num_edges; i++) {
    int vertex_u, vertex_v;
    cin >> vertex_u >> vertex_v;

    adjacency_list[vertex_u].push_back(vertex_v);
    in_degree[vertex_v]++;
  }

  topologicalSort(num_vertices);

  return 0;
}
