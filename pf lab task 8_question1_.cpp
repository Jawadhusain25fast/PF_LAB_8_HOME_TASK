#include <stdio.h>
int main() {
    int seats[5][6] = {0};
    int row, col;
    int i, j;
    int booked = 0, empty = 0;
    int count, max = 0, maxRow = 1;
    while (1) {
        scanf("%d", &row);
        if (row == -1) {
            break;
        }
        scanf("%d", &col);
        if (row < 1 || row > 5 || col < 1 || col > 6) {
            printf("Error: Invalid row or column!\n");
        }
        else if (seats[row - 1][col - 1] == 1) {
            printf("Error: Seat already booked!\n");
        }
        else {
            seats[row - 1][col - 1] = 1;
            printf("Seat booked successfully.\n");
        }
    }
    printf("\nSeating Chart:\n");
    printf("     1 2 3 4 5 6\n");
    for (i = 0; i < 5; i++) {
        printf("Row %d ", i + 1);
        for (j = 0; j < 6; j++) {
            if (seats[i][j] == 1) {
                printf("X ");
                booked++;
            }
            else {
                printf("O ");
                empty++;
            }
        }

        printf("\n");
    }

    // Find row with most bookings
    for (i = 0; i < 5; i++) {
        count = 0;

        for (j = 0; j < 6; j++) {
            if (seats[i][j] == 1) {
                count++;
            }
        }

        if (count > max) {
            max = count;
            maxRow = i + 1;
        }
    }
    printf("\nTotal booked seats: %d\n", booked);
    printf("Total empty seats: %d\n", empty);
    printf("Row with most bookings: Row %d\n", maxRow);
    return 0;
}


