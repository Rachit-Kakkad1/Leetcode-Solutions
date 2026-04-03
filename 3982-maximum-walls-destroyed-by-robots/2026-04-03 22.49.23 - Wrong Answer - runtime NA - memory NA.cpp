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

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int pos = rob[i].first, d = rob[i].second;

            int leftCap  = (i == 0)   ? pos - d : rob[i-1].first + 1;
            int rightCap = (i == n-1) ? pos + d : rob[i+1].first - 1;

            int own = countWalls(pos, pos);
            int Lonly = countWalls(max(pos - d, leftCap), pos - 1);
            int Ronly = countWalls(pos + 1, min(pos + d, rightCap));

            ans += own + max(Lonly, Ronly);
        }

        return ans;
    }
};