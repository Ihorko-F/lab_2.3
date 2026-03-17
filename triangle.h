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

    double area() const;
    bool containsHeron(const Point &P) const;

    bool containsVector(const Point &P) const;

    bool isDegenerate() const;
};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);
void RunProgram();

#endif