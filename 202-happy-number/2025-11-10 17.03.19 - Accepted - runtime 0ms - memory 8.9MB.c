bool isHappy(int n) {
    int seen[1000] = {0};
    while (n != 1) {
        if (seen[n % 1000]) return false;
        seen[n % 1000] = 1;
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        n = sum;
    }
    return true;
}
