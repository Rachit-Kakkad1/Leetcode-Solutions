class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> rob;
        for(int i = 0; i < n; i++) {
            rob.push_back({robots[i], distance[i]});
        }
        sort(rob.begin(), rob.end());

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int pos = rob[i].first;
            int dist = rob[i].second;

            int leftBound = pos - dist;
            if(i > 0) leftBound = max(leftBound, rob[i-1].first);

            int l1 = lower_bound(walls.begin(), walls.end(), leftBound) - walls.begin();
            int r1 = upper_bound(walls.begin(), walls.end(), pos) - walls.begin() - 1;
            int leftCount = (l1 <= r1) ? (r1 - l1 + 1) : 0;

            int rightBound = pos + dist;
            if(i < n-1) rightBound = min(rightBound, rob[i+1].first);

            int l2 = lower_bound(walls.begin(), walls.end(), pos) - walls.begin();
            int r2 = upper_bound(walls.begin(), walls.end(), rightBound) - walls.begin() - 1;
            int rightCount = (l2 <= r2) ? (r2 - l2 + 1) : 0;

            ans += max(leftCount, rightCount);
        }

        return ans;
    }
};