/**
 * @param {number} n
 * @return {boolean}
 */
function isPowerOfFour(n) {
    if (n <= 0) return false;

    const x = Math.log(n) / Math.log(4);
    return Number.isInteger(x);
}
