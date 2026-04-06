#include <stdio.h>
#include "converter.h"

int main(void)
{
    printf("100 km = %.2f miles\n", km_to_miles(100));
    printf("37 C = %.2f F\n", celsius_to_fahrenheit(37));
    printf("70 kg = %.2f pounds\n", kg_to_pounds(70));

    return 0;
}