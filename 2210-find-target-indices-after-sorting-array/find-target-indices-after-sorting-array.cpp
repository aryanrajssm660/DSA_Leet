class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int target_count = 0;
        int smaller = 0;
        for (int it : nums) {
            if(it<target){
                smaller++;
            }
            else if(it==target){
                target_count++;
            }
        }
         vector<int>ans;
        if(target_count==0){
            return ans;
        }
        for(int i=smaller;i<smaller+target_count;i++){
            ans.push_back(i);
        }
        return ans; 
       
    }
};