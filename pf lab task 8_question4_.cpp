
#include <stdio.h>

int main()
{
    int beds[2][3][2] = {0};

    int choice, floor, patientID;
    int i, j, k;
    int found, placed;

    int occupied, vacant;
    int totalOccupied;
    int highest = -1;
    int highFloor = 0, highWard = 0;
    float percentage;

    do
    {
        printf("\n--- Hospital Ward Bed Management ---\n");
        printf("1. Admit Patient\n");
        printf("2. Discharge Patient\n");
        printf("3. Occupancy Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter floor (1-2): ");
                scanf("%d", &floor);

                printf("Enter patient ID: ");
                scanf("%d", &patientID);

                if (floor < 1 || floor > 2 || patientID <= 0)
                {
                    printf("Invalid floor or patient ID.\n");
                }
                else
                {
                    placed = 0;

                    for (j = 0; j < 3; j++)
                    {
                        for (k = 0; k < 2; k++)
                        {
                            if (beds[floor - 1][j][k] == 0
                                && placed == 0)
                            {
                                beds[floor - 1][j][k] = patientID;

                                printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n",
                                       patientID, floor, j + 1, k + 1);

                                placed = 1;
                            }
                        }
                    }

                    if (placed == 0)
                    {
                        printf("Floor %d is full.\n", floor);
                    }
                }
                break;

            case 2:
                printf("Enter patient ID to discharge: ");
                scanf("%d", &patientID);

                found = 0;

                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 3; j++)
                    {
                        for (k = 0; k < 2; k++)
                        {
                            if (beds[i][j][k] == patientID
                                && found == 0)
                            {
                                beds[i][j][k] = 0;

                                printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n",
                                       patientID, i + 1, j + 1, k + 1);

                                found = 1;
                            }
                        }
                    }
                }

                if (found == 0)
                {
                    printf("Patient ID %d not found.\n", patientID);
                }
                break;

            case 3:
                printf("\n--- Occupancy Report ---\n");

                highest = -1;
                highFloor = 0;
                highWard = 0;

                for (i = 0; i < 2; i++)
                {
                    printf("\nFloor %d\n", i + 1);
                    totalOccupied = 0;

                    for (j = 0; j < 3; j++)
                    {
                        occupied = 0;

                        for (k = 0; k < 2; k++)
                        {
                            if (beds[i][j][k] != 0)
                            {
                                occupied++;
                            }
                        }

                        vacant = 2 - occupied;
                        totalOccupied = totalOccupied + occupied;

                        printf("  Ward %d: Occupied %d, Vacant %d\n",
                               j + 1, occupied, vacant);

                        if (occupied > highest)
                        {
                            highest = occupied;
                            highFloor = i + 1;
                            highWard = j + 1;
                        }
                    }

                    percentage = (totalOccupied / 6.0) * 100;

                    printf("  Floor occupancy: %.1f%%\n", percentage);

                    if (percentage > 80.0)
                    {
                        printf("WARNING: Floor %d is more than 80%% full.\n",
                               i + 1);
                    }
                }

                printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n",
                       highFloor, highWard, highest);
                break;

            case 4:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}


