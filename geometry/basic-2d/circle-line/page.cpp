Point intersect(const Circle &c, const Point &a, const Point &b) {
    double x = sqrt(sqr(c.r) - sqr(c.o.to(a, b)));
    return c.o.project(a, b) + (a - b).normalize() * x;
}
