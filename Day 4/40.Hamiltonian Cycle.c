#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph
int i,v;
void printSolution(int path[]);
bool isSafe(int v, bool graph[V][V], int path[], int pos);
bool hamiltonianUtil(bool graph[V][V], int path[], int pos);

void findHamiltonianCircuit(bool graph[V][V]) {
    int path[V];
    for (i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0;

    if (!hamiltonianUtil(graph, path, 1)) {
        printf("No Hamiltonian circuit found.\n");
        return;
    }

    printf("Hamiltonian circuit:\n");
    printSolution(path);
}

bool hamiltonianUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        // Check if the last vertex is connected to the starting vertex
        if (graph[path[pos - 1]][path[0]]) {
            return true;
        }
        return false;
    }

    for ( v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1)) {
                return true;
            }

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (path[pos - 1] == v) {
        return false;
    }

    if (!graph[path[pos - 1]][v]) {
        return false;
    }

    for (i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

void printSolution(int path[]) {
    for (i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

int main() {
    bool graph[V][V] = {
        {0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };

    findHamiltonianCircuit(graph);

    return 0;
}

