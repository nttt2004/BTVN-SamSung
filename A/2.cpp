#include <iostream>
using namespace std;

int counts(int V, int E) {
  if(E > V*(V-1)/2 || E < 0)
    return 0;

  int count = 1;

  for(int i = 0; i < E; i++)
    count = count * (V*(V-1)/2 - i)/(E-i);

  return count;
}

int main() {
  int V, E;
  cin >> V >> E;
  cout << "So do thi vo huong khac nhau la: " << counts(V, E);
  return 0;
}
