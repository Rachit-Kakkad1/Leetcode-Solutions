/**
 * @param {string} s
 * @return {number}
 */
function minFlips(s) {
    let n = s.length;
    let t = s + s;

    let alt1 = 0; 
    let alt2 = 0; 

    let left = 0;
    let ans = n;

    for (let right = 0; right < 2 * n; right++) {

        if (t[right] !== (right % 2 === 0 ? '0' : '1')) alt1++;
        if (t[right] !== (right % 2 === 0 ? '1' : '0')) alt2++;

        if (right - left + 1 > n) {

            if (t[left] !== (left % 2 === 0 ? '0' : '1')) alt1--;
            if (t[left] !== (left % 2 === 0 ? '1' : '0')) alt2--;

            left++;
        }

        if (right - left + 1 === n) {
            ans = Math.min(ans, alt1, alt2);
        }
    }

    return ans;
}