Point intersect(const Point &a, const Point &b,
                const Point &c, const Point &d) {
    double s_1 = det(b - a, c - a);
    double s_2 = det(b - a, d - a);
    return (s_2 * c - s_1 * d) / (s_2 - s_1);
}
