#include <iostream>
using namespace std;

int counts(int V) {
  if (V == 1) return 1;
  int count = 0;
  for(int i = 0; i < V; i++)
    count += counts(V-1-i) * counts(i);

  return count;
}

int main() {
  int V;
  cin >> V;
  cout << "So do thi co huong phi chu trinh la: " << counts(V);
  return 0;
}
