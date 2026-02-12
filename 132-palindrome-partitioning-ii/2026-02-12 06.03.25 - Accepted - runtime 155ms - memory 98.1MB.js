/**
 * @param {string} s
 * @return {number}
 */
function minCut(s) {
    const n = s.length;

    
    const dp = new Array(n).fill(0);

    
    const isPal = Array.from({ length: n }, () => new Array(n).fill(false));

    for (let i = 0; i < n; i++) {
        dp[i] = i; 

        for (let j = 0; j <= i; j++) {
            if (
                s[i] === s[j] &&
                (i - j <= 2 || isPal[j + 1][i - 1])
            ) {
                isPal[j][i] = true;

                if (j === 0) {
                    dp[i] = 0; 
                } else {
                    dp[i] = Math.min(dp[i], dp[j - 1] + 1);
                }
            }
        }
    }

    return dp[n - 1];
}
