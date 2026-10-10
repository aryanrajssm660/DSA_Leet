class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};