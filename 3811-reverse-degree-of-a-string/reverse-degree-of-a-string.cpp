class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int digit=s[i]-'a';
            ans+=(26-digit)*(i+1);
        }
        return ans;
    }
};