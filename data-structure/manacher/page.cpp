void manacher(char text[], int n, int palindrome[]) {
    palindrome[0] = 1;
    for (int i = 1, j = 0, i < (n << 1) - 1; ++ i) {
        int p = i >> 1;
        int q = i - p;
        int r = (j + 1 >> 1) + palindrome[j] - 1;
        palindrome[i] = r < q? 0: min(r - q + 1, palindrome[(j << 1) - i]);
        while (0 <= p - palindrome[i] && q + palindrome[i] < n 
                && text[p - palindrome[i]] == text[q + palindrome[i]]) {
            palindrome[i] ++;
        }
        if (q + palindrome[i] - 1 > r) {
            j = i;
        }
    }
}
