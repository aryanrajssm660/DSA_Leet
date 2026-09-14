class Solution {
public:
int find(int index,int selceted,vector<int>& nums,vector<vector<int>>&dp){
    if(index>=nums.size()){
        return 0;
    }
    int take=0,skip;
    if(dp[index][selceted]!=-1){
        return dp[index][selceted];
    }
    if(selceted-1==-1){
        take=1+find(index+1,index+1,nums,dp);
        skip=find(index+1,0,nums,dp);
    }
    else {
        take=0;
        if(nums[index]>nums[selceted-1]){
            take=1+find(index+1,index+1,nums,dp);
        }
        skip=find(index+1,selceted,nums,dp);

    }
    return dp[index][selceted]=max(take,skip);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return find(0,0,nums,dp);
    }
};