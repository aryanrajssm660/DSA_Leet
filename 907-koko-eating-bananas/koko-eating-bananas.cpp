class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int n=piles.size();
        int high=*max_element(piles.begin(),piles.end());
        int ans=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=h;
            for(int i=0;i<n;i++){
                int req=(piles[i]+mid-1)/mid;
                temp-=req;
            }
            if(temp<0){
                low=mid+1;
            }
            else {
                ans=min(ans,mid);
                high=mid-1;
            }
        }
        return ans;
    }
};