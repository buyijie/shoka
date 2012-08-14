pair <Point, Point> tangent(const Circle &a, const Circle &b) {
    if (signum(a.r - b.r) == 0) {
        Point r = (b.o - a.o).normalize().rotate() * 0.5 * (a.r + b.r);
        return make_pair(a.o + r, b.o + r);
    }
    if (signum(a.r - b.r) > 0) {
        return tangent(b, a);
    }
    Point p = tangent(a.o, Circle(b.o, b.r - a.r));
    Point r = (p - b.o).normalize() * a.r;
    return make_pair(a.o + r, b.o + r);
}
