bool Point::on(const Point &a, const Point &b) const {
    Point p = *this;
    return signum(det(p - a, p - b)) == 0 && signum(dot(p - a, p - b)) < 0;
}
