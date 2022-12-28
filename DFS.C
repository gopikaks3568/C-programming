#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct {
  // Adjacency list representation of the graph
  int edges[MAX_VERTICES][MAX_VERTICES];
  int numVertices;
} Graph;

// Array to track which vertices have been visited
bool visited[MAX_VERTICES];

void dfs(Graph* g, int start) {
  // Create a stack to hold the vertices that have not yet been visited
  int stack[MAX_VERTICES];
  int top = 0;
  
  // Push the starting vertex onto the stack
  stack[top++] = start;

  // While the stack is not empty
  while (top > 0) {
    // Pop the top vertex from the stack
    int vertex = stack[--top];

    // If the vertex has not been visited, mark it as visited and perform some action on it
    if (!visited[vertex]) {
      visited[vertex] = true;
      printf("Visiting vertex %d\n", vertex);
    }

    // Push all of the vertex's unvisited neighbors onto the stack
    for (int i = 0; i < g->numVertices; i++) {
      if (g->edges[vertex][i] && !visited[i]) {
        stack[top++] = i;
      }
    }
  }
}

int main(void) {
  // Create a graph with 5 vertices
  Graph g = {
    .numVertices = 5
  };

  // Add edges to the graph
  g.edges[0][1] = 1;
  g.edges[0][2] = 1;
  g.edges[1][3] = 1;
  g.edges[2][4] = 1;

  // Perform a depth-first search starting at vertex 0
  dfs(&g, 0);

  return 0;
}
