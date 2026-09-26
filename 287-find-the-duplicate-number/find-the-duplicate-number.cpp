class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ind=nums[i]>0?nums[i]:-nums[i];
            if(nums[ind]>0){
                nums[ind]=-nums[ind];
            }
            else{
                return ind;
            }
        }
        return -1;
    }
};