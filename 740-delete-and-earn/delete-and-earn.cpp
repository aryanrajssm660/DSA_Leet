class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>arr(mx+1,0);
        for(auto it:nums){
            arr[it]+=it;
        }
        vector<int>dp(mx+1,0);
        dp[1]=arr[1];
        dp[0]=arr[0];
        for(int i=2;i<=mx;i++){
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
        }
        return dp[mx];
    }
};