vector <int> sieve(int n) {
    vector <bool> visit(n + 1, false);
    vector <int> primes;
    for (int i = 2; i <= n; ++ i) {
        if (!visit[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n; ++ j) {
            visit[i * primes[j]] = true;
            if (i % primes[j]) {
                break;
            }
        }
    }
    return primes;
}
