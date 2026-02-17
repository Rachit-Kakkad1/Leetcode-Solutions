/**
 * @param {number} n
 * @return {number}
 */
function maxProduct(n) {
    let max1 = 0; 
    let max2 = 0; 

    while (n > 0) {
        let a = n % 10;

        if (a > max1) {
            max2 = max1;
            max1 = a;
        } else if (a > max2) {
            max2 = a;
        }

        n = Math.floor(n / 10);
    }

    return max1 * max2;
}