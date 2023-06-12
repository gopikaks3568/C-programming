#include <stdio.h>

#define MAX_PROCESS 10
#define MAX_RESOURCE 10

int main() {
    int processes, resources, i, j, k;
    int allocation[MAX_PROCESS][MAX_RESOURCE];
    int max[MAX_PROCESS][MAX_RESOURCE];
    int available[MAX_RESOURCE];
    int need[MAX_PROCESS][MAX_RESOURCE];
    int finish[MAX_PROCESS] = {0};
    int safeSequence[MAX_PROCESS];
    int count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &processes);

    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    // Calculating the need matrix
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Banker's algorithm
    while (count < processes) {
        int found = 0;
        for (i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int safe = 1;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > available[j]) {
                        safe = 0;
                        break;
                    }
                }

                if (safe) {
                    for (j = 0; j < resources; j++) {
                        available[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            break;
        }
    }

    if (count == processes) {
        printf("System is in a safe state.\nSafe sequence: ");
        for (i = 0; i < processes; i++) {
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("System is in an unsafe state.\n");
    }

    return 0;
}


/*
OUTPUT

Enter the number of processes: 5
Enter the number of resources: 3
Enter the allocation matrix:
0 2 0
2 0 0 
3 0 2 
2 1 1 
0 0 2
Enter the maximum matrix:
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter the available resources:
10 5 3 
System is in a safe state.
Safe sequence: 0 1 2 3 4 


*/


