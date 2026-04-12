class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        vector<int> dp(26, 0);
        int total = 0;

        for (int i = 0; i < word.size() - 1; i++) {
            int a = word[i] - 'A';
            int b = word[i + 1] - 'A';

            int d = dist(a, b);
            total += d;

            for (int j = 0; j < 26; j++) {
                dp[a] = max(dp[a], dp[j] + d - dist(j, b));
            }
        }

        int best = 0;
        for (int x : dp) best = max(best, x);

        return total - best;
    }
};