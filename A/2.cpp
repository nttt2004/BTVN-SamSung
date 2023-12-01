#include <iostream>
using namespace std;

int countGraphs(int V, int E) {
  if(E > V*(V-1)/2 || E < 0)
    return 0;

  int count = 1;

  for(int i = 0; i < E; i++)
    count = count * (V*(V-1)/2 - i)/(E-i);

  return count;
}

int main() {
  int V, E;
  cout << "Nhap so dinh V: ";
  cin >> V;
  cout << "Nhap so canh E: ";
  cin >> E;

  cout << "So do thi vo huong khac nhau la: " << countGraphs(V, E);

  return 0;
}
