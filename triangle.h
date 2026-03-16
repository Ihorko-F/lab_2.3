#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    double x, y;
};

double distance(const Point &p1, const Point &p2);

struct Triangle {
    Point A, B, C;

    double area() const;
    
    // Перевірка на виродженість
    bool isDegenerate() const;

    // Потужний векторний добуток
    bool contains(const Point &P) const;
};

double heronArea(const Triangle &t);
void RunProgram();

#endif