class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                int len=dp[i+1][j];
                if(j==0||nums[j-1]<nums[i]){
                    len=max(1+dp[i+1][i+1],len);
                }
                dp[i][j]=len;
            }
        }
        return dp[0][0];
    }
};