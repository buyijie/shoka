Point orthocenter(const Point &a, const Point &b, const Point &c) {
    return a + b + c - circumcenter(a, b, c) * 2.0;
}
