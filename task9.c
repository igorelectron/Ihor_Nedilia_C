#include <stdio.h>

struct MaterialData
{
    double mass;
    double volume;
};

int findMaxDensityMaterial(const struct MaterialData *materials, int N)
{
    if (N <= 0)
    {
        return -1; 
    }

    double maxDensity = materials[0].mass / materials[0].volume;
    int maxDensityIndex = 0;

    for (int i = 1; i < N; ++i)
    {
        double density = materials[i].mass / materials[i].volume;
        if (density > maxDensity)
        {
            maxDensity = density;
            maxDensityIndex = i;
        }
    }

    return maxDensityIndex;
}

int main()
{
    int N;
    printf("Enter the number of items: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Invalid number of items.\n");
        return 1;
    }

    struct MaterialData *materials = malloc(N * sizeof(struct MaterialData));

    if (materials == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; ++i)
    {
        printf("Enter mass and volume for item %d: ", i + 1);
        scanf("%lf %lf", &materials[i].mass, &materials[i].volume);
    }

    int maxDensityIndex = findMaxDensityMaterial(materials, N);

    if (maxDensityIndex != -1)
    {
        printf("Item with the highest material density:\n");
        printf("Mass: %.2lf\n", materials[maxDensityIndex].mass);
        printf("Volume: %.2lf\n", materials[maxDensityIndex].volume);
        printf("Density: %.2lf\n", materials[maxDensityIndex].mass / materials[maxDensityIndex].volume);
    }
    else
    {
        printf("No items to analyze.\n");
    }

    free(materials);

    return 0;
}
