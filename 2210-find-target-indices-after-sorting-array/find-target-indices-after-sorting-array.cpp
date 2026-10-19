class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int small = 0;
        for (int it : nums) {
            if(it<target){
                small++;
            }
            else if(it==target){
                count++;
            }
        }
         vector<int>ans;
        if(count==0){
            return ans;
        }
        for(int i=0;i<count;i++){
            ans.push_back(i+small);
        }
        return ans; 
       
    }
};