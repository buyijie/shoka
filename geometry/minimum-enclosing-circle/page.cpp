Circle minCircle(Point points[], int n) {
    Circle result(Point(0.0, 0.0), 0.0);
    for (int i = 0; i < n; ++ i) {
        if (!result.contains(points[i])) {
            result = Circle(points[i], 0.0);
            for (int j = 0; j < i; ++ j) {
                if (!result.contains(points[j])) {
                    result = Circle(points[i], points[j]);
                    for (int k = 0; k < j; ++ k) {
                        if (!result.contains(points[k])) {
                            result = Circle(points[i], points[j], points[k]);
                        }
                    }
                }
            }
        }
    }
    return result;
}
