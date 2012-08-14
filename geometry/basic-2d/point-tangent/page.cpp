Point tangent(const Point &p, const Circle &c) {
    Circle a(p, c.o);
    return intersect(a, c);
}
