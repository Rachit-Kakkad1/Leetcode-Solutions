/**
 * @param {number[]} nums
 * @return {boolean}
 */
var findSubarrays = function(nums) {
    
    for (let i = 0; i < nums.length - 1; i++) {
        let sum1 = nums[i] + nums[i + 1];
        
        for (let j = i + 1; j < nums.length - 1; j++) {
            let sum2 = nums[j] + nums[j + 1];
            
            if (sum1 === sum2) {
                return true;
            }
        }
    }
    
    return false;
};