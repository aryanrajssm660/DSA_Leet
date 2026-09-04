class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n);
        vector<int> mini(n);
        int maximum=nums[0];
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
            maxi[i]=maximum;
        }
        int minimum=nums[n-1];
        for(int i=n-1;i>=0;i--){
            minimum=min(minimum,nums[i]);
            mini[i]=minimum;
        }
        for(int i=0;i<n;i++){
            cout<<maxi[i]<<"  "<<mini[i]<<endl; 
        }
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k){
                return i;
            }
        }
        return -1;

    }
};