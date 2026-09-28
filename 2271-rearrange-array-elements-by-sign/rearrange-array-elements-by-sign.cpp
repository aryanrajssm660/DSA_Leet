class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int l=0,r=1;
        for(auto it:nums){
            if(it>0){
                ans[l]=it;
                l+=2;
            }
            else{
                ans[r]=it;
                r+=2;
            }
        }
        return ans;
    }
};