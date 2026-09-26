class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ind=nums[i]>0?nums[i]:-nums[i];
            if(nums[ind-1]>0){
                nums[ind-1]=-nums[ind-1];
            }
            else{
                ans.push_back(ind);
            }
           
        }
        return ans;
    }
};