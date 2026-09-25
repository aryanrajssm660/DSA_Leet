class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int ind=0;
        int prev=-1e8;
        int n=nums.size();
        while(i<n){
            if(prev<nums[i]){
                prev=nums[i];
                swap(nums[ind],nums[i]);
                ind++;
            }
            i++;
        }
        return ind;
    }
};