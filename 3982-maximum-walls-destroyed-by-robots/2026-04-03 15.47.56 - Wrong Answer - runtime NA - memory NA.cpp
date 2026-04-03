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
            int L = (int)(lower_bound(walls.begin(), walls.end(), l) - walls.begin());
            int R = (int)(upper_bound(walls.begin(), walls.end(), r) - walls.begin()) - 1;
            return (L <= R) ? (R - L + 1) : 0;
        };

        // left[i]  = walls robot i can hit firing left  (from pos-dist to pos, blocked by i-1)
        // right[i] = walls robot i can hit firing right (from pos to pos+dist, blocked by i+1)
        vector<int> L(n), R(n);

        L[0] = countWalls(rob[0].first - rob[0].second, rob[0].first);
        R[n-1] = countWalls(rob[n-1].first, rob[n-1].first + rob[n-1].second);

        for (int i = 0; i < n - 1; i++) {
            int pos1 = rob[i].first,   d1 = rob[i].second;
            int pos2 = rob[i+1].first, d2 = rob[i+1].second;
            R[i]   = countWalls(pos1, min(pos1 + d1, pos2));
            L[i+1] = countWalls(max(pos2 - d2, pos1), pos2);
        }

        // dp[i][0] = best total walls if robot i fires LEFT
        // dp[i][1] = best total walls if robot i fires RIGHT
        vector<array<int,2>> dp(n, {0, 0});
        dp[0][0] = L[0];
        dp[0][1] = R[0];

        for (int i = 1; i < n; i++) {
            int pos1 = rob[i-1].first;
            int pos2 = rob[i].first;

            // If robot i fires LEFT, it covers L[i] which includes pos1..pos2 overlap region.
            // If robot i-1 fired RIGHT, it also covers that overlap — so we must subtract overlap.
            int overlap = countWalls(max(rob[i].first - rob[i].second, rob[i-1].first),
                                     min(rob[i-1].first + rob[i-1].second, rob[i].first));

            dp[i][0] = max(dp[i-1][0] + L[i],
                           dp[i-1][1] + L[i] - overlap);

            dp[i][1] = max(dp[i-1][0] + R[i],
                           dp[i-1][1] + R[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, max(dp[i][0], dp[i][1]));
        return ans;
    }
};