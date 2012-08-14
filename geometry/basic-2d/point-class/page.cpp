const double EPSILON = 1e-9;

int signum(double x) { return x < -EPSILON? -1: x > EPSILON; }

struct Point {
    double x, y;

    Point(double x = 0.0, double y = 0.0): x(x), y(y) {}

    Point &operator +=(const Point &o) { return x += o.x, y += o.y, *this; }
    Point &operator -=(const Point &o) { return x -= o.x, y -= o.y, *this; }
    Point &operator *=(double k) { return x *= k, y *= k, *this; }
    Point &operator /=(double k) { return x /= k, y /= k, *this; }

    Point rotate() const { return Point(-y, x); }

    double norm2() const;
    double norm() const;
    Point normalize() const;
};

Point operator +(Point a, const Point &b) { return a += b; }
Point operator -(Point a, const Point &b) { return a -= b; }
Point operator *(Point a, double k) { return a *= k; }
Point operator *(double k, Point a) { return a *= k; }
Point operator /(Point a, double k) { return a /= k; }

double det(const Point &a, const Point &b) { return a.x * b.y - b.x * a.y; }
double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double angle(const Point &a, const Point &b) { return atan2(det(a, b), dot(a, b)); }

double Point::norm2() const { return dot(*this, *this); }
double Point::norm() const { return sqrt(norm2()); }
Point Point::normalize() const { return *this / norm(); }
