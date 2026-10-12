class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        int remove=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(auto it:nums){
            sum+=it;
            remove=sum-k;
            count+=mpp[remove];
            mpp[sum]++;


        }
        return count;

    }
};