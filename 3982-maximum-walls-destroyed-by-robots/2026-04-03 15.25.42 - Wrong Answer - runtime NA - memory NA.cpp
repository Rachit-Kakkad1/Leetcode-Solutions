class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        sort(walls.begin(), walls.end());

        vector<pair<int,int>> rob;
        for(int i=0;i<n;i++) rob.push_back({robots[i], distance[i]});
        sort(rob.begin(), rob.end());

        vector<vector<int>> intervals;

        for(int i=0;i<n;i++){
            int pos = rob[i].first;
            int dist = rob[i].second;

            int leftBound = pos - dist;
            if(i > 0) leftBound = max(leftBound, rob[i-1].first);

            int rightBound = pos + dist;
            if(i < n-1) rightBound = min(rightBound, rob[i+1].first);

            // LEFT interval
            int l = lower_bound(walls.begin(), walls.end(), leftBound) - walls.begin();
            int r = upper_bound(walls.begin(), walls.end(), pos) - walls.begin() - 1;
            if(l <= r) intervals.push_back({l, r});

            // RIGHT interval
            l = lower_bound(walls.begin(), walls.end(), pos) - walls.begin();
            r = upper_bound(walls.begin(), walls.end(), rightBound) - walls.begin() - 1;
            if(l <= r) intervals.push_back({l, r});
        }

        // Greedy: sort by end
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int m = walls.size();
        vector<bool> used(m, false);

        int ans = 0;

        for(auto &it : intervals){
            int l = it[0], r = it[1];
            for(int i = l; i <= r; i++){
                if(!used[i]){
                    used[i] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};