class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        int pos = 0; 
        int neg = 1; 

        while (pos < n && neg < n) {
            
            if (nums[pos] > 0) pos += 2;
            else if (nums[neg] < 0) neg += 2;
            else {
              
                swap(nums[pos], nums[neg]);
                pos += 2;
                neg += 2;
            }
        }

        return nums;
    }
};