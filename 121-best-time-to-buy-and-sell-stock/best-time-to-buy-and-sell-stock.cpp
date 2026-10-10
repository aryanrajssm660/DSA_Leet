class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int ans=0;
        int n=prices.size();
        for(int it:prices){
            if(buy<it){
                ans=max(ans,it-buy);
            }
            else{
                buy=it;
            }
        }
        return ans;

    }
};