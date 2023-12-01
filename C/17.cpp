#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int start, end, weight;
};

vector<Edge> minimumSpanningTree;
vector<Edge> allEdges;

int vertices, edges;

int findRoot(int vertex) {
  for(Edge edge: minimumSpanningTree)
    if (edge.start == vertex || edge.end == vertex)
      return edge.start == vertex ? edge.end : edge.start;

  return -1;
}

void addEdge(Edge newEdge) {
  int rootStart = findRoot(newEdge.start);
  int rootEnd = findRoot(newEdge.end);

  if(rootStart != rootEnd) {
    minimumSpanningTree.push_back(newEdge);
  } else {
    // Find the edge with the maximum weight in the cycle
    int maxWeight = -1;
    Edge maxWeightEdge;
    for(Edge existingEdge: minimumSpanningTree) {
      if((existingEdge.start == newEdge.start || existingEdge.start == newEdge.end) &&
         (existingEdge.end == newEdge.start || existingEdge.end == newEdge.end)) {

        if(existingEdge.weight > maxWeight) {
          maxWeight = existingEdge.weight;
          maxWeightEdge = existingEdge;
        }
      }
    }
    minimumSpanningTree.erase(
      find(minimumSpanningTree.begin(), minimumSpanningTree.end(), maxWeightEdge)
    );
    minimumSpanningTree.push_back(newEdge);
  }
}

int vyssotsky() {
  sort(allEdges.begin(), allEdges.end(),
       [](Edge a, Edge b) { return a.weight < b.weight; });

  for(Edge edge: allEdges)
    addEdge(edge);

  int totalWeight = 0;
  for(Edge edge: minimumSpanningTree)
    totalWeight += edge.weight;

  return totalWeight;
}

int main() {
  cin >> vertices >> edges;

  for(int i = 0; i < edges; i++) {
    int start, end, weight;
    cin >> start >> end >> weight;
    allEdges.push_back({start, end, weight});
  }

  cout << vyssotsky();

  return 0;
}
