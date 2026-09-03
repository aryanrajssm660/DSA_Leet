class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
            int mini=INT_MAX;
            for(auto it:nums1){
                if(it&1){
                    mini=min(mini,it);
                }
            }
            if(mini==INT_MAX){
                return true;
            }
            for(auto it:nums1){
                if(it%2==0&&it<=mini){
                    return false;
                }
            }
            return true;
    }
};