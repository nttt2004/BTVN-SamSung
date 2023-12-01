#include <iostream>
#include <queue>
using namespace std;

const int M = 10;
const int N = 10;

bool inside(int x, int y) {
  return x >= 0 && x < M && y >= 0 && y < N;  
}

void floodFill(int image[M][N], int x, int y, int newColor, int oldColor) {
  if (image[x][y] != oldColor) return;

  queue<pair<int, int>> q; 
  q.push({x, y});
  image[x][y] = newColor;

  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];

      if (inside(nx, ny) && image[nx][ny] == oldColor) {
        q.push({nx, ny});
        image[nx][ny] = newColor;  
      }
    }
  }
}

int main() {

  int image[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                     {1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
                     {1, 2, 2, 2, 2, 0, 1, 0, 0, 1},
                     {1, 1, 1, 2, 2, 0, 1, 0, 0, 1},
                     {1, 1, 1, 2, 2, 2, 2, 0, 0, 1},
                     {1, 1, 1, 1, 1, 2, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
  
  floodFill(image, 1, 1, 5, 1);

  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      cout << image[i][j] << " ";
    }
    cout << endl;
  }
}
