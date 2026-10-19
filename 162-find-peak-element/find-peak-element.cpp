class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int ans=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==ans){
                return i;
            }
        }
        return -1;
    }
};