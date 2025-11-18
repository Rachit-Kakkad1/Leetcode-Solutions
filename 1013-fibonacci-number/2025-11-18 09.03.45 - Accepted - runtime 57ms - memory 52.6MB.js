/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    if (n < 2) return n;
    const sqrt5 = Math.sqrt(5);
    const phi = (1 + sqrt5) / 2;
    return Math.round(Math.pow(phi, n) / sqrt5);
};
