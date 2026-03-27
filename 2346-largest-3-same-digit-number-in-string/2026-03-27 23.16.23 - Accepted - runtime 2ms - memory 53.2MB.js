/**
 * @param {string} num
 * @return {string}
 */
function largestGoodInteger(num) {
    let ans = "";

    for (let i = 0; i < num.length - 2; i++) {
        if (num[i] === num[i+1] && num[i] === num[i+2]) {
            let temp = num.substring(i, i+3);
            if (temp > ans) ans = temp;
        }
    }

    return ans;
}
