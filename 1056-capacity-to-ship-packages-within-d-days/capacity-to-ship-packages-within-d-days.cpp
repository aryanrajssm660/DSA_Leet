class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        int ans = 1e8;
        for (auto it : weights) {
            high += it;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            int count = 1;
            for (int it : weights) {
                sum += it;
                if (sum > mid) {
                    sum = it;
                    count++;
                }
            }
            if (count <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};