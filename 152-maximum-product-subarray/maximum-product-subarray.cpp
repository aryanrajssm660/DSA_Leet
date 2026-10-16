class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int n=nums.size();
        int answer=-1e8;
        
        for(int i=0;i<n;i++){
            prefix*=nums[i];
            suffix*=nums[n-i-1];
        
            answer=max({answer,prefix,suffix});
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
        }
return answer;
    }
};