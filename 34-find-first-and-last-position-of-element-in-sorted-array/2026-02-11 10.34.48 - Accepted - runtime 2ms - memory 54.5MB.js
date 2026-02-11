/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let s = -1;
    let e = -1;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === target) {
            if (s === -1) s = i;
            e = i;
        }
    }

    return [s, e];
};