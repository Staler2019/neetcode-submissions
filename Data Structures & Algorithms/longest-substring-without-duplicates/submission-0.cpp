class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int n = static_cast<int>(s.length());
        vector<int> lastIdx(130, -1);  // ascii 128
        int boundary = -1;

        for (int i = 0; i < n; i++) {
            char& c = s[i];
            if (lastIdx[c] > boundary) {
                boundary = lastIdx[c];
            }
            lastIdx[c] = i;

            int currLen = i - boundary;
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
