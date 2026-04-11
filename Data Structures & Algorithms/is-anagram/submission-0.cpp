class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_chars_count;

        for(char& sc: s) {
            s_chars_count[sc]++;
        }

        for(char& tc: t) {
            s_chars_count[tc]--;
        }

        for(auto& it: s_chars_count) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};
