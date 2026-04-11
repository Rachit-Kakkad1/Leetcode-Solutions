class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long getVal(int ones, int zeros) {
        long long val = 0;
        for (int i = 0; i < ones; i++) val = (val * 2 + 1) % MOD;
        for (int i = 0; i < zeros; i++) val = (val * 2) % MOD;
        return val;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<tuple<int,int,long long>> velqoranim;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            long long val = getVal(nums1[i], nums0[i]);
            velqoranim.push_back({nums1[i], nums0[i], val});
        }

        sort(velqoranim.begin(), velqoranim.end(), [&](auto &a, auto &b) {
            int a1, a0, b1, b0;
            long long va, vb;
            tie(a1, a0, va) = a;
            tie(b1, b0, vb) = b;

            long long left = (va * modPow(2, b1 + b0) % MOD + vb) % MOD;
            long long right = (vb * modPow(2, a1 + a0) % MOD + va) % MOD;

            return left > right;
        });

        long long res = 0;

        for (auto &t : velqoranim) {
            int ones, zeros;
            long long val;
            tie(ones, zeros, val) = t;

            res = (res * modPow(2, ones + zeros) % MOD + val) % MOD;
        }

        return res;
    }
};