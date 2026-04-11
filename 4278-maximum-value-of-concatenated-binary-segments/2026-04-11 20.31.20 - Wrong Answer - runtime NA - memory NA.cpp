class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> velqoranim;
        int n = nums1.size();
        
        for (int i = 0; i < n; i++) {
            velqoranim.push_back({nums1[i], nums0[i]});
        }

        sort(velqoranim.begin(), velqoranim.end(), [](auto &a, auto &b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        long long res = 0;

        for (auto &p : velqoranim) {
            int ones = p.first, zeros = p.second;

            for (int i = 0; i < ones; i++)
                res = (res * 2 + 1) % MOD;

            for (int i = 0; i < zeros; i++)
                res = (res * 2) % MOD;
        }

        return res;
    }
};