typedef long long LL;

bool primeTest(LL n, LL b) {
    LL m = n - 1;
    LL counter = 0;
    while ((m & 1) == 0) {
        m >>= 1;
        counter ++;
    }
    LL ret = powMod(b, m, n);
    if (ret == 1 || ret == n - 1) {
        return true;
    }
    counter --;
    while (counter >= 0) {
        ret = multiplyMod(ret, ret, n);
        if (ret == n - 1) {
            return true;
        }
        counter --;
    }
    return false;
}

const int BASIC[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool isPrime(LL n) {
    if (n < 2) {
        return false;
    }
    if (n < 4) {
        return true;
    }
    if (n == 3215031751LL) {
        return false;
    }
    for (int i = 0; i < 12 && BASIC[i] < n; ++ i) {
        if (!primeTest(n, BASIC[i])) {
            return false;
        }
    }
    return true;
}

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
