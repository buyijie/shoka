bool Point::in(Point polygon[], int n) const {
    Point p = *this;
    int counter = 0;
    for (int i = 0; i < n; ++ i) {
        Point a = polygon[i];
        Point b = polygon[(i + 1) % n];
        if (p.on(a, b)) { return false; }
        int x = signum(det(p - a, b - a));
        int y = signum(a.y - p.y);
        int z = signum(b.y - p.y);
        if (x > 0 && y <= 0 && z > 0) { counter ++; }
        if (x < 0 && z <= 0 && y > 0) { counter --; }
    }
    return counter != 0;
}
