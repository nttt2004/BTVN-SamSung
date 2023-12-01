#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<pair<int, int>> adjacency_list[MAX_N];
bool is_visited[MAX_N];
int distances[MAX_N];

int prim(int num_vertices) {
  int total_weight = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for(int vertex = 0; vertex < num_vertices; vertex++) {
    distances[vertex] = INF;
  }

  distances[0] = 0;
  pq.push({0, 0});

  while(!pq.empty()) {
    int current_vertex = pq.top().second;
    pq.pop();

    if(is_visited[current_vertex]) continue;

    is_visited[current_vertex] = true;
    total_weight += distances[current_vertex];

    for(auto edge : adjacency_list[current_vertex]) {
      int next_vertex = edge.first, weight = edge.second;

      if(!is_visited[next_vertex] && weight < distances[next_vertex]) {
        distances[next_vertex] = weight;
        pq.push({distances[next_vertex], next_vertex});
      }
    }
  }

  return total_weight;
}
