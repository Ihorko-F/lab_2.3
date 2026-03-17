#include "triangle.h"
#include <iostream>

using namespace std;

double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle &t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2.0;
    double val = s * (s - a) * (s - b) * (s - c);
    return sqrt(val < 0 ? 0 : val);
}

double Triangle::area() const {
    return heronArea(*this);
}

bool Triangle::isDegenerate() const {
    return area() < 1e-9;
}

bool Triangle::containsHeron(const Point &P) const {
    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    return fabs(S_main - S_sum) < 1e-9;
}

bool Triangle::containsVector(const Point &P) const {
    auto cross_product = [](Point p1, Point p2, Point p) {
        return (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x);
    };

    double cp1 = cross_product(A, B, P);
    double cp2 = cross_product(B, C, P);
    double cp3 = cross_product(C, A, P);

    bool has_neg = (cp1 < 0) || (cp2 < 0) || (cp3 < 0);
    bool has_pos = (cp1 > 0) || (cp2 > 0) || (cp3 > 0);

    return !(has_neg && has_pos);
}

void RunProgram() {
    double x, y;
    cout << "Please, input triangle coordinates" << endl;
    cout << "Enter A (x y): "; cin >> x >> y; Point pA = {x, y};
    cout << "Enter B (x y): "; cin >> x >> y; Point pB = {x, y};
    cout << "Enter C (x y): "; cin >> x >> y; Point pC = {x, y};

    Triangle t = {pA, pB, pC};

    if (t.isDegenerate()) {
        cout << "Error: Degenerate triangle (area is zero)!" << endl;
        return;
    }

    int count;
    cout << "\nHow many points to check? ";
    cin >> count;

    for (int i = 1; i <= count; ++i) {
        cout << "\nPoint " << i << " (x y): ";
        cin >> x >> y;
        Point p = {x, y};

        cout << "Heron's Formula Result: ";
        if (t.containsHeron(p)) cout << "Point belongs to triangle or is on its rim" << endl;
        else cout << "Point does NOT belong to triangle" << endl;

        cout << "Vector Cross Product Result: ";
        if (t.containsVector(p)) cout << "Point belongs to triangle or is on its rim" << endl;
        else cout << "Point does NOT belong to triangle" << endl;
    }
}