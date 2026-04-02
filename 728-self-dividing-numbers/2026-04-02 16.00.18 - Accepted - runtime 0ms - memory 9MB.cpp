class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;

        for (int num = left; num <= right; num++) {
            int t = num;
            bool iv = true;

            while (t > 0) {
                int dt = t % 10;

                if (dt == 0) {
                    iv = false;
                    break;
                }

                if (num % dt != 0) {
                    iv = false;
                    break;
                }

                t /= 10;
            }

            if (iv) {
                result.push_back(num);
            }
        }

        return result;
    }
};