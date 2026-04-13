class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        set<int> s; // here we can use unordered_set as well but it would cause the runtime to be larger then the set cuase the input is small and set is faster than unordered_set in case of the small input !
        for (auto it : freq) {
            s.insert(it.second);
        }

        return freq.size() == s.size();
    }
};