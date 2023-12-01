#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100;

vector<pair<int, int>> allEdges;
vector<pair<int,int>> finalEdges;

int root[MAX_N];

int findRoot(int vertex) {
  if(root[vertex] == vertex) return vertex;
  return findRoot(root[vertex]);
}

void unite(int vertex1, int vertex2) {
  vertex1 = findRoot(vertex1);
  vertex2 = findRoot(vertex2);
  if(rand() & 1)
    swap(vertex1, vertex2);

  if(vertex1 != vertex2)
    root[vertex1] = vertex2;
}

bool isValid() {
  for(int i = 0; i < MAX_N; i++)
    root[i] = i;

  for(auto edge: finalEdges)
    unite(edge.first, edge.second);

  for(int i = 1; i < MAX_N; i++)
    if(findRoot(0) != findRoot(i))
      return false;

  return true;
}

int reverseDelete() {
  for(auto edge: allEdges) {
    finalEdges.push_back(edge);
  }

  sort(finalEdges.begin(), finalEdges.end(),
       [](pair<int,int> a, pair<int, int> b) {
         return a.second > b.second;
       });

  for(int i = 0; i < finalEdges.size(); i++) {
    auto last = finalEdges.back();
    finalEdges.pop_back();

    if(isValid()) continue;
    else finalEdges.push_back(last);
  }

  int totalWeight = 0;
  for(auto edge: finalEdges)
    totalWeight += edge.second;

  return totalWeight;
}

int main() {

  int vertices, edges;
  cin >> vertices >> edges;

  for(int i = 0; i < edges; i++) {
    int start, end, weight;
    cin >> start >> end >> weight;
    allEdges.push_back({start, end, weight});
  }

  cout << reverseDelete();

  return 0;
}

//Độ phức tạp: O(ElogE) do sắp xếp các cạnh.
