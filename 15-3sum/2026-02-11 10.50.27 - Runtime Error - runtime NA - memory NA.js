/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function threeSum(nums) {
    nums.sort((a, b) => a - b);
    const res = [];

    for (let i = 0; i < nums.length - 2; i++) {

       
        if (i > 0 && nums[i] === nums[i - 1]){
         continue;
        }    

        let lt = i + 1;
        let rt = nums.length - 1;

        while (l < rt) {
            const sum = nums[i] + nums[lt] + nums[rt];

            if (sum === 0) {
                res.push([nums[i], nums[lt], nums[rt]]);

              
                while (lt < rt && nums[lt] === nums[lt + 1]) lt++;
                while (lt < rt && nums[rt] === nums[rt - 1]) rt--;

                lt++;
                rt--;
            }
            else if (sum < 0) {
                lt++;
            }
            else {
                rt--;
            }
        }
    }

    return res;
};