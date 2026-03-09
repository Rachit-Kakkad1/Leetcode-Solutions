/**
 * @param {number} zero
 * @param {number} one
 * @param {number} limit
 * @return {number}
 */
function numberOfStableArrays(zero, one, limit) {
    const MOD = 1e9 + 7;

    const dp0 = Array.from({ length: zero + 1 }, () => Array(one + 1).fill(0));
    const dp1 = Array.from({ length: zero + 1 }, () => Array(one + 1).fill(0));

    dp0[1][0] = 1;
    dp1[0][1] = 1;

    for (let i = 0; i <= zero; i++) {
        for (let j = 0; j <= one; j++) {

            if (i > 0) {
                dp0[i][j] = ((dp0[i][j] + dp0[i - 1][j] + dp1[i - 1][j]) % MOD);

                if (i - limit - 1 >= 0)
                    dp0[i][j] = (dp0[i][j] - dp1[i - limit - 1][j] + MOD) % MOD;
            }

            if (j > 0) {
                dp1[i][j] = ((dp1[i][j] + dp0[i][j - 1] + dp1[i][j - 1]) % MOD);

                if (j - limit - 1 >= 0)
                    dp1[i][j] = (dp1[i][j] - dp0[i][j - limit - 1] + MOD) % MOD;
            }
        }
    }

    return (dp0[zero][one] + dp1[zero][one]) % MOD;
}