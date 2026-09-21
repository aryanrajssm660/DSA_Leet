class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>ahead(n+1,0);
        vector<int>curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                int len=ahead[j];
                if(j==0||nums[j-1]<nums[i]){
                    len=max(1+ahead[i+1],len);
                }
                curr[j]=len;
            }
            ahead=curr;
        }
        return curr[0];
    }
};