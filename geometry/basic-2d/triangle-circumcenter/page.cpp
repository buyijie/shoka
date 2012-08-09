Point circumcenter(Point a, Point b, Point c) {
    b -= a, c -= a;
    double d = 2.0 * det(b, c);
    Point p = Point(b.norm2(), c.norm2());
    return a + Point(det(p, Point(b.y, c.y)), det(Point(b.x, c.x), p)) / d;
}
