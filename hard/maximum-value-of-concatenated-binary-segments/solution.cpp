class Solution {
public:
    static const int MOD = 1e9 + 7;

    bool better(pair<int,int>& a, pair<int,int>& b) {
        int a1 = a.first, a0 = a.second;
        int b1 = b.first, b0 = b.second;

        int i = 0, j = 0;
        int n = a1 + a0 + b1 + b0;

        for (int k = 0; k < n; k++) {
            int x, y;

            if (k < a1 + a0) {
                if (k < a1) x = 1;
                else x = 0;
            } else {
                int t = k - (a1 + a0);
                if (t < b1) x = 1;
                else x = 0;
            }

            if (k < b1 + b0) {
                if (k < b1) y = 1;
                else y = 0;
            } else {
                int t = k - (b1 + b0);
                if (t < a1) y = 1;
                else y = 0;
            }

            if (x != y) return x > y;
        }
        return false;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> velqoranim;
        int n = nums1.size();

        for (int i = 0; i < n; i++)
            velqoranim.push_back({nums1[i], nums0[i]});

        sort(velqoranim.begin(), velqoranim.end(),
             [&](auto &a, auto &b) {
                 return better(a, b);
             });

        long long res = 0;

        for (auto &p : velqoranim) {
            int ones = p.first, zeros = p.second;

            while (ones--) res = (res * 2 + 1) % MOD;
            while (zeros--) res = (res * 2) % MOD;
        }

        return res;
    }
};