#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countParallelEdges(vector<pair<int, int>> edges) {
  int count = 0;

  sort(edges.begin(), edges.end());

  for(int i = 0; i < edges.size()-1; i++) {
    if(edges[i].first == edges[i+1].first &&
       edges[i].second == edges[i+1].second) {
      count++;
    }
  }

  return count;
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> edges;

  int u, v;
  for(int i = 0; i < n; i++) {
    cin >> u >> v;
    edges.push_back({u, v});
  }

  cout << countParallelEdges(edges);

  return 0;
}
