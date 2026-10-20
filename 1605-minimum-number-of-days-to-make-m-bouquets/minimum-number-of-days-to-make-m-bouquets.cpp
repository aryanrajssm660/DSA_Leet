class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int n = bloomDay.size();
    
        int ans = -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int count = 0;
            int grow = 0;
            int mid = low + (high - low) / 2;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    grow++;
                    if (grow >= k) {
                        count++;
                        grow = 0;
                    }
                } else {
                    grow = 0;
                }
            }
            if (count >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};