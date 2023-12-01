#include <iostream>
#include <queue>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

bool isValid(int x, int y) {
  return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

void floodFill(int matrix[ROWS][COLS], int startX, int startY, int newColor, int oldColor) {
  if (matrix[startX][startY] != oldColor) return;

  queue<pair<int, int>> q;
  q.push({startX, startY});
  matrix[startX][startY] = newColor;

  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};

  while (!q.empty()) {
    pair<int, int> current = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = current.first + dx[i];
      int ny = current.second + dy[i];

      if (isValid(nx, ny) && matrix[nx][ny] == oldColor) {
        q.push({nx, ny});
        matrix[nx][ny] = newColor;
      }
    }
  }
}

int main() {
  int matrix[ROWS][COLS] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
                            {1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
                            {1, 2, 2, 2, 2, 0, 1, 0, 0, 1},
                            {1, 1, 1, 2, 2, 0, 1, 0, 0, 1},
                            {1, 1, 1, 2, 2, 2, 2, 0, 0, 1},
                            {1, 1, 1, 1, 1, 2, 1, 1, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

  floodFill(matrix, 1, 1, 5, 1);

  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
