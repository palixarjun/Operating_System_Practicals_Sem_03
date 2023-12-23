#include <stdio.h>

// Number of processes
#define P 5
// Number of resources
#define R 5

// Function to check if the requested resources can be granted
int isSafe(int available[R], int max[P][R], int alloc[P][R], int need[P][R], int process)
{
    for (int i = 0; i < R; i++) {
        if (need[process][i] > available[i])
            return 0;
    }
    return 1;
}

// Banker's algorithm function
void bankersAlgorithm(int available[R], int max[P][R], int alloc[P][R])
{
    int need[P][R];

    // Calculate the need matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Array to track whether a process is finished
    int finish[P];
    for (int i = 0; i < P; i++) {
        finish[i] = 0;
    }

    // Array to store the safe sequence
    int safeSequence[P];
    int safeCount = 0;

    // Check for each process
    for (int count = 0; count < P; count++) {
        for (int i = 0; i < P; i++) {
            // If the process is not finished
            if (!finish[i]) {
                // Check if the resources can be granted
                if (isSafe(available, max, alloc, need, i)) {
                    // Grant the resources to the process
                    for (int j = 0; j < R; j++) {
                        available[j] += alloc[i][j];
                    }
                    // Mark the process as finished
                    finish[i] = 1;
                    // Add the process to the safe sequence
                    safeSequence[safeCount++] = i;
                }
            }
        }
    }

    // Check if all processes are finished
    for (int i = 0; i < P; i++) {
        if (!finish[i]) {
            printf("Unsafe state: System has deadlocked\n");
            return;
        }
    }

    // Print the safe sequence
    printf("Safe state: System is safe\nSafe sequence: ");
    for (int i = 0; i < P; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
}

// Driver program
int main()
{
    // Available resources
    int available[R] = {1, 1, 0, 0};

    // Maximum resources that can be allocated to processes
    int max[P][R] = {{0, 6, 5, 6},
                     {0, 6, 5, 2},
                     {0, 0, 1, 2},
                     {1, 7, 5, 0},
{2, 3, 5, 6}};

    // Resources currently allocated to processes
    int alloc[P][R] = {{0, 5, 3, 4},
                       {0, 6, 3, 2},
                       {0, 0, 1, 2},
                       {1, 0, 0, 0}, {1, 3, 5, 4}};

    bankersAlgorithm(available, max, alloc);

    return 0;
}
