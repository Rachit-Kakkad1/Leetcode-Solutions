/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
function searchRange(nums, target) {

    function boundary(isFirst) {
        let left = 0, right = nums.length - 1;
        let ans = -1;

        while (left <= right) {
            const mid = Math.floor((left + right) / 2);

            if (nums[mid] === target) {
                ans = mid;
                isFirst ? right = mid - 1 : left = mid + 1;
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        return ans;
    }

    return [boundary(true), boundary(false)];
}
