/**
 * @param {number[]} nums
 * @return {string}
 */
function largestNumber(nums) {
    nums.sort((a, b) => ('' + b + a) - ('' + a + b));

    if (nums[0] === 0) return "0";

    return nums.join('');
}
