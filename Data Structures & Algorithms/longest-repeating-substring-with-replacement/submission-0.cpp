class Solution {
    unordered_map<char, int> windowCount;

    int findMaxWindowCnt(){
        int result = 0;
        for (auto& iter : windowCount) {
            result = max(result, iter.second);
        }

        return result;
    }

public:
    int characterReplacement(string s, int k) {
        if (s.length() == 0) {
            return 0;
        }

        int n = static_cast<int>(s.length());
        int left = 0, right = 0;
        int result = 0;
        windowCount[s[0]]++;

        while (left < n && right < n) {
            int windowSize = right - left + 1;
            if (windowSize <= (findMaxWindowCnt() + k)) {
                // accepted
                result = max(windowSize, result);
                right++;
                windowCount[s[right]]++;
            } else {
                windowCount[s[left]]--;
                left++;
            }
        }

        return result;
    }
};
