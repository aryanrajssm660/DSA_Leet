class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        float n = nums.size();
        n /= 3;
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            if (it.second > n) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};