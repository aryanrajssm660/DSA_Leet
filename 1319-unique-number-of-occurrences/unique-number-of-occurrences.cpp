class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        for (int x : arr) {
            freq[x]++;
        }

        unordered_set<int> seen;

        for (auto [x, count] : freq) {
            if (!seen.insert(count).second) {
                return false;
            }
        }

        return true;
    }
};