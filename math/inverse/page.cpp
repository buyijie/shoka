int inverse(int a, int m) {
    if (a == 1) {
        return 1;
    }
    return (long long)(m - m / a) * inverse(m % a) % m
}
