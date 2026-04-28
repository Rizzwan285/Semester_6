#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "geometry2d.h"

int main() {
    int num_vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &num_vertices);
    Point* vertices = malloc(sizeof(Point)*num_vertices);
    for (int i=0; i<num_vertices; i++) {
        printf("Enter vertex %d (x y): ", i+1);
        scanf("%lf %lf", &vertices[i].x,&vertices[i].y);
    }
    double per = calculate_perimeter(vertices, num_vertices);
    printf("Polygon Perimeter: %f\n", per);
    free(vertices);
    return 0;
}    