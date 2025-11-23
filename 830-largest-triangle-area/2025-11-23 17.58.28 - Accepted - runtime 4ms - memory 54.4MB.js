/**
 * @param {number[][]} points
 * @return {number}
 */
var largestTriangleArea = function(points) {
    const n = points.length;
    let max2 = 0;

    for (let i = 0; i < n; i++) {
        const pi = points[i];
        const x1 = pi[0], y1 = pi[1];

        for (let j = i + 1; j < n; j++) {
            const pj = points[j];
            const x2 = pj[0], y2 = pj[1];

            for (let k = j + 1; k < n; k++) {
                const pk = points[k];
                const x3 = pk[0], y3 = pk[1];

                let val =
                    x1 * (y2 - y3) +
                    x2 * (y3 - y1) +
                    x3 * (y1 - y2);

                if (val < 0) val = -val;
                if (val > max2) max2 = val;
            }
        }
    }
    return max2 * 0.5;
};
