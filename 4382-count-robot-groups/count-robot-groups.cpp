class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        int ans=position.size();
        int curr_Speed=speed[n-1];
        for(int i=n-2;i>=0;i--){
            if(position[i+1]-position[i]<=distance){
                ans--;
            }
            else if(speed[i]>curr_Speed){
                ans--;
            }
            else{
                curr_Speed=speed[i];
            }
        }
        return ans;
    }
};