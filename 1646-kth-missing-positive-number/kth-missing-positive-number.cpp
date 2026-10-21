class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int temp=k;
        for(int it:arr){
            if(it<=temp){
                temp++;
            }
            else{
                return temp;
            }
        }
        return temp;
    }
};