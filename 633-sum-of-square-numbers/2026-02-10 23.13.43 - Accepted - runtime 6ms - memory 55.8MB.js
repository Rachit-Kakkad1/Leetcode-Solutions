/**
 * @param {number} c
 * @return {boolean}
 */
function judgeSquareSum(c) {
    let a = 0;
    let b = Math.floor(Math.sqrt(c));

    while (a <= b) {
        const sum = a * a + b * b;

        if (sum === c) return true;
        if (sum < c) a++;
        else b--;
    }

    return false;
}
