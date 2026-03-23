#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    bool containsHeron(Point &P);

    bool containsVector(Point &P);

    bool isDegenerate();

    double heronArea();
};

double distance(const Point &p1, const Point &p2);
void RunProgram();

#endif