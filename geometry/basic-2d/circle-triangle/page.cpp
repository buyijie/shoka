double intersect(Cirlce c, Point a, Point b) {
    a -= c.o, b -= c.o, c.o = Point();
    if (c.contains(b)) { swap(a, b); }
    if (c.contains(a) && c.contains(b)) { 
        return 0.5 * abs(det(a, b)); 
    }
    if (c.contains(a)) {
        Point p = intersect(c, b, a);
        return 0.5 * (abs(det(a, p)) + abs(sqr(c.r) * angle(p, b)));
    }
    if (c.o.to(a, b) >= c.r - EPSILON) {
        return 0.5 * abs(sqr(c.r) * angle(a, b));
    }
    Point p = intersect(c, a, b);
    Point q = intersect(c, b, a);
    return 0.5 * (abs(det(a, p)) 
                + abs(sqr(c.r) * angle(p, q)) 
                + abs(det(q, b)));
}
