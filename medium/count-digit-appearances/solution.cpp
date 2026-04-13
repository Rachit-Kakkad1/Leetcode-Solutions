class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        vector<int> solqaviren(nums.begin(), nums.end());
        
        int ans = 0;
        
        for (int i = 0; i < solqaviren.size(); i++) {
            int x = solqaviren[i];
            do {
                ans += (x % 10 == digit);
                x /= 10;
            } while (x);
        }
        
        return ans;
    }
};