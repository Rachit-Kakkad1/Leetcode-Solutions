class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &p : mp) {
            auto &v = p.second;

            if (v.size() < 3) continue;
           
            for (int i = 0; i + 2 < v.size(); i++) {
                int first = v[i];
                int last = v[i + 2];

                ans = min(ans, 2 * (last - first));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};