/**
 * @param {number[][]} points
 * @return {number}
 */
var largestTriangleArea = function(points) {
    let max2 = 0;  
    const n = points.length;

    for (let i = 0; i < n; i++) {
        const [x1, y1] = points[i];

        for (let j = i + 1; j < n; j++) {
            const [x2, y2] = points[j];

            for (let k = j + 1; k < n; k++) {
                const [x3, y3] = points[k];

               
                let val =
                    x1 * (y2 - y3) +
                    x2 * (y3 - y1) +
                    x3 * (y1 - y2);

                if (val < 0) val = -val;

                if (val > max2) max2 = val;
            }
        }
    }

    return max2 / 2;
};
