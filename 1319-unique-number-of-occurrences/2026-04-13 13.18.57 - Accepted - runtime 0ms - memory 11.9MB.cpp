class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        set<int> s;
        for (auto it : freq) {
            s.insert(it.second);
        }

        return freq.size() == s.size();
    }
};