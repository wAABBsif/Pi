#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef long double lDouble;

typedef struct Vector2
{
    lDouble x, y;
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
        if (scanf("%llu", &resolution) != 1)
        {
            printf("Error reading resolution\n");
            return EXIT_FAILURE;
        }
    }

    printf("Calculating pi at a resolution of %llu...\n", resolution);
    lDouble pi = 0.0L;
    Vector2 pos = {-1.0L, 0.0L};
    Vector2 nPos = pos;

    for (uint64_t i = 0; i <= resolution; i++)
    {
        nPos.x += 2.0L / resolution;
        nPos.y = sqrtl(1.0L - nPos.x * nPos.x);
        if (fabsl(nPos.x) >= 1.0L)
        {
            nPos.x = 1.0L;
            nPos.y = 0.0L;
        }

        const Vector2 diff = {pos.x - nPos.x, pos.y - nPos.y};
        const lDouble distance = sqrtl(diff.x * diff.x + diff.y * diff.y);
        #ifdef IS_DEBUG
        printf("[%f, %f], Adding %f - total: %f\n", nPos.x, nPos.y, distance, pi);
        #endif
        pi += distance;

        pos = nPos;
    }

    printf("Pi was calculated to be approximately...\n%.15Lf\n", pi);
    return EXIT_SUCCESS;
}