#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector2
{
    double x, y;
} Vector2;

int main(const int argc, char **argv)
{
    uint64_t resolution = 0;
    if (argc > 1)
    {
        resolution = atol(argv[1]);
    }
    else
    {
        printf("Enter the resolution you want to calculate at: ");
        if (scanf("%lu", &resolution) != 1)
        {
            printf("Error reading resolution\n");
            return EXIT_FAILURE;
        }
    }

    printf("Calculating pi at a resolution of %lu...\n", resolution);
    double pi = 0;
    Vector2 pos = {-1, 0};
    Vector2 nPos = pos;

    for (uint64_t i = 0; i < resolution; i++)
    {
        nPos.x += 2.0 / resolution;
        nPos.y = sqrt(1 - nPos.x * nPos.x);
        if (fabs(nPos.x) >= 1)
        {
            nPos.x = 1;
            nPos.y = 0;
        }

        const Vector2 diff = {pos.x - nPos.x, pos.y - nPos.y};
        const double distance = sqrt(diff.x * diff.x + diff.y * diff.y);
        #ifdef IS_DEBUG
        printf("[%f, %f], Adding %f - total: %f\n", nPos.x, nPos.y, distance, pi);
        #endif
        pi += distance;

        pos = nPos;
    }

    printf("Pi was calculated to be approximately...\n%.13f\n", pi);
    return EXIT_SUCCESS;
}