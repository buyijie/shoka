Point incenter(const Point &a, const Point &b, const Point &c) {
    double p = (a - b).norm() + (b - c).norm() + (c - a).norm();
    return (a * (b - c).norm() + b * (c - a).norm() + c * (a - b).norm()) / p;
}
