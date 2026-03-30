#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    long double x, y;
};

struct Triangle {
    Point A, B, C;

    bool containsHeron(Point &P);

    bool containsVector(Point &P);

    bool isDegenerate();

    long double heronArea();

    double area () const;
};

long double distance(const Point &p1, const Point &p2);
void RunProgram();

#endif