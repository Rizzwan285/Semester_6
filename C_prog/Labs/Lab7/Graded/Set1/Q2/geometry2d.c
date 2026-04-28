#include <math.h>
#include "geometry2d.h"

double calculate_perimeter(const Point *vertices, int num_vertices)
{
    double p = 0;

    for (int i = 0; i < num_vertices; i++)
    {
        int next = (i + 1) % num_vertices;

        double dx = vertices[i].x - vertices[next].x;
        double dy = vertices[i].y - vertices[next].y;

        p += sqrt(dx * dx + dy * dy);
    }

    return p;
}