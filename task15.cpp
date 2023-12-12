#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

double calculateGeometricMean(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cerr << "Unable to open file." << std::endl;
        return 0.0;
    }

    double product = 1.0;
    double count = 0.0;
    double number;

    while (file >> number)
    {
        product *= number;
        count += 1.0;
    }

    file.close();

    if (count == 0.0)
    {
        std::cerr << "No numbers found in the file." << std::endl;
        return 0.0;
    }

    double geometricMean = std::pow(product, 1.0 / count);

    return geometricMean;
}

int main()
{
    double result = calculateGeometricMean("input.txt");

    std::cout << "Geometric Mean: " << result << std::endl;

    return 0;
}
