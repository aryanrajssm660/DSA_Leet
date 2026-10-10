class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0, ans1 = INT_MIN, ans2 = INT_MIN;
        for (auto it : nums) {
            if (count1 == 0 && it != ans2) {
                ans1 = it;
                count1++;
            } else if (count2 == 0 && it != ans1) {
                ans2 = it;
                count2++;
            } else if (it == ans1) {
                count1++;
            } else if (it == ans2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        int k1 = 0, k2 = 0;
        for (int it : nums) {
            if (it == ans1) {
                k1++;
            }
            if (it == ans2) {
                k2++;
            }
        }
        int n = nums.size();
        n /= 3;
        vector<int> ans;
        if (k1 > n) {
            ans.push_back(ans1);
        }
        if (k2 > n) {
            ans.push_back(ans2);
        }
        return ans;
    }
};