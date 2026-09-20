class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // stack<int>st;

        // for(auto it:height){
        //     left=max(left,it);
        //     if(it<left)
        // }
        int l=0;
        int r=n-1;
        int l_max=height[0];
        int r_max=height[r];
        int ans=0;
        while(l<r){
            if(height[l]<height[r]){
                if(l_max<height[l]){
                    l_max=height[l];
                }
                else{
                    ans+=l_max-height[l];
                }
                l++;
            }
            else{
                if(r_max<height[r]){
                    r_max=height[r];
                }
                else{
                    ans+=r_max-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};