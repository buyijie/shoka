Point Point::project(const Point &a, const Point &b) const {
    Point p = *this;
    return a + dot(p - a, b - a) / (a - b).norm2() * (b - a);
}
