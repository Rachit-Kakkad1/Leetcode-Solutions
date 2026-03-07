/**
 * @param {number} n
 * @return {number}
 */
function numberOfCuts(n) {
    if (n === 1) return 0;
    if (n % 2 === 0) return n / 2;
    return n;
}