#include "triangle.h"

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

bool Triangle::contains(const Point &P) const {
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
    cout << "Enter the coordinates of the points" << endl;
    cout << "Enter A (x y): "; cin >> x >> y; Point pA = {x, y};
    cout << "Enter B (x y): "; cin >> x >> y; Point pB = {x, y};
    cout << "Enter C (x y): "; cin >> x >> y; Point pC = {x, y};

    Triangle t = {pA, pB, pC};

    if (t.isDegenerate()) {
        cout << "Error: the triangle is degenerate!!!" << endl;
        return;
    }

    int count;
    cout << "\nHow many points do you wish to check? ";
    cin >> count;

    for (int i = 1; i <= count; ++i) {
        cout << "Point " << i << " (x y): ";
        cin >> x >> y;
        Point p = {x, y};

        if (t.contains(p)) {
            cout << "The point is inside the triangle or on its rim" << endl;
        } else {
            cout << "The point does not belong to the triangle" << endl;
        }
    }
}