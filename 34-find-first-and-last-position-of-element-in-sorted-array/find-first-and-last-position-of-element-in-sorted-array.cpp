class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=nums.size();
        int last=-1;
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>target){
                h=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                first=min(first,mid);
                h=mid-1;
            }
        }
        l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>target){
                h=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                last=max(last,mid);
                l=mid+1;
            }
        }
        if(first==nums.size()){
            return {-1,-1};
        }
        return {first,last};
    }
};