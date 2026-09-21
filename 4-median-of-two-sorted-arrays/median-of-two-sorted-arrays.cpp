class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int prev, count;
        int size1 = nums1.size();
        int size2 = nums2.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : nums1) {
            pq.push(it);
        }
        for (auto it : nums2) {
            pq.push(it);
        }
        int size = pq.size();
        if (size & 1) {
            int half = size / 2 + 1;

            while (half--) {
                ans = pq.top();

                pq.pop();
            }
            return ans;
        } else {
            int half = size / 2 + 1;

            while (half--) {
                prev = ans;
                ans = pq.top();

                pq.pop();
            }
            ans= (ans + prev)/2;
        }
        return ans;
    }
};