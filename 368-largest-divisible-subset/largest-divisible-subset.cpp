class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;
        int last=0;
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0&&dp[i]<1+dp[j]){
                    hash[i]=j;
                    dp[i]=1+dp[j];
                }
                if(ans<dp[i]){
                    ans=dp[i];
                    last=i;
                }
            }
        }
        vector<int>answer;
        while(hash[last]!=last){
            answer.push_back(nums[last]);
            last=hash[last];
        }
        answer.push_back(nums[last]);
        return answer;
    }
};