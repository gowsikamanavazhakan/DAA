#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of workers and tasks

// Function to find the minimum element in a matrix
int findMin(int costMatrix[N][N], bool rowVisited[N], bool colVisited[N]) {
    int minVal = INT_MAX,i,j;
    
    for (i = 0; i < N; i++) {
        if (!rowVisited[i]) {
            for (j = 0; j < N; j++) {
                if (!colVisited[j] && costMatrix[i][j] < minVal) {
                    minVal = costMatrix[i][j];
                }
            }
        }
    }
    
    return minVal;
}

// Branch and Bound function
void branchAndBound(int costMatrix[N][N], int assignment[N], bool rowVisited[N], bool colVisited[N], int currentCost, int *bestCost) {
	int i,j;
    if (currentCost >= *bestCost) {
        return;
    }
    
    int unassignedWorker = -1;
    
    for (i = 0; i < N; i++) {
        if (!rowVisited[i]) {
            unassignedWorker = i;
            break;
        }
    }
    
    if (unassignedWorker == -1) {
        if (currentCost < *bestCost) {
            *bestCost = currentCost;
            printf("Current best cost: %d\n", *bestCost);
        }
        return;
    }
    
    rowVisited[unassignedWorker] = true;
    
    for ( j = 0; j < N; j++) {
        if (!colVisited[j]) {
            colVisited[j] = true;
            assignment[unassignedWorker] = j;
            
            int reducedCost = currentCost + costMatrix[unassignedWorker][j] - findMin(costMatrix, rowVisited, colVisited);
            
            branchAndBound(costMatrix, assignment, rowVisited, colVisited, reducedCost, bestCost);
            
            assignment[unassignedWorker] = -1;
            colVisited[j] = false;
        }
    }
    
    rowVisited[unassignedWorker] = false;
}

int main() {
    int i,costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    
    int assignment[N];
    bool rowVisited[N] = {false};
    bool colVisited[N] = {false};
    int currentCost = 0;
    int bestCost = INT_MAX;
    for (i = 0; i < N; i++) {
        assignment[i] = -1;
    }
    
    branchAndBound(costMatrix, assignment, rowVisited, colVisited, currentCost, &bestCost);
    
    printf("Optimal assignment: ");
    for (i = 0; i < N; i++) {
        printf("(%d, %d) ", i, assignment[i]);
    }
    printf("\nOptimal cost: %d\n", bestCost);
    
    return 0;
}

