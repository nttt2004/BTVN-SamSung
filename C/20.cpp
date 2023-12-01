#include <GL/glut.h>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

double weight[MAX_N][MAX_N];
double xCoord[MAX_N], yCoord[MAX_N];

bool nodeVisited[MAX_N];
vector<pair<double, pair<int, int>>> allEdges;
vector<pair<int, int>> minimumSpanningTree;

void drawGraph() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 0.0, 0.0);
  glPointSize(5);

  for (auto edge : allEdges) {
    int start = edge.second.first;
    int end = edge.second.second;

    glBegin(GL_LINES);
    glVertex2d(xCoord[start], yCoord[start]);
    glVertex2d(xCoord[end], yCoord[end]);
    glEnd();
  }

  for (int vertex = 0; vertex < V; vertex++) {
    glBegin(GL_POINTS);
    glVertex2d(xCoord[vertex], yCoord[vertex]);
    glEnd();
  }

  glFlush();
}

void runKruskal() {
  sort(allEdges.begin(), allEdges.end());

  for (auto edge : allEdges) {
    drawGraph();

    int start = edge.second.first;
    int end = edge.second.second;

    if (!nodeVisited[start] || !nodeVisited[end]) {
      minimumSpanningTree.push_back({start, end});

      nodeVisited[start] = nodeVisited[end] = true;
    }

    glutPostRedisplay();
    glutSwapBuffers();
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  Init();

  runKruskal();

  glutMainLoop();

  return 0;
}
