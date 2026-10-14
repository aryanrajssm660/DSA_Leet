class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long count = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int n = nums.size();
        int xo = 0;

        for (int it : nums) {
            xo ^= it;
            if (mpp[xo]>0) {
                count += mpp[xo];
            }
            mpp[xo]++;
        }
        return count;
    }
};