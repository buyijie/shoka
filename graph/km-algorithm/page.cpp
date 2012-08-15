typedef int Type;

const int N = 200;
const Type INFINITY = 1000000000;

int n, visitX[N], visitY[N], match[N], parent[N];
Type weight[N][N], labelX[N], labelY[N], slack[N];

void adjust(int v) {
    match[v] = visitY[v];
    if (visitX[match[v]] != -2) {
        adjust(visitX[match[v]]);
    }
}

bool find(int i) {
    for (int j = 0; j < n; ++ j) {
        if (visitY[j] == -1) {
            if (slack[j] > labelX[i] + labelY[j] - weight[i][j]) {
                slack[j] = labelX[i] + labelY[j] - weight[i][j];
                parent[j] = i;
            }
            if (labelX[i] + labelY[j] == weight[i][j]) {
                visitY[j] = i;
                if (match[j] == -1) {
                    adjust(j);
                    return true;
                }
                if (visitX[match[j]] != -1) {
                    continue;
                }
                visitX[match[j]] = j;
                if (find(match[j])) {
                    return true;
                }
            }
        }
    }
    return false;
}

void km() {
    for (int i = 0; i < n; ++ i) {
        labelX[i] = -INFINITY;
        for (int j = 0; j < n; ++ j) {
            labelX[i] = max(labelX[i], weight[i][j]);
        }
        labelY[i] = 0;
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            visitX[j] = visitY[j] = -1;
            slack[j] = INFINITY;
        }
        visitX[i] = -2;
        if (find(i)) {
            continue;
        }
        bool flag = false;
        while (!flag) {
            Type delta = INFINITY;
            for (int j = 0; j < n; ++ j) {
                if (visitY[j] == -1) {
                    delta = min(delta, slack[j]);
                }
            }
            for (int j = 0; j < n; ++ j) {
                if (visitX[j] != -1) {
                    labelX[j] -= delta;
                }
                if (visitY[j] != -1) {
                    labelY[j] += delta;
                } else {
                    slack[j] -= delta;
                }
            }
            for (int j = 0; j < n; ++ j) {
                if (visitY[j] == -1 && slack[j] != 0) {
                    visitY[j] = parent[j];
                    if (match[j] == -1) {
                        adjust(j);
                        flag = true;
                        break;
                    }
                    visitX[match[j]] = j;
                    if (find(match[j])) {
                        flag = true;
                        break;
                    }
                }
            }
        }
    }
}
