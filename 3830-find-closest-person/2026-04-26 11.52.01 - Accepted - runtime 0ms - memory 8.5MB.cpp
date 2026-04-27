class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1, d2;

        if (x > z) {
            d1 = x - z;
        } else {
            d1 = z - x;
        }
        if (y > z) {
            d2 = y - z;
        } else {
            d2 = z - y;
        }
        if (d1 < d2) {
            return 1;
        }
        if (d2 < d1) {
            return 2;
        }
        return 0;
    }
};