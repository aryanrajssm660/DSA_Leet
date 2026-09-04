class Solution {
public:
int find(int index1,int index2,string &word1, string &word2,vector<vector<int>>&dp){
    if(index1<0){
        return index2+1;
    }
    if(index2<0){
        return index1+1;
    }
    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    if(word1[index1]==word2[index2]){
        return dp[index1][index2]=find(index1-1,index2-1,word1,word2,dp);
    }
    return dp[index1][index2]=1+min({find(index1,index2-1,word1,word2,dp),find(index1-1,index2,word1,word2,dp),find(index1-1,index2-1,word1,word2,dp)});
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
return find(m-1,n-1,word1,word2,dp);
    }
};