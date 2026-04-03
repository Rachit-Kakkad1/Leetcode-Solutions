class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> rob(n);
        for(int i = 0; i < n; i++) rob[i] = {robots[i], distance[i]};
        sort(rob.begin(), rob.end());

        auto countWalls = [&](int l, int r) -> int {
            if (l > r) return 0;
            int L = (int)(lower_bound(walls.begin(), walls.end(), l) - walls.begin());
            int R = (int)(upper_bound(walls.begin(), walls.end(), r) - walls.begin()) - 1;
            return (L <= R) ? (R - L + 1) : 0;
        };

        
        vector<array<int,2>> dp(n, {0, 0});

        
        dp[0][0] = countWalls(rob[0].first - rob[0].second, rob[0].first);
        
        dp[0][1] = 0;

        for (int i = 0; i < n - 1; i++) {
            int pos1 = rob[i].first,   d1 = rob[i].second;
            int pos2 = rob[i+1].first, d2 = rob[i+1].second;

           
            int A = countWalls(pos1, min(pos1 + d1, pos2 - 1));
            
            int B = countWalls(max(pos2 - d2, pos1 + 1), pos2);

            dp[i+1][0] = max(dp[i][0] + B,
                             dp[i][1] + A + B);

            dp[i+1][1] = max(dp[i][0],
                             dp[i][1] + A);
        }

       
        int posLast = rob[n-1].first, dLast = rob[n-1].second;
        int rightmost = countWalls(posLast, posLast + dLast);

        
        int ans = max(dp[n-1][0],dp[n-1][1] + rightmost); 
        return ans;
    }
};