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

    // Method 1: Heron's Area Method (from your example)
    double area() const;
    bool containsHeron(const Point &P) const;

    // Method 2: Vector Cross Product Method
    bool containsVector(const Point &P) const;

    // General check for degenerate triangle
    bool isDegenerate() const;
};

double distance(const Point &p1, const Point &p2);
double heronArea(const Triangle &t);
void RunProgram();

#endif