class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r) {
        int n = r - l + 1;
        vector<int> arr(n);
        int i1 = l, i2 = mid + 1, i = 0;
        while (i1 <= mid && i2 <= r) {
            if (nums[i1] <= nums[i2]) {
                arr[i] = nums[i1];
                i1++;
            } else {
                arr[i] = nums[i2];
                i2++;
            }
            i++;
        }
        while (i1 <= mid) {
            arr[i] = nums[i1];
            i1++;
            i++;
        }
        while (i2 <= r) {
            arr[i] = nums[i2];
            i2++;
            i++;
        }
        
        for (int i = 0; i < n; i++) {
            nums[i + l] = arr[i];
        }
        return;
    }
    int counting(vector<int>& nums, int l, int mid, int r) {
        int count = 0;
        int it = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (it <= r && nums[i] >1ll* 2 * nums[it]) {
                it++;
            }
            count += (it - mid - 1);
        }
        return count;
    }
    int mergesort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = l + (r - l) / 2;
        int count = 0;
        count += mergesort(nums, l, mid);

        count += mergesort(nums, mid + 1, r);

        count += counting(nums, l, mid, r);
        merge(nums, l, mid, r);
        return count;
    }
    int reversePairs(vector<int>& nums) {

        return mergesort(nums, 0, nums.size() - 1);
        // for (auto it : nums) {
        //     cout << it << " ";
        // }

    }
};