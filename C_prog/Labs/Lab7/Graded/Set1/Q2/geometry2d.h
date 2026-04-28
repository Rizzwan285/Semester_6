#ifndef GEOMETRY2D_H
#define GEOMETRY2D_H

typedef struct Point {
    double x;
    double y;
} Point;

double calculate_perimeter(const Point *vertices, int num_vertices);

#endif
