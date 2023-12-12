#include <iostream>
#include <fstream>
#include <string>

void compressFile(const std::string &inputFileName, const std::string &outputFileName)
{
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    char currentChar, lastChar = '\0';
    int charCount = 1;

    while (inputFile.get(currentChar))
    {
        if (currentChar == lastChar)
        {
            charCount++;
        }
        else
        {
            if (charCount > 1)
            {
                outputFile << lastChar << charCount;
            }
            else
            {
                outputFile << lastChar;
            }

            lastChar = currentChar;
            charCount = 1;
        }
    }

    if (charCount > 1)
    {
        outputFile << lastChar << charCount;
    }
    else
    {
        outputFile << lastChar;
    }

    inputFile.close();
    outputFile.close();
}

int main()
{
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    compressFile(inputFileName, outputFileName);

    std::cout << "File compression complete." << std::endl;

    return 0;
}
