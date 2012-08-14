Point intersect(const Circle &a, const Circle &b) {
    Point r = (b. o - a.o).normalize();
    double d = (b.o - a.o).norm();
    double x = 0.5 * ((sqr(a.r) - sqr(b.r)) / d + d);
    double h = sqrt(sqr(a.r) - sqr(x));
    return a.o + r * x + r.rotate() * h;
}
