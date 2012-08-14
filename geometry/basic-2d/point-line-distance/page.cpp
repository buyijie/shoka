double Point::to(const Point &a, const Point &b) const {
    Point p = *this;
    return abs(det(p - a, p - b) / (a - b).norm());
}
