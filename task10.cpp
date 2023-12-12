#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

void processFile(const std::string &inputFileName, const std::string &outputFileName)
{
    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open())
    {
        std::cerr << "Unable to open input file." << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContent = buffer.str();

    std::replace(fileContent.begin(), fileContent.end(), ',', ' ');
    fileContent.erase(std::remove_if(fileContent.begin(), fileContent.end(), ::isspace), fileContent.end());

    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open())
    {
        std::cerr << "Unable to open output file." << std::endl;
        return;
    }

    outputFile << fileContent;

    inputFile.close();
    outputFile.close();

    std::cout << "File processing completed successfully." << std::endl;
}

int main()
{
    processFile("input.txt", "output.txt");
    return 0;
}
