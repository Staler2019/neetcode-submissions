class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_chars_count(26, 0);

        for(char& sc: s) {
            s_chars_count[sc- 'a']++;
        }

        for(char& tc: t) {
            s_chars_count[tc - 'a']--;
        }

        for(auto& cnt: s_chars_count) {
            if (cnt != 0) {
                return false;
            }
        }

        return true;
    }
};
