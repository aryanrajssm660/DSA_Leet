class Solution {
public:
vector<int>row(int n){
    long long ans=1;
    vector<int>ans_row;
    ans_row.push_back(1);
    for(int i=1;i<=n;i++){
        ans=ans*(n-i+1);
        ans/=i;
        ans_row.push_back(ans);
    }
    return ans_row;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(row(i));
        }
        return ans;
    }
};