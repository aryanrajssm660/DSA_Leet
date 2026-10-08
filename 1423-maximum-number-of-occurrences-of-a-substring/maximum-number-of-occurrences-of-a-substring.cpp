class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        int freq[26] = {};
        int unique = 0;

        for (int i = 0; i < minSize; i++) {
            if (freq[s[i] - 'a'] == 0)
                unique++;

            freq[s[i] - 'a']++;
        }

        if (unique <= maxLetters)
            mp[s.substr(0, minSize)]++;

        for (int i = minSize; i < s.size(); i++) {

            // remove left character
            freq[s[i - minSize] - 'a']--;

            if (freq[s[i - minSize] - 'a'] == 0)
                unique--;

            // add right character
            if (freq[s[i] - 'a'] == 0)
                unique++;

            freq[s[i] - 'a']++;

            if (unique <= maxLetters)
                mp[s.substr(i - minSize + 1, minSize)]++;
        }

        int ans = 0;

        for (auto it : mp)
            ans = max(ans, it.second);

        return ans;
    }
};