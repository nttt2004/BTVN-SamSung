#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

int countParallelEdges(const vector<pair<int, int>>& edges) {
    unordered_map<pair<int, int>, int> edgeCount;

    for (const auto& edge : edges) {
        edgeCount[edge]++;
    }

    int parallelEdges = 0;
    for (const auto& entry : edgeCount) {
        if (entry.second > 1) {
            parallelEdges += entry.second - 1;
        }
    }

    return parallelEdges;
}

int main() {
    int n;
    cin >> n;

    if (n < 0) {
        return 1;
    }

    vector<pair<int, int>> edges;

    int u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    int parallelEdges = countParallelEdges(edges);

    cout << "Number of parallel edges: " << parallelEdges << endl;

    return 0;
}
