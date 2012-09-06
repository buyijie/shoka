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
