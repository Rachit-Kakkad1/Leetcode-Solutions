/**
 * @param {number} zero
 * @param {number} one
 * @param {number} limit
 * @return {number}
 */
function numberOfStableArrays(zero, one, limit) {
    const MOD = 1e9 + 7;

    const dp = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0])
    );

    for (let i = 1; i <= Math.min(limit, zero); i++) dp[i][0][0] = 1;
    for (let j = 1; j <= Math.min(limit, one); j++) dp[0][j][1] = 1;

    for (let i = 0; i <= zero; i++) {
        for (let j = 0; j <= one; j++) {

            if (i > 0) {
                for (let k = 1; k <= limit && i - k >= 0; k++) {
                    dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
                }
            }

            if (j > 0) {
                for (let k = 1; k <= limit && j - k >= 0; k++) {
                    dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
                }
            }

        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}