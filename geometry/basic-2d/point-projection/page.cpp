Point Point::project(const Point &a, const Point &b) const {
    Point p = *this;
    return a + dot(p - a, p - b) / (a - b).norm2() * (b - a);
}
