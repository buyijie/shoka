struct Circle {
    Point o;
    double r;

    Circle(const Point &o, double r): o(o), r(r) {}
    Circle(const Point &a, const Point &b): o(0.5 * (a + b)), r(0.5 * (a - b).norm()) {}
    Circle(const Point &a, const Point &c, const Point &d): o(circumcenter(a, b, c)) {
        r = (a - o).norm();
    }
};
