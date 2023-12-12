#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представлення інформації про іграшки
struct Toy
{
    char name[50];
    double price;
    int minAge;
    int maxAge;
};

// Функція для знаходження ціни найдорожчого товару з певною назвою
double findMaxPriceByName(struct Toy *toys, int numToys, const char *name)
{
    double maxPrice = 0;

    for (int i = 0; i < numToys; i++)
    {
        if (strcmp(toys[i].name, name) == 0 && toys[i].price > maxPrice)
        {
            maxPrice = toys[i].price;
        }
    }

    return maxPrice;
}

// Функція для виведення результатів на консоль та у бінарний файл
void outputResults(const char *filename, double maxPrice, const char *name)
{
    FILE *file = fopen(filename, "wb");

    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    printf("Ціна найдорожчого товару з назвою '%s': %.2lf грн\n", name, maxPrice);
    fprintf(file, "Ціна найдорожчого товару з назвою '%s': %.2lf грн\n", name, maxPrice);

    fclose(file);
}

int main()
{
    // Припустимо, що у вас є файл "toys.dat", в якому міститься інформація про іграшки
    struct Toy toys[] = {
        {"мʼяч", 25.99, 2, 5},
        {"лялька", 39.99, 3, 7},
        {"конструктор", 49.99, 4, 10},
        // Додайте інші іграшки за необхідності
    };

    int numToys = sizeof(toys) / sizeof(toys[0]);

    // Задаємо назву товару, для якого шукаємо найдорожчий екземпляр
    const char *searchName = "мʼяч";

    // Знаходимо ціну найдорожчого товару з певною назвою
    double maxPrice = findMaxPriceByName(toys, numToys, searchName);

    // Виводимо результати на консоль та у бінарний файл
    outputResults("output.txt", maxPrice, searchName);

    return 0;
}
