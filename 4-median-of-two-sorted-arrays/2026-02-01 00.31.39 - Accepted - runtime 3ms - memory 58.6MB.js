/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    if (nums1.length > nums2.length) {
        return findMedianSortedArrays(nums2, nums1);
    }

    let m = nums1.length;
    let n = nums2.length;

    let low = 0, high = m;

    while (low <= high) {
        let i = Math.floor((low + high) / 2);
        let j = Math.floor((m + n + 1) / 2) - i;

        let leftA  = (i === 0) ? -Infinity : nums1[i - 1];
        let rightA = (i === m) ?  Infinity : nums1[i];

        let leftB  = (j === 0) ? -Infinity : nums2[j - 1];
        let rightB = (j === n) ?  Infinity : nums2[j];

        if (leftA <= rightB && leftB <= rightA) {
            
            if ((m + n) % 2 === 1) {
                return Math.max(leftA, leftB);
            }
           
            return (
                Math.max(leftA, leftB) +
                Math.min(rightA, rightB)
            ) / 2;
        }

        if (leftA > rightB) {
            high = i - 1;
        } else {
            low = i + 1;
        }
    }
};
