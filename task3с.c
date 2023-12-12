#include <stdio.h>
#include <math.h>

int main()
{
    FILE *fileF = fopen("F.txt", "w");
    if (fileF == NULL)
    {
        perror("Error opening file F.txt for writing");
        return 1;
    }

    printf("Enter integers into file F (enter 0 to stop):\n");
    int number;
    do
    {
        scanf("%d", &number);
        fprintf(fileF, "%d ", number);
    } while (number != 0);

    fclose(fileF);

    fileF = fopen("F.txt", "r");
    if (fileF == NULL)
    {
        perror("Error opening file F.txt for reading");
        return 1;
    }

    FILE *fileG = fopen("G.txt", "w");
    if (fileG == NULL)
    {
        perror("Error opening file G.txt for writing");
        return 1;
    }

    printf("Numbers that are perfect squares (file G):\n");

    while (fscanf(fileF, "%d", &number) != EOF)
    {
        double sqrtNumber = sqrt(number);
        if (ceil(sqrtNumber) == sqrtNumber)
        {
            printf("%d ", number);
            fprintf(fileG, "%d ", number);
        }
    }

    printf("\n");

    fclose(fileF);
    fclose(fileG);

    return 0;
}
