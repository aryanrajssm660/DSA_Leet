class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr(n);

        // Store {digit sum, original number}
        for (int i = 0; i < n; i++) {
            arr[i] = {digitSum(nums[i]), nums[i]};
        }

        // Sort by digit sum, then by original number
        sort(arr.begin(), arr.end());

        // Map each number to its correct sorted index
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        // Count permutation cycles
        for (int i = 0; i < n; i++) {
            if (visited[i] || mp[nums[i]] == i) {
                continue;
            }

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = mp[nums[j]];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};