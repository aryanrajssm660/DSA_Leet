class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int answer = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                answer += st.size() * st.size();
            }
        }
        return answer;
    }
};