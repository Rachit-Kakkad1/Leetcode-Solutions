class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> rob(n);
        for (int i = 0; i < n; i++) rob[i] = {robots[i], distance[i]};
        sort(rob.begin(), rob.end());

        auto countWalls = [&](int l, int r) -> int {
            if (l > r) return 0;
            int L = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
            int R = upper_bound(walls.begin(), walls.end(), r) - walls.begin() - 1;
            return (L <= R) ? (R - L + 1) : 0;
        };

        vector<int> own(n), Lonly(n), Ronly(n), overlap(n, 0);

        for (int i = 0; i < n; i++) {
            int pos = rob[i].first, d = rob[i].second;

            int leftCap  = (i == 0)   ? pos - d : rob[i-1].first + 1;
            int rightCap = (i == n-1) ? pos + d : rob[i+1].first - 1;

            int L = max(pos - d, leftCap);
            int R = min(pos + d, rightCap);

            own[i] = countWalls(pos, pos);
            Lonly[i] = countWalls(L, pos - 1);
            Ronly[i] = countWalls(pos + 1, R);

            if (i > 0) {
                int prev_pos = rob[i-1].first, prev_d = rob[i-1].second;

                int prev_right_L = prev_pos + 1;
                int prev_right_R = min(prev_pos + prev_d, pos - 1);

                int curr_left_L = max(pos - d, rob[i-1].first + 1);
                int curr_left_R = pos - 1;

                int l = max(prev_right_L, curr_left_L);
                int r = min(prev_right_R, curr_left_R);

                overlap[i] = countWalls(l, r);
            }
        }

        vector<array<int,2>> dp(n);

        dp[0][0] = own[0] + Lonly[0];
        dp[0][1] = own[0] + Ronly[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = own[i] + Lonly[i] + max(
                dp[i-1][0],
                dp[i-1][1] - overlap[i]
            );

            dp[i][1] = own[i] + Ronly[i] + max(
                dp[i-1][0],
                dp[i-1][1]
            );
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};