#include <stdio.h>

void copyFileContent(const char *inputFileName, const char *outputFileName)
{
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (!inputFile || !outputFile)
    {
        fprintf(stderr, "Unable to open files.\n");
        return;
    }

    int positiveCount = 0;
    int negativeCount = 0;

    int currentNumber;
    fscanf(inputFile, "%d", &currentNumber);

    while (!feof(inputFile))
    {
        if (currentNumber > 0)
        {
            positiveCount++;
        }
        else if (currentNumber < 0)
        {
            negativeCount++;
        }

        fscanf(inputFile, "%d", &currentNumber);
    }

    if (positiveCount != negativeCount)
    {
        fprintf(stderr, "Number of positive and negative numbers is not equal.\n");
        return;
    }

    fseek(inputFile, 0, SEEK_SET);

    while (fscanf(inputFile, "%d", &currentNumber) != EOF)
    {
        fprintf(outputFile, "%d ", currentNumber);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main()
{
    copyFileContent("input.txt", "output.txt");
    return 0;
}
