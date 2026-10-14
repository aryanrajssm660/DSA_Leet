class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());
        int i=0;
        int n=intervals.size();
        vector<vector<int>>ans;
        while(i<n){
            int left=intervals[i][0];
            int right=intervals[i][1];
            while(i+1<n&&intervals[i+1][0]<=right){
                if(right<=intervals[i+1][1])
                right=intervals[i+1][1];
                i++;
            }
            ans.push_back({left,right});
            i++;

        }
        return ans;
    }
};