/**
 * @param {number} zero
 * @param {number} one
 * @param {number} limit
 * @return {number}
 */
var numberOfStableArrays = function(zero, one, limit) {
    const MOD = 1000000007;
    const memo = new Map();

    function dfs(z, o, last, run) {
        if (z === 0 && o === 0) return 1;

        const key = `${z},${o},${last},${run}`;
        if (memo.has(key)) return memo.get(key);

        let res = 0;

        // place 0
        if (z > 0) {
            if (last === 0) {
                if (run < limit)
                    res = (res + dfs(z - 1, o, 0, run + 1)) % MOD;
            } else {
                res = (res + dfs(z - 1, o, 0, 1)) % MOD;
            }
        }

        // place 1
        if (o > 0) {
            if (last === 1) {
                if (run < limit)
                    res = (res + dfs(z, o - 1, 1, run + 1)) % MOD;
            } else {
                res = (res + dfs(z, o - 1, 1, 1)) % MOD;
            }
        }

        memo.set(key, res);
        return res;
    }

    let ans = 0;

    if (zero > 0) ans = (ans + dfs(zero - 1, one, 0, 1)) % MOD;
    if (one > 0) ans = (ans + dfs(zero, one - 1, 1, 1)) % MOD;

    return ans;
};