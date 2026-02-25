/**
 * @param {number[]} nums
 * @return {number}
 */
function maximumTripletValue(nums) {
    let maxValue = 0;

    for (let i = 0; i < nums.length - 2; i++) {
        for (let j = i + 1; j < nums.length - 1; j++) {
            for (let k = j + 1; k < nums.length; k++) {
                let value = (nums[i] - nums[j]) * nums[k];
                maxValue = Math.max(maxValue, value);
            }
        }
    }

    return maxValue;
}