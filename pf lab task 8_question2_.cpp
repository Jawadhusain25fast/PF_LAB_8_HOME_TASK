#include <stdio.h>
int main() {
    int marks[4][3];
    int total[4];
    float average[4];
    char grade[4];
    int highest, lowest, sum;
    float subAvg[3];
    int i, j;
    int top = 0, worst = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &marks[i][j]);
            while (marks[i][j] < 0 || marks[i][j] > 100) {
                printf("Invalid mark! Enter a value between 0 and 100.\n");
                scanf("%d", &marks[i][j]);
            }
        }
    }

    // Student results
    printf("\nStudent     Prog  Calc  Phys  Total  Average  Grade\n");

    for (i = 0; i < 4; i++) {
        total[i] = 0;

        for (j = 0; j < 3; j++) {
            total[i] = total[i] + marks[i][j];
        }

        average[i] = total[i] / 3.0;

        if (average[i] >= 80)
            grade[i] = 'A';
        else if (average[i] >= 65)
            grade[i] = 'B';
        else if (average[i] >= 50)
            grade[i] = 'C';
        else
            grade[i] = 'F';

        printf("Student %d", i + 1);

        for (j = 0; j < 3; j++) {
            printf("%7d", marks[i][j]);
        }

        printf("%7d  %7.2f  %c\n",
               total[i], average[i], grade[i]);
    }

    // Find top student
    for (i = 1; i < 4; i++) {
        if (average[i] > average[top]) {
            top = i;
        }
    }

    // Subject statistics
    printf("\nSubject statistics:\n");
    printf("Subject       Highest  Lowest  Average\n");

    for (j = 0; j < 3; j++) {
        highest = marks[0][j];
        lowest = marks[0][j];
        sum = 0;

        for (i = 0; i < 4; i++) {
            sum = sum + marks[i][j];

            if (marks[i][j] > highest)
                highest = marks[i][j];

            if (marks[i][j] < lowest)
                lowest = marks[i][j];
        }

        subAvg[j] = sum / 4.0;

        if (j == 0)
            printf("Programming");
        else if (j == 1)
            printf("Calculus");
        else
            printf("Physics");

        printf("%10d%8d%9.2f\n",
               highest, lowest, subAvg[j]);
    }

    // Find worst subject
    for (j = 1; j < 3; j++) {
        if (subAvg[j] < subAvg[worst]) {
            worst = j;
        }
    }

    printf("\nTop student: Student %d (Average %.2f)\n",
           top + 1, average[top]);

    if (worst == 0)
        printf("Worst subject: Programming (Average %.2f)\n",
               subAvg[worst]);
    else if (worst == 1)
        printf("Worst subject: Calculus (Average %.2f)\n",
               subAvg[worst]);
    else
        printf("Worst subject: Physics (Average %.2f)\n",
               subAvg[worst]);

    return 0;
}

