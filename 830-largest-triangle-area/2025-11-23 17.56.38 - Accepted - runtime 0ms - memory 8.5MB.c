double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
    int max2 = 0;  // store double-area to avoid using double inside loops

    for (int i = 0; i < pointsSize; i++) {
        int x1 = points[i][0], y1 = points[i][1];

        for (int j = i + 1; j < pointsSize; j++) {
            int x2 = points[j][0], y2 = points[j][1];

            for (int k = j + 1; k < pointsSize; k++) {
                int x3 = points[k][0], y3 = points[k][1];

                // Compute 2*Area using integer arithmetic
                int val =
                    x1 * (y2 - y3) +
                    x2 * (y3 - y1) +
                    x3 * (y1 - y2);

                // manual abs avoids call to fabs()
                if (val < 0) val = -val;

                if (val > max2)
                    max2 = val;
            }
        }
    }

    return max2 / 2.0; 
}
