#include <iostream>
using namespace std;

int countDAGs(int V) {
  if (V == 1) return 1;

  int count = 0;
  for(int i = 0; i < V; i++) 
    count += countDAGs(V-1-i) * countDAGs(i);
  
  return count;  
}

int main() {
  int V;
  cin >> V;
  
  cout << "So do thi co huong phi chu trinh la: " << countDAGs(V);

  return 0;
}
