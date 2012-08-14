Point Point::reflect(const Point &a, const Point &b) const {
    Point p = *this;
    Point q = p.project(a, b);
    return 2 * q - p;
}
