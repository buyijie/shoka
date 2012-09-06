void rotate(int x) {
    int t = type[x];
    int y = parent[x];
    int z = children[x][1 ^ t];
    type[x] = type[y];
    parent[x] = parent[y];
    if (type[x] != 2) {
        children[parent[x]][type[x]] = x;
    }
    type[y] = 1 ^ t;
    parent[y] = x;
    children[x][1 ^ t] = y;
    if (z != 0) {
        type[z] = t;
        parent[z] = y;
    }
    children[y][t] = z;
    update(y);
}

void splay(int x) {
    vector <int> stack(1, x);
    for (int i = x; type[i] != 2; i = parent[i]) {
        stack.push_back(parent[i]);
    }
    while (!stack.empty()) {
        push(stack.back());
        stack.pop_back();
    }
    while (type[x] != 2) {
        int y = parent[x];
        if (type[x] == type[y]) {
            rotate(y);
        } else {
            rotate(x);
        }
        if (type[x] == 2) {
            break;
        }
        rotate(x);
    }
    update(x);
}

void access(int x) {
    int z = 0;
    while (x != 0) {
        splay(x);
        type[children[x][1]] = 2;
        children[x][1] = z;
        type[z] = 1;
        update(x);
        z = x;
        x = parent[x];
    }
}
