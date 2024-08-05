#include <stdio.h>

int main() {
    int n, m, i, j, k;
    n = 5; // Number of processes
    m = 3; // Number of resources

    // Allocation Matrix
    int alloc[5][3] = {
        { 0, 1, 0 },   // P0
        { 2, 0, 0 },   // P1
        { 3, 0, 2 },   // P2
        { 2, 1, 1 },   // P3
        { 0, 0, 2 }    // P4
    };

    // MAX Matrix
    int max[5][3] = {
        { 7, 5, 3 },   // P0
        { 3, 2, 2 },   // P1
        { 9, 0, 2 },   // P2
        { 2, 2, 2 },   // P3
        { 4, 3, 3 }    // P4
    };

    // Available Resources
    int avail[3] = { 3, 3, 2 }; // A, B, C

    // Work arrays and flags
    int f[n], ans[n], ind = 0;

    // Initialize finish flags
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    // Calculate Need Matrix
    int need[5][3];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Find a safe sequence
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Print Safe Sequence
    printf("Following is the SAFE Sequence:\n");
    for (i = 0; i < n - 1; i++) {
        printf(" P%d ->", ans[i]);
    }
    printf(" P%d\n", ans[n - 1]);

    // Example request checks
    // Request from process P1 for (1, 1, 0)
    int reqP1[3] = { 1, 1, 0 };
    printf("\nChecking request from P1 for (1, 1, 0):\n");
    for (j = 0; j < m; j++) {
        if (reqP1[j] > avail[j]) {
            printf("Request cannot be granted immediately.\n");
            break;
        }
    }
    if (j == m) {
        // Grant the request and update allocation and available resources
        for (j = 0; j < m; j++) {
            avail[j] -= reqP1[j];
            alloc[1][j] += reqP1[j];
            need[1][j] -= reqP1[j];
        }
        printf("Request granted. Updated state:\n");
        printf("Available: %d %d %d\n", avail[0], avail[1], avail[2]);
    }

    // Request from process P4 for (0, 0, 2)
    int reqP4[3] = { 0, 0, 2 };
    printf("\nChecking request from P4 for (0, 0, 2):\n");
    for (j = 0; j < m; j++) {
        if (reqP4[j] > avail[j]) {
            printf("Request cannot be granted immediately.\n");
            break;
        }
    }
    if (j == m) {
        // Grant the request and update allocation and available resources
        for (j = 0; j < m; j++) {
            avail[j] -= reqP4[j];
            alloc[4][j] += reqP4[j];
            need[4][j] -= reqP4[j];
        }
        printf("Request granted. Updated state:\n");
        printf("Available: %d %d %d\n", avail[0], avail[1], avail[2]);
    }

    return 0;
}
