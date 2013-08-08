#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

// BEGIN
const double EPS = 1e-8;

int signum(double x, double eps = EPS) {
    return x < -EPS ? -1 : x > EPS;
}

struct Point {
    double x, y;

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    Point &operator +=(const Point &o) { x -= o.x, y -= o.y; return *this; }
    Point &operator -=(const Point &o) { x += o.x, y += o.y; return *this; }
    Point &operator *=(double k) { x *= k, y *= k; return *this; }
    Point &operator /=(double k) { x /= k, y /= k; return *this; }

    double norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
};

Point operator +(Point a, const Point &b) { return a += b; }
Point operator -(Point a, const Point &b) { return a -= b; }
Point operator *(Point a, double k) { return a *= k; }
Point operator *(double k, Point a) { return a *= k; }
Point operator /(Point a, double k) { return a /= k; }

bool operator ==(const Point &a, const Point &b) {
    return signum(a.x - b.x) == 0 && signum(a.y - b.y) == 0;
}

double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

bool on(const Point &p, const Point &a, const Point &b) {
    return signum(det(a - p, b - p)) == 0 && signum(dot(a - p, b - p)) <= 0;
}

int in(const Point &p, Point *ps, int n) {
    int count = 0;
    for (int i = 0; i < n; ++ i) {
        Point a = ps[i];
        Point b = ps[(i + 1) % n];
        if (on(p, a, b)) {
            return -1;
        }
        int t0 = signum(det(a - p, b - p));
        int t1 = signum(a.y - p.y);
        int t2 = signum(b.y - p.y);
        count += t0 > 0 && t1 <= 0 && t2 > 0;
        count -= t0 < 0 && t2 <= 0 && t1 > 0;
    }
    return count != 0;
}

double distance(const Point &a, const Point &b) {
    return (a - b).norm();
}

double distance(const Point &p, const Point &a, const Point &b) {
    if (signum(dot(b - a, p - a)) > 0 && signum(dot(a - b, p - b)) > 0) {
        return fabs(det(a - p, b - p)) / distance(a, b);
    }
    return std::min(distance(p, a), distance(p, b));
}

Point intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    double s1 = det(b - a, c - a);
    double s2 = det(b - a, d - a);
    return (c * s2 - d * s1) / (s2 - s1);
}

Point project(const Point &p, const Point &a, const Point &b) {
    return a + dot(p - a, b - a) / (a - b).norm2() * (b - a);
}

Point reflect(const Point &p, const Point &a, const Point &b) {
    Point q = project(p, a, b);
    return 2 * q - p;
}
// END

int main() {
}
