
#include <stdio.h>

int main()
{
    int image[4][4], result[4][4];
    int i, j, k, l;
    int amount, threshold, sum;

    printf("Enter 16 pixel values:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    scanf("%d", &amount);
    scanf("%d", &threshold);

    printf("\nOriginal image:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", image[i][j]);
        }
        printf("\n");
    }

    // Brightness
    printf("\nBrightness (+%d):\n", amount);

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            result[i][j] = image[i][j] + amount;

            if (result[i][j] > 255)
                result[i][j] = 255;
            else if (result[i][j] < 0)
                result[i][j] = 0;

            printf("%5d", result[i][j]);
        }
        printf("\n");
    }

    // Black and white
    printf("\nBlack and white (threshold %d):\n", threshold);

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (image[i][j] >= threshold)
                result[i][j] = 255;
            else
                result[i][j] = 0;

            printf("%5d", result[i][j]);
        }
        printf("\n");
    }

    // Horizontal flip
    printf("\nFlipped horizontally:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            result[i][j] = image[i][3 - j];
            printf("%5d", result[i][j]);
        }
        printf("\n");
    }

    // Smoothing
    printf("\nSmoothed image:\n");

    // Copy original image so border pixels remain unchanged
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            result[i][j] = image[i][j];
        }
    }

    // Use a second array because changed pixels must not
    // affect the calculations of the next pixels.
    for (i = 1; i < 3; i++)
    {
        for (j = 1; j < 3; j++)
        {
            sum = 0;

            for (k = i - 1; k <= i + 1; k++)
            {
                for (l = j - 1; l <= j + 1; l++)
                {
                    sum = sum + image[k][l];
                }
            }

            result[i][j] = sum / 9;
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

