#include "triangle.h"
#include <iostream>

using namespace std;

long double distance(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}


double Triangle::area() const {
    return fabs(
        (B.x - A.x) * (C.y - A.y) -
        (B.y - A.y) * (C.x - A.x)
    ) / 2.0;
}

long double Triangle::heronArea() {
    long double a = distance(A, B);
    long double b = distance(B, C);
    long double c = distance(C, A);
    long double s = (a + b + c) / 2.0;
    long double val = s * (s - a) * (s - b) * (s - c);
    return sqrt(val);
}

bool Triangle::isDegenerate(){
    return this->area() < 1e-8;
}

bool Triangle::containsHeron(Point &P){
    Triangle T1 = {A, B, P};
    Triangle T2 = {B, C, P};
    Triangle T3 = {C, A, P};

    long double S_main = this->heronArea();
    long double S_sum = T1.heronArea() + T2.heronArea() + T3.heronArea();

    return fabs(S_main - S_sum) < 1e-17;
}

double cross_product (Point p1, Point p2, Point p) {
    return (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x);
}

bool Triangle::containsVector(Point &P){

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