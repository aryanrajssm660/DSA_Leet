class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(auto it:nums){
            if(it>temp.back()){
                temp.push_back(it);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),it)-temp.begin();
                temp[ind]=it;
            }
        }
        return temp.size();
    }
};