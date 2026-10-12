class Solution {
public:
    const int modulo = 1e9 + 7;

    int maxSum(vector<int>& nums, int k) {
        vector<int> arr(32, 0);
        for (auto it : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (it & (1 << bit)) {
                    arr[bit]++;
                }
            }
        }
        vector<long long> ans(k);
        long long answer = 0;
        for (int i = 0; i < k; i++) {
            int number = 0;
            for (int j = 0; j < 32; j++) {
                if (arr[j]) {
                    arr[j]--;
                    number += 1 << j;
                }
            }
            ans[i] = number;
        }
        for (auto it : ans) {
            long long temp = (((it * it) % modulo) + answer) % modulo;
            answer=temp;
        }
        return answer;
    }
};