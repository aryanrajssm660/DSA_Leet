class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>arr(mx+1,0);
        for(auto it:nums){
            arr[it]+=it;
        }
        vector<int>dp(mx+1,0);
        
        int prev=arr[0];
        int curr=arr[1];
        for(int i=2;i<=mx;i++){
            dp[i]=max(curr,arr[i]+prev);
            prev=curr;
            curr=dp[i];
        }
        return curr;
    }
};