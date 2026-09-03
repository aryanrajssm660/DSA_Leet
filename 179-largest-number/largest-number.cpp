class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;

        for (auto it : nums) {
            temp.push_back(to_string(it));
        }

        sort(temp.begin(), temp.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        // If the largest number is 0, all numbers are 0
        if (temp[0] == "0") {
            return "0";
        }

        string ans = "";

        for (auto it : temp) {
            ans += it;
        }

        return ans;
    }
};