typedef long long LL;

int solve(int a, int b, int m) {
    int tmp = 1 % m;
    if (tmp == b) {
        return 0;
    }
    for (int i = 1; i < 50; ++ i) {
        tmp = (LL)tmp * a % m;
        if (tmp == b) {
            return i;
        }
    }
    int x_0 = 0;
    int d = 1 % m;
    while (true) {
        int ret = gcd(a, m);
        if (ret == 1) {
            break;
        }
        x_0 ++;
        d = (LL)d * (a / ret) % m;
        if (b % ret != 0) {
            return -1;
        }
        b /= ret;
        m /= ret;
    }
    int c = (int)(ceil(sqrt(m)));
    map <int, int> hash;
    tmp = b = (LL)b * inverse(d, m) % m;
    int tmpInverse = inverse(a, m);
    for (int i = 0; i < c; ++ i) {
        if (hash.find(tmp) == hash.end()) {
            hash[tmp] = i;
        }
        tmp = (LL)tmp * tmpInverse % m;
    }
    tmp = 1;
    for (int i = 0; i < c; ++ i) {
        tmp = (LL)tmp * a % m;
    }
    int answer = 1;
    for (int i = 0; i < c; ++ i) {
        if (hash.find(answer) != hash.end()) {
            return x_0 + i * c + hash[answer];
        }
        answer = (LL)answer * tmp % m;
    }
    return -1;
}
