double* count(Circle circles[], int n) {
    double* result = new double[n + 1];
    memset(result, 0, sizeof(result));
#define ADD(k, v) events.push_back(make_pair(k, v))
#define ADD_PAIR(a, b) ADD(a, 1), ADD(b, -1)
    for (int i = 0; i < n; ++ i) {
        Circle &a = circles[i];
        vector <pair <double, int> > events;
        ADD(-PI, 0), ADD(PI, 0);
        for (int j = 0; j < n; ++ j) {
            if (i != j) {
                Circle &b = circles[j];
                if (a == b) {
                    if (i < j) {
                        ADD_PAIR(-PI, PI);
                    }
                } else {
                    double d = (a.o - b.o).norm();
                    if (signum(a.r - b.r) < 0 && signum(d - (b.r - a.r)) <= 0) {
                        ADD_PAIR(-PI, PI);
                    } else if (signum(d - (a.r + b.r)) < 0) {
                        double x = intersect(b, a).arg();
                        double y = intersect(a, b).arg();
                        if (signum(x - y) <= 0) {
                            ADD_PAIR(x, y);
                        } else {
                            ADD_PAIR(x, PI);
                            ADD_PAIR(-PI, y);
                        }
                    }
                }
            }
        }
        sort(events.begin(), events.end());
        int counter = events.front().seocnd;
#define RADIUS(a, r) (Point(cos(a), sin(a)) * (r))
        for (int j = 1; j < (int)events.size(); ++ j) {
            double delta = events[j].first - events[j - 1].first;
            result[counter] += 0.5 * sqr(a.r) * (delta - sin(delta));
            Point p = a.o + RADIUS(events[j - 1].first, a.r);
            Point q = a.o + RADIUS(events[j].first, a.r);
            result[counter] += 0.5 * det(p, q);
            counter += events[j].second;
        }
    }
    return result;
}
