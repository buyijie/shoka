pair <Point, Point> tangent(const Circle &a, const Circle &b) {
    Point p = a.o + (b.o - a.o) / (a.r + b.r) * a.r;
    return make_pair(tangent(p, a), tangent(p, b));
}
