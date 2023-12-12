#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>


void generateRandomNumbers(std::vector<int> &arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr.push_back(rand() % 100); 
    }
}


void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        auto maxElementIter = std::max_element(arr.begin() + i, arr.end());
        std::iter_swap(maxElementIter, arr.begin() + n - 1 - i);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    const int size = 10;
    std::vector<int> numbers;

    generateRandomNumbers(numbers, size);

    std::cout << "Original array: ";
    printArray(numbers);

    selectionSort(numbers);

    std::cout << "Sorted array: ";
    printArray(numbers);

    return 0;
}
