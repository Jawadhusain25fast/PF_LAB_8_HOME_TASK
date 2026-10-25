
#include <stdio.h>

int main() {
    int stock[3][4];
    int i, j;
    int total, max = 0, maxAisle = 1;
    int empty = 0;
    int grandTotal = 0;

    // Input stock values
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &stock[i][j]);
        }
    }

    // Print original stock
    printf("Original stock:\n");

    for (i = 0; i < 3; i++) {
        printf("Aisle %d: ", i + 1);

        for (j = 0; j < 4; j++) {
            printf("%4d", stock[i][j]);
        }

        printf("\n");
    }

    // Find aisle with most stock
    for (i = 0; i < 3; i++) {
        total = 0;

        for (j = 0; j < 4; j++) {
            total = total + stock[i][j];
        }

        if (total > max) {
            max = total;
            maxAisle = i + 1;
        }
    }

    printf("\nAisle with most stock: Aisle %d (%d units)\n",
           maxAisle, max);

    // Low stock alerts
    printf("\nLow stock alerts:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (stock[i][j] < 5) {
                printf("Aisle %d, Position %d -> %d units\n",
                       i + 1, j + 1, stock[i][j]);
            }

            if (stock[i][j] == 0) {
                empty++;
            }
        }
    }

    printf("\nEmpty shelves: %d\n", empty);

    // Restock shelves with fewer than 5 units
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            if (stock[i][j] < 5) {
                stock[i][j] = stock[i][j] + 10;
            }
        }
    }

    // Print stock after restocking
    printf("\nStock after restocking:\n");

    for (i = 0; i < 3; i++) {
        printf("Aisle %d: ", i + 1);

        for (j = 0; j < 4; j++) {
            printf("%4d", stock[i][j]);
            grandTotal = grandTotal + stock[i][j];
        }

        printf("\n");
    }

    printf("\nNew grand total: %d units\n", grandTotal);

    return 0;
}

