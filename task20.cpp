#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    const std::string fileName = "vector.txt";
    std::ifstream inputFile(fileName);

    std::vector<double> vector;
    double temp;

    while (inputFile >> temp)
    {
        vector.push_back(temp);
    }

    if (vector.size() % 2 == 0)
    {
        std::cout << "Enter three real numbers to add to the vector:\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cin >> temp;
            vector.push_back(temp);
        }
    }

    std::cout << "Initial vector:\n";
    for (const auto &element : vector)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";

    if (vector.size() >= 5)
    {
        auto middle = vector.begin() + vector.size() / 2 - 1;
        vector.erase(middle, middle + 3);
    }

    std::cout << "Vector after removing middle elements:\n";
    for (const auto &element : vector)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";

    inputFile.close();

    return 0;
}
