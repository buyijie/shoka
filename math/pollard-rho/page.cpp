typedef long long LL;

LL pollardRho(LL n, LL seed) {
    LL x, y;
    x = y = rand() % (n - 1) + 1;
    LL head = 1;
    LL tail = 2;
    while (true) {
        x = multiplyMod(x, x, n);
        x = addMod(x, seed, n);
        if (x == y) {
            return n;
        }
        LL d = gcd(abs(x - y), n);
        if (1 < d && d < n) {
            return d;
        }
        head ++;
        if (head == tail) {
            y = x;
            tail <<= 1;
        }
    }
}

vector <LL> divisors;

void factorize(LL n) {
    if (n > 1) {
        if (isPrime(n)) {
            divisors.push_back(n);
        } else {
            LL d = n;
            while (d >= n) {
                d = pollardRho(n, rand() % (n - 1) + 1);
            }
            factorize(n / d);
            factorize(d);
        }
    }
}
