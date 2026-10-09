class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_1 = 0;
        for (int i = 1; i <= n; i++) {
            xor_1 ^= i;
        }
        int xor_2 = 0;
        for(int i=0;i<n;i++){
            xor_2^=nums[i];
        }
        return xor_1^xor_2;
    }
};