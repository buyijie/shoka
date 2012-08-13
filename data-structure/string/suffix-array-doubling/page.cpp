const int N = 123456;

template <class T> 
void construct(int text[], int n, int array[], int rank[]) {
    static pair <T, int> order[N];
    for (int i = 0; i < n; ++ i) {
        order[i] = make_pair(text[i], i);
    }
    sort(order, order + n);
    for (int i = 0; i < n; ++ i) {
        array[i] = order[i].second;
        rank[array[i]] = i == 0? 1: 
            rank[array[i - 1]] + (order[i - 1].first != order[i].first);
    }
    static int newArray[N];
    static int newRank[2][N];
    static int count[N + 1];
    for (int length = 1; length < n; length <<= 1) {
        for (int i = 0; i < n; ++ i) {
            newRank[0][i] = rank[i];
            newRank[1][i] = i + length < n? rank[i + length]: 0;
        }
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; ++ i) { count[newRank[1][i]] ++; }
        for (int i = 0; i < n; ++ i) { count[i] += count[i - 1]; }
        for (int i = n - 1; i >= 0; -- i) { 
            newArray[-- count[newRank[1][i]]] = i; 
        }
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; ++ i) { count[newRank[0][i]] ++; }
        for (int i = 0; i < n; ++ i) { count[i] += count[i - 1]; }
        for (int i = n - 1; i >= 0; -- i) {
            array[-- count[newRank[0][newArray[i]]]] = newArray[i];
        }
        rank[array[0]] = 1;
        for (int i = 1; i < n; ++ i) {
            rank[array[i]] = rank[array[i - 1]] 
                + (newRank[0][array[i]] != newRank[0][array[i - 1]] 
                || newRank[1][array[i]] != newRank[1][array[i - 1]]);
        }
    }
}
