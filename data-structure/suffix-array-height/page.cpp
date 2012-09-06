template <class Type>
void construct(Type text[], int n, int array[], int rank[], int height[]) {
    for (int i = 0, k = 0; i < n; ++ i) {
        if (rank[i] > 0) {
            int j = array[rank[i] - 1];
            while (i + k < n && j + k < n && text[i + k] == text[j + k]) {
                k ++;
            }
            height[i] = k;
            if (k > 0) {
                k --;
            }
        }
    }
}
