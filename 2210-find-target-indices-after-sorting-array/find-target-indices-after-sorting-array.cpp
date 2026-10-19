class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {   vector<int>arr(nums.begin(),nums.end());
    vector<int>ans;
        sort(arr.begin(),arr.end());
        int low=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        int high=upper_bound(arr.begin(),arr.end(),target)
        -arr.begin();
        if(low-high==0){
            return ans;
        }
        for(int i=low;i<high;i++){
            ans.push_back(i);
        }
        return ans;
        
    }
};