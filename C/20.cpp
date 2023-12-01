#include <GL/glut.h>
#include <algorithm>

using namespace std;

double w[MAX_N][MAX_N]; // Adjacency matrix 
double x[MAX_N], y[MAX_N]; // Vertex coordinates

bool visited[MAX_N];
vector<pair<double, pair<int, int>>> edges; 
vector<pair<int, int>> spanningTree;

// Draw graph
void drawGraph() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0, 0.0, 0.0);  
  glPointSize(5);

  // Draw edges
  for (auto e : edges) {
    int u = e.second.first;
    int v = e.second.second;

    glBegin(GL_LINES);
    glVertex2d(x[u], y[u]);
    glVertex2d(x[v], y[v]);
    glEnd();
  }

  // Draw vertices
  for (int u = 0; u < V; u++) {
    glBegin(GL_POINTS);
    glVertex2d(x[u], y[u]);
    glEnd();
  }

  glFlush(); 
}

// Kruskal's algorithm
void kruskal() {  
  sort(edges.begin(), edges.end());

  for (auto e : edges) {
    // Draw new added edge 
    drawGraph();

    int u = e.second.first;
    int v = e.second.second;
    
    if (!visited[u] || !visited[v]) {
      spanningTree.push_back({u, v});

      visited[u] = visited[v] = true;
    }

    glutPostRedisplay();
    glutSwapBuffers(); 
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  // Initialize OpenGL
  Init();

  kruskal(); // Run algorithm  
  
  glutMainLoop();

  return 0;
}
