class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }

    int nextPrime(int x) {
        while (!isPrime(x)) x++;
        return x;
    }

    int nextNonPrime(int x) {
        while (isPrime(x)) x++;
        return x;
    }

    int minOperations(vector<int>& nums) {
        vector<int> qerlanovid(nums.begin(), nums.end());
        
        int ops = 0;
        
        for (int i = 0; i < qerlanovid.size(); i++) {
            int val = qerlanovid[i];
            
            if (i % 2 == 0) {
                if (!isPrime(val)) {
                    int target = nextPrime(val);
                    ops += target - val;
                }
            } else {
                if (isPrime(val)) {
                    int target = nextNonPrime(val);
                    ops += target - val;
                }
            }
        }
        
        return ops;
    }
};