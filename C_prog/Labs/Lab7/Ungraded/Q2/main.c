#include <stdio.h>
#include "geometry.h"

int main(void)
{
    printf("Circle area (r=5) : %.2f\n", circle_area(5));
    printf("Rectangle area (4 x 6) : %.2f\n", rectangle_area(4, 6));

    return 0;
}