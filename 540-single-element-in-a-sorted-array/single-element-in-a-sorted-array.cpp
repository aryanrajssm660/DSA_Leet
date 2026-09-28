class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     int n = nums.size();
    int lo = 0, hi = n - 1;
    
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        // Ensure mid is even
        if (mid % 2 == 1)
            mid--;
        
        // If repeating element is at even position, 
        // then single element must be on the right side
        if (nums[mid] == nums[mid + 1]) {
            lo = mid + 2;
          
        // Else single element must be on the left  
        } else {
            hi = mid;
        }
    }
    
    return nums[lo];
    }
};