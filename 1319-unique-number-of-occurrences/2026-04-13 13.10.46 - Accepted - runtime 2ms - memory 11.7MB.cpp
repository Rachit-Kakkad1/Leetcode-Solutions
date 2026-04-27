class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n; i++) {
        
            bool alreadySeen = false;
            for (int k = 0; k < i; k++) {
                if (arr[k] == arr[i]) {
                    alreadySeen = true;
                    break;
                }
            }
            if (alreadySeen) continue;

            
            int count1 = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i]) count1++;
            }

            
            for (int j = i + 1; j < n; j++) {
                
                bool skip = false;
                for (int k = 0; k < j; k++) {
                    if (arr[k] == arr[j]) {
                        skip = true;
                        break;
                    }
                }
                if (skip) continue;

                int count2 = 0;
                for (int k = 0; k < n; k++) {
                    if (arr[k] == arr[j]) count2++;
                }

                if (count1 == count2) return false;
            }
        }

        return true;
    }
};